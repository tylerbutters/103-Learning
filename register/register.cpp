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

void authenticateUser(vector<vector<string>> databaseContent, string username, string password) {
	for (vector<string> vectorRow : databaseContent) {
		if (username == vectorRow.at(0) && password == vectorRow.at(1)) {
			switch (stoi(vectorRow.at(2))) {
			case 1:
				cout << '\n' << "Logged in as student";
				exit(0);
				//studentAccount();
				break;
			case 2:
				cout << '\n' << "Logged in as parent";
				exit(0);
				//parentAccount();
				break;
			case 3:
				cout << '\n' << "Logged in as teacher";
				exit(0);
				//teacherAccount();
				break;
			case 4:
				cout << '\n' << "Logged in as admin";
				exit(0);
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
	databaseContent.clear();
}

string inputLoginDetails() {
	string username;
	string password;
	int loginAccountType;

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

	return username, password;
}

vector<vector<string>> loadUsersFromDatabase(fstream& userDatabase) {
	string databaseRow;
	string databaseColumn;
	vector<string> vectorRow;
	vector<vector<string>> databaseContent;

	// loops through each row of database file
	while (getline(userDatabase, databaseRow, '\n')) {
		vectorRow.clear();
		stringstream stream(databaseRow);
		// loops through each column of database file
		while (getline(stream, databaseColumn, ',')) {
			//appends data from database into vector
			vectorRow.push_back(databaseColumn);
		}
		//adds the whole vector to a vector matrix with data of entire file
		databaseContent.push_back(vectorRow);
	}
	return databaseContent;
}

void userLoginInterface(string userDataBaseFile) {
	fstream userDatabase;
	bool authenticated = false;
	int loginAttempts = 3;
	
	userDatabase.open(userDataBaseFile, ios::in | ios::app);
	
	if (!userDatabase.is_open()) {
		cout << "Warning file is not open" << '\n';
		return;
	}

	vector<vector<string>> databaseContent = loadUsersFromDatabase(userDatabase);

	drawLine();
	cout << "LOGIN" << '\n';
	drawLine();
	
	//FIX THIS
	string username, password = inputLoginDetails();


	while (authenticated == false && loginAttempts != 0) {
		authenticateUser(databaseContent, username, password);
		loginAttempts -= 1;
		if (loginAttempts != 0) {
			cout << '\n' << "Wrong username, password or associated account type";
			cout << '\n' << loginAttempts << " attempts left";
		}
	}

	if (loginAttempts == 0) {
		cout << '\n' << "0 attempts left! Shutting down application..." << '\n';
		exit(0);
	}

	userDatabase.close();
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
		userLoginInterface(userDataBaseFile);
		break;
	case 2:
		registerNewUser(userDataBaseFile);
		break;
	case 0:
		cout << "Shutting down application..." << '\n';
		break;
	default:
		cout << '\n' << "Please choose one of the options";
		break;
	}
}