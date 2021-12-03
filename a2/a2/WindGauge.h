#include <deque>
#include <iostream>
using namespace std;

class WindGauge {
public:
WindGauge(int period = 12);
void currentWindSpeed(int speed);
int highest() ;
int lowest() ;
int average() ;
void print();
protected:
deque<int> dint;
};