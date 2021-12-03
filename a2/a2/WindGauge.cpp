#include <iostream>
#include<deque>
#include <algorithm>
#include "WindGauge.h"



WindGauge::WindGauge(int period ){
    period=this->dint.max_size();
}

void WindGauge::currentWindSpeed(int speed){
    if(dint.size()==12){
        this->dint.pop_front();
    }
    this->dint.push_back(speed);
    
}

int WindGauge::highest(){
  deque<int>::iterator it=this->dint.begin();
  int temp=*it;
  for(;it!=this->dint.end();it++){
      if(temp<*it){temp=*it;}
  }
    return temp;
}

int WindGauge::lowest(){
  deque<int>::iterator it=this->dint.begin();
  int temp=*it;
  for(;it!=this->dint.end();it++){
      if(temp>*it){temp=*it;}
  }
    return temp;
}

int WindGauge::average(){
    deque<int>::iterator it=this->dint.begin();
    int sum = 0;
    for(;it!=this->dint.end();it++){
      sum+=*it;
    }
    float f=sum/12;
    return (int)f;
}

void WindGauge::print(){
    cout << "highest wind speed: "<<this->highest()<<endl;
    cout << "lowest wind speed: "<<this->lowest()<<endl;
    cout << "average wind speed: "<<this->average()<<endl;
}