
#include <iostream>

int main(int argc, char** argv)
{
	const int NUM_NUMBERS = 5;
	int numbers[NUM_NUMBERS] = { 10, 20, 30, 40, 50 };
	size_t n = sizeof(numbers) / sizeof(numbers[0]);

	/* 
	TODO: Print each value of the array in order
	Expected:
		10, 20, 30, 40, 50,
	*/
	// Task1: Write your Code here
	// ------------------------------------------------------------------------
	for (int i = 0; i < n; i++) {
		std::cout << numbers[i] << ' ';
	}
	// ------------------------------------------------------------------------


	/*
	TODO: Print each value of the array in reverse order
	Expected:
		50, 40, 30, 20, 10,
	*/

	// Task 2: Write your Code here
	// ------------------------------------------------------------------------
	for (int i = n -1 ; i >= 0; i--) {
		std::cout << numbers[i] << ' ';
	}

	// ------------------------------------------------------------------------

	return 0;
}
