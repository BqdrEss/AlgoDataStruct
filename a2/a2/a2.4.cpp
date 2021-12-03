#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    vector <int> V1 ;
    for(int i=1 ; i<=30 ; i++){
      V1.push_back(i);
    }
    V1.push_back(5);
    reverse(V1.begin(),V1.end());
    vector<int>::iterator VI;
    for(VI=V1.begin();VI!=V1.end();VI++){
      cout << *VI << endl;
    }
    replace (V1.begin(), V1.end(), 5, 129);
    for(VI=V1.begin();VI!=V1.end();VI++){
      cout << *VI << endl;
    }
	return 0;
}