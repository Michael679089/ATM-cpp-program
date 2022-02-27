/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <sstream>  
#include <iostream>
using namespace std;

using namespace std;

int main() {
	///////////
	string user_idInfo[1][2]; // 0 is user id and 2 is user tag. 
	string password;
	string ifpassword;
	string ifuser_id;
	int money = 0;
	int deposit_money = 0;
	int withdraw_money = 0;

	int maxAmount;
	////////////

	cout << "Hi! Welcome to MJ's ATM Machine!" << endl;
	cout << endl;

	char user_input = ' ';
	while (user_input != 'q' && user_input != 'Q') {
		cout << "Please select an option from the menu below:" << endl;
		cout << "l - Log in" << endl;
		cout << "c - create account" << endl;
		cout << "q - quit the program" << endl;
		cout << "> ";
		cin >> user_input;
		cout << endl;

		if (user_input == 'q') {
			cout << "THANKS FOR STOPING BY!" << endl;
		}

		if (user_input == 'l' && (user_idInfo[0][0].empty() && password.empty())) {
			cout << "******** LOGIN FAILED! ********" << endl;
			cout << "Sorry, we need you to create an account first" << endl;
			cout << endl;
			cout << endl;
		}
		else if (user_input == 'c') {
			cout << "Create your own password and user ID" << endl;
			cout << "User id: ";
			cin >> user_idInfo[0][0];
			cout << "Password: ";
			cin >> password;
			cout << "Override Account. Created A New Account." << endl;
			srand(unsigned(time(0))); // Serves as a starting point
			int tempInt = (rand() % 10); // Creates the userID's Tag

			// Converting integer to string
			stringstream ss;
			ss << tempInt;
			ss >> user_idInfo[0][1];
			cout << endl;
			cout << endl;
		}

		if (user_input == 'l' && ((user_idInfo[0][0].empty() && password.empty()) == false)) {
			cout << "Please enter your user ID and password" << endl;
			cout << "User ID: ";
			cin >> ifuser_id;
			cout << "Password: ";
			cin >> ifpassword;
			cout << endl;

			if (ifuser_id != user_idInfo[0][0] && ifpassword != password) {
				cout << "Wrong credentials!" << endl;
				cout << endl;
			}

			if (ifuser_id == user_idInfo[0][0] && ifpassword == password) {
				char user_input2 = ' ';
				cout << "Hello " << user_idInfo[0][0] << "!" << " Welcome Back!" << endl;
				cout << "UserTag: " << user_idInfo[0][1] << endl;


				while (user_input2 != 'L' && user_input2 != 'l') {
					cout << "Please select an option from the menu below:" << endl;
					cout << "d - deposit money" << endl;
					cout << "w - withdraw money" << endl;
					cout << "r - request balance" << endl;
					cout << "L - Log out the program" << endl;
					cout << "> ";
					cin >> user_input2;
					cout << endl;
					cout << endl;


					switch (user_input2) {
					case 'r':
						cout << "Request Balance Section" << endl;
						cout << "Your balance is: P" << money << endl;
						if (money < 0) {
							cout << "Oh no! you're in debt!" << endl;
						}
						cout << endl;
						cout << endl;

						break;
					case 'd':
						cout << "Deposit Section" << endl;
						cout << "How much money do you want to deposit: P";
						cin >> deposit_money;

						if (deposit_money > 10000) {
							cout << "Sorry, but we can't add that much money" << endl;
							cout << endl;
							break;
							return deposit_money = 0;
						}

						money = deposit_money + money;
						cout << endl;
						cout << "Now your balance is: P" << money;
						cout << endl;
						cout << endl;

						break;
					case 'w':
						cout << "Withdraw Section" << endl;
						cout << "How much money do you want to withdraw: P";
						cin >> withdraw_money;
						if (withdraw_money > 10000) {
							cout << "Sorry, but we can't withdraw that much money" << endl;
							cout << endl;
							break;
							return withdraw_money = 0;
						}
						money = money - withdraw_money;
						cout << endl;
						cout << "Now your balance is: P" << money;
						cout << endl;
						if (money < 0) {
							cout << "Oh no! you're in debt!" << endl;
						}

						break;
					case 'L':
						cout << "--You just logged out--" << endl;
						cout << endl;
						break;
					}
				}
			}
		}
	}
}
























