#include<iostream>
#include<queue>
using namespace std;
queue<int> qx;
queue<int> qy;
queue<int> step;
const int N = 15;
char G[N][N];
int n,m,sx,sy,ex,ey;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>G[i][j];
    cin>>sx>>sy>>ex>>ey;
    //BFS
    int nx=sx,ny=sy,tx,ty,nstep=0;
    G[sx][sy]='#';
    for(int i=0;i<4;i++){
        tx=nx+dir[i][0];
        if(tx<1||tx>7) continue;
        ty=ny+dir[i][1];
        if(ty<1||ty>11) continue;
        if(G[tx][ty]=='#')
            continue ;
        qx.push(tx);
        qy.push(ty);
        step.push(nstep+1);
    }
    while(!qx.empty()){
        nx=qx.front();qx.pop();
        ny=qy.front();qy.pop();
        nstep=step.front();step.pop();
        G[nx][ny]='#';
        if(nx==ex&&ny==ey){
            cout<<nstep<<endl;
            return 0;
        }
        for(int i=0;i<4;i++){
            tx=nx+dir[i][0];
            ty=ny+dir[i][1];
            if(tx<1||tx>7) continue;
            if(ty<1||ty>11) continue;
            if(G[tx][ty]=='#')
                continue ;
            qx.push(tx);
            qy.push(ty);
            step.push(nstep+1);
        }
    }
    cout<<"No answer!"<<endl;
    return 0;
}