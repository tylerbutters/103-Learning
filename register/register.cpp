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

struct UserInfo {
	int accountType;
	string username;
	string password;
};

string g_userDatabaseFile = ("user-database.csv");

void drawLine() {
	// just draws line
	cout << "---------------------------------------------------------------------" << '\n';
}

void addUserToDatabase(int accountType, string username, string password) {
	fstream userDatabase(g_userDatabaseFile, ios::in | ios::app);

	if (!userDatabase.is_open()) {
		throw std::runtime_error("Warning file is not open");
	}

	// writes user input to file
	userDatabase << username << "," << password << "," << accountType << '\n';
	userDatabase.close();
}

UserInfo getRegistrationDetailsFromUser() {
	UserInfo userRegistrationDetails;

	cout << '\n';
	drawLine();
	cout << "REGISTER" << '\n';
	drawLine();

	cout << '\n' << "Choose the account you want to create" << '\n';
	cout << '\n' << "[STUDENT = 1] [PARENT = 2] [TEACHER = 3] [ADMIN = 4] [BACK = 0]" << '\n';
	cin >> userRegistrationDetails.accountType;

	switch (userRegistrationDetails.accountType) {
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
	cin >> userRegistrationDetails.username;
	cout << "Create a password: ";
	cin >> userRegistrationDetails.password;

	return userRegistrationDetails;
}

void registerNewUserThenReturn() {
	UserInfo userRegistrationDetails = getRegistrationDetailsFromUser();

	addUserToDatabase(userRegistrationDetails.accountType, userRegistrationDetails.username, userRegistrationDetails.password);

	cout << '\n' << "Account created!" << '\n';
	main();
}

bool authenticateUser(vector<vector<string>> databaseContent, UserInfo userInfoToAuthenticate) {
	for (vector<string> vectorRow : databaseContent) {
		if (userInfoToAuthenticate.username == vectorRow.at(0) && userInfoToAuthenticate.password == vectorRow.at(1)) {
			return true;
		}
	}
	// databaseContent.clear();

	return false;
}

UserInfo getLoginDetailsFromUser() {
	UserInfo loginDetailsFromUser;

	cout << '\n';
	drawLine();
	cout << "LOGIN" << '\n';
	drawLine();

	cout << '\n' << "Select account type" << '\n';
	cout << '\n' << "[STUDENT = 1] [PARENT = 2] [TEACHER = 3] [ADMIN = 4] [BACK = 0]" << '\n';
	cin >> loginDetailsFromUser.accountType;

	// back to main menu
	if (loginDetailsFromUser.accountType == 0) {
		main();
	}

	cout << "Enter your username: ";
	cin >> loginDetailsFromUser.username;
	cout << "Enter your password: ";
	cin >> loginDetailsFromUser.password;

	return loginDetailsFromUser;
}

vector<vector<string>> loadAllUsers() {
	string databaseRow;
	string databaseColumn;
	vector<string> vectorRow;
	vector<vector<string>> databaseContent;

	fstream userDatabase;
	
	userDatabase.open(g_userDatabaseFile, ios::in | ios::app);

	if (!userDatabase.is_open()) {
		throw std::runtime_error("Warning file is not open");
	}

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
	userDatabase.close();

	return databaseContent;
}

void getLoginDetailsFromUserAndAuthenticate() {
	int loginAttempts = 3;

	vector<vector<string>> allUsers = loadAllUsers();

	while (loginAttempts > 0) {
		UserInfo userLoginDetails = getLoginDetailsFromUser();
		bool isAuthenticated = authenticateUser(allUsers, userLoginDetails);

		if (isAuthenticated) {
			return;
		}

		loginAttempts--;
		cout << '\n' << "Wrong username, password or associated account type";
		cout << '\n' << loginAttempts << " attempts left";
	}

	if (loginAttempts == 0) {
		cout << '\n' << "Shutting down application..." << '\n';
		exit(0);
	}
}

int getMainMenuChoiceFromUser() {
	int userChoice;

	cout << '\n';
	drawLine();
	cout << "WELLINGTON HIGH SCHOOL STUDENT INFORMATION SYSTEM" << '\n';
	drawLine();

	cout << '\n' << "Please input the number to the following option" << '\n';
	cout << '\n' << "[LOGIN = 1] [REGISTER = 2] [EXIT = 0]" << '\n';
	cin >> userChoice;

	return userChoice;
}

void printMainMenu() {
	switch (getMainMenuChoiceFromUser()) {
	case 1:
		getLoginDetailsFromUserAndAuthenticate();
		break;
	case 2:
		registerNewUserThenReturn();
		break;
	case 0:
		cout << "Shutting down application..." << '\n';
		break;
	default:
		cout << '\n' << "Please choose one of the options";
		printMainMenu();
		break;
	}
}

int main() {
	printMainMenu();
}