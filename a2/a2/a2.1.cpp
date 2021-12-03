#include <list>
#include <iostream>
#include<fstream>

using namespace std;
int main(){
  list <int> A;
  list<int> B;
  ofstream f1;
  f1.open("listB.txt");
  int n;
  while(1){
      cin >> n;
      if (n <= 0){
        break;
      }
      A.push_back(n);
      B.push_front(n);
  }
  list<int>::iterator Aliter;
  list<int>::iterator Bliter=B.begin();
  for ( Aliter=A.begin(); Aliter != A.end(); Aliter++){
		  cout << *Aliter << " ";
    }
  for ( Bliter=B.begin(); Bliter != B.end(); Bliter++){
		  f1 << *Bliter << " ";
    }
 cout << endl;

  int temp1,temp2;
  temp1=*A.begin();
  A.push_back(temp1);
  A.pop_front();
  temp2=*B.begin();
  B.push_back(temp2);
  B.pop_front();

  for ( Aliter=A.begin(); Aliter != A.end(); Aliter++){
      cout<< *Aliter << ",";
  }

  cout << endl ;
  while (Bliter != B.end()){
      cout<< *Bliter << ",";
      Bliter++;
  }

  while(Bliter != B.end()){
    A.push_back(*Bliter);
    Bliter++;
  }
  for ( Aliter=A.begin(); Aliter != A.end(); Aliter++){
      cout<< *Aliter << ",";
  }
  cout<<endl;
  A.merge(B);
  for ( Aliter=A.begin(); Aliter != A.end(); Aliter++){
      cout<< *Aliter << " ";
  }
  cout << endl;
}
  
