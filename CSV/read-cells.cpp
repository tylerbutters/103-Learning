//#include <iostream>
//#include <stdlib.h>
//#include <sstream>
//#include <vector>
//#include <string>
//#include <fstream>
//
//namespace stdprefixes {
//	using std::cout;
//	using std::cin;
//	using std::string;
//	using std::vector;
//	using std::endl;
//	using std::ifstream;
//	using std::fstream;
//	using std::ostream;
//	using std::ios;
//}
//
//using namespace stdprefixes;
//
//int main()
//{
//	string readCsvFile;
//	//trunc(trunculate) defualt and also will remove contents
//
//	fstream csvFileExample;
//	csvFileExample.open("csv-file-example.csv", ios::out | ios::trunc);
//	if (!csvFileExample.is_open()) {
//		cout << "file is not open";
//		return 0;
//	}
//
//	csvFileExample << "John" << "," << "Doe" << "," << "johndoe@gmail.com";
//	csvFileExample.close();
//
//	//append sets the stream to the end of the stream and then appends
//	csvFileExample.open("csv-file-example.csv", ios::app);
//	if (!csvFileExample.is_open()) {
//		cout << "file is not open";
//		return 0;
//	}
//
//	csvFileExample << "John" << "," << "dig" << "," << "johndoe@gmail.com";
//	csvFileExample.close();
//
//	csvFileExample.open("csv-file-example.csv", ios::in);
//	if (csvFileExample.is_open()) {
//		while (getline(csvFileExample, readCsvFile)) {
//			cout << readCsvFile << endl;
//		}
//		csvFileExample.close();
//	}
//
//
//	// ______________________________________________________________________
//	//beg indicates the location
//	csvFileExample.open("csv-file-example.csv", ios::in | ios::beg);
//	if (!csvFileExample.is_open()) {
//		cout << "file is not open";
//		return 0;
//	}
//
//	string line, word;
//	vector<string> row;
//	vector<vector<string>> fileContent;
//
//	while (getline(csvFileExample, line, '\n')) {
//		row.clear(); //ensure no content is already in row
//		std::stringstream stream(line);
//		//iterate through each cell
//		while (getline(stream, word, ',')) {
//			row.push_back(word);
//		}
//		fileContent.push_back(row);
//	}
//
//	//for each row in filecontent
//	for (vector<string> row : fileContent) {
//		//for each word in row
//		for (string word : row) {
//			cout << word << '\t';
//		}
//		cout << "\n";
//	}
//	csvFileExample.close();
//}