#include <iostream>

using namespace std;

const int N = 5;

int arc[N][N] = {0};
int color[N] = {0};
void mygragh()
{
	arc[0][1] = 1,arc[0][3] = 1;
	arc[0][4] = 1,arc[1][0] = 1;
	arc[1][2] = 1,arc[1][3] = 1;
	arc[2][1] = 1,arc[2][3] = 1;
	arc[3][0] = 1,arc[3][2] = 1;
	arc[3][4] = 1,arc[4][0] = 1;
	arc[4][1] = 1,arc[4][3] = 1;
 } 

int ok(int k)
{
	for(int i = 0; i < k; i++)
	{
		if (arc[k][i] == 1 && color[i] == color[k]) return 0;
	}
	return 1;
}
void pintar(int step)
{
	int k;
	
	
}
void graghcolor(int m)
{
	int i,k;
	for(i = 0; i < N; i++)
		color[i] = 0;
	k = 0;
	
	while(k >= 0)
	{
		color[k] += 1;
		while(color[k] <= m)
		{
			if (ok(k)) break;
			else color[k] += 1;
		}
		if(color[k] <= m && k == N-1)
		{
			for(i = 0; i < N; i++)
				cout<<color[i]<<" ";
			return;
		}
		if(color[k] <= m && k < N-1)
		k++;
		else
		color[k--] = 0;
	}
}
int main()
{
	mygragh();
	graghcolor(3);
	return 0;
}
