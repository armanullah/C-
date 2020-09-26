// FinalProject_Khan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;


int* randomNumberFunction() {

	cout << "You have chosen to randomly generate your numbers. Here they are: " << endl;

	//srand(time(0));
	srand((unsigned int)time(NULL));

	static int randomNumberArray[6];

	for (int i = 0; i < 5; i++) {
		randomNumberArray[i] = 1 + (rand() % 69);
	}

	//assign a seperate random number for index 5 since it's range of values are different

	randomNumberArray[5] = 1 + (rand() % 26);

	for (int l = 0; l < 6; l++) {
		cout << randomNumberArray[l] << endl;
	}

	for (int j = 0; j < 5; j++) {
		for (int k = j + 1; k < 6; k++) {
			int temp;

			if (randomNumberArray[j] > randomNumberArray[k]) {
				temp = randomNumberArray[j];
				randomNumberArray[j] = randomNumberArray[k];
				randomNumberArray[k] = temp;
			}
		}
	}

	return randomNumberArray;
}

int* userPicksNumber() {

	static int userNumberArray[6];

	cout << "You have chosen to pick your own numbers.\n " << endl;

	for (int i = 0; i < 5; i++) {
		cout << "Please enter a number: (Must be a number 1-69 for the first 5 numbers)" << endl;
		cin >> userNumberArray[i];

		while (userNumberArray[i] > 69 || userNumberArray[i] < 1) {
			cout << "Number was invalid and not in range, must be 1-69 for first 5 numbers and 1-26 for the 6th number." << endl;
			cin >> userNumberArray[i];
		}
	}



	cout << "Please enter the last number, must be 1-26." << endl;
	cin >> userNumberArray[5];


	while (userNumberArray[5] > 26 || userNumberArray[5] < 1) {
		cout << "Please enter a valid number in range." << endl;
		cin >> userNumberArray[5];
	}

	//sorting algorithm
	for (int j = 0; j < 5; j++) {
		for (int k = j + 1; k < 6; k++) {
			int temp;

			if (userNumberArray[j] > userNumberArray[k]) {
				temp = userNumberArray[j];
				userNumberArray[j] = userNumberArray[k];
				userNumberArray[k] = temp;
			}
		}
	}

	return userNumberArray;
}

int* winningNumbers() {

	//srand(time(0));
	srand((unsigned int)time(NULL));
	static int winningNumberArray[6];

	for (int i = 0; i < 5; i++) {
		winningNumberArray[i] = 1 + (rand() % 69);
	}

	//assign a seperate random number for index 5 since it's range of values are different

	winningNumberArray[5] = 1 + (rand() % 26);

	for (int l = 0; l < 6; l++) {
		cout << winningNumberArray[l] << endl;
	}

	for (int j = 0; j < 5; j++) {
		for (int k = j + 1; k < 6; k++) {
			int temp;

			if (winningNumberArray[j] > winningNumberArray[k]) {
				temp = winningNumberArray[j];
				winningNumberArray[j] = winningNumberArray[k];
				winningNumberArray[k] = temp;
			}
		}
	}

	return winningNumberArray;
}


int main()
{
	ofstream lotteryNumbers;
	lotteryNumbers.open("Powerball.txt");

	int userPick;
	int tickets;

	cout << "Hello and welcome to the Powerball Lottery Game. Depending on the numbers you pick, you can win a HUGE PRIZE.\n\n" << endl;
	cout << "Here are the rules: " << endl;
	cout << "First enter the amount of tickets you would like to purchase. You can't purchase more then 100." << endl;
	cin >> tickets;
	lotteryNumbers << "******************** POWER BALL ********************" << endl;


	while (tickets < 1 || tickets > 100) {
		cout << "You can't have negative tickets or greater than 100!" << endl;
		cin >> tickets;
	}

	lotteryNumbers << "This is how many tickets you have purchased: " << tickets << endl;

	cout << "Now would you like to pick your own numbers or have them randomly generated?\n";
	cout << "Press 1 for auto-pick. Press 2 for self pick." << endl;
	cin >> userPick;


	while (userPick < 1 || userPick > 2) {
		cout << "Invalid choice. Must pick either 1 or 2 as a selection." << endl;
		cin >> userPick;
	}

	if (userPick == 1) {
		int* randomNumberArray = randomNumberFunction();
		cout << "Here are your numbers: " << randomNumberArray[0] << " " << randomNumberArray[1] << " " << randomNumberArray[2] << " " << randomNumberArray[3] << " " << randomNumberArray[4] << " " << randomNumberArray[5];
		lotteryNumbers << "Here are your numbers: " << randomNumberArray[0] << " " << randomNumberArray[1] << " " << randomNumberArray[2] << " " << randomNumberArray[3] << " " << randomNumberArray[4] << " " << randomNumberArray[5] << endl;
		

	}
	else if (userPick == 2) {
		int* userNumberArray = userPicksNumber();
		cout << "Here are your numbers: " << userNumberArray[0] << " " << userNumberArray[1] << " " << userNumberArray[2] << " " << userNumberArray[3] << " " << userNumberArray[4] << " " << userNumberArray[5];
		lotteryNumbers << "Here are your numbers: " << userNumberArray[0] << " " << userNumberArray[1] << " " << userNumberArray[2] << " " << userNumberArray[3] << " " << userNumberArray[4] << " " << userNumberArray[5] << endl;

		int* winningNumberArray = winningNumbers();
		int a, compare = 1;
		for (a = 0; a < 6 && compare; a++) {
			if (userNumberArray[a] != winningNumberArray[a]) {
				compare = 0;
			}
		}

		if (compare) {
			lotteryNumbers << "Your numbers match the winning numbers! YOU WIN 999,000,000$!!" << endl;
		}
		else {
			lotteryNumbers << "You numbers do not match and you win nothing." << endl;
		}
	}

	//compare arrays
	int a, compare = 1;

	//print winning number array
	int* winningNumberArray = winningNumbers();
	cout << "These are the winning numbers: " << winningNumberArray[0] << " " << winningNumberArray[1] << " " << winningNumberArray[2] << " " << winningNumberArray[3] << " " << winningNumberArray[4] << " " << winningNumberArray[5] << endl;
	lotteryNumbers << "These are the winning numbers: " << winningNumberArray[0] << " " << winningNumberArray[1] << " " << winningNumberArray[2] << " " << winningNumberArray[3] << " " << winningNumberArray[4] << " " << winningNumberArray[5] << endl;

	int* randomNumberArray = randomNumberFunction();
	for (a = 0; a < 6 && compare; a++) {
		if (randomNumberArray[a] != winningNumberArray[a]) {
			compare = 0;
		}
	}

	if (compare) {
		lotteryNumbers << "Your numbers match the winning numbers! YOU WIN 999,000,000$!!" << endl;
	}
	else {
		lotteryNumbers << "You numbers do not match and you win nothing." << endl;
	}

	
	/*for (a = 0; a < 6 && compare; a++) {
		if (userNumberArray[a] != winningNumberArray[a]) {
				compare = 0;
			}
		}

		if (compare) {
			lotteryNumbers << "Your numbers match the winning numbers! YOU WIN 999,000,000$!!" << endl;
		}
		else {
			lotteryNumbers << "You numbers do not match and you win nothing." << endl;
		} */

	lotteryNumbers.close();
}