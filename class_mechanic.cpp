#include "D:\SPRING 2023\CS 2\assignments\assignment 3\class_mechanic.h" // including the .h file of the class_mechanic

mechanic:: Appointment mechanic :: get_app_by_index(int inx){
return (*(apps+inx));
}

int mechanic :: getC(){
    return counter;
}

mechanic ::mechanic(){
    counter = 0;
    apps = new Appointment[5]; 
}
mechanic :: ~mechanic(){
    delete [] apps;
}
bool mechanic :: isAvailable(Appointment needed_app){
bool res = true;
for(int i = 0; i < 10; i++){
    if(needed_app.hours == apps[i].hours && needed_app.mins == apps[i].mins){
        res = false;
    }
}
return res;
}
void mechanic :: setC(int c){
    counter = c;
}
void mechanic :: setAPP(int th , int tm){
if(th > 0 && tm>0 && th<25 && tm<61){
(apps+counter)->hours = th;
(apps+counter)->mins = tm;
counter++;
}
}
void mechanic :: print(){
    cout << "Name: " << name << '\t' << "Age: " <<'\t' << "Id: "<< id << '\t' << " Number of times booked " << counter << endl; 

}