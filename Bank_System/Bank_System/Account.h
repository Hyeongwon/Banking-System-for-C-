#ifndef __ACCOUNT_H
#define __ACCOUNT_H

class Account {

private:

	int accID;
	int balance;
	char *cusName;

public:

	Account(int ID, int money, char *name);

	int GetAccID();

	void Deposit(int money);

	int WithDraw(int money);

	void ShowAccInfo();

	~Account();
};



void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

#endif