#include "Megadrive Vector Table Reader.h";

int main(int argumentCount, char* arguments[])
{
	int exit = EXIT_SUCCESS;
	if (arguments[1] == NULL)
	{
		std::cout << "Please specify the path to the Mega Drive ROM you would like to parse." << std::endl;
		exit = EXIT_FAILURE;
	}
	else
	{
		std::ifstream fileStream(arguments[1]);
		exit = parseROM(fileStream, arguments[1]);
	}
	return exit;
}

int parseROM(std::ifstream& fileStream, char* filePath)
{
	if (!fileStream.good())
	{
		std::cout << "The file specified does not exist." << std::endl;
		return EXIT_FAILURE;
	}
	else
	{
		fileStream.seekg(0, fileStream.end);
		int fileLength = fileStream.tellg();

		if (fileLength < 0x260)
		{
			std::cout << "The file specified is not a valid Mega Drive ROM." << std::endl;
			return EXIT_FAILURE;
		}

		fileStream.seekg(0x100);
		std::vector<char> buffer(4);
		fileStream.read(&buffer[0], buffer.size());
		std::string SEGA(buffer.begin(), buffer.end());

		if (SEGA != MD_ROM_IDENTIFIER)
		{
			std::cout << "The file specified is not a valid Mega Drive ROM." << std::endl;
			return EXIT_FAILURE;
		}

		std::stringstream output;
		try
		{
			output << filePath << "\n";
			fileStream.seekg(0x0);
			for (int i = 0; i < 64; i++)
			{
				uint32_t offset;
				fileStream.read(reinterpret_cast<char*>(&offset), sizeof(offset));
				offset = _byteswap_ulong(offset);
				output << "0x" << std::setfill('0') << std::setw(3) << fileStream.tellg() << " ";
				output << VECTORS[i] + ": 0x" << std::setfill('0') << std::setw(8) << std::hex << (offset) << std::endl;
			}
		}
		catch (const std::exception&)
		{
			std::cout << "Could not parse the vector table within the given file." << std::endl;
			return EXIT_FAILURE;
		}
		std::cout << output.rdbuf();
		return EXIT_SUCCESS;
	}
}