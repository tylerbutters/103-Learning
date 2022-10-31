#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string readFile;

    fstream testingFile;
    testingFile.open("testingFile.txt", ios::out); //write
    if (testingFile.is_open()) {
        testingFile << "Input this text to testFile.txt\n";
        testingFile.close();
    }
    //using ios::out again will override current line

    testingFile.open("testingFile.txt", ios::app); //append
    if (testingFile.is_open()) {
        testingFile << "Input more text to testFile.txt\n";
        testingFile.close();
    }

    testingFile.open("testingFile.txt", ios::in); //read
    if (testingFile.is_open()) {
        while (getline(testingFile, readFile)) {
            cout << readFile << endl;
        }
        testingFile.close();
    }
}
