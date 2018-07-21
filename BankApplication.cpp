#include <iostream>
#include <string.h>
using namespace std;

class Account {
private:
	char* ano;
	char* owner;
	int balance;
public:
	 Account(char* _ano = "", char* _owner = "", int _balance = 0){
		 this->ano = (char*)malloc(strlen(_ano) + 1);
		 strcpy_s(ano, strlen(_ano) + 1, _ano);
		 this->owner = (char*)malloc(strlen(_owner) + 1);
		 strcpy_s(owner, strlen(_owner) + 1, _owner);
		 this->balance = _balance;
	}

	 char* getAno() {
		 return this->ano;
	 }

	 void setAno(char* _ano) {
		 this->ano = (char*)malloc(strlen(_ano) + 1);
		 strcpy_s(ano, strlen(_ano) + 1, _ano);
	 }

	 char* getOwner() {
		 return this->owner;
	 }

	 void setOwner(char* _owner) {
		 this->owner = (char*)malloc(strlen(_owner) + 1);
		 strcpy_s(owner, strlen(_owner) + 1, _owner);
	 }

	 int getBalance() {
		 return this->balance;
	 }

	 void setBalance(int nVal) {
		 balance = nVal;
	 }

	 void display() {
		 cout << this->ano << " " << this->owner << " " << this->balance << endl;
	 }
};

class BankApplication {
private:
	Account* accountArray = NULL;
	int accountNum;
public:
	BankApplication() {
		accountArray = new Account[5];
		accountNum = 0;
	}

	void accountList() {
		cout << "계좌 목록" << endl;
		cout << "-------------------" << endl;
		for (int i = 0; i < accountNum; i++) {
			accountArray[i].display();
		}
	}

	void createAccount() {
		cout << "-----------------------------------------------------------------" << endl;
		cout << "계좌생성" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		if (accountNum >= 5) {
			return;
		}
		else {
			cout << "계좌번호: ";
			char input[20];
			cin >> input;
			accountArray[accountNum].setAno(input);
			cout << "\n";
			cout << "계좌주: ";
			cin >> input;
			accountArray[accountNum].setOwner(input);
			cout << "\n";
			int e = 0;
			cout << "초기입금액 : ";
			cin >> e;
			accountArray[accountNum].setBalance(e);
			cout << "\n";
			cout << "계좌가 생성되었습니다" << endl;
			accountNum++;
		}

	}

	int findAccount(char* szVal) {
		for (int i = 0; i < accountNum; i++) {
			if (!(strcmp(accountArray[i].getAno(), szVal))) {
				return i;
			}
		}
		return -1;
	}

	void deposit() {
		cout << "-----------------------------------------------------------------" << endl;
		cout << "예금 " ;
		cout << "-----------------------------------------------------------------" << endl;
		cout << "계좌번호: ";
		char input[20];
		cin >> input;
		cout << "\n";
		cout << "예금액 : ";
		int e = 0;
		cin >> e;
		int num = findAccount(input);
		if (num == -1) {
			cout << "계좌를 찾을 수 없습니다. " << endl;
			return;
		}
		else {
			int balance = accountArray[num].getBalance();
			balance += e;
			accountArray[num].setBalance(balance);
		}	
	}

	void withdraw() {
		cout << "-----------------------------------------------------------------" << endl;
		cout << "출금 ";
		cout << "-----------------------------------------------------------------" << endl;
		cout << "계좌번호: ";
		char input[20];
		cin >> input;
		cout << "\n";
		cout << "출금액 : ";
		int e = 0;
		cin >> e;
		int num = findAccount(input);
		if (num == -1) {
			cout << "계좌를 찾을 수 없습니다. " << endl;
			return;
		}
		else {
			int balance = accountArray[num].getBalance();
			if (e > balance) {
				cout << "출금액이 잔고보다 더 커서 출금이 안됩니다. " << endl;
				return;
			}
			accountArray[num].setBalance(balance - e);
			cout << "출금 성공 : 출금 액수 : " << e << endl;
		}
	}




	void BankProgram() {
		bool run = true;
		int SelectNum = 0;
		while (run) {
			cout << "-----------------------------------------------------------------" << endl;
			cout << "1. 계좌 생성 | 2. 계좌 목록 | 3. 예금 | 4. 출금 | 5. 종료" << endl;
			cout << "-----------------------------------------------------------------" << endl;
			cout << "선택 >";
			cin >> SelectNum;
			if (SelectNum == 1) {
				createAccount();
			}
			else if (SelectNum == 2) {
				accountList();
			}
			else if (SelectNum == 3) {
				deposit();
			}
			else if (SelectNum == 4) {
				withdraw();
			}
			else if (SelectNum == 5) {
				run = 0;
			}
		}
		cout << "program 종료" << endl;
	}
};



int main() {
	BankApplication bank;
	bank.BankProgram();

	return 0;
}