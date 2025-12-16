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

Storing it as a char string would allow for an arbitrary large number of digits. A limit on the number of digits would 


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


