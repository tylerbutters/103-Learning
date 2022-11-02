//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//#include <string>
//#include <fstream>
//
//namespace stdprefixes {
//	using std::cout;
//	using std::cin;
//	using std::string;
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
//	string readcsvfile;
//	//csv files
//	//we can use csv files to store data in the formate of rows and columns
//	//this can generate take the form of a spreadsheet
//	//a csv file differs from a text file as we are able to edit data of individual cells
//
//	fstream csvfileexample;
//	csvfileexample.open("csv-file-example.csv", ios::out);
//	// first anme | lastname | email
//	if (csvfileexample.is_open()) {
//		//everything in one cell
//		csvfileexample << "john" << "doe" << "johndoe@gmail.com" << '\n';
//		//comma splits the cell
//		csvfileexample << "john" << "," << "doe" << "," << "johndoe@gmail.com";
//
//
//		csvfileexample.close();
//	}
//}