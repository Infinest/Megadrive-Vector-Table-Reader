#include "Megadrive Vector Table Reader.h"

int main(int argumentCount, char* arguments[])
{
	const std::vector<std::string> args(arguments + 1, arguments + argumentCount);

	if (!parseArgs(args))
	{
		return EXIT_FAILURE;
	}

	if (!parseROM())
	{
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

bool parseArgs(std::vector<std::string> args)
{
	if (args.size() == 0)
	{
		std::cout << "Usage: mdvtr.exe file [options]" << std::endl;
		std::cout << std::noskipws << "  options:" << std::endl;
		std::cout << std::noskipws << "    -p, --prefix:      Specify the prefix for the output vector/s [default: \"0x\"]" << std::endl;
		std::cout << std::noskipws << "    -b, --bit-padding: Determines the padding for the output vector/s." << std::endl;
		std::cout << std::noskipws << "                       Bit padding must be supplied in decimal, must be a multiple of 4 and the following must apply 0 <= padding <= 32. [default: 32]" << std::endl;
		std::cout << std::noskipws << "    -o, --offset:      If specified, only outputs the vector at the given offset." << std::endl;
		std::cout << std::noskipws << "                       Offset must be supplied in hexadecimal, must be a multiple of 0x4 and the following must apply 0x0 <= offset <= 0xfc. Allowed syntax: 0xXX or XX" << std::endl;
		return false;
	}

	for (size_t i = 0; i < args.size(); i++)
	{
		// The first parameter is always supposed to be the target file path
		if (i == 0)
		{
			fileStream.open(args[i]);
			if (!fileStream.good())
			{
				std::cout << "Invalid file specified." << std::endl;
				return false;
			}
		}
		else
		{
			if (!VALID_ARGUMENTS.contains(args[i]))
			{
				std::cout << "Invalid parameter \"" << args[i] << "\" specified." << std::endl;
				return false;
			}

			switch (VALID_ARGUMENTS.at(args[i]))
			{
			case PARAM_PREFIX:
				prefix = args[++i];
				break;
			case PARAM_OFFSET:
				try {
					offset = (uint8_t)std::stoul(args[++i], nullptr, 16);

					// Range 0x0 to 0xfc, Only multiples of 0x4
					if (offset.value() < 0x0 || 0xfc < offset.value() || offset.value() % 0x4 != 0)
					{
						throw std::invalid_argument("Invalid number specified.");
					}
				}
				catch (const std::exception&)
				{
					std::cout << "Invalid offset \"" << args[i] << "\" specified. Offset must be supplied in hexadecimal, must be a multiple of 0x4 and the following must apply 0x0 <= offset <= 0xfc. Allowed syntax: 0xXX or XX" << std::endl;
					return false;
				}
				break;
			case PARAM_BIT_PADDING:
				try
				{
					bitPadding = (uint8_t)std::stoul(args[++i], nullptr, 10);

					// Range 0 to 32, Only multiples of 4
					if (bitPadding < 0 || 32 < bitPadding || bitPadding % 4 != 0)
					{
						throw std::invalid_argument("Invalid number specified.");
					}
				}
				catch (const std::exception&)
				{
					std::cout << "Invalid bit padding \"" << args[i] << "\" specified. Bit padding must be supplied in decimal, must be a multiple of 4 and the following must apply 0 <= padding <= 32." << std::endl;
					return false;
				}
				break;
			}
		}
	}

	return true;
}

bool parseROM()
{
	fileStream.seekg(0, fileStream.end);
	std::streampos fileLength = fileStream.tellg();

	if (fileLength < 0x260)
	{
		std::cout << "The file specified is not a valid Mega Drive ROM." << std::endl;
		return false;
	}

	fileStream.seekg(0x100);
	std::vector<char> buffer(4);
	fileStream.read(&buffer[0], buffer.size());
	std::string SEGA(buffer.begin(), buffer.end());

	if (SEGA != MD_ROM_IDENTIFIER)
	{
		std::cout << "The file specified is not a valid Mega Drive ROM." << std::endl;
		return false;
	}

	std::stringstream output;

	if (offset.has_value())
	{
		try
		{
			fileStream.seekg(offset.value());
			uint32_t vector;
			fileStream.read(reinterpret_cast<char*>(&vector), sizeof(vector));
			vector = _byteswap_ulong(vector);
			output << prefix << std::setfill('0') << std::setw(bitPadding / 4) << std::hex << (vector);
		}
		catch (const std::exception&)
		{
			std::cout << "Could not parse vector at the given offset." << std::endl;
			return false;
		}
	}
	else
	{
		try
		{
			fileStream.seekg(0x0);
			for (size_t i = 0; i < VECTORS.size(); i++)
			{
				output << prefix << std::setfill('0') << std::setw(3) << fileStream.tellg() << " ";
				uint32_t vector;
				fileStream.read(reinterpret_cast<char*>(&vector), sizeof(vector));
				vector = _byteswap_ulong(vector);
				output << VECTORS[i] << ": " << prefix << std::setfill('0') << std::setw(bitPadding / 4) << std::hex << (vector) << std::endl;
			}
		}
		catch (const std::exception&)
		{
			std::cout << "Could not parse the vector table within the given file." << std::endl;
			return false;
		}
	}
	std::cout << output.rdbuf();
	return true;
}