#include <iostream>
#include <stdio.h>
using namespace std;

class Node {
public:
int key;
int value;
Node(int key, int value){
        this->value = value;
        this->key = key;
    }
};
class HashTable {
  private:
    Node **arr;
    int maxSize;
    int currentSize;
  public:
    HashTable(){
      //Initial maxSize of hash array
        maxSize = 20;
        currentSize=0;
        arr = new Node*[maxSize];
          
        //Initialise all elements of array as NULL
        for(int i=0 ; i < maxSize ; i++)
            arr[i] = NULL;
    }
    int hashCode(int key){
      return key % maxSize;
    }
    void insertNode(int key, int value){
      Node *temp = new Node(key, value);    
      // Apply hash function to find index for given key
      int hashIndex = hashCode(key);
          
      //find next free space 
      while(arr[hashIndex] != NULL && arr[hashIndex]->key != key && arr[hashIndex]->key != -1){
            hashIndex++;
            hashIndex %= maxSize;
        }
          
        //if new node to be inserted increase the current size
        if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
            currentSize++;
        arr[hashIndex] = temp;
        }
    int get(int key){
      // Apply hash function to find index for given key
      int hashIndex = hashCode(key);
      int counter=0;
      //finding the node with given key   
      while(arr[hashIndex] != NULL)
      {    int counter =0;
           if(counter++>maxSize)  //to avoid infinite loop
              return 0;        
          //if node found return its value
          if(arr[hashIndex]->key == key)
              return arr[hashIndex]->value;
          hashIndex++;
          hashIndex %= maxSize;
      }
          
      //If not found return null
      return 0;
    }
    bool isEmpty(){
      //Return true if size is 0
      return currentSize == 0;
    }
    //Function displays if the table is empty or not
    void Empty_display()
    {
      if(this->isEmpty()){cout<<"The table is empty"<<endl;}
      else{cout<<"The table is non empty"<<endl;}
    }
    //Function to display the stored key value pairs
    void display()
    {
        for(int i=0 ; i<maxSize ; i++)
        {
            if(arr[i] != NULL && arr[i]->key != -1)
                cout << "key = " << arr[i]->key 
                     <<"  value = "<< arr[i]->value << endl;
        }
    }
};
int main(){
   HashTable h; 
    h.insertNode(1,1);
    h.insertNode(2,2);
    h.insertNode(2,3);
    h.display();
    h.Empty_display();
    cout<<"enter a key: ";
    cin>>n;
    cout<<"The value for key "<<n<<" is "<<h.get(n);
    return 0;
}