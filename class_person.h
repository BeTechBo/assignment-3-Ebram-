#ifndef class_person
#define class_person
#include <iostream>
using namespace std;
class person {
    string name;
    unsigned int id;
    int age;
    protected:
    struct Appointment{
        int mins, hours;
    };
    public:
    person();
    void setN(string);
    void setA(int);
    void setI(int);
    string getN();
    int getA();
    int getI();
    void print();
};
#endif