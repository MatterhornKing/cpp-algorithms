#include <iostream>
#include <cmath>
#include<algorithm>
using namespace std;
#define MVNum 100
typedef char VerTexType;
typedef int Arctype;

typedef struct
{
	int x;
	int y;
}position;
typedef struct
{
	VerTexType vexs[MVNum];
	position pos[MVNum];
	Arctype arcs[MVNum][MVNum];
	int vexnum,arcnum;
}AMGragh;

int FindWay(int n,AMGragh a,int path[]);

int figure(int x1,int y1,int x2,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

} 

int main ()
{
	int distance; 
	int path1[9],path2[17];
	AMGragh g1,g2;
	for(int i=0;i<8;i++)
	{
		g1.vexs[i]=65+i;
	}
	for(int i=0;i<16;i++)
	{
		g2.vexs[i]=65+i;
	}
	
	
	g2.pos[0].x=41;g2.pos[0].y=94;
	g2.pos[1].x=37;g2.pos[1].y=84;
	g2.pos[2].x=54;g2.pos[2].y=67;
	g2.pos[3].x=25;g2.pos[3].y=62;
	g2.pos[4].x=7;g2.pos[4].y=64;
	g2.pos[5].x=2;g2.pos[5].y=99;
	g2.pos[6].x=68;g2.pos[6].y=58;
	g2.pos[7].x=71;g2.pos[7].y=44;
	g2.pos[8].x=54;g2.pos[8].y=62;
	g2.pos[9].x=83;g2.pos[9].y=69;
	g2.pos[10].x=64;g2.pos[10].y=60;
	g2.pos[11].x=18;g2.pos[11].y=54;
	g2.pos[12].x=22;g2.pos[12].y=60;
	g2.pos[13].x=83;g2.pos[13].y=46;
	g2.pos[14].x=91;g2.pos[14].y=38;
	g2.pos[15].x=25;g2.pos[15].y=38;
	
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16;j++)
		{
			g2.arcs[i][j]=figure(g2.pos[i].x,g2.pos[i].y,g2.pos[j].x,g2.pos[j].y);
			printf("%d ",g2.arcs[i][j]);
		}
		printf("\n");
	}
	distance=FindWay(16,g2,path2);
	cout<<"The shortest way is ";
	for(int i=0;i<16;i++)
	{
		cout<<g2.vexs[path2[i]]<<"->";
	}
	cout<<g2.vexs[0]<<endl;
	cout<<"The distance is "<<distance<<endl;
	return 0;
	
}

int FindWay(int n,AMGragh a,int path[])
{
	int p[n];
	int distance=32767;
	
	for(int i=0;i<n;i++)
	{
		p[i]=i;
	}
	
	do
	{
		int cost=0;
		
		for(int i=0;i<n;i++)
		{
			cost=cost+a.arcs[p[i]][p[i]+1];
		}
		cost=cost+a.arcs[p[n]][p[0]];
		
		if (cost<distance) 
		{
			distance=cost;
			for (int i=0;i<n;i++) 
				path[i]=p[i];
		}
	}while(next_permutation(p, p+n));
	
	return distance;
}
