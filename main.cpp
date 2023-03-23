#include <fstream>
#include "D:\SPRING 2023\CS 2\assignments\assignment 3\class_person.h"
#include "D:\SPRING 2023\CS 2\assignments\assignment 3\class_mechanic.h"
#include "D:\SPRING 2023\CS 2\assignments\assignment 3\class_customer.h"
#include "D:\SPRING 2023\CS 2\assignments\assignment 3\template_queue.h"


string FIND_MECHANIC_BY_ID(mechanic* m , int id){ // finding the name of the mechanic by id
string res;
for(int i = 0; i < 4; i++){
    if((m+i)->getI() == id ){
        res = (m+i)->getN();
        break; 
    }
}
return res;
}
void read_data(mechanic *p ,customer *c){
    
    string n; int h , m , age , id; 
    int i = 0 , j =0;
    string n1; int h1 , m1;
    ifstream r,rr; // declaring an object of type ifstream
    r.open("D:\\SPRING 2023\\CS 2\\assignments\\assignment 3\\mechanics_data.txt");
    rr.open("D:\\SPRING 2023\\CS 2\\assignments\\assignment 3\\customers_data.txt");
    while(!r.eof()){
        r >> n >> age >> id;
        (*(p+i)).setN(n);
        (*(p+i)).setA(age);
        (*(p+i)).setI(id);
        i++;
    }
    r.close();
    while (!rr.eof()){ // reading the data from the file
        rr >>n1; 
        (*(c+j)).setN(n1);
        rr >> h1 >> m1;
        (c+j)->setAPP(h1,m1);
        j++;
    }
    rr.close();
}

void Assign_mechanics(mechanic *p , customer *c){ // to assign mehcnaics to customers
    cout << "Before sorting and sending to the queue"<<endl;
    bool found_slots;
    for(int j = 0; j < 5; j++){
        found_slots = false;
        if(j >=4){
        for(int i = 0; i < 4; i++){
            if((p+i)->isAvailable((c+j)->getAPP_timing())){
            (p+i)->setAPP((c+j)->getAPP_timing().hours , (c+j)->getAPP_timing().mins);
            (c+j)->setMID((p+i)->getI());
            found_slots = true; // this changes the key to found slots to avoid printing the message of not being able to find
            cout << (p+i)->getN() << " the mechanic is booked for " << (c+j)->getN() << " at " << (c+j)->getAPP_timing().hours << " : " <<(c+j)->getAPP_timing().mins<<endl;
            break;
            }
        }
        }
        else{
        (p+j)->setAPP((c+j)->getAPP_timing().hours , (c+j)->getAPP_timing().mins);
        (c+j)->setMID((p+j)->getI());
        cout << (p+j)->getN() << " the mechanic is booked for " << (c+j)->getN() << " at " << (c+j)->getAPP_timing().hours << " : " <<(c+j)->getAPP_timing().mins<<endl;
        found_slots = true;
        }
    }
    if(found_slots == false){ // this happens after not finding
        cout << "No slots found, pls get back to us soon\n";
    }
}
void queue_operations(mechanic *p , customer *c){ //this performs all the queue operations
    int IDD , num_app; string name_assigned;
    customer x,temp;
    ofstream ww;
    queue <customer> q;

    ww.open("D:\\SPRING 2023\\CS 2\\assignments\\assignment 3\\DATABASE_CUSTOMERS.txt");
    
    for(int i = 0; i < 5 ; i++){
        for(int j = 0; j<5; j++){
            if(*(c+i)<*(c+j)){
                x = *(c+i);
                *(c+i) = *(c+j);
                *(c+j) = x;
            }
        }
    }
    for(int i = 0; i < 5; i++){
        q.enqueue(*(c+i));
    }
    cout << endl<<"After inserting in the queue"<<endl;
    for(int i = 0; i < 5; i++){
    temp = q.dequeue();
    IDD = temp.get_assigned_mech_id();
    name_assigned = FIND_MECHANIC_BY_ID(p , IDD);
    //cout << "\nTESTING FOR DEBUGGING\n" << IDD << '\t' << name_assigned << '\t' << num_app << endl;
    
    if(name_assigned != "\0"){
        cout << name_assigned << " the mechaninc is booked for " << temp.getN() << " at " << temp.getAPP_timing().hours << " : " <<temp.getAPP_timing().mins<<endl;
        ww << temp.getN() << endl << temp.getAPP_timing().hours << endl << temp.getAPP_timing().mins << endl << IDD<<endl;
    }
    else{
        cout << temp.getN() << " could not find any suitable timing"<<endl;
    }
    }
    ww.close();
}
void writing_mechanics_data(mechanic *p){ // saving the sata into the meachanics database files. for the customers, this is done in the queue operations.
ofstream w;
int c; 

w.open("D:\\SPRING 2023\\CS 2\\assignments\\assignment 3\\DATABASE_MECHANICS.txt");
for(int i = 0; i < 4 ; i++){
c = (p+i)->getC();
w << (p+i)->getN() << endl << (p+i)->getA() << endl << (p+i)->getI()<< endl << c <<endl; 
for(int j = 0; j < c; j++){
w << (p+i)->get_app_by_index(j).hours << endl<<(p+i)->get_app_by_index(j).mins << endl;
}
}
w.close(); 
}
int main(){
    cout << "Example 2:\n";
    mechanic *p =  new mechanic[4];
    customer *c =  new customer[5];
    read_data(p,c);
    Assign_mechanics(p,c);
    queue_operations(p,c);   
    writing_mechanics_data(p);
}