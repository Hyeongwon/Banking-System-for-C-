#include <iostream>
#include <cstring>
#include "Account.h"
using namespace std;

const int NAME_LEN = 20;

Account *accArr[100];
int accNum = 0;

Account::Account(int ID, int money, char *name)
		:accID(ID), balance(money) {

			cusName = new char[strlen(name)+1];
			strcpy(cusName, name);
}

int Account::GetAccID() {

	return accID;
}

void Account::Deposit(int money) {

	balance += money;
}

int Account::WithDraw(int money) {

	if(balance < money)
		return 0;

	balance -= money;
	return money;
}

void Account::ShowAccInfo() {

	cout << "Account ID : " << accID << "\n";
	cout << "Name : " << cusName << "\n";
	cout << "Balance : " << balance <<"\n";
}

Account::~Account() {

	delete []cusName;
}

void ShowMenu(void) {

	cout << "----------Menu---------" << "\n";
	cout << "1.   Make Account" << "\n";
	cout << "2.      Deposit   " << "\n";
	cout << "3.      Withdraw     " << "\n";
	cout << "4.Print All Account Info" << "\n";
	cout << "5.     Exit Program" << "\n";
}

void MakeAccount (void) {

	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[Make Accout]" << "\n";
	cout << "Accout_ID : "; cin >> id;
	cout << "Name : "; cin >> name;
	cout << "Balance : "; cin >> balance;
	cout << "\n";

	accArr[accNum++] = new Account(id, balance, name);
}

