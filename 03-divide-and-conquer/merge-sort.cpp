#include <iostream>
using namespace std;
#define MAX 100
int count=0;
void MergeSort(int a[],int i,int j);
void Merge(int a[],int r[],int i,int mid,int j);
int main ()
{
	int a[9]={8,5,7,2,1,9,6,3,4};
	MergeSort(a,0,8);
	for(int i=0;i<9;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
 } 
 
void MergeSort(int a[],int i,int j)
{
	int mid;
	int r[MAX]; 
	if(i==j) 
	{
		return;
	}
	else
	{
		mid=(i+j)/2;
		MergeSort(a,i,mid);
		MergeSort(a,mid+1,j);
		Merge(a,r,i,mid,j);
		for(int s=i;s<=j;s++)
		{
			a[s]=r[s];
		}
	}
}

void Merge(int a[],int r[],int i,int mid,int j)
{
	int p=i,m=mid+1,q=i;
	while(p<=mid&&m<=j)
	{
		if(a[p]<=a[m])
			r[q++]=a[p++];
		else
			r[q++]=a[m++];
	}
	while(p<=mid)
		r[q++]=a[p++];
	while(m<=j)
		r[q++]=a[m++];
}
