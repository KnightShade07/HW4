#include <iostream>
// TO DO: include statements go here
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

//Ethen Lee Oliva
//Instructor: Ken Meerdink
//C++ Programming Assignment 4 - Functions
//GitHub Repository: https://github.com/KnightShade07/HW4
//Description: This assignment is an exercise in the various
//uses for C++ Functions.

// TO DO: function prototypes go here
double mathRootSum(int num);

bool isOdd(int num);

int countEs(string word);

vector<int> cumulative(vector<int> &vec);

string factors56(int num);

int main() {
	// test mathRootSum
	cout << (abs(mathRootSum(624) - 24.0) < 0.0000000000001 ? "Success" : "Fail")
	     << " on mathRootSum test 1" << endl;
	cout << (abs(mathRootSum(1000) - 30.6386) < 0.0001 ? "Success" : "Fail")
		<< " on mathRootSum test 2" << endl;

	// test isOdd
	cout << (isOdd(3) ? "Success" : "Fail") 
		<< " on isOdd test 1" << endl;
	cout << (isOdd(-1) ? "Success" : "Fail") 
		<< " on isOdd test 2" << endl;
	cout << (!isOdd(-2) ? "Success" : "Fail") 
		<< " on isOdd test 3" << endl;

	// test countEs
	cout << (countEs("Elephant") == 2 ? "Success" : "Fail") 
		<< " on countEs test 1" << endl;
	cout << (countEs("Aardvark") == 0 ? "Success" : "Fail") 
		<< " on countEs test 2" << endl;
	cout << (countEs("Elephantine") == 3 ? "Success" : "Fail")
		<< " on countEs test 3" << endl;
	
	// test cumulative
	vector<int> v1{ 1, 1, 2, 3, 5 };
	vector<int> v1Cumulative{ 1, 2, 4, 7, 12 };
	cumulative(v1);
	cout << (v1 == v1Cumulative ? "Success" : "Fail")
		<< " on cumulative test 1" << endl;

	vector<int> v2{ 1 };
	vector<int> v2Cumulative{ 1 };
	cumulative(v2);
	cout << (v2 == v2Cumulative ? "Success" : "Fail")
		<< " on cumulative test 2" << endl;

	vector<int> v3{};
	vector<int> v3Cumulative{};
	cumulative(v3);
	cout << (v3 == v3Cumulative ? "Success" : "Fail")
		<< " on cumulative test 3" << endl;

	// test factors56
	cout << (factors56(10) == "10 is divisible by 5 or 6, but not both" ? "Success" : "Fail")
		<< " on factors56 test 1" << endl;
	cout << (factors56(30) == "30 is divisible by both 5 and 6" ? "Success" : "Fail")
		<< " on factors56 test 2" << endl;
	cout << (factors56(23) == "23 is not divisible by either 5 or 6" ? "Success" : "Fail")
		<< " on factors56 test 3" << endl;

	system("pause");
}

// TO DO: function definitions go here

//This function will calculate a sum for you using an equation.

double mathRootSum(int num){
	double result = 0;
	if (num > 0)
	{
		for (int i = 1; i <= num; i++)
		{
			result += 1 / (sqrt(i) + sqrt(i + 1));
		}
		
	}

	return result;
	
}

//This function will return true if a number is odd, otherwise, return false.

bool isOdd(int num) {
	if (num % 2 == 0)
	{
		return false;
	}
	else {
		return true;
	}
	
}

//This function will return how many
//Es are in a word, both uppercase and lowercase.

int countEs(string word){
	int numOfEs = 0;

	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == 'e' || word[i] == 'E')
		{
			numOfEs++;
		}
		
	}

	return numOfEs;
	
}
//This function takes a vector of integers,
//and changes it to take the cumulative sum
//going up through the index

//To quote the document itself:
/*
	". For example, if the vector passed contains {1, 1, 2, 3,5}, 
	your function should modify it to store {1, 2, 4, 7, 12}."
*/
vector<int> cumulative(vector<int> &v) {
	if (v.size() > 1)
	{
		for (int i = v.size() - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				v[i] += v[j];
			}
			
		}
		
	}

	return v;
	
}
	
	
//This function checks to see if a number is divisible by 5 or 6
//and returns feedback to the user using a string variable.

string factors56(int num){
	string isOrIsNotDivisible = "";
	if (num % 5 == 0 && num % 6 == 0)
	{
		isOrIsNotDivisible = to_string(num) + " is divisible by both 5 and 6";
	}
	else if (num % 5 == 0 || num % 6 == 0)
	{
		isOrIsNotDivisible = to_string(num) + " is divisible by 5 or 6, but not both";
	}
	else{
		isOrIsNotDivisible = to_string(num) + " is not divisible by either 5 or 6";
	}

	return isOrIsNotDivisible;
	
	
}