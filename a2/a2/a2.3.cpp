#include <iostream>
#include<deque>
#include<list>
#include "WindGauge.h"

using namespace std;

int main(){
    WindGauge H;
    list <int>L1 = {15,16,12,15,15};
    list<int>::iterator it1;
    for(it1=L1.begin(); it1!=L1.end(); it1++){
        H.currentWindSpeed(*it1);
    } 
    list <int>L2 = { 16,17,16,16,20,17,16,15,16,20};
    list<int>::iterator it2; 
    for(it2=L2.begin(); it2!=L2.end(); it2++){
        H.currentWindSpeed(*it2);
    }
    H.print();
}