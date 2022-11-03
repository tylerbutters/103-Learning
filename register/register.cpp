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
	// just draws line
	cout << "---------------------------------------------------------------------" << '\n';
}

void registerNewUser(string userDataBaseFile) {
	int registerAccountType;
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
	cin >> registerAccountType;

	switch (registerAccountType) {
	case 1:
		cout << '\n' << "Student selected" << '\n';
		break;
	case 2:
		cout << '\n' << "Parent selected" << '\n';
		break;
	case 3:
		cout << '\n' << "Teacher selected" << '\n';
		break;
	case 4:
		cout << '\n' << "Admin selected" << '\n';
		break;
	case 0:
		// back to main menu
		main();
		break;
	default:
		cout << '\n' << "Invalid user type selected";
		break;
	}

	cout << "Create a username: ";
	cin >> username;
	cout << "Create a password: ";
	cin >> password;

	// writes user input to file
	userDataBase << username << "," << password << "," << registerAccountType << '\n';
	userDataBase.close();

	cout << '\n' << "Account created!" << '\n';
	main();
}

void userLogin(string userDataBaseFile) {
	fstream userDataBase;
	int loginAccountType;
	string databaseRow;
	string databaseColumn;
	string username;
	string password;
	vector<string> vectorRow;
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
	cin >> loginAccountType;

	// back to main menu
	if (loginAccountType == 0) {
		main();
	}

	cout << "Enter your username: ";
	cin >> username;
	cout << "Enter your password: ";
	cin >> password;

	// loops through each row of database file
	while (getline(userDataBase, databaseRow, '\n')) {
		vectorRow.clear();
		stringstream stream(databaseRow);
		// loops through each column of database file
		while (getline(stream, databaseColumn, ',')) {
			//appends data from database into vector
			vectorRow.push_back(databaseColumn);
		}
		//adds the whole vector to a vector matrix with data of entire file
		fileContent.push_back(vectorRow);
	}

	for (vector<string> vectorRow : fileContent) {
		if (username == vectorRow.at(0) && password == vectorRow.at(1)) {
			switch (stoi(vectorRow.at(2))) {
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
			case 0:
				//back to main menu
				main();
				break;
			default:
				cout << '\n' << "Invalid user type selected";
				break;
			}
		}
	}

	userDataBase.close();
	fileContent.clear();
}

int main() {
	int userChoice;
	//applies file location to a variable
	string userDataBaseFile = ("user-database.csv");

	cout << '\n';
	drawLine();
	cout << "WELLINGTON HIGH SCHOOL STUDENT INFORMATION SYSTEM" << '\n';
	drawLine();

	cout << '\n' << "Please input the number to the following option" << '\n';
	cout << '\n' << "[LOGIN = 1] [REGISTER = 2] [EXIT = 0]" << '\n';
	cin >> userChoice;

	switch (userChoice) {
	case 1:
		userLogin(userDataBaseFile);
		break;
	case 2:
		registerNewUser(userDataBaseFile);
		break;
	case 0:
		cout << "Application closing...";
		break;
	default:
		cout << '\n' << "Please choose one of the options";
		break;
	}
}