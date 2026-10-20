#include <stdio.h>
#include <iostream>
using namespace std;
#define N 100
typedef struct
{
	int a[N];
	int length;
}Sqlist;
void HeapAdjust(Sqlist &L,int k,int n)
{
	int i,j,temp;
	i=k;
	j=2*i+1;
	while(j<n)//有孩子 
	{
		if(j<n-1&&L.a[j]<L.a[j+1]) j++;//有两个孩子 
		if(L.a[i]>L.a[j])
		break;
		else
		{
			temp=L.a[i];
			L.a[i]=L.a[j];
			L.a[j]=temp;
			i=j;
			j=2*i+1;
		}
	}
}

void insert(Sqlist &L,int n)
{
	L.a[L.length]=n;
	
	int k=L.length;//插入的结点 
	L.length+=1;
	int j=(k-1)/2;//它爸爸 
	int temp;
	while(j>=0)
	{
		if(L.a[j]<L.a[k])//假如他爸比他小 
		{
			temp=L.a[j];
			L.a[j]=L.a[k];//爸爸变儿子 
			L.a[k]=temp;
			k=j;
			j=(k-1)/2;
		}
		else
		{
			break;
		}
	}
	return; 
}
void CreateHeap(Sqlist &L)
{
	int n=L.length;
	for(int i=(n-1)/2;i>=0;--i)
		HeapAdjust(L,i,n);
}

int main ()
{
	Sqlist L;int n;int l;
	scanf("%d",&l);
	L.length=l;
	for(int i=0;i<l;i++)
	{
		scanf("%d",&L.a[i]);

	}
	CreateHeap(L);
	cout<<"原堆" <<endl; 
	for(int i=0;i<l;i++)
	{
		cout<<L.a[i]<<endl;
	}
	cout<<endl;
	scanf("%d",&n);
	insert(L,n);
	cout<<endl;
	cout<<"插入后" <<endl; 
	for(int i=0;i<L.length;i++)
	{
		cout<<L.a[i]<<endl;
	}
	return 0;
}
