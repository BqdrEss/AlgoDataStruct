#include <iostream>

#include<ctime>

#include<cstdlib>

#include <fstream>

using namespace std;

 

void insertion_sort(int arr[], int l, int r)

{

    int i, key, j;

    for (i=l; i<r+1; i++)

        {

        key=arr[i];

        j=i-1;

        while (j>=0 && arr[j] >key)

            {

            arr[j+1]=arr[j];

            j=j-1;

            }

        arr[j+1]=key;

    }

}

void merge(int arr[], int l, int m, int r )

{

   

    int i, j, k;

    int n1= m - l +1;

    int n2= r-m;

    int *L= new int[n1], *R= new int[n2];

 

    for(i=0; i<n1; i++)

    {

        L[i]=arr[l+i];

    }

    for (j=0; i<n2; j++)

    {

        R[i]=arr[m+1+j];

    }

   

    i=j=0;

    k=l;

   

    while (i<n1 && j<n2)

    {

        if (L[i]<R[j])

            {

            arr[k]=L[i];

            i++;

            }

        else

            {

            arr[k]=R[j];

            j++;

            }

        k++;

    }

    while (i<n1)

    {

        arr[k]=L[i];

        i++;

        k++;

    }

     while (j<n2)

    {

        arr[k]=R[i];

        j++;

        k++;

    }

}

void mergesort(int arr[], int l, int r, int k)

{

    if((r-l+1)<=k)

        {

        insertion_sort(arr, l, r);

        }

    else

        {

        int m=l+(r-l)/2;

       

        mergesort(arr, l, m, k);

        mergesort(arr, m+1, r, k);

       

        merge(arr,l,m,r);

        }
}

 

 

 

int main()

{

    ofstream myfile1;

    ofstream myfile2;

    ofstream myfile3;

 

    myfile1.open("Bestcase.txt", ios::out);

    myfile2.open("Avergacase.txt", ios::out);

    myfile3.open("Worstcase.txt", ios::out);

 

 

 

 

    for (int k=1; k<1000; k+=500)

    {

        for (int n=1000; n<=10000; n+=500)

        {

            int arr1[n];

            for (int j=0; j<n; j++)

            {

                arr1[j]=j;

            }

        float f;

        f=clock();

        mergesort(arr1,0,n-1,k);

        f= clock() - f;

        cout<< f/CLOCKS_PER_SEC << endl;

        myfile1<<n<< "  ";

        myfile1<< k << "  ";

        myfile1<<f/CLOCKS_PER_SEC<<endl;

 

        }

    }

    cout << "--------------------------------------------"<<endl;

    srand(time(NULL));

    for (int k=1; k<100; k+=10)

    {

        for (int n=1000; n<=10000; n+=500)

        {

            int arr2[n];

            for (int j=0; j<n; j++)

            {

                arr2[j]=rand()%1000+1;

            }

        float f;

        f=clock();

        mergesort(arr2,0,n-1,k);

        f= clock() - f;

        cout<< f/CLOCKS_PER_SEC << endl;

        myfile2<<n<< "  ";

        myfile2<< k << "  ";

        myfile2<<f/CLOCKS_PER_SEC<<endl;

 

        }

    }

    cout << "--------------------------------------------"<<endl;

 

    for (int k=1; k<100; k+=10)

    {

        for (int n=1000; n<=10000; n+=500)

        {

            int arr3[n];

            for (int j=n; j>0; j--)

            {

                arr3[j]=j;

            }

        float f;

        f=clock();

        mergesort(arr3,0,n-1,k);

        f= clock() - f;

        cout<< f/CLOCKS_PER_SEC << endl;

        myfile3<<n<< "  ";

        myfile3<< k << "  ";

        myfile3<<f/CLOCKS_PER_SEC<<endl;

        }

    }

   

    

    

   myfile1.close();

   myfile2.close();

   myfile3.close();

    return 0;

}