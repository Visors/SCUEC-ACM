//暴力求解法之深宽搜 
//岛屿面积（DFS） 
//2016.5.13 
#include<iostream>
using namespace std;
const int N = 55;
int map[N][N],book[N][N];
int n,m,sx,sy,tx,ty,tot=1;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y)
{
	for(int i=0;i<=3;i++){
		tx=x+dir[i][0];
		ty=y+dir[i][1];		
		if(tx<1||tx>n||ty<1||ty>m) continue;
		if(map[tx][ty]&&book[tx][ty]==0){
			tot++;
			book[tx][ty]=1;
			dfs(tx,ty);
		}
	}
	return; 
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>map[i][j];
	cin>>sx>>sy;
	book[sx][sy]=1;
	dfs(sx,sy);
	cout<<tot<<endl;
	return 0;
}
