# Chapter 15: The File Control Block
- CP/M takes on the task of keeping track of physical disk addresses, allowing us to “talk” to the disk through named files


## Getting to know the FCB
- Disk accesses use the same entry point as I/O access (location 5)
- A block of RAM memory known as a File Control Block (FCB) is used to pass all the required information to access named files
- The default transient file control block (TFCB) is established by CP/M at memory locations 005CH through 007CH
- TFCB consists of 33 bytes of memory
- All FCB locations other than the drive select byte and file name (8 bytes)/file type (3bytes) are operating system workspace


## How CP/M uses the FCB
- When using the FCB to access named files, we let CP/M keep track of the 128 byte records that make up a unit of data storage. The operating system will allocate disk space in groups consisting of eight records each, meaning each group will contain 1024 bytes (the minimum size of any file on a CP/M disk)

## Creating a disk file
- When we want to write a file onto a disk, we provide CP/M with a FCB containing the drive selection and the file name and type
- CP/M will find the lowest numbered available disk group and allow us to write up to eight records into it while CP/M updates the record countries in the FCB
- If our file is larger than 16K bytes, CP/M will automatically open an extension of the file, incrementing the contents of ex in the FCB for each 16K bytes of disk space used
- When we tell CP/M to close a file, the first 32 bytes of the FCB are written onto the disk as a directory entry and the drive select byte (dr) is zeroed

## SHOFN: displays the TCFB file name set up by CCP
- Begins by saving the contents of the BC and HLregister pairs
- Uses the message output subroutine COMSG: to display the file name and type
- Saves the contents of FCBTY and puts a zero at the end to terminate the file name string
- The memory contents are loaded in A then moved to C
- A is zeroed, and another zero is stuffed into FCBEX to terminate the file type string
- If the current drive has been specified the “at sign” is shown to say you are at the current drive. Otherwise, the single character console output subroutine CO: is used to display the drive designator letter
- The index is then incremented to point to the first file name character, and the file name is displayed by the call to COMSG
- The index is reinitialized to point to FCBTY, the original contents of this location restored, and then a period and the type field are output to the console


## Breaking up with ED
- The CPMIO subroutines can be broken up using ED
- Edit the files by killing all of the lines you do not want to retain

## Merging files with PIP
- “PIP TESTC15.ASM=DISKEQU.LIB, TESTC15.LIB, SHOFN.LIB,CPMIO.LIB” merges all the .LIB files required for testing SHOFN:
- When merging files, the main program must be first followed by the subroutines
