#include <iostream>
using namespace std;
#include <bits/stdc++.h>

template<class T>
class Stack{
protected:
  struct StackNode { // linked list
  T data;
  StackNode * next;
  };
  int size; // -1 if not set, value otherwise
  int current_size; // unused if size = -1
public:
  StackNode * top; // top of stack
  Stack(){
        this->size = -1;
        this->current_size = 0;
        this->top = NULL;
  }

  Stack(int nsize){
        this->size = nsize;
        this->current_size = 0;
        this->top = NULL;
  }

  void push(T x){  // if size set, check for overflow
    // Create new node temp and allocate memory
    StackNode * temp;    // Check if stack (heap) is full.
    temp = new StackNode();    // Then inserting an element would
    if (this->current_size == this->size)            // lead to stack overflow
    {
        cout << "\nStack Overflow";
        exit(1);
    }
    temp->data=x;    // Initialize data into temp data field
    temp->next = this->top;   // Put top pointer reference into temp link
    this->top = temp;   // Make temp as top of Stack
    this->current_size++;
  }


  T pop(){ // return element if not in underflow
    StackNode* temp;    // Check for stack underflow
    temp = this->top;   // Top assign into temp
    if (this->current_size == 0)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
        this->top = this->top->next;    // Assign second node to top
        // Destroy connection between
        T data = temp->data;
        temp->next = NULL;    // first and second
        free(temp);   // Release memory of top node
        this->current_size--;
        return data;
    }
  }


  bool isEmpty() {// true if empty, false otherwise
    if(this->top == NULL){return true;}
    else{return false;}
  }


  void display(){
    struct StackNode* temp;
    // Check for stack underflow
    if (top == NULL){cout << "\nStack Underflow";exit(1);}
    else
    {
        temp = this->top;
        while (temp != NULL)
        {
            // Print node data
            cout << temp->data << "\t";
            // Assign temp link to temp
            temp = temp->next;
        }
        cout<<endl;
    }
  }
};


template<class T>
class Queue  {
private:
  Stack<T> s1 ; 
  Stack<T> s2 ; 
  int qsize;
public:

  void enQueue(T x){  // if size set, check for overflow
        while (!s1.isEmpty()) {
            s2.push(s1.top->data);
            s1.pop();
        }
        // Push item into s1
        s1.push(x);
        this->qsize++;
        // Push everything back to s1
        while (!s2.isEmpty()) {
            s1.push(s2.top->data);
            s2.pop();
        }
        
  }


  T deQueue(){ // return element if not in underflow
        // if first stack is empty
        if (s1.isEmpty()) {
            cout << "Q is Empty";
            exit(0);
        }
  
        // Return top of s1
        T x = s1.top->data;
        s1.pop();
        return x;
    }


  void qdisplay(){s1.display();}
};
// Driver Code
int main()
{    

    Stack<int> S1(3);
    Stack<float> S2(3);
    Stack<string> S3(3);

    Queue<int> q1;
    Queue<string> q2;
    // Push the elements of stack
    //S.pop();    //print underflow message
    S1.push(11);
    S1.push(22);
    S1.push(33);

    S2.push(0.11);
    S2.push(0.22);
    S2.push(0.33);

    S3.push("abc");
    S3.push("def");
    S3.push("ghi");
    //S.push(55);       //print overflow message
    // Push the elements of stack
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);

    q2.enQueue("a");
    q2.enQueue("b");
    q2.enQueue("c");
    cout<<"Stacks:"<<endl;
    // Display stack elements
    S1.display();
    S2.display();
    S3.display();
    // Display queue elements
    cout<<"Queues:"<<endl;
    q1.qdisplay();
    q2.qdisplay();
    // Delete top elements of stack
    if(!S1.isEmpty()){
    S1.pop();
    S1.pop();
    }
    if(!S2.isEmpty()){
    S2.pop();
    S2.pop();
    }
    if(!S3.isEmpty()){
    S3.pop();
    S3.pop();
    }
    // Delete top elements of queue
    q1.deQueue();
    q2.deQueue();
    // Display stack and queue elements
    cout<<"Stacks after removing 2 elements:"<<endl;
    S1.display();
    S2.display();
    S3.display(); 
    cout<<"Queues after removing 1 element:"<<endl;
    q1.qdisplay();
    q2.qdisplay();
    return 0;
}


// except