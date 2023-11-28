#include<iostream>
#include<string>

// Nigel Lee
// CS-120-08
// Assignment 11
// 11/10/2023 
using namespace std;

class node{
   private:
     node *next;
     string name;
     int age;
   public:
     void setNext(node *n){next = n;} // inline function
     void setData(string n){name = n;}  // inline function

     void setAge(int n){age = n;} //inline function
     void setBoth(string n, int m){setData(n);setAge(m);} //inline function
     void insert(string n, int m);
     int find(string n);
     void print(); // defined below
     void reversePrint(); //defined below
};

void node::insert(string n, int m) {
  if(next == NULL) {
    next = new node();
    next->setBoth(n,m);
    next->setNext(NULL);
  } else {
    next->insert(n,m);
  }
}

int node::find(string n) {
  if (name == n) {
    return 1;
  } else if (next == NULL) {
    return 0;
  } else {
    return next->find(n);
  }
}

void node::print(){
   cout << name << endl;
   if(next != NULL)
      next -> print();
}

void node::reversePrint() {
    //find end of list
    if(next != NULL) {
        next -> reversePrint();
    }
    //work backwards through if checks;
    cout << name << endl;



}

int main(){
  node *head, *temp;  // pointers to a node object
  temp = new node();  // create a new node object
  temp -> setBoth("Sally", 23); // add data
  temp -> setNext(NULL);  // make the next object Null
  head = temp;           // make head point to the beginning of the list
  
  temp = new node();  // create another new node object
  temp -> setBoth("Fred", 48); // add data
  temp -> setNext(head); // 'point' the new object to the beginning of the list
  head = temp;          // make head point to the new beginning of the list
  
  temp = new node();    // repeat
  temp -> setBoth("Anne", 37);
  temp -> setNext(head);
  head = temp;
  
  temp = new node();
  temp -> setBoth("Alan", 94);
  temp -> setNext(head);
  head = temp;
  
  head->print();       // print the list
  cout << endl; // for spacing
  head->reversePrint(); // print reverse list

/* For lab 12. Not necessary for assignment 12.
  int bobs; // bob storage
  cout << "How much of 'Bob' do you want to add: ";
  cin >> bobs;
    //loop to make and add bobs
  for (int i = 0; i < bobs; i++) {
    temp = new node();
    temp -> setData("Bob");
    temp -> setNext(head);
    head = temp;
  }
*/

  head -> print();
}
