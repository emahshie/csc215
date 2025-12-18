# Answers to the study questions
## Set 1
**1. Suppose you want to add unary operations (i.e., ones requiring only one operand) to the calculator. For example, we might add "M" to indicate unary minus (i.e., change the sign of the old value) and "A" to indicate absolute value. What changes would need to be made to the program?**

In the switch statement, you need to add another case for the new uniary operators. Additionally, you need to place the "scanf("%d", &input);" statement into an if statement that does not collect input if it's a unary operator.
   
**2. Suppose that words rather than single character symbols are to be used for the operators (e.g., the user types "times" instead of "*"). Where in the program would the necessary changes occur?**

The input would be a string of chars. Before the switch statement, we would add a loop that compares the char strings to the expected values and then convert them into the expected chars.

**3. Suppose that the calculator is to be converted to use C++ double values rather than integers. Where would changes need to be made?**

We cannot do this in our environment.

**4. Most modern systems support graphical displays and mouse (or other pointer) input. Rewrite the Calculator program to take advantage of these features to produce an on-screen push-button calculator (this is a large programming project).**

We cannot do this in our environment.

**6. Show how a new command, "C", which acts like the "Clear" command on a calculator could be implemented. The clear command sets the current value to zero.**

We could add another case value to the switch statement for the char 'C'. It would set the accumulator to zero and use the same logic as the unary operators to not accept another input directly after. 

**7. (AB only) How could the calculator be modified to allow the use of parentheses to control the order of operations?**

It would accept a string of chars as input and parse through the string until it finds the innermost parenthesis. It would work out from the paranthesis performing the operations in order.

## Set 2
**1. What are the largest and smallest integer values in the programming environment you use?**

The largest is 32767, and the smallest is -32768

**2. Each BigInt object will need to store the digits that represent the BigInt value. The decision to allow arbitrarily large BigInt values affects the choices for storing digits. Name one method for storing digits that will permit an arbitrary number of digits to be stored. What effect would a limit on the number of digits in a BigInt have in the design of the BigInt class?**

Storing it as a char string would allow for an arbitrary large number of digits. A limit on the number of digits would make it easier to design the BigInt class because you could have a fixed size array to store the numbers

**3. Based on your knowledge of pencil-and-paper methods for doing arithmetic, what do you think will be the most difficult arithmetic operation (+, \*, !) to implement for the BigInt class? Why?**

I think division will be the most difficult because its computationally intensive, requiring iterative subtraction or complex algorithms. It also can change the data type from an int to a double (which is not possible in our environment).

**4. Experiment with the calculator. If you enter abcd1234 when a number is expected, what happens? If you enter 1234abcd is the behavior different? What happens if you enter an operator that’s not one of the three that are implemented?**

The second you enter a letter, the calculator stops the input at the last digit entered before the letter. If you start with a letter, it treats the number as zero. If you enter an operator that's not implemented, it reprompts you to enter another operator. 

**5. List as many operations as you can that are performed on integers, but that are not included in the list of BigInt functions and operators above.**

++, --, %

**6. (AB only) What implementation decisions would require providing a destructor, a copy constructor, and an assignment operator?**

This does not work in our environment

**7. Consider the headers for operator- and operator+ given below.**

BigInt operator - (const BigInt & big, int small);

// postcondition: returns big - small

BigInt operator + (const BigInt & big, int small);

// postcondition: returns big + small

**Write the body of operator- assuming that operator+ has been written**

It first handles specific scenarios such as when the operands have different signs (converting subtraction to addition) or when the result should be negative by flipping the order of subtraction. For same-sign numbers, it performs digit-by-digit subtraction from right to left, managing borrowing when needed, and constructs the result. After computation, leading zeros are removed, the result is reversed for correct ordering, and a new BigInt with the calculated value is returned.

## Set 3
**1. Consider the error handling provided by your C++ system. What does the system do if a file is not present in a call to open? What happens on integer overflow or divide by zero? Determine which method(s) are used and discuss the relative desirability of other options.**

If a file isn't present, the system will give an error to the user. Integer overflow doesn't produce an error, but it provides an incorrect result.

**2. List several errors that might be generated by BigInt operations and develop a declaration for an enumerated type (enum) to hold the errors.**

Invalid input (any of them), division by 0 (division)

**3. Some systems allow error checking to be “turned off” entirely for greater speed. Under what circumstances is this approach preferred?**

This is preferred when speed is incredibly important and inputs are guarenteed to be valid or errors are not very critical

**4. Consider another method for handling errors: Use an interactive error-handling approach. An error message is displayed to the user who then has the option of (a) correcting the value that caused the error, (b) halting the program, or (c) ignoring the error. Describe the strengths and weaknesses of this approach.**

The strengths would be that is it allows users to fix their errors immediately, makes it easier to recover from errors, and is overall more user friendly. The weaknesses would be that the program will be much more complex and it allows the users to potentially make a poor decision about what to do after an error. 

**5. Consider another method for handling errors: Error results are stored in a single global variable. This is set initially to indicate a “no error” condition. Whenever an error is detected, the global variable is set to an appropriate value, and the client program is responsible for examining the value of the global variable**

This approach is simple and centralized, but if it only stores the most recent error and overwrites old ones, then it wouldn't be ideal

## Set 4
**1. Why is a char vector used to store digits rather than an int vector? How will a change in the kind of element stored in the vector affect the implementation of all BigInt member functions.**

A char is a smaller data type than an int, so it can save larger numbers better. A change in the type would change the way you access the digits, but once you have the digits, the operations would be performed the same.

**2. We have chosen an enum for storing the sign of a BigInt. Describe two alternatives or types other than an enum that can be used to represent the sign of a BigInt.**

A boolean with T = positive and F = negative could be used. An integer with 1 for positive and 0 for negative could also be used. 

**3. Why will it be difficult to write the non-member functions operator == and operator < given the current method for accessing digits using GetDigit? Write the function operator == for positive BigInt values assuming that NumDigits and GetDigit are public member functions.**

Comparison would be difficult because there is no digit by digit access, so it'll be very inefficient.


