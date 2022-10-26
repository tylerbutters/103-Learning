#include <iostream>
using namespace std;

enum Flags {
    None = 0,
    B = 1,
    I = 2,
    U = 4
};

void returnValue(int flagInfo) {
    switch (flagInfo) {
    case 0:
        cout << "None\n";
        break;
    case 1:
        cout << "B\n";
        break;
    case 2:
        cout << "I\n";
        break;
    case 3:
        cout << "B U\n";
        break;
    case 4:
        cout << "U\n";
        break;
    case 5:
        cout << "B U\n";
        break;
    case 6:
        cout << "I U\n";
        break;
    case 7:
        cout << "B I U\n";
        break;
    }
}

int main() {
    //bitwise or
    int flagInfo = 0;
    int flag;

    cin >> flag;

    do {
        switch (flag)
        {
        case 1:
            flagInfo = B;
            break;
        case 2:
            flagInfo = I;
                break;
        case 3:
            flagInfo = U;
                break;
        default:
            break;
        }
    } while (flagInfo != 4);

    returnValue(flagInfo);
}
