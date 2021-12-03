#include <vector>
#include <iostream>

const int size = 50;

using namespace std;

int main(int argc, char** argv)
{  
    string str;
    vector<string> vstr;
	while(1){
        cin >> str;
        if (str == "END"){
            break;
        }
        else{
            vstr.push_back(str);
        }
    }
    for(int i=0; i < vstr.size(); i++){
        cout<<vstr[i]<<" ";
    }
    cout << endl;
    
    vector<string>::iterator viter = vstr.begin();
     while (viter != vstr.end()) {
		cout << *viter << "," ;
		viter++;
	}
	cout << endl;
}