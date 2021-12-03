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

  if(vstr.size()>=5){
    string temp;
    temp=vstr[1];
    vstr[1]=vstr[4];
    vstr[4]=temp;
  }
  else{
    cout<<"error could not swap !!!"<<endl;
  }
  vstr.pop_back();
  vstr.push_back("???");

  for(int i=0; i < vstr.size(); i++){
    cout<<vstr[i]<<",";
  }
  cout << endl;
  vector<string>::iterator viter = vstr.begin();
  while (viter != vstr.end()) {
		cout << *viter << ";" ;
		viter++;
	}
  cout<<endl;
  vector<string>::reverse_iterator fe = vstr.rbegin(); //takes first element 
	for (vector<string>::reverse_iterator it = vstr.rbegin();it != vstr.rend(); it++) {
			if (it == fe)
				std::cout << *it;
			else std::cout << " " << *it;
		}
	cout << endl;
}