# Chapter 13: Buffered Input/Output
- The CPMIO.ASM file from the last chapter only has single-character-at-a-time I/O subroutines, which aren’t very practical because you typically want to display a whole message
- The goal of this chapter is to enter, assemble, and test subroutines that will allow you to transfer a line at a time between programs and the computer operator

## Saving Old Files
- Save a copy of the debugged CPMIO.ASM file just in case
- Delete all .BAK files to free up disk space because they are only good as temporary backup while editing

## Adding Library Files
- To add the new line-oriented subroutines to the CPMIO file, you must add text to the existing source file and update the test program to exercise the new routines
- It is faster to add the new text into the library (.LIB) files rather than directly into the original source file. One library file should be called CH13.LIB and contain the new subroutines. The other should be named TESTC13.LIB and contain the test program
- These files can be inserted into CPMIO.ASM, and if done correctly, you should be able to assemble it error free

## Program Broken Down
(the textbook has a more detailed explanation of each subroutine, but for the sake of time here’s a summary)
- CCRLF: uses subroutine CO: to start a new line on the console by outputting the code for carriage return followed by the code for line feed to the CON: device
- COMSG: displays a line of text on the CON: using an index register to point into successive locations in the text buffer in memory
- CIMSG: gets a line from the operator stored in INBUF: (the line input buffer)

## Testing the Subroutines
- The new test program starts by displaying the sign-on message through START1:
- The index is initialized to point to the start of the message buffer, COMSG: is called, and the message is displayed followed by the CR and LF that were included in its buffer.
- START2: creates an endless loop that calls CIMSG: to input a message. The user types a message followed by a return, which will case a return to the CALL CCRLF instruction to begin a new line on the screen
- COMSG: is called to echo the line to the user, and a new line is started to allow the user to type more

## Debugging with DDT
### What is DDT and how to start it
- Most errors should be able to be identified by comparing the assembler output with the expected output included in the chapter
- If that doesn’t work, you must use DDT, the CP/M Dynamic Debugging Tool
- To start debugging, enter DDT CPMIO.COM

### How DDT hooks into the system
- DDT is loaded into the TPA from the disk, but then relocates itself up in memory to free the TPA workspace for the program
- DDT changes the BDOS call vector (location 5 in memory) so it can trap I/O calls your program makes
- It also sets one of the CPU interrupt vectors (location 38H) to point to itself and uses a software interrupt instruction (RST 7, opcode 0FFH) to create breakpoints.

### Basic way to run and break
- To tell DDT “run from address 100H up to but not including 103H”, you use a command like:
G100,103
- DDT replaces the instruction at 103H with the restart opcode so when the program reaches 103H the CPU traps into DDT
- When the trap happens DDT prints *103 to show the breakpoint was hit and gives you a prompt for another command
- At each breakpoint step, you can call for the display of any or all register contents and the contents of memory

### Tracing and step execution
- The trace command is the best way to test a program
- The trace command shows each instruction executed and the full set of CPU registers after each instruction
- Tracing can be slow because it prints every instruction and register contents.
- Use short trace counts to step through a subroutine instead of tracing for long periods.
- Example: T1A means trace 1A hex (26 decimal) instructions.


### How DDT handles BDOS/system calls
- When your program calls BDOS DDT traps those calls so it can display what happens, but DDT typically disables tracing while the BDOS call runs because BDOS routines are already trusted/working

### Flags and their names
- The flag register bits (Zero, Carry, Sign, Parity, etc.) are displayed in DDT but DDT uses some different names than Intel conventions. The textbook as a table showing the naming conversions
