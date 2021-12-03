#include <deque>
#include <iostream>


using namespace std;
int main(){
  deque<float> A;
  deque<float> B;
  int n;
  while(1){
      cin >> n;
      if (n == 0){
        break;
      }
  (n <0) ? A.push_front(n) : A.push_back(n);
  }
  for(int i=0;i<A.size();i++){
    if(i==A.size()){
      cout<<A[i]<<endl;
    }
    cout<<A[i]<<" ";
  }
  cout<<endl;
  std::deque<float>::iterator it ;
 for (it = A.begin(); it != A.end(); it++) {
		if (*it > 0) {
			A.insert(it, 0);
			break;
		}
	}

  for(it = A.begin();it!=A.end();it++){
    if(it==A.end()-1){
      cout<<*it;
    }
    else {
      cout<<*it<<";";
    }
  }
}
