#include <iostream>
#include <cstring>
#include "Account.h"
using namespace std;

Account *accArr[100];
int accNum = 0;
const int NAME_LEN = 20;

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

void DepositMoney(void) {

	int money;
	int id;
	
	cout << "[Deposit]"<< "\n";
	cout << "Account ID : "; cin >> id;
	cout << "Deposit Money :"; cin >> money;

	for(int i = 0; i < accNum; i++) {

		if(accArr[i]-> GetAccID() == id) {
			accArr[i]-> Deposit(money);
			cout << "Complete Deposit" <<"\n\n";
			return;
		}

	}
	cout << "NotValid ID" << "\n";
}

void WithdrawMoney(void) {

	int money;
	int id;
	cout << "[WithDraw]\n";
	cout << "Account ID : "; cin >> id;
	cout << "WithDraw money :"; cin >> money;

	for(int i = 0; i < accNum; i++) {

		if(accArr[i]->GetAccID() == id) {

			if(accArr[i]->WithDraw(money) == 0) {
				cout << "Insufficient funds\n\n";
				return;
			}
		}
		cout << "Complete Withdraw\n\n";
		return;
	}
	cout << "NotValid ID" << "\n";
}

void ShowAllAccInfo(void) {

	for(int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

