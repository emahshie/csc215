# Chapter 3
## Logical Names and Physical Entities
- Things attached to computer
- CRT: Cathode ray tube - old style of bulky monitor
- CON: console - keyboard and screen device
- LPT: line printer to make listings of programs
- A, B, etc: Disk drives numbered 0 and 1
- Four logical I/O devices can be accessed through the CP/M operating system
	- CON
- LST: list device
- RDR & PUN: input and output devices accessed through these (PTR & PTP on old fashioned)
## Selecting I/O Devices
- If real switches are connected, they can be used to switch from on I/O device to another (For instance, our RDR: could receive data from a card reader, or a paper tape reader, or the receive side (Rx) of a modem, depending on the setting of the RDR: switch)
- Rather than real selector switches, CP/M uses bit patterns stored in a one-byte memory location called IOBYT to select a physical device for each logical device
- Having physical devices permanently attached to the computer and selecting them in software allows the operator to make a selection through the CP/M CON: interface or we could allow our programs to change the selections
- Doesn’t matter which one they are connected to as long as we know which one is where
- A device such as the modem that includes both send and receive functions must have the proper settings in both the RDR: and PUN: sections of the IOBYT. The CON: is the only bi-directional logical device
- We will never need to change the IOBYT switches and will only be using CRT: as CON:, and LPT: as LST:

# Chapter 4
- It is not as easy to keep track of what is happening within a software system as it is in the hardware environment
- Since the bootstrap PROM program accesses the floppy disk system and since the computer may contain a monitor program that can access the console and possibly other peripherals, there are more than one paths to these devices
## Named File Handling
- The name of a file in a CP/M system has a few constraints
	- It can be up to 8 characters
	- A file type of 3 characters is appended to the name, following a period
	- ie FILENAME.TYP
	- .ASM: assembly language source program
- .COM: command file that CP/M will load into memory and execute whenever you type in its FILENAME following the prompt “>” that says CP/M is ready to accept a command
- You can make your own file types as long as they don’t conflict with the default types
- It is a good idea to start off by naming each of your disks with this kind of empty file that will create a directory entry to provide identification for each disk you use
- Files can be created or deleted, or accessed for reading or writing, either from the console or from within a user's programs, using the same nam- ing conventions in all cases
## Wildcards in File Names
- Enter the command DIR to list all the files on the current disk
- DIR *.TYP lists all the files with file type TYP
- * is a wildcard that tells CP/M to accept any FILENAME
- L???.TYP or L*.TYP lists all files that start with an L in that type (number of ? doesn’t matter)
- PIP B:=A:*.* tells the Peripheral Interchange Program (PIP) to copy all the files from drive A: onto the disk in drive B:
- The options for accessing named files is the same for utility programs and CP/M
## Logical Unit Access
- From the console, the operator can specify a logical unit within a command string such as
PIP PUN:=FILENAME.TYP and have the named disk file sent to the physical device currently attached as logical device PUN:. In this way the computer operator could send a program source file to another computer using a modem and a telephone connection
- A program can access any of the logical devices
- Either the operator or user program can change the logical device assignments
## Line Editing
- If you are keying in a command line in response to the СР/М prompt ">" and make a single-keystroke error, you can back up one character by hitting the DEL, DELETE, BS, or RUBOUT key on your terminal
- When CP/M sees the delete key code, it will not always be able to back up the cursor on the screen, depending on version. If your version does not back up and over-write the character, the deletion is shown by the repetition of the character. Since this clutters up the typed line with extra characters, you can review the command line before terminating it with the usual carriage return by entering the control code CTRL R
- To review the line as displayed on the CRT before executing it, type CTRL R and it will be repeated as edited on the next line
- To give up, and abort the entire entry if you have made too many errors, type CTRL U or CTRL X


