# Altair Manual Part 3 Notes
## A. The front panel switches and LEDs
- The front panel has 25 switches and 36 indicators, but can be operated with  just 15 switches and 16 indicators
- Front panel switches
  - ON-OFF: applies power/cuts off power and erases memory
  - STOP-RUN: stop program execution/start program execution
  - SINGLE STEP: implements a single machine language instruction
  - EXAMINE-EXAMINE NEXT: displays contents of a memory address/displays content of the next memory address
  - DEPOSIT-DEPOSIT NEXT: loads the data byte into memory address/loads the data byte into the next memory address
  - RESET-CLR: sets the Program Counter to the first memory address (goes to the first step of a program)/clears external equipment
  - PROTECT-UNPROTECT: prevents memory contents from being changed/allows memory contents to be changed
  - AUX: available for use with peripherals added to the basic machine
  - DATA/ADDRESS: up means a 1 bit, down means a 0 bit
- Indicator LEDs
  - ADDRESS: denotes the memory address being examined or loaded with data
  - DATA: denotes the data in the specified memory address
  - INTE: when on an interrupt has been enabled
  - PROT: when on the memory is protected
  - WAIT: when on the CPU is in a wait state
  - HLDA: when on a hold has been acknowledged
- Status LEDs - when on
  - MEMR: the memory bus will be used
  - INP: input data on the data bus
  - M1: the CPU is processing the first machine cycle
  - OUT: contains the address of an output device
  - HLTA: a halt instruction has been executed and acknowledged
  - STACK: holds the Stack Pointer’s push-down stack address
  - WO: operation in the cycle will be a write memory or output function. Otherwise, a read memory or input operation will occur
  - INT: an interrupt request has been acknowledged
## B
- LDA: Load the acumulator
- MOV: move acumulator contence to register
- ADD: add Acumulator to register then saves in Acumulator
- STA: stores Acumulator to memory adress
- JMP: go to start of program
- Adding program: LDA, MOV, STA, LDA, ADD, STA, JMP

- here is all the bit paterns for each of the commands
  
![bit map](bitpatern.png)

- he is the steps for entering it

  
 ![steps](image.png)

## C
- Machine language requires the programmer to keep track of memory
- Memory mapping: a technique where you assign various types of data to certain blocks of memory reserved for a specific purpose
- Make a table to record where items are stored
- Be sure to update the table when changes are made
## D
- The Altair 8800 uses various memory addressing methods, including **direct addressing**, **register pair addressing**, **Stack Pointer addressing**, **immediate addressing**, and **stack addressing of subroutines**. Each method involves specific instructions and memory management techniques, which are crucial for effective programming.
## E
- some methods to help speed up altaire usage
    - always proof read you programs by resseting the the first memory location of the program and reading though and checking to make sure everything is correct and fixing it if it isnt
    - if you need more steps later and you already added some NOP(No OPeration) it is much easier to just add the steps instead of a NOP
    - when debuging you can use a single step switch to go though the code step by step and examin the memory
