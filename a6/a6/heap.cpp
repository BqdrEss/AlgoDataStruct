#include <iostream>
#include <iterator>
#include <cmath>
#include<ctime>
#include <fstream>


using namespace std;

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 

    
    
    
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i = n - 1; i >= 0; i--) { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 
  
/* A utility function to print array of size n */
int down(int arr[], int n, int i) 
{ 
    int largest;
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l >= n ){ 
        return i; 
    }
    // If right child is larger than largest so far 
    else if (r >= n ){ 
        swap(arr[i], arr[l]);
        return l;
    }  
    // If largest is not root 
    else{
        if (arr[l]>arr[r]) { 
            swap(arr[i], arr[l]);
            largest = l ;
        }
        else{ 
            swap(arr[i], arr[r]);
            heapify(arr, n, largest); 
            largest = l ;
        }
        return down(arr,n,largest);
    } 
} 
void up(int arr[],int i){
    int Up=(i-1)%2;
    if(arr[Up]<arr[i]){
      swap(arr[i],arr[Up]);
      up(arr,Up);
    }
}

void bottom_up(int *arr,int n){ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
    int size=sizeof(arr)/sizeof(*arr);
    // One by one extract an element from heap 
    for (int i = size - 1; i >= 0; i--) { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
        --n;
        int d=down(arr,n,0);
        up(arr,d); 
    } 
}

int main(){
    clock_t begin, end;
    srand(time(NULL));
    int rand_size[] = {1,10,50,100,1000,5000,10000,1000000};
    int m=sizeof(rand_size)/sizeof(*rand_size);
    double time0[m],time1[m]; //time0 for normal heap and time1 for bottom_up
    ofstream out;
    out.open("Cases.txt");
    out<<"Times for :\nHeap_Sort\t\tBottom_up"<<endl;
    for(int j=0;j<m;j++)     //to generat 100 random array for each case and compare times
    {
        int arr[rand_size[j]],arr2[rand_size[j]];
        for(int i=0;i<rand_size[j];i++){
            arr[i]=rand()%100+1;
            arr2[i]=arr[i];
        }
        begin = clock();
        heapSort(arr,rand_size[j]);
        end = clock();
        time0[j] = 1e3*((double)(end - begin) / CLOCKS_PER_SEC);    //time in ms
        begin = clock();
        bottom_up(arr2,rand_size[j]);
        end = clock();
        time1[j] = 1e3*((double)(end - begin) / CLOCKS_PER_SEC);    //time in ms
        out<<time0[j]<<"\t\t\t\t"<<time1[j]<<endl;
    }   
    out.close(); 
}