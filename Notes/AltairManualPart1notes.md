# Altair 8800 Manual Notes
## Introduction
- At the time, the ALTAIR 8800 was the cheapest computer option
- It uses an Intel 8080 Microcomputer, which is a CPU on a chip
- The purpose of the manual is to teach users of all levels how to operate the computer
- Part 1 talks about computer terminology, number systems, basic programming, and computer languages
- Parts 2 and 3 talk about how to operate the computer
- Part 4 has the instructions
- As a user gets more experience with the machine, it will get easier to use

## A. Logic
- George Boole showed how logical statements can be analyzed through arithmetics by assuming a statement is either true or false
- AND: true if all conditions are true
- OR: true if any conditions are true
- NOT: reverses the meaning
- Truth tables can be used to show the output of logical expressions

## B. Electronic Logic
* the 3 basic logic functions can be made with simple circuits
* semi circle is and
* pointy semi circle is or
* triangle with circle on the right is not
* combining not with the other 2 make 2 more logic circuits NAND and NOR
* these are shown with the symbol of either and or or but they have a circle on the right side like how the original not does
* 3 or more logic circuits make a logic system
* one basic logic system is an exclusive or (xor)
* the xor it only activates when one and only one is true
* this can be used for addition when it has a carry because if one and only one of the inputs is true it should return a 1
* this can be represented as a or with an extra line on the left and the carry is generally ignored
  
## C. Number Systems
- Number systems can be based on different numbers to be more compatible with computers
  
## D. The Binary System
* The altair uses binary calculations
* one number contains 8 bits
* A byte is 8 bits
* Binary uses 0 and 1 and is base 2
* to convert from binary to decimal you can multiply each digit by 2^(column of the number starting from the right at 0) then adding them all together
