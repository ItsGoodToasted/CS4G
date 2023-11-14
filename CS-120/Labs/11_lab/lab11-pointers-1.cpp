#include<iostream>
using namespace std;

int func(int, int &);
void func2(int, int []);

int main(){
   //x = 99, y = 55
   int x = 99, y = 55;
   // a[] = 1, 2, 3, 4, 5
   int a[5] = {1,2,3,4,5};
   //new pointer p
   int *p;
   //p points at location of a[0]
   p = a;
   //p points at a[1]
   p++;
   //x = 99 + 1
   x++;
   //a[1] = 8
   *p = 8;
   //p points at a[3]
   p = &a[3];
   //a[3] = 12
   *p = 12;   
   //p points at a[2]
   p--;
   //a[2] = 11
   *p = 11;
   //a[0] = 102
   a[0] = func(x,y);
   //x = 100, a[4] = 456
   func2(x,a);
   cout << "x = " << x << endl;
   cout << "y = " << y << endl;
   for(int i = 0; i < 5; i++){
      cout << "a[" << i << "] = " << a[i] << endl;
   }
}

int func(int a, int &b){
   a = 100;
   b = 101;
   return 102;
}

void func2(int a, int b[]){
   a = 123;
   b[4] = 456;
}