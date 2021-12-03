#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    string FName, LName, bDate, cName;
    map<string, string> bMap;
    ifstream f1;
    f1.open("data.txt");
    if (!f1.good()) {
		cerr << "Error while opening file!!" << endl;
		exit(1);
	}

	if (f1.is_open())
		while (!f1.eof()) {
			f1 >> FName >> LName >> bDate;
			bMap[FName + " " + LName] = bDate;		
		}
    while(1){
        cout<<"enter a name:  "<<endl;
        getline(cin,cName); //choosen name
        if(cName=="EXIT"){exit(1);}
        if(bMap.find(cName)!=bMap.end()){
            cout<<bMap[cName]<<endl;
         }
        else{
            cout<<"Name not found!"<<endl;
        }
    }
    return 0;
}