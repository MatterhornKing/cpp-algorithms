#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
const int MAX = 500;

typedef int Vertextype;
typedef bool Arctype;

typedef struct
{
	Vertextype vex[MAX];
	Arctype arc[MAX][MAX];
	int vexnum, arcnum;
}AMGragh;

Vertextype v[MAX] = {0};
Arctype g[MAX][MAX];

int paint();
int ok(int i);

int main ()
{
	AMGragh pic;
	
	FILE *fp;
	fp = fopen("in.txt", "r");
	//freopen("in.txt", "r", stdin);
	int row = -1;
	int n;
	fscanf(fp,"%d",&n);
	//for (int i = 0; i < n; ++i)
    //{
       // printf("%d: ", i);
       // for (int j = 0; j < n; ++j)
        //    if (g[i][j])
       //         printf("%d ", j);
      //  printf("\n");
    //}
	//cout<<n<<endl;
	char cake[6];
	while (fscanf(fp,"%s", cake) != EOF)
	{
		//cout<<cake<<endl; 
		int len = strlen(cake);
		if(cake[len - 1] ==':')
			row++;
		else
		{
			int sum = 0;
			for(int i = 0; i < len; ++i)
			{
				sum += (pow(10, len - i -1) + 0.1)*(cake[i] - '0');
			}
			g[row][sum] = true;//cout<<g[row][sum]<<" ";
		}	
		
	}
	
	//for (int i = 0; i < n; ++i)
    //{
    //    printf("%d: ", i);
     //   for (int j = 0; j < n; ++j)
     //       if (pic.arc[i][j])
      //          printf("%d ", j);
     //   printf("\n");
    //}
	//for(int i = 0; i < n; i++)
	//{
	//	for(int j = 0; j < n; j++)
	//	{
	//		cout<<g[i][j]<<" ";
	//	}
	//	cout<<endl;
	//}
	cout<<paint();
	
	return 0;
}

int paint()
{
	int k = 0;
	int flag = 1;
	while (flag == 1)
	{
		k++;flag = 0;
		for (int i = 0; i < MAX; i++)
		{
			if (v[i] == 0)
			{
				v[i] = k;
				for (int j = 0; j < MAX; j++)
				{
					if (g[i][j] == 1 && v[i] == v[j])
					{
						v[i] = 0;
					flag = 1;
					}
					
				}
				//if (!ok(i))
				//{
				//	v[i] = 0;
				//	flag = 1;
				//}
			}
		}
	}
	return k;
}

int ok(int i)
{
	for (int j = 0; j < MAX; j++)
	{
		if (g[i][j] == 1 && v[i] == v[j])return 0;
		return 1;
	}
}
