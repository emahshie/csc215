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

It would accept a string of chars as input and parse through the string until it finds the innermost paranthesis. It would work out from the paranthesis performing the operations in order.
