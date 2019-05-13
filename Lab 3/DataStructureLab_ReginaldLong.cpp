#include<iostream>
#include"complex_number.h"


using namespace std;


int main(){

   complex_number a (double a = 2.0, double b = 3.0);
   complex_number b (double c = 6.0, double d = 4.0);
   
   complex_number operator + (complex_number a, complex_number b);
   complex_number result();


   cout << a << endl;


   cout << b << endl;
   
   cout << a*b   ;
   return 0;
}