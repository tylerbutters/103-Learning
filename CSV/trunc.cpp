#include <iostream>
#include <stdlib.h>
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

int main()
{
	string readCsvFile;
	//trunc(trunculate) defualt and also will remove contents

	fstream csvFileExample;
	csvFileExample.open("csv-file-example.csv", ios::out | ios::trunc);
	if (!csvFileExample.is_open()) {
		cout << "file is not open";
		return 0;
	}

	csvFileExample << "John" << "," << "Doe" << "," << "johndoe@gmail.com";
	csvFileExample.close();

	//append sets the stream to the end of the stream and then appends
	csvFileExample.open("csv-file-example.csv", ios::out);
	if (!csvFileExample.is_open()) {
		cout << "file is not open";
		return 0;
	}

	csvFileExample << "John" << "," << "dig" << "," << "johndoe@gmail.com";
	csvFileExample.close();

	csvFileExample.open("csv-file-example.csv", ios::in);
	if (csvFileExample.is_open()) {
		while (getline(csvFileExample, readCsvFile)) {
			cout << readCsvFile << endl;
		}
		csvFileExample.close();
	}

	// vectors
	//beg indicates the location
	csvFileExample.open("csv-file-example.csv", ios::in | ios::beg);
	if (!csvFileExample.is_open()) {
		cout << "file is not open";
		return 0;
	}

	string line, word;
	vector<string> row;
	vector<vector<string>> fileContent;




}