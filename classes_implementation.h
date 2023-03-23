#include <iostream>
using namespace std;
class person {
    string name;
    unsigned int id;
    int age;
    protected:
    struct Appointment{
        int hours, mins;
    };

    public:
    person(){
        name = ""; id = 0; age = 0;
    }
    void setN(string n){name = n;}
    void setA(int a)   {age = a;}
    void setI(int i)   {id = i;}
    string getN()      {return name;}
    int getA()         {return age;}
    int getI()         {return id;}

    void print(){
        cout << "Name: " << name << '\t' << "Age: " <<'\t' << "Id: "<< id << endl; 
    }
};

class customer : public person{
int MechanicId;
Appointment appointment;

public:
void setMID(int d){
    MechanicId = d;
}
void setAPP(int h , int m){
    if(h>0 && h<25 && m>0 && m <61){
    appointment.hours = h;
    appointment.mins = m; 
    }
}

Appointment getAPP_timing(){
    return appointment;
}

bool operator ==(const customer &passed_customer) const{ // constant passing by ref to optimize the memory
bool res;
((passed_customer.appointment.hours == appointment.hours) && (passed_customer.appointment.mins == appointment.mins)) ? (res = 1) : (res = 0);
return res;
}

bool operator > (const customer &passed_customer) const{
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

bool operator < (const customer &passed_customer) const{
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
int get_assigned_mech_id(){
    return MechanicId;
};
};

class mechanic : public person{
int counter;
Appointment *apps;
public:
int getC(){
    return counter;
}
mechanic(){
    counter = 0;
    apps = new Appointment[5]; 
}
~mechanic(){
    delete [] apps;
}
bool isAvailable(const Appointment &needed_app){
bool res = true;
for(int i = 0; i < 10; i++){
    if(needed_app.hours == apps[i].hours && needed_app.mins == apps[i].mins){
        res = false;
    }
}
return res;
}
void setC(int c){
    counter = c;
}
void setAPP(int th , int tm){
if(th > 0 && tm>0 && th<25 && tm<61){
(apps+counter)->hours = th;
(apps+counter)->mins = tm;
counter++;
}
}
Appointment get_app_by_index(int inx){
return *(apps+inx);
}
};

template <typename T> class queue{
T *qu;
int front, rear, counterQ, maxS;
public:
queue(){
    qu = new T[10];
    maxS = 10;
    front = 0; rear = -1; counterQ = 0;
}
~queue(){
    delete [] qu;
}
bool isEmpty(){
    if(!counterQ){return true;}
    else{return false;}
}
bool isFull(){
    if(counterQ< maxS){return false;}
    else{return true;}
}
void enqueue(T x){
    if(!isFull()){
    rear = (rear +1) % maxS;
    *(qu+rear) = x;
    counterQ ++; }
} 
T dequeue(){
    if(isEmpty()){
    exit(EXIT_FAILURE);
    }
    T x = *(qu+front);
    front = (front+1)%maxS; 
    counterQ--;
    return x;
}
};