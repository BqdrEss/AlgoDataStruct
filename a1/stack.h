    #include <cassert>
    #include <iostream>     

    using namespace std;

    /* 
    This is a generic stack. Its type T is generic and its initial 
    size defaults to 10.
    */
    template<class T>
    class Stack 
    {
        T *ptr;			// data will be stored in an array
        int size;		// number of elements in the array
        int where;  	// last non-free position
        void extend();  // used to expand the vector when it is full
    public:
        Stack();
        ~Stack();
    Stack(const Stack&);  //copy constructor
    Stack(int);
    bool push(T);	// checks the validity of pushing
    bool pop(T&);			// returns and extracts an element
    T back(void);
    int getNumEntries();
    void printSt(); //prints stack
    };


    template<class T>
    Stack<T>::Stack() 
    {
        size = 10;
        ptr = new T[size];	// creates a vector of the given size
        where = -1;					// no elements up to now
    }

    template<class T>
    Stack<T>::~Stack()
    {
        delete[] ptr;			// deallocate memory
    } 

    template<class T>
    Stack<T>::Stack(const Stack& s)
    {
        ptr=s.ptr;
    size=s.size;
    where=s.where;
    } 

    template<class T>
    Stack<T>::Stack(int nsize)
    {
        ptr=new T[size];
    } 

    template<class T>
    bool Stack<T>::push( T element)
    {
        if (where + 1 == size)	// no room?  
            extend();			// expand the vector
        where++;				// and insert the element 
        ptr[where] = element;
    return true;
    }

    template<class T>
    bool Stack<T>::pop(T& out)
    {
        if(where>0){
        ptr[where]=out;
        where--;
        return true;
        }
        else{return false;}
    }

    template<class T>
    T Stack<T>::back(void)
    {
    T temp=ptr[where];
    return temp;
    }

    template<class T>
    int Stack<T>::getNumEntries()
    {
    return where+1;
    }

    template<class T>
    void Stack<T>::extend()
    {
        T *newptr = new T[2 * size];	// creates a new vector with double size
        for (int i = 0; i < size; i++)	// copy the old elements
            newptr[i] = ptr[i];
        delete[] ptr;	// release old memory
        ptr = newptr;	// adjust pointers
        size *= 2;		// store the new size
    }

template <class T>
    void Stack<T>::printSt(){
    if(where==-1)
    {
       cout<<"Empty!!"<<endl;
      exit(0);
    }

       int i=0;
        for( i=0; i<where+1; i++)
        {
            cout<<ptr[i]<<" ";
        }
        cout<<endl;
    }