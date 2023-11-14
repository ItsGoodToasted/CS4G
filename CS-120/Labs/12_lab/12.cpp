#include<iostream>
#include<string>
using namespace std;

class node{
   private:
     node *next;
     string name;
   public:
     void setnext(node *n){next = n;} // inline function
     void setdata(string n){name = n;}  // inline function
     void print(); // defined below
     void reversePrint(); //defined below
};

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
  temp -> setdata("Sally"); // add data
  temp -> setnext(NULL);  // make the next object Null
  head = temp;           // make head point to the beginning of the list
  
  temp = new node();  // create another new node object
  temp -> setdata("Fred"); // add data
  temp -> setnext(head); // 'point' the new object to the beginning of the list
  head = temp;          // make head point to the new beginning of the list
  
  temp = new node();    // repeat
  temp -> setdata("Anne");
  temp -> setnext(head);
  head = temp;
  
  temp = new node();
  temp -> setdata("Alan");
  temp -> setnext(head);
  head = temp;
  
  head->print();       // print the list
  cout << endl; // for spacing
  head->reversePrint(); // print reverse list
  int bobs; // bob storage
  cout << "How much of 'Bob' do you want to add: ";
  cin >> bobs;
    //loop to make and add bobs
  for (int i = 0; i < bobs; i++) {
    temp = new node();
    temp -> setdata("Bob");
    temp -> setnext(head);
    head = temp;
  }  

  head -> print();
}
