//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    string readFile;
//    int numEntires;
//    string email;
//    string name;
//
//    //makes new file and assisgns name
//    ofstream newFile("new-file.txt");
//
//    cout << "Enter the number of entires: ";
//    cin >> numEntires;
//
//    for (int i = 0; i < numEntires; i++) {
//        cout << "Enter name: ";
//        cin >> name;
//        cout << "Enter email: ";
//        cin >> email;
//        //stores data to file
//        newFile << "name: " << name << "\t" << "email: " << email << endl;
//    }
//    newFile.close();
//        
//    //makes file readable
//    ifstream readNewFile("new-file.txt");
//    cout << "input data reads as: \n";
//    //outputs lines of file
//    while (getline(readNewFile, readFile)) {
//        cout << readFile << endl;
//    }
//    readNewFile.close();
//}
