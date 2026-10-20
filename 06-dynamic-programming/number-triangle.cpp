#include<iostream>
#include<cstdlib> 
#include<ctime>
using namespace std;
#define N 20

int answer=0;
int datatower(int a[N][N],int row);
int maketower(int a[20][20],int n);
int bftower(int a[N][N],int loc1,int loc2,int sum);
int main ()
{
	int mytower[20][20];
	int row;
	row=maketower(mytower,20);
	bftower(mytower,0,0,0);
	cout<<"The answer is "<<answer<<endl;
	//cout<<"The answer is "<<datatower(mytower,row)<<endl;
	return 0;
} 

int maketower(int a[N][N],int n)
{
	int row=0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			a[i][j]=rand()%100;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return n;
}

int datatower(int a[N][N],int row)
{
	int plan[row][row];
	for(int i=0;i<row;i++)
	{
		plan[row-1][i]=a[row-1][i];
	}
	
	for(int j=row-2;j>=0;j--)
	{
		for(int k=0;k<=j;k++)
		{
			if(plan[j+1][k]>plan[j+1][k+1])
			{
				plan[j][k]=a[j][k]+plan[j+1][k];
			}
			else
			{
				plan[j][k]=a[j][k]+plan[j+1][k+1];
			}
		}
	}
	
	return plan[0][0];
}

int bftower(int a[N][N],int loc1,int loc2,int sum)
{

	if (loc1==N-1)
	{
		sum=sum+a[loc1][loc2];
		if(sum>answer)
		answer=sum;
		return sum;
	}
	
	else 
	{
		sum=sum+a[loc1][loc2];
		bftower(a,loc1+1,loc2,sum);
		bftower(a,loc1+1,loc2+1,sum);
	}
}
