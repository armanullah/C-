// Project 1A Arman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{ 
	string name;
	int number;
	int number2;

	
	cout << "Hello, welcome to Montgomery College! My name is Cortana.\n";
	cout << "May I have your name?";
	getline(cin, name);
	cout << "Nice to have you with us today, " << name << "! Let me impress you with a small game.\n";
	cout << "Give me the age of an important person or a pet to you. Please give me only a number!" << endl;
	cin >> number;
	cout << "You have entered " << number << ". If this is for a person, the age can be expressed as \n";

	int months = number * 12;
	int days = number * 365;
	int hours = days * 24;
	int minutes = hours * 60;
	int seconds = minutes * 60;
	int dogYears = number * 7;
	int goldFishYears = number * 5;

	cout << number << " years or " << months << " months or about " << days << " days or about " << hours << " hours or about " << minutes << endl;
	cout << " minutes or about " << seconds << " seconds.\n";
	cout << "If this is for a dog, it is " << dogYears << " years old in human age." << endl;
	cout << "If this is for a gold fish, it is " << goldFishYears << " years old in human age.\n\n\n"<< endl;
	cout << "Let's play another game, " << name << ". Give me a whole number." << endl;
	cin >> number;
	cout << "Very well. Give me another whole number.\n" << endl;
	cin >> number2;
	cout << "Using the operator '+' in C++, the result of " << number << " + " << number2 << " is " << number + number2 << ".\n" << endl;
	double number1 = static_cast<double>(number);
	double Number2 = static_cast<double>(number2);
	cout << "Using the '/' operator, the result of " << number << "/" << number2 << " is " << number / number2 << "; \nhowever, the result of " << number1 << "/" << Number2 << " is about " << number1 / Number2 << ".\n\n" ;

	cout << "Do you like games, " << name << "?\n" << "If you do, you can learn more by taking our classes. If you don't, I am sad." << endl;


	return 0;
}

