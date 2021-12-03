#include <iostream>
#include <string>
using namespace std;

class Complex {
    private:
        int real;
        int imaginary;
    public:
        // Constructors
        // Construct Complex object with all parameters supplied
        Complex(int real, int complex);
        // Construct Complex with no parameters supplied
        Complex();
        // Copy constructor
        Complex(Complex& num);

        // Destructor
        ~Complex();

        // Setter Methods
        void setReal(int newReal);
        void setImaginary(int newImaginary);

        // Getter methods
        int getReal();
        int getImaginary();

        // Methods
        // Overloaded friend functions for extractor and inserter
        friend std::ostream& operator<<(std::ostream &out, const Complex &c);
        
        // Overloaded assignment operator for Complex instances
        Complex& operator=(const Complex obj);

        // Overloaded equality operator for Complex instance
        bool operator==(const Complex& obj);

        void print();
};
// Constructor Complex with 2 parameters 
Complex::Complex(int Real, int Imaginary) {
    real = Real;
    imaginary = Imaginary;
}

// Constructor Complex with no parameters sets value to 0 to data members
Complex::Complex() {
    real = 0;
    imaginary = 0;
}

// Copy constructor
Complex::Complex(Complex& num) : real(num.real), imaginary(num.imaginary) {
    // Copy data members
}

// Destructor Complex
Complex::~Complex() {
    // Empty destructor
}

// Setter methods for each data member of Complex class 
void Complex::setReal(int newReal) {
    real = newReal;
}

void Complex::setImaginary(int newImaginary) {
    imaginary = newImaginary;
}

// Getter methods for each data member of Complex class
int Complex::getReal() {
    return real;
}

int Complex::getImaginary() {
    return imaginary;
}

std::ostream& operator<<(std::ostream &out, const Complex &c) {
    if (c.imaginary > 0)
        out << c.real << "+" << c.imaginary << "i";
    else if(c.imaginary < 0)
	      out << c.real <<"-"<< c.imaginary << "i";
    else
        out <<c.real;
	return out;
}


Complex& Complex::operator=(const Complex c) {
    real = c.real;
    imaginary = c.imaginary;
    return *this;
}

bool Complex::operator==(const Complex& obj) {
    if (this->real == obj.real && this->imaginary == obj.imaginary)
        return true;
    else 
      return false;
}
template <class T>
int array_search(T A[], int n, T toseek)
{
    for (int i = 0; i < n; i++)
        if (A[i] == toseek)
            return i + 1;
    return -1;
}

int main()
{
    int n = 5;
    double x=7.7;
    string s="world";
    Complex c(-2,1);
    Complex c1(1,1),c2(-3,0),c3(-2,1);  
    int arr1[5] = {5, 6, -7, 8, 9};
    double arr2[5] = {-5.5, 6.6, 7.7, -8.8, 9.9};
    string arr3[3] = {"hello","world","!!!"};
    Complex arr4[3]={c1,c2,c3};
    cout<<"checking the position of 5 in first array: "<<array_search(arr1, 5, n)<<endl;
    cout<<"checking the position of 7.7 in second array : "<<array_search(arr2, 5, x)<<endl;
    cout<<"checking the position of world in third array : "<<array_search(arr3, 3, s)<<endl;
    cout<<"checking the position of -2+i in fourth array : "<<array_search(arr4,3,c)<<endl;
    return 0;
}   