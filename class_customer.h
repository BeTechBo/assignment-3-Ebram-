#ifndef class_customer
#define class_customer
#include "D:\SPRING 2023\CS 2\assignments\assignment 3\class_person.h"
class customer : public person{

int MechanicId;
Appointment appointment;

public:
void setMID(int);
void setAPP(int , int);
Appointment getAPP_timing();
bool operator ==(const customer &);
bool operator > (const customer &);
bool operator < (const customer &);
int get_assigned_mech_id();
void print();
};
#endif