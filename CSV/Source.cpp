#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

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
}

using namespace stdprefixes;

fstream openFileForWrite(string fileName) 
{
	fstream fileStream;
	fileStream.open(fileName, ios::out | ios::trunc);
	if (!fileStream.is_open()) {
		cout << "file is not open";
	}
	return fileStream;
}

bool closeFile(fstream& fileStream) {
	fileStream.close();
	if (fileStream.is_open()) {
		cout << "file is still iopen";
		return false;
	}
	cout << "file closed";
	return true;
}

void write(string fileName) 
{
	fstream fileStream = openFileForWrite(fileName);
	string firstName;
	string lastName;
	int numEntries;

	cout << "How many names do you want to enter?";
	cin >> numEntries;

	for (int i = 0; i < numEntries; i++) {
		cout << "First name: ";
		cin >> firstName;
		cout << "Last name: ";
		cin >> lastName;
		fileStream << firstName << "," << lastName << "\n";
	}
	closeFile(fileStream);
}

void read(string fileName)
{
	fstream fileStream;
	fileStream.open(fileName, ios::in | ios::beg);
	
	if (!fileStream.is_open()) {
		cout << "file is not open, exiting";
		return;
	}
	cout << "reading";
	
	string line, word;
	vector<string> row;
	vector<vector<string>> fileContent;

	while (getline(fileStream, line, '\n')) {
		cout << "yes";
		row.clear(); //ensure no content is already in row
		std::stringstream stream(line);
		//iterate through each cell
		while (getline(stream, word, ',')) {
			row.push_back(word);
		}
		fileContent.push_back(row);
	}

	//for each row in filecontent
	for (vector<string> row : fileContent) {
		//for each word in row

		for (string word : row) {
			cout << word << '\t';
		}
		cout << "\n";
	}
	closeFile(fileStream);
}

int main()
{
	string fileName = "C:\\Users\\User\\source\\repos\\103-Learning\\CSV\\csv-exercise.csv";
	write(fileName);
	read(fileName);
}