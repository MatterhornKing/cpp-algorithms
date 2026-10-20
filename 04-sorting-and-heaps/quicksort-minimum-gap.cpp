#include <stdio.h>
#define N 100
#include<stdlib.h>
#include<time.h>
void QuickSort(int a[],int low,int high);
int partition(int a[],int low,int high);
int findmin(int a[]);
int main ()
{
	int a[N];
	int aa,ans;
	
	srand((unsigned)time(NULL));
	for(int i=0;i<N;i++)
	{
		aa=rand()%1000+1;
		a[i]=aa;

	}
	QuickSort(a,0,N-1);
	for(int i=0;i<N;i++)
	{
		printf("%d ",a[i]);
	}
	ans=findmin(a);
	printf("最小差为%d",ans);
	return 0;
 } 
int partition(int a[],int low,int high)
{
	int pivot;
	int i=0,j=N-1;
	pivot=a[low];
	while(low<high)
	{
		while(low<high&&a[high]>=pivot)--high;
		a[low]=a[high];
		while(low<high&&a[low]<=pivot)++low;
		a[high]=a[low];
	}
	a[low]=pivot;
	return low;//返回枢轴位置 
}
void QuickSort(int a[],int low,int high)
{
	if(low>=high)//需要额外注意不能写成low==high 
	return;
	else
	{
		int pivotloc=partition(a,low,high);
		QuickSort(a,low,pivotloc-1);
		QuickSort(a,pivotloc+1,high);
	}
}
int findmin(int a[])
{
	int ans=a[1]-a[0]; 
	for(int i=2;i<N;i++)
	{
		if(a[i]-a[i-1]<ans)
		ans=a[i]-a[i-1];
	}
	return ans;
}
