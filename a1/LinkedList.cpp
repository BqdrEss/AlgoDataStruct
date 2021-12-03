#include <iostream>
#include "LinkedList.h"
using namespace std;
int main() {
	List<int> intlist;
 	List<float> floatlist;
	List<string> strlist;

    intlist.push_f(2);
    intlist.push_f(1);
    intlist.push_b(3);

    floatlist.push_f(3);
    floatlist.push_f(1.5);
    floatlist.push_b(4.5);

    strlist.push_f("b");
    strlist.push_f("a");
    strlist.push_b("c");


    cout << "List of integers has: " << intlist.elementNumber()<< " elements." <<"\n"
         << "Element in the front: " << intlist.pos_f() <<"\n"
			  << "Element in the back: " << intlist.pos_l() << endl;

     cout << "List of integers has: " << floatlist.elementNumber()<< " elements." <<"\n"
         << "Element in the front: " << floatlist.pos_f() <<"\n"
			  << "Element in the back: " << floatlist.pos_l() << endl;
    
     cout << "List of integers has: " << strlist.elementNumber()<< " elements." <<"\n"
        << "Element in the front: " << strlist.pos_f() <<"\n"
			  << "Element in the back: " << strlist.pos_l() << endl;

    cout << "Popping first element which was: "<< intlist.pos_fr() << endl
			  << "Popping last element which was: " << intlist.pos_lr() << endl;
    
     cout << "Popping first element which was: "<< floatlist.pos_fr() << endl
			  << "Popping last element which was: " << floatlist.pos_lr() << endl;
    
     cout << "Popping first element which was: "<< strlist.pos_fr() << endl
			  << "Popping last element which was: " << strlist.pos_lr() << endl;

	cout << "Amount of elements in the lists:\nlist of ints: "<< intlist.elementNumber()<<endl
			  << " list of floats: "<< floatlist.elementNumber()<<endl
        << " list of strings: "<< strlist.elementNumber()<<endl;
	return 0;
}