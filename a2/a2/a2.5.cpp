#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct cmpStruct {
  bool operator () (int const & lhs, int const & rhs) const
  {
    return lhs < rhs;
  }
};
int main() {
    srand (time(NULL));
    set <int,cmpStruct> srandom ;
    int key=0;
    for(int i=0 ; i<6 ; i++){
      srandom.insert(rand()%49+1);
    }
    
    set<int>::iterator it;
    for(it = srandom.begin(); it != srandom.end(); it++)
		cout << *it << " ";
	cout << endl;
    
	return 0;
}
