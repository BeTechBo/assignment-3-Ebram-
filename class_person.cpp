#include "D:\SPRING 2023\CS 2\assignments\assignment 3\class_person.h"
void person::setN(string n){name = n;}
void person::setA(int a)   {age = a;}
void person::setI(int i)   {id = i;}
string person:: getN()     {return name;}
int person::getA()         {return age;}
int person::getI()         {return id;}
void person::print(){
        cout << "Name: " << name << '\t' << "Age: " <<'\t' << "Id: "<< id << endl; 
    }
person::person(){
    name = ""; id = 0; age = 0;
}