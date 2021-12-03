#include<iostream>
#include"Stack.h"
using namespace std;
    int main()
    {
      char c;
      Stack<char> charStack;
      charStack.push('Z');
      charStack.push('A');
      charStack.push('B');
      cout<<"Stack is: "<<endl;
      charStack.printSt();
      charStack.pop(c);
      cout<<"New stack is: "<<endl;
      charStack.printSt();
      cout<<"Data on top of the stack is: "<<charStack.back()<<endl;
      cout<<"Number of enteries: "<<charStack.getNumEntries()<<endl;
      return 0;
    }

