//List<Part> parts = new List<Part>();
#include<iostream>
using namespace std;

template<class T>
class List0{
  public:
    T element;
    List0 *prev;
    List0 *next;
};

template<class T>
class List{
  List0<T> *f;  //for the front
  List0<T> *b;  //for the back
  int size;
  public:
  List(); //empty constructor
  ~List();  //destructor
  T pos_f();  // returns the first element
  T pos_l();  // returns the last element
  T pos_fr();  // returns the first element with removing it
  T pos_lr();  // returns the last element  with removing it
  void push_f(T); //push front
  void push_b(T);  //push back
  int elementNumber();
};

template<class T>
List<T>::List(){
  this->f = NULL;
  this->b = NULL;
  this->size = 0;
}

template<class T>
List<T>::~List(){
    List0<T> *temp = NULL; 
    while(this->f != NULL){
    temp=this->b; 
    this->b = this->b->prev; 
    size--; 
    delete temp;  
  }
}

template<class T>
T List<T>::pos_f(){
  return this->f->element;
}

template<class T>
T List<T>::pos_l(){
  return this->b->element;
}

template<class T>
T List<T>::pos_fr(){
  T nelem;
  while(this->size > 0){   //to check if the list is empty
    List0<T> *temp = NULL; 
    temp=this->f;
    nelem = this->f->element;
    this->f = this->f->next;
    size--; 
    delete temp;
  }
  return nelem;
};

template<class T>
T List<T>::pos_lr(){
  T nelem;
  if(this->size > 0){   //to check if the list is empty
    List0<T> *temp = NULL; 
    temp=this->b;
    nelem = this->b->element;
    this->b = this->b->prev;
    size--; 
    delete temp;
  }
  return nelem;
}

template<class T>
void List<T>::push_f(T element){
  if(this->f != NULL){  //to check if the list is empty
    List0<T> *cur=this->f;   //we use it as a cursor
    List0<T> *temp;
    while(cur != NULL){
      temp = cur;
      cur=cur->next; 
    }
  }
}

template<class T>
void List<T>::push_b(T element){
  List0<T> *cur;
  cur->element= element;
  if(this->f == NULL){
    this->f = cur;
  }
  else{
  this->b = cur->prev;
  cur->next = NULL;
  size++;
  }
}

template <class T>
int List<T>::elementNumber(){
  return this->size;
}