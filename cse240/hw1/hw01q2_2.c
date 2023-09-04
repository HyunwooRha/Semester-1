/* This C program demonstrates the switch statement without using breaks.*/
#include <stdio.h>
void main(){
	// declares the two numbers used for the calculator as a double
    double a = 10, b = 20;
	// for loop that runs the code 5 times, where i starts from 0 and ending at 4
    for (int i = 0; i<5; i++){
	    //prompt that makes it look like it is asking a question
        printf("Enter math operation: ");
	    // asks for a character, is used for switch statement
        char ch = getchar();
        // f is defined as a float for the floating point used in the printf statements
	float f;
        printf("ch = %c\n", ch);
        switch (ch) {
		    // different cases for each character, defaulting to printing invalid
		    // the %.0f cuts the decimal entirely, %.01f includes 1 decimal place in case for division
            case '+': f = a + b; printf("f = %.0f\n", f); break;
            case '-': f = a - b; printf("f = %.0f\n", f); break;
            case '*': f = a * b; printf("f = %.0f\n", f); break;
            case '/': f = a / b; printf("f = %.01f\n", f); break;
            default: printf("invalid operator\n"); break;
        }
	ch = getchar();
    }

}
