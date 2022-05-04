// HellowNeighbour.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <string>


int main()
{
#pragma region celsius to fahrenheit
	//celsius to fahrenheit
	//float degcelsius = 78.0f;
	//float degfahrenheit = 172.4f; // modify this variable below.

	//std::cout << "please enter the temperature in celsius:" << std::endl;
	//std::cout << degcelsius << "c  " << std::endl;
	//std::cout << "\n" << std::endl;

	//std::cout << "celsius to fahrenheit)" << std::endl;
	//std::cout << "celsius:    " << degcelsius << std::endl;
	//std::cout << "fahrenheit: " << degfahrenheit << std::endl;
#pragma endregion

#pragma region average5numbers

	//float a, b, c, d, e;    // modify these variables below.
	//float avg;              // modify this variable below.
	//avg = a = b = c = d = e = 0.0f; // initialize all to zero.

	//std::cout << "please enter 5 numbers \n" << std::endl;
	//std::cout << "first number" << std::endl;
	//std::cin >> a;
	//std::cout << "second number" << std::endl;
	//std::cin >> b;
	//std::cout << "third number" << std::endl;
	//std::cin >> c;
	//std::cout << "fourth number" << std::endl;
	//std::cin >> d;
	//std::cout << "fifth number" << std::endl;
	//std::cin >> e;

	//avg = (a + b + c + d + e) / 5;

	//std::cout << "average of five)" << std::endl;
	//std::cout << a << "," << b << "," << c << "," << d << "," << e << std::endl;
	//std::cout << "avg: " << avg << std::endl;

#pragma endregion

#pragma region area of a rectangle
	//float rectwidth = 4.0f;  // modify this variable below.
	//float rectheight = 5.0f; // modify this variable below.
	//float rectarea = 0.0f;   // modify this variable below.

	//rectarea = rectwidth * rectheight;

	//std::cout << "area of a rectangle)" << std::endl;
	//std::cout << "h: " << rectheight << " , w: " << rectwidth << std::endl;
	//std::cout << "area: " << rectarea << std::endl;

#pragma endregion

#pragma region Number Swapper

	//int x = 13;
	//int y = 24;
	////int temp = y;
	////y = x;
	////x = temp;
	//x = x ^ y;
	//y = y ^ x;
	//x = x ^ y;

	//std::cout << "Number Swap)" << std::endl;
	//std::cout << "x is " << x << std::endl;
	//std::cout << "y is " << y << std::endl;

#pragma endregion
#pragma region Age
	//int age = 22;
	//int month = 264;

	//// <Your work can go here.>

	//// <You must add more lines to output to the terminal>
	//std::cout << "Howdy! You are " << age << " years old!" << std::endl;
	//std::cout << "You had been alive for at least " << month << " months!" << std::endl;
#pragma endregion

#pragma region Test Array
//int numbers[10] = { 0, 0, 1, 0, 0, 1, 0, 0, 1, 1 };
//
//int matrix[5] = { 1, 2, 3, 4, 5, 6, 7 };
//
//double radii[10] = (3.2, 4.7};
//
//int table[7] = { 2, , , 27, , 45, 39 };
//
//char codes[] = { 'A', 'X', '1', '2', 's' };
//
//int blanks[];
//
//int collection[-20];
//
//int hours[3] = 8, 12, 16;

//int values[] = { 2, 6, 10, 14 };	
//std::cout << values[2] << std::endl;
//std::cout << ++values[0] << std::endl;
//std::cout << values[1]++ << std::endl;
//int(x) = 2;
//std::cout << values[++x] << std::endl;
//std::cout << values[4];
#pragma endregion
#pragma region Loop Arrays
//int data[10];
//for (int i = 0; i >= 9; i++) 
//{
//	data[i] = 10 - i;
//	std::cout << data[i] << "\n";
//}




#pragma endregion

#pragma region MyRegion

int grid[3][3];
int number = 0;

for (int row = 0; row < 3; row++)
{
	for (int col = 0; col < 3; col++)
	{
		grid[row][col] = number++;
	}
}
for (int row = 0; row < 3; row++)
{
	for (int col = 0; col < 3; col++)
	{
		std::cout << "|" << grid[row][col] << "|";
	}
	std::cout << std::endl;
}
#pragma endregion

	
	
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
