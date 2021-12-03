#include<iostream>
#include <cmath>
#include <fstream>
#include<ctime>

using namespace std;

int Fibo1(int n){  //naive recursion
  if(n<2){
      return n;
  }
  else{
    return Fibo1(n-1)+Fibo1(n-2);
  }
}

int Fibo2(int n){ //bottomup
  int A[n];
    A[0] = 0;
    A[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        A[i] = A[i - 2] + A[i - 1];
    }
    return A[n];
  }

  int Fibo3(int n){ //closed form
    return round (pow((1 + sqrtl(5)) / 2.0,n)/sqrt(5));
  }

  void power(int F[2][2], int n);
 
int Fibo4(int n)
{
    int F[2][2] = { { 1, 1 }, { 1, 0 } };
     
    if (n == 0)
        return 0;
         
    power(F, n - 1);
     
    return F[0][0];
}
 
void multiply(int F[2][2], int M[2][2]) //
{
    int x = F[0][0] * M[0][0] + 
            F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + 
            F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + 
            F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + 
            F[1][1] * M[1][1];
     
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
 
void power(int F[2][2], int n)
{
    int i;
    int M[2][2] = { { 1, 1 }, { 1, 0 } };
     
    // n - 1 times multiply the 
    // matrix to {{1,0},{0,1}}
    for(i = 2; i <= n; i++)
        multiply(F, M);
}
// Driver program to test above function 
int main() 
{  time_t f = 1.0;                     //f time to 1 seconds for each function
    clock_t begin, end;
    double time;

    int n = 0;
    ofstream out;
    out.open("Naive_Data.txt");
    do
    {
        begin = clock();
        Fibo1(n);
        end = clock();
        time = 1e3*((double)(end - begin) / CLOCKS_PER_SEC);    //time in ms
        out <<n <<" "<<  time << endl;
        n=n+10;
    } while (time < f);
    out.close(); 

    ofstream out1;
    out1.open("Bottom_Data.txt");
    n = 0;
    do
    {
        begin = clock();
        Fibo2(n);
        end = clock();
        time = (double)(end - begin) / CLOCKS_PER_SEC;
        out1<< n << " "  << time << endl;
        n=n+10;
    } while (time < f);
    out1.close();
    
    ofstream out2;
    out2.open("Closed_Data.txt");
    n = 0;
    do
    {
        begin = clock();
        Fibo3(n);
        end = clock();
        time = (double)(end - begin) / CLOCKS_PER_SEC;
        out2 << n << " " << time << endl;
        n=n+10;
    } while (time < f);
    out2.close();

    ofstream out3;
    out3.open("Matrix_Data.txt");
    n = 0;
    do
    {
        begin = clock();
        Fibo4(n);
        end = clock();
        time = (double)(end - begin) / CLOCKS_PER_SEC;
        out3 << n << " " << time << endl;
        n=n+10;
    } while (time < f);
    out3.close();
    cout<<"cc"<<endl;
    return 0;
}