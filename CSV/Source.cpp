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

fstream open() 
{
	fstream csvExercise;
	csvExercise.open("csv-exercise.csv", ios::out | ios::trunc);
	if (!csvExercise.is_open()) {
		cout << "file is not open";
	}
	return csvExercise;
}

void write(fstream& csvExercise) 
{
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
		csvExercise << firstName << "," << lastName << "\n";
	}
}

void read(fstream& csvExercise) 
{
	csvExercise.open("csv-exercise.csv", ios::in | ios::beg);
	if (!csvExercise.is_open()) {
		cout << "file is not open";
	}

	string line, word;
	vector<string> row;
	vector<vector<string>> fileContent;

	while (getline(csvExercise, line, '\n')) {
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
	csvExercise.close();
}

int main()
{
	fstream csvExercise = open();
	write(csvExercise);
	read(csvExercise);
	//close(csvExercise);
}