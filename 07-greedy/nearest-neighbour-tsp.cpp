#include <iostream>
#include <cmath>
#include<algorithm>
using namespace std;
#define MVNum 100
typedef char VerTexType;
typedef float Arctype;

typedef struct
{
	float x;
	float y;
}position;//每个城市坐标
 
typedef struct
{
	VerTexType vexs[MVNum];
	position pos[MVNum];
	Arctype arcs[MVNum][MVNum];
}AMGragh;

float FindWay_greedy(int n, AMGragh a, int path[]);

float figure(float x1, float y1, float x2, float y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

} //计算每个点之间距离 

int main ()
{
	float distance; //总距离 
	int path1[9], path2[31];//记录路径 
	AMGragh g1, g2;//之前做八个城市剩下的，这里只用g2
	 
	//for(int i=0;i<8;i++)
	//{
	//	g1.vexs[i]=65+i;
	//}
	//for(int i=0;i<30;i++)
	//{
	//	g2.vexs[i]=65+i;
	//}
	
	
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
	
	g2.pos[16].x=24;g2.pos[16].y=42;
	g2.pos[17].x=58;g2.pos[17].y=69;
	g2.pos[18].x=71;g2.pos[18].y=71;
	g2.pos[19].x=74;g2.pos[19].y=78;
	g2.pos[20].x=87;g2.pos[20].y=76;
	g2.pos[21].x=18;g2.pos[21].y=40;
	g2.pos[22].x=13;g2.pos[22].y=40;
	g2.pos[23].x=82;g2.pos[23].y=7;
	g2.pos[24].x=62;g2.pos[24].y=32;
	g2.pos[25].x=58;g2.pos[25].y=35;
	g2.pos[26].x=45;g2.pos[26].y=21;
	g2.pos[27].x=41;g2.pos[27].y=26;
	g2.pos[28].x=44;g2.pos[28].y=35;
	g2.pos[29].x=4;g2.pos[29].y=50;
	
	
	
	for(int i=0;i<30;i++)
	{
		for(int j=0;j<30;j++)
		{
			g2.arcs[i][j] = figure(g2.pos[i].x, g2.pos[i].y, g2.pos[j].x, g2.pos[j].y);
			printf("%.2f ", g2.arcs[i][j]);
		}
		printf("\n");
	}//初始化邻接矩阵
	 
	distance = FindWay_greedy(30,g2,path2);
	
	cout<< "The shortest way is ";
	for(int i=0;i<30;i++)
	{
		cout<< path2[i] << "->";
	}
	cout<< 0 <<endl;//补上返回起始点 
	cout<< "The distance is " << distance <<endl;
	return 0;
	
}

float FindWay_greedy(int n,AMGragh a,int path[])
{
	float flag[MVNum]={0};//标记这个点有没有走过 
	float cost=0,min;//总代价，min是每个点到剩余点的最短距离 
	int next; int now=0;//标记所在点和即将去往的点 
	path[0]=0;//起始点0 
	flag[0]=1;//起始点标记走过 
	int k=1;
	
	do
	{
		min=32467;
		for(int i=1;i<n;i++)
		{
			
			if(flag[i]==0&&a.arcs[now][i]<min&&now!=i)
			{
				next=i;	
				min=a.arcs[now][next];
			}
			
		}
		flag[next]=1;now=next;
		cost=cost+min;
		path[k]=next;
		k++;
		
	}while(k<30);
	
	cost=cost+a.arcs[0][next];
	
	return cost;
}
