#include<iostream>
#include<ctime>
#include <fstream>

using namespace std;

void bubble_S(int *arr,int L){
    bool swap= false;
    for(int i=0;i<L-1;i++){
        for(int j=0;j<L-1-i;j++){
            swap= false;
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=true;
            }
        }
        
    }
}
int main(){
    clock_t begin, end;
    int c=0,l=20;
    double time0[l],time1[l],time2[l]; //time for best,worst and average case
    ofstream out;
    out.open("Casel.txt");
    out<<"Time for:\nsize\tBest\t\tWorst\t\tAverage "<<endl;
    while (c < l )     //to generat 100 random array for each case and compare times
    {
        int rand_size = rand()%1000;
        int arr[rand_size];
        int best[rand_size];
        int avg[rand_size];
        int wrst[rand_size];
        for(int i=0;i<rand_size;i++){
            arr[i]=rand();
            avg[i]=arr[i];  //as for the average we need just random numbers
        }
        bubble_S(arr,rand_size);    // so I can read from right to left for worst case and the 
                                    // other sens for the best case
        //for the best case
        for(int i=0;i<rand_size;i++){
            best[i]=arr[i];
        }
        for(int i=rand_size-1;i>=0;i--){
            wrst[i]=arr[i];
        }
        begin = clock();
        bubble_S(best,rand_size);
        end = clock();
        time0[c] = 1e3*((double)(end - begin) / CLOCKS_PER_SEC);    //time in ms
        begin = clock();
        bubble_S(wrst,rand_size);
        end = clock();
        time1[c] = 1e3*((double)(end - begin) / CLOCKS_PER_SEC);    //time in ms
        begin = clock();
        bubble_S(avg,rand_size);
        end = clock();
        time2[c] = 1e3*((double)(end - begin) / CLOCKS_PER_SEC);    //time in ms
        out<<rand_size<<"\t\t"<<time0[c]<<"\t\t"<<time1[c]<<"\t\t"<<time2[c]<<endl;
        c++;
    }   
    out.close(); 
}