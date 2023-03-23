#include "D:\SPRING 2023\CS 2\assignments\assignment 3\class_customer.h"

void customer :: setMID(int d){
    MechanicId = d;
}
void customer :: setAPP(int h , int m){
    if(h>0 && h<25 && m>0 && m <61){
    appointment.hours = h;
    appointment.mins = m; 
    }
}

bool customer :: operator == (const customer &passed_customer) {
bool res;
((passed_customer.appointment.hours == appointment.hours) && (passed_customer.appointment.mins == appointment.mins)) ? (res = 1) : (res = 0);
return res;
}

bool customer :: operator > (const customer &passed_customer) {
bool res;

if (this->appointment.hours> passed_customer.appointment.hours){
res = 1;
}
else if(this->appointment.hours == passed_customer.appointment.hours){

if(this->appointment.mins>= passed_customer.appointment.mins){
res = 1;
}
else {res = 0;}
}
else{
res = 0;
}   
return res;
}

bool customer :: operator < (const customer &passed_customer){
bool res;

if (this->appointment.hours< passed_customer.appointment.hours){
res = 1;
}
else if(this->appointment.hours == passed_customer.appointment.hours){

if(this->appointment.mins<= passed_customer.appointment.mins){
res = 1;
}
else {res = 0;}
}
else{
res = 0;
}   
return res;
}
int customer :: get_assigned_mech_id(){
    return MechanicId;
}
customer :: Appointment customer:: getAPP_timing() {return appointment;} 