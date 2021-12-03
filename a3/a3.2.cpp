#include <iostream>
using namespace std;

void selection_sort(int A[],int n){
    for(int i=0; i<n-1;i++){
        int key=i;
        for(int j=i+1;j<n;j++){
          if(A[key]>A[j]){
            key = j;
          }
        }
    if (i != key) 
    {
        swap(i,key);
    }
    }
}
void Worst_C(int A[], int n){
srand(time(nullptr));
int key;
key =  rand() % n + 1;
A[0]=key;
int temp = n;
for(int i=1;i<n;i++){
    if(A[i-1]== temp)
        temp += n/2;
    key =  rand() % temp  + 1;
    while(!(key>A[i-1]))
            key =  rand() % temp + 1;
    A[i]=key;
}
}
void Best_C(int A[],int n){
    int key;
    key =  rand() % n + 1;
    A[0]=key;
    int temp = n;
    for (int i = 0; i < n; i++){
      A[i+1]=rand()% n;
      if(key>A[i+1]){
        key=i+1;
      }
    }  

}

int main(){
    int n;
    int A[n],B[n];
    Case_B(B,n);
    cout<<"enter size of arrays"<<endl;
    cin>>n;
    for(int i=0 ; i<n ;i++){
      cout<<A[i]<<" ";
    }
    cout<<endl;
    Worst_C(A,n);
    for(int i=0 ; i<n ;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    Best_C(B,n);
    for(int i=0 ; i<n ;i++){
        cout<<B[i]<<" ";
    }
}