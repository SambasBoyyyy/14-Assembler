#include <iostream>
#include <string>
#include <sstream> // this will allow you to use stringstream in your program

using namespace std;

int main() {

   stringstream ss; 
   

   string str;
   cin>>str;
   
 
   int num;
   
   
  
   ss << str;
   

   ss >> num;
   
 
   cout << num << endl; 
}