#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 8; 

int queen[N]={0}; 
int Counts = 0;

void print()
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(queen[i] == j)
			cout<<1<<" ";
			else
			cout<<0<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int ok(int row, int col)
{
	for(int i = 0;i < row; i++)
	{
		if(queen[i] == col || abs(i-row) == abs(queen[i] - col))
		return 0;
		
	}
	return 1;
}
void QUEEN(int row)
{

	for(int col = 0; col < N; col++)
	{
		if(ok(row,col))
		{
			queen[row] = col;
			if(row == N-1)
			{
				Counts++;
				print();
				queen[row] = 0;
				return;
			}
			QUEEN(row+1);
			queen[row] = 0;
		}
	}
}
int main()
{
	QUEEN(0);
	cout<<Counts<<" ways"<<endl;
	return 0;
}
