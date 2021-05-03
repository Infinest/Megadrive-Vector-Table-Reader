#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <intrin.h>

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

int main(int argumentCount, char* arguments[]);
int parseROM(std::ifstream& fileStream, char* filePath);