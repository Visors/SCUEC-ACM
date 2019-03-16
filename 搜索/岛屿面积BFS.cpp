#include<iostream>
using namespace std;
const int N = 55;
int map[N][N],book[N][N],tx,ty,
	sx,sy,n,m,head,tail,tot=1;
int dir[4][2]={{1,0},{0,1},
		{-1,0},{0,-1}};
struct box
{
	int x;
	int y;
}que[2555];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>map[i][j];
	cin>>sx>>sy;
	head=1;
	tail=1;
	que[tail].x=sx;
	que[tail].y=sy;
	tail++;
	book[sx][sy]=1;
	while(head<tail)
	{
		for(int i=0;i<=3;i++){
			tx=que[head].x
				+dir[i][0];
			ty=que[head].y
				+dir[i][1];
			if(tx<1||tx>n||
					ty<1||ty>n)
				continue;
			if(map[tx][ty]&&
				book[tx][ty]==0){
				tot++;
				book[tx][ty]=1;
				que[tail].x=tx;
				que[tail].y=ty;
				tail++;
			}
		}
		head++;
	}
	cout<<tot<<endl;
	return 0;
}
