#include<bits/stdc++.h>
#include <iostream>
#include <list>
#define N 5

using namespace std;




// Function for finding maximum sum
void maxPathSum(int tri0[][N], int m, int n)
{
  int tri[N][N];
  for(int i=0;i<N;i++){
    for(int j=0 ; j<i+1;j++){
      tri[i][j]=tri0[i][j];
    }
  }
	// loop for bottom-up calculation
	for (int i=m-1; i>=0; i--)
	{
		for (int j=0; j<=i; j++)
		{
			if (tri[i+1][j] > tri[i+1][j+1])
				tri[i][j] += tri[i+1][j];
			else
				tri[i][j] += tri[i+1][j+1];
		}
	}
  
	cout<<tri[0][0]<<endl;

  for (int i=0;i<N;i++){
    int temp=0;
    for (int j=0;j<i+1;j++)
            if (tri[i][temp] < tri[i][temp + 1])
                temp += 1;
    cout<<tri0[i][temp]<<' ';
  }
  cout<<endl;
}




/* Driver program to test above functions */
int main()
{
int n, path[N],count=0;
int tri[N][N] ;
for (int i=0;i<N;i++){
  for(int j=0;j<i+1;j++){
    cin>>n;
    count++;
    tri[i][j]=n;
  }
}
for (int i=0;i<N;i++){
  for (int j=0;j<i+1;j++){
    cout<<tri[i][j]<<' ';
  }
  cout<<endl;
}
maxPathSum(tri, N-1, N-1);
return 0;
}