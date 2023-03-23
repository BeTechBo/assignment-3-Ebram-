#ifndef class_mechanic
#define class_mechanic
#include "D:\SPRING 2023\CS 2\assignments\assignment 3\class_person.h"

class mechanic : public person{
int counter;
Appointment *apps;
public:
int getC();
mechanic();
~mechanic();
bool isAvailable(Appointment);
void setC(int);
void setAPP(int, int);
Appointment get_app_by_index(int);
};
#endif