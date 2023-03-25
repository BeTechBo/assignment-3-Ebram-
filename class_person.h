#ifndef class_person
#define class_person
#include <iostream>
using namespace std;
class person {
    protected:
    string name;
    unsigned int id;
    int age;
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
    virtual void print() = 0; // abstract class because of the pure virtual function
};
#endif