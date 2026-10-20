#include <stdio.h>
#define N 100
#include<stdlib.h>

void QuickSort(int a[],int low,int high);
int partition(int a[],int low,int high);
int mode=0;
int modec=0;
int main ()
{
	int a[10]={4,3,4,5,6,8,7,4,8,7};
	QuickSort(a,0,4);
    printf("%d",mode);
	return 0;
 } 
int partition(int a[],int low,int high)
{
	int pivot;int count=0;
	int i=0,j=N-1;
	pivot=a[low];
	while(low<high)
	{
		while(low<high&&a[high]>=pivot)
		{
			if(a[high]==pivot)
			count++;
			--high;
		}
		a[low]=a[high];
		while(low<high&&a[low]<=pivot)
		{
			if(a[high]==pivot)
			count++;
			++low;
		}
		a[high]=a[low];
	}
	a[low]=pivot;
	if (count>modec)
	{
		modec=count;
		mode=pivot;
	}
	return low;//返回枢轴位置 
}
void QuickSort(int a[],int low,int high)
{
	if(low>=high)//需要额外注意不能写成low==high 
	return;
	else
	{
		int pivotloc=partition(a,low,high);
		if(mode>=pivotloc-low&&mode>=high-pivotloc) return;
		else if(mode>=high-pivotloc)
		QuickSort(a,low,pivotloc-1);
		else if(mode>=pivotloc-low)
		QuickSort(a,pivotloc+1,high);
		else
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
