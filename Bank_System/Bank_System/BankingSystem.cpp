/*
*Banking System ver 0.2
*Developer : JOSH
*Content : Define Accout Class, Adjust Object pointer Array
*/

#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

int main(void) {

	int choice;

	while(1) {

		ShowMenu();
		cout <<"Select : ";
		cin >> choice;
		cout << "\n";

		switch(choice) {

		case MAKE:
			MakeAccount();
			break;
		}
	}

	return 0;
}