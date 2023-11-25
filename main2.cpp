#include <iostream>

using namespace std;

class Employee {
    //name
    //salary
    //
    const int id;
    char* name;
    int salary;

public:
    Employee():id(0) {
        this->name = nullptr;
        this->salary = 0;
    };

    Employee(int Id, char* Name, int Salary) : id(Id) {
        if(Name == NULL) {
            throw exception("name empty");
        }
        this->name = new char(strlen(Name)+1);
        strcpy(name, Name);
        this->salary = Salary;
    };

    Employee (const Employee& e): id (e.id) {
        if(e.name == NULL) {
            throw exception("name null");
        this->name = new char[strlen(e.name)+1];
        strcpy(this->name, getName());
        }
    };

    ~Employee() {
        if(this->name != NULL) {
            delete[] this-> name;
            this->name = nullptr;
        }
    };

    char* getName(char* Name) {
        return this-> name;
    };

    operator int() {
        return this->salary;
    }

    explicit operator int() {
        return this->salary;
        Employee& operator+=(int newAmount) {
            this->salary+=newAmount;
            return *this;
        }
    }

    void showObject() {
        cout << "Name: " << name << "\nSalary: \n" << salary << endl;
    };

};

class Departament {
    //name
    //Employees*
    //buget -> int*

//     char* name;
//     Employee* employees;
//     int* budget;
//     int noEmployees;

// public:
//     Departament() {
//         this->name = NULL;
//         this->budget = 0;
//         this->employees = NULL;
//     };

//     Departament(char* Name, int* Budget, int size) : budget(Budget) {
//         this->name = new char(strlen(Name)+1);
//         strcpy(name, Name);
//         this->employees = new Employee[size];
//         //for()
//     }

//     void showObject() {
//         cout << "Name: " << name << "\nBudget: " << budget << endl;
//     }

};

int main() {
    Employee e("George", 3300);
    e.showObject();
    // Departament d("HR", 3300, 3);
    // e.showObject();
    return 0;
}