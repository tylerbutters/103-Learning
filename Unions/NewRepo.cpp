#include <iostream>
using namespace std;

struct User {
    string name;
    string pass;
    int age;
};

struct Admin {
    string name;
    string pass;

    Admin(string NAME, string PASS) {
        name = NAME;
        pass = PASS;
    }
};

//allocates memory for the largest member
union Account {
    User user;
    Admin admin;

    Account(){}
};

void runUser(User acc) {

}

void runAdmin(Admin acc) {

}

int main() {
    Account* acc = new Account();

    int accessLevel = 0;

    switch (/*file*/) {
    case 0:
        acc->user.name = "namerad";
        acc->user.pass = "password";
        acc->user.age = 0;
        runUser(acc->user);
        break;
    case 1:
        acc->admin.name = "namerad";
        acc->admin.pass = "password";
        runAdmin(acc->admin);
        break;
    }
}
