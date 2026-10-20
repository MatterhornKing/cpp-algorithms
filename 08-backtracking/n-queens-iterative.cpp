#include <iostream>
#include <cmath>
using namespace std;

const int N = 8;
bool chess[N][N];
int queen[N]; 
void QUEEN(int n); 
int ok(int k)
{
	//cout<<k<<" ";
	//cout<<j<<endl;
	for(int i = 0; i < k; i++)
	{
		if(queen[i] == queen[k] ||abs(i - k) == abs(queen[i] - queen[k]))
		{
			return 0;
		}
		
	}
	return 1;
}
int main()
{
	QUEEN(8);
	return 0;
 }
 

void QUEEN(int n)
{
	int k = 0;int count = 0;
	while(k >= 0)
	{
		queen[k]++;
		while(queen[k] < n && ok(k) == 0)
			queen[k]++;
		if (queen[k] < n && k == n - 1)
		{
			count++;
			for(int i = 0; i < n; i++)
			{
				cout<< queen[i] + 1 <<" ";	
			}
			cout << endl;
			//return;
		}
		if(queen[k] < n && k < n-1)
		k = k+1;
		else
		queen[k--] = -1;
		
	}
	
	cout << count <<endl;
	return;	
 } 

