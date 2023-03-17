# Megadrive-Vector-Table-Reader
This is a small tool which will parse the 68k vector table of a specified Mega Drive ROM and output it in a human readable format.

## Sample usage
```bash
Megadrive_Vector_Table_Reader.exe example.md
```

## Sample output
```
example.md
0x000 Initial Stack Address                     : 0x00ff0592
0x004 Start of program Code                     : 0x00000200
0x008 Bus error                                 : 0xffffffff
0x00c Address error                             : 0xffffffff
0x010 Illegal instruction                       : 0xffffffff
0x014 Division by zero                          : 0xffffffff
0x018 CHK exception                             : 0xffffffff
0x01c TRAPV exception                           : 0xffffffff
0x020 Privilage violation                       : 0xffffffff
0x024 TRACE exception                           : 0xffffffff
0x028 Line-A emulator                           : 0xffffffff
0x02c Line-F emulator                           : 0xffffffff
0x030 Reserved (NOT USED)                       : 0xffffffff
0x034 Co-processor protocol violation           : 0xffffffff
0x038 Format error                              : 0xffffffff
0x03c Uninitialized Interrupt                   : 0xffffffff
0x040 Reserved (NOT USED)                       : 0xffffffff
0x044 Reserved (NOT USED)                       : 0xffffffff
0x048 Reserved (NOT USED)                       : 0xffffffff
0x04c Reserved (NOT USED)                       : 0xffffffff
0x050 Reserved (NOT USED)                       : 0xffffffff
0x054 Reserved (NOT USED)                       : 0xffffffff
0x058 Reserved (NOT USED)                       : 0xffffffff
0x05c Reserved (NOT USED)                       : 0xffffffff
0x060 Spurious Interrupt                        : 0xffffffff
0x064 IRQ Level 1                               : 0x0001326e
0x068 IRQ Level 2 (EXT Interrupt)               : 0x0001326e
0x06c IRQ Level 3                               : 0x0001326e
0x070 IRQ Level 4 (VDP Horizontal Interrupt)    : 0x00013270
0x074 IRQ Level 5                               : 0x00013270
0x078 IRQ Level 6 (VDP Vertical Interrupt)      : 0x00013272
0x07c IRQ Level 7                               : 0x00013272
0x080 TRAP #00 Exception                        : 0xffffffff
0x084 TRAP #01 Exception                        : 0xffffffff
0x088 TRAP #02 Exception                        : 0xffffffff
0x08c TRAP #03 Exception                        : 0xffffffff
0x090 TRAP #04 Exception                        : 0xffffffff
0x094 TRAP #05 Exception                        : 0xffffffff
0x098 TRAP #06 Exception                        : 0xffffffff
0x09c TRAP #07 Exception                        : 0xffffffff
0x0a0 TRAP #08 Exception                        : 0xffffffff
0x0a4 TRAP #09 Exception                        : 0xffffffff
0x0a8 TRAP #10 Exception                        : 0xffffffff
0x0ac TRAP #11 Exception                        : 0xffffffff
0x0b0 TRAP #12 Exception                        : 0xffffffff
0x0b4 TRAP #13 Exception                        : 0xffffffff
0x0b8 TRAP #14 Exception                        : 0xffffffff
0x0bc TRAP #15 Exception                        : 0xffffffff
0x0c0 (FP) Branch or Set on Unordered Condition : 0xffffffff
0x0c4 (FP) Inexact Result                       : 0xffffffff
0x0c8 (FP) Divide by Zero                       : 0xffffffff
0x0cc (FP) Underflow                            : 0xffffffff
0x0d0 (FP) Operand Error                        : 0xffffffff
0x0d4 (FP) Overflow                             : 0xffffffff
0x0d8 (FP) Signaling NAN                        : 0xffffffff
0x0dc (FP) Unimplemented Data Type              : 0xffffffff
0x0e0 MMU Configuration Error                   : 0xffffffff
0x0e4 MMU Illegal Operation Error               : 0xffffffff
0x0e8 MMU Access Violation Error                : 0xffffffff
0x0ec Reserved (NOT USED)                       : 0xffffffff
0x0f0 Reserved (NOT USED)                       : 0xffffffff
0x0f4 Reserved (NOT USED)                       : 0xffffffff
0x0f8 Reserved (NOT USED)                       : 0xffffffff
0x0fc Reserved (NOT USED)                       : 0xffffffff
```
