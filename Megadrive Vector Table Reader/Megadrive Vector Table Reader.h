#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <intrin.h>
#include <map>
#include <optional>

const std::string MD_ROM_IDENTIFIER = "SEGA";
const std::vector<std::string> VECTORS = {
"Initial Stack Address                     ",
"Start of program Code                     ",
"Bus error                                 ",
"Address error                             ",
"Illegal instruction                       ",
"Division by zero                          ",
"CHK exception                             ",
"TRAPV exception                           ",
"Privilage violation                       ",
"TRACE exception                           ",
"Line-A emulator                           ",
"Line-F emulator                           ",
"Reserved (NOT USED)                       ",
"Co-processor protocol violation           ",
"Format error                              ",
"Uninitialized Interrupt                   ",
"Reserved (NOT USED)                       ",
"Reserved (NOT USED)                       ",
"Reserved (NOT USED)                       ",
"Reserved (NOT USED)                       ",
"Reserved (NOT USED)                       ",
"Reserved (NOT USED)                       ",
"Reserved (NOT USED)                       ",
"Reserved (NOT USED)                       ",
"Spurious Interrupt                        ",
"IRQ Level 1                               ",
"IRQ Level 2 (EXT Interrupt)               ",
"IRQ Level 3                               ",
"IRQ Level 4 (VDP Horizontal Interrupt)    ",
"IRQ Level 5                               ",
"IRQ Level 6 (VDP Vertical Interrupt)      ",
"IRQ Level 7                               ",
"TRAP #00 Exception                        ",
"TRAP #01 Exception                        ",
"TRAP #02 Exception                        ",
"TRAP #03 Exception                        ",
"TRAP #04 Exception                        ",
"TRAP #05 Exception                        ",
"TRAP #06 Exception                        ",
"TRAP #07 Exception                        ",
"TRAP #08 Exception                        ",
"TRAP #09 Exception                        ",
"TRAP #10 Exception                        ",
"TRAP #11 Exception                        ",
"TRAP #12 Exception                        ",
"TRAP #13 Exception                        ",
"TRAP #14 Exception                        ",
"TRAP #15 Exception                        ",
"(FP) Branch or Set on Unordered Condition ",
"(FP) Inexact Result                       ",
"(FP) Divide by Zero                       ",
"(FP) Underflow                            ",
"(FP) Operand Error                        ",
"(FP) Overflow                             ",
"(FP) Signaling NAN                        ",
"(FP) Unimplemented Data Type              ",
"MMU Configuration Error                   ",
"MMU Illegal Operation Error               ",
"MMU Access Violation Error                ",
"Reserved (NOT USED)                       ",
"Reserved (NOT USED)                       ",
"Reserved (NOT USED)                       ",
"Reserved (NOT USED)                       ",
"Reserved (NOT USED)                       "
};

const uint8_t PARAM_PREFIX = 1;
const uint8_t PARAM_OFFSET = 2;
const uint8_t PARAM_BIT_PADDING = 3;
const uint8_t PARAM_IGNORE_IDENTIFIER = 4;
const std::map<std::string, uint8_t> VALID_ARGUMENTS = {
	{"-p", PARAM_PREFIX},
	{"--prefix", PARAM_PREFIX},
	{"-o", PARAM_OFFSET},
	{"--offset", PARAM_OFFSET},
	{"-b", PARAM_BIT_PADDING},
	{"--bit-padding", PARAM_BIT_PADDING},
	{"-i", PARAM_IGNORE_IDENTIFIER},
	{"--ignore-identifier", PARAM_IGNORE_IDENTIFIER}
};

std::ifstream fileStream;
std::optional<uint8_t> offset;
std::string prefix = "0x";
uint8_t bitPadding = 32;
bool checkIdentifier = true;

int main(int argumentCount, char* arguments[]);
bool parseArgs(std::vector<std::string> args);
bool parseROM();