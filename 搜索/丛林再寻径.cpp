//暴力求解法之深宽搜 
//丛林再寻径
//2016.5.13 
#include<iostream>
using namespace std; 
const int N = 51;
int map[N][N],book[N][N];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int head=1,tail=1;
int n,m,sx,sy,fx,fy,tx,ty,flag;
struct queue
{
	int x;
	int y;
	int s;
}que[2501];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>map[i][j];
	cin>>sx>>sy>>fx>>fy;
	que[tail].x=sx;
	que[tail].y=sy;
	que[tail++].s=0;
	book[sx][sy]=1;
	flag=0;
	while(head<tail){
		for(int i=0;i<=3;i++){
			tx=que[head].x+dir[i][0];
			ty=que[head].y+dir[i][1];
			if(tx<1||tx>n||ty<1||ty>m)
				continue;
			if(map[tx][ty]==0&&book[tx][ty]==0){
				book[tx][ty]=1;
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].s=que[head].s+1;
				tail++;
			}
			if(tx==fx&&ty==fy){
				flag=1;
				break;
			}
		}
		if(flag==1)
			break;
		head++;
	}
	cout<<que[tail-1].s<<endl;
	return 0;
}
