// Nigel Lee
// CS-120-08
// Assignment 11
// 11/27/2023 

#include<iostream>
#include<string>
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
};

void node::insert(string n, int m) {
  //If it has reached the end of the list, add a new node with the argument data
  //else, go to next node
  if(next == NULL) {
    next = new node();
    next->setBoth(n,m);
    next->setNext(NULL);
  } else {
    next->insert(n,m);
  }
}

int node::find(string n) {
  //Check name match, and if not at end of list, continue through list until all names checked.
  if (name == n) {
    return 1;
  } else if (next == NULL) {
    return 0;
  } else {
    return next->find(n);
  }
}

void node::print(){
   cout << name << " : " << age << endl;
   if(next != NULL)
      next -> print();
}

int main(){
  cout << "Code modified to call only 'setBoth' function. If successful, both setAge and setBoth work.\n";
  cout << "It should create Sally, Fred, and Anne with ages of 23, 48, and 37.\n" << endl;

  node *head, *temp;  // pointers to a node object
  temp = new node();  // create a new node object
  temp -> setBoth("Sally", 23); // add data
  temp -> setNext(NULL);  // make the next object Null
  head = temp;           // make head point to the beginning of the list
  temp = new node(); 
  temp -> setBoth("Fred", 48);
  temp -> setNext(head); // 'point' the new object to the beginning of the list
  head = temp;
  temp = new node();
  temp -> setBoth("Anne", 37);
  temp -> setNext(head); 
  head = temp; 
  head->print();// print the list

  cout << "\nCalling 'insert' function. If successful, Alex with an age of 27 should be added to the end.\n" << endl;
  head->insert("Alex", 27); //insert a new node
  head->print();
  string search; //storage for search
  cout << "\nTesting 'find' function. Enter a name: ";
  cin >> search;
  cout << "\n Calling 'find' to see if '" << search << "' is in the list." << endl;
  cout << head->find(search) << "\n"; //call 'find' on user entered data to search list
  return 0;
}

