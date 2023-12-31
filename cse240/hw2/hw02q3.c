#include <stdio.h>
#pragma warning(disable : 4996) // needed in VS

// CSE 240 Fall 2023 Homework 2 Question 3 (25 points)
// Note: You may notice some warnings when you compile in GCC or VS, that is okay.

#define subtract2(x) (x - x - x)

#define combMacro(a, b) (4 * a - b * a * a * b)

int combFunc(int a, int b) {
	return (4 * a - b * a * a * b);
}

// Part 1:
// We want to pass the value of 2 to Subtract2 and expect the result to be -2, why is the result 0? Correct the error (5 points)
void part1(int x) {
	int result;
	--x;
	result = subtract2(x);
	
	printf("subtract2(2) = %d \n\n", result);

	// Why did this error occur? Please provide the answer in your own words below.
	printf("Explanation: --x - --x - --x = 0 when x=3. we need to calculate --x first then pass that as an input\n\n\n"); // (2.5 points)
}


// Part 2:
// We want to pass decremented values of x and y to the macro and function to compare their outputs in VS and GCC.
// Run this program in Visual Studio(VS) and then again in GCC. Fill the blanks below with the output values for combFunc and combMacro.
// Then correct/edit this function so that combFunc and combMacro produce same correct output of -28.			// (5 points)
// 
void part2(int x, int y) {
	int copy_x = --x, copy_y = --y;
	printf("combFunc(x, y) = %d\ncombMacro(x, y) = %d\n\n", combFunc(x, y), combMacro(copy_x, copy_y));


	// Replace the 4 blank spaces below with the actual output observed when running the code in VS and GCC.
	// The blanks should have the answers of unedited program. Keep the answers in blanks as they were, after editing the program.
	printf("In VS : the result of combFunc = 0 and combMacro = -5 \n"); 			// (5 points)
	printf("In GCC: the result of combFunc = -28 and combMacro = 8 \n\n"); 		// (5 points)

	// Explain in a short sentence why VS and GCC could possibly produce a different value for the same program and for the same input.
	printf("Explanation: the compilers for gcc and VS are different. The preprocessor might also work differently.\n\n"); //  (2.5 points)
}

// Do not edit main()  
int main()
{
	int x = 3, y = 4;

	printf("Part 1:\n\n");
	part1(x);
	printf("Part 2:\n\n");
	part2(x, y);

	while (1);	// needed to keep console open in VS
	return 0;
}
