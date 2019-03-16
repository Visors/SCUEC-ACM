//暴力求解法之深宽搜 
//丛林再寻径（带路径） 
//2016.5.13 
#include<iostream>
#include<stack>
using namespace std; 
const int N = 51;

int map[N][N],book[N][N];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int head=1,tail=1;
int n,m;
int sx,sy,fx,fy,tx,ty;
int flag;
stack <int> x;
stack <int> y;

struct node
{
	int x;
	int y;
	int f;
	int s;
}que[2501];

void instack(int k)
{
	if(k==1){
		x.push(que[1].x);
		y.push(que[1].y);
		return;
	}
	x.push(que[k].x);
	y.push(que[k].y);
	return instack(que[k].f);
}

void outstack()
{
	int totx=x.size();
	int toty=y.size();
	while(totx>1&&toty>1){
		cout<<'('<<x.top()<<','<<y.top()<<')'<<"->";
		x.pop();
		y.pop();
		totx--;
		toty--;
	}
	cout<<'('<<x.top()<<','<<y.top()<<')'<<endl;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>map[i][j];
	cin>>sx>>sy>>fx>>fy;
	que[tail].x=sx;
	que[tail].y=sy;
	que[tail].f=0;
	que[tail++].s=0;
	book[sx][sy]=1;
	flag=0;
	while(head<tail){
		for(int i=0;i<=3;i++){
			tx=que[head].x+dir[i][0];
			ty=que[head].y+dir[i][1];
			if(tx<1||tx>n||ty<1||ty>m)
				continue;
			if(map[tx][ty]==0&&
				book[tx][ty]==0){
				book[tx][ty]=1;
				que[tail].x=tx;
				que[tail].y=ty;
				que[tail].f=head;
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
	instack(tail-1);
	cout<<que[tail-1].s<<endl;
	outstack();
	return 0;
}
