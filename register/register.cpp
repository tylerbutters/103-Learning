#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <ctype.h>

namespace stdprefixes {
	using std::cout;
	using std::cin;
	using std::string;
	using std::vector;
	using std::endl;
	using std::ifstream;
	using std::fstream;
	using std::ostream;
	using std::ios;
	using std::stringstream;
}

using namespace stdprefixes;

int main();

void drawLine() {
	cout << "---------------------------------------------------------------------" << '\n';
}

void createUserAccount(string userDataBaseFile) {
	string accountType = "0";
	string username;
	string password;

	fstream userDataBase(userDataBaseFile, ios::in | ios::app);
	
	if (!userDataBase.is_open()) {
		cout << "Warning file is not open." << '\n';
		return;
	}

	cout << '\n';
	drawLine();
	cout << "REGISTER" << '\n';
	drawLine();

	cout << '\n' << "Choose the account you want to create" << '\n';
	cout << '\n' << "[STUDENT = 1] [PARENT = 2] [TEACHER = 3] [ADMIN = 4] [BACK = 0]" << '\n';
	cin >> accountType;

	if (accountType == "0") {
		main();
	}

	cout << "Create a username: ";
	cin >> username;
	cout << "Create a password: ";
	cin >> password;

	userDataBase << username << "," << password << "," << accountType << '\n';
	userDataBase.close();

	cout << '\n' << "Account created!" << '\n';
	main();
}

void userLogin(string userDataBaseFile) {
	fstream userDataBase;
	string accountType;
	string line;
	string word;
	string username;
	string password;
	vector<string> row;
	vector<vector<string>> fileContent;

	userDataBase.open(userDataBaseFile, ios::in | ios::app);
	
	if (!userDataBase.is_open()) {
		cout << "Warning file is not open" << '\n';
		return;
	}

	drawLine();
	cout << "LOGIN" << '\n';
	drawLine();

	cout << '\n' << "Select account type" << '\n';
	cout << '\n' << "[STUDENT = 1] [PARENT = 2] [TEACHER = 3] [ADMIN = 4] [BACK = 0]" << '\n';
	cin >> accountType;

	if (accountType == "0") {
		main();
	}

	cout << "Enter your username: ";
	cin >> username;
	cout << "Enter your password: ";
	cin >> password;

	while (getline(userDataBase, line, '\n')) {
		row.clear();
		stringstream stream(line);

		while (getline(stream, word, ',')) {
			row.push_back(word);
		}
		fileContent.push_back(row);
	}

	for (vector<string> row : fileContent) {
		if (username == row.at(0) && password == row.at(1)) {
			switch (stoi(row.at(2))) {
			case 1:
				cout << '\n' << "Logged in as student";
				//studentAccount();
				break;
			case 2:
				cout << '\n' << "Logged in as parent";
				//parentAccount();
				break;
			case 3:
				cout << '\n' << "Logged in as teacher";
				//teacherAccount();
				break;
			case 4:
				cout << '\n' << "Logged in as admin";
				//adminAccount();
				break;
			}
		}
	}

	userDataBase.close();
	fileContent.clear();
}

int main() {
	int userChoice;
	string userDataBaseFile = ("user-database.csv");

	cout << '\n';
	drawLine();
	cout << "WELLINGTON HIGH SCHOOL STUDENT INFORMATION SYSTEM" << '\n';
	drawLine();

	cout << '\n' << "Please input the number to the following option" << '\n';
	cout << '\n' << "[LOGIN = 1] [REGISTER = 2] [EXIT = 0]" << '\n';
	cin >> userChoice;

	switch (userChoice)
	{
	case 1:
		userLogin(userDataBaseFile);
		break;
	case 2:
		createUserAccount(userDataBaseFile);
		break;
	case 0:
		cout << "Application closing...";
		break;
	}
}