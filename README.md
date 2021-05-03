# Megadrive-Vector-Table-Reader
This is a small tool which will parse the 68k vector table of a specified Mega Drive ROM and output it in a human readable format.

## Sample usage
```bash
Megadrive_Vector_Table_Reader.exe example.md
```

## Sample output
```
example.md
0x004 Initial Stack Address                     : 0x00ff0592
0x008 Start of program Code                     : 0x00000200
0x00c Bus error                                 : 0xffffffff
0x010 Address error                             : 0xffffffff
0x014 Illegal instruction                       : 0xffffffff
0x018 Division by zero                          : 0xffffffff
0x01c CHK exception                             : 0xffffffff
0x020 TRAPV exception                           : 0xffffffff
0x024 Privilage violation                       : 0xffffffff
0x028 TRACE exception                           : 0xffffffff
0x02c Line-A emulator                           : 0xffffffff
0x030 Line-F emulator                           : 0xffffffff
0x034 Reserved (NOT USED)                       : 0xffffffff
0x038 Co-processor protocol violation           : 0xffffffff
0x03c Format error                              : 0xffffffff
0x040 Uninitialized Interrupt                   : 0xffffffff
0x044 Reserved (NOT USED)                       : 0xffffffff
0x048 Reserved (NOT USED)                       : 0xffffffff
0x04c Reserved (NOT USED)                       : 0xffffffff
0x050 Reserved (NOT USED)                       : 0xffffffff
0x054 Reserved (NOT USED)                       : 0xffffffff
0x058 Reserved (NOT USED)                       : 0xffffffff
0x05c Reserved (NOT USED)                       : 0xffffffff
0x060 Reserved (NOT USED)                       : 0xffffffff
0x064 Spurious Interrupt                        : 0xffffffff
0x068 IRQ Level 1                               : 0x0001326e
0x06c IRQ Level 2 (EXT Interrupt)               : 0x0001326e
0x070 IRQ Level 3                               : 0x0001326e
0x074 IRQ Level 4 (VDP Horizontal Interrupt)    : 0x00013270
0x078 IRQ Level 5                               : 0x00013270
0x07c IRQ Level 6 (VDP Vertical Interrupt)      : 0x00013272
0x080 IRQ Level 7                               : 0x00013272
0x084 TRAP #00 Exception                        : 0xffffffff
0x088 TRAP #01 Exception                        : 0xffffffff
0x08c TRAP #02 Exception                        : 0xffffffff
0x090 TRAP #03 Exception                        : 0xffffffff
0x094 TRAP #04 Exception                        : 0xffffffff
0x098 TRAP #05 Exception                        : 0xffffffff
0x09c TRAP #06 Exception                        : 0xffffffff
0x0a0 TRAP #07 Exception                        : 0xffffffff
0x0a4 TRAP #08 Exception                        : 0xffffffff
0x0a8 TRAP #09 Exception                        : 0xffffffff
0x0ac TRAP #10 Exception                        : 0xffffffff
0x0b0 TRAP #11 Exception                        : 0xffffffff
0x0b4 TRAP #12 Exception                        : 0xffffffff
0x0b8 TRAP #13 Exception                        : 0xffffffff
0x0bc TRAP #14 Exception                        : 0xffffffff
0x0c0 TRAP #15 Exception                        : 0xffffffff
0x0c4 (FP) Branch or Set on Unordered Condition : 0xffffffff
0x0c8 (FP) Inexact Result                       : 0xffffffff
0x0cc (FP) Divide by Zero                       : 0xffffffff
0x0d0 (FP) Underflow                            : 0xffffffff
0x0d4 (FP) Operand Error                        : 0xffffffff
0x0d8 (FP) Overflow                             : 0xffffffff
0x0dc (FP) Signaling NAN                        : 0xffffffff
0x0e0 (FP) Unimplemented Data Type              : 0xffffffff
0x0e4 MMU Configuration Error                   : 0xffffffff
0x0e8 MMU Illegal Operation Error               : 0xffffffff
0x0ec MMU Access Violation Error                : 0xffffffff
0x0f0 Reserved (NOT USED)                       : 0xffffffff
0x0f4 Reserved (NOT USED)                       : 0xffffffff
0x0f8 Reserved (NOT USED)                       : 0xffffffff
0x0fc Reserved (NOT USED)                       : 0xffffffff
0x100 Reserved (NOT USED)                       : 0xffffffff
```
