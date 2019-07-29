#include<iostream>
using namespace std;
const int N = 55;
const int oo = 0x3f3f3f3f;
int G[N][N];
int main()
{
    int n;//点的数量
    cin>>n;
    int m;//边的数量
    cin>>m;
    //a b c    表示从节点a到节点b的长度为c
    int a,b,c;
    //初始化图G
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i==j) G[i][j]=0;
            else G[i][j]=oo;
        }
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        G[a][b]=c;//G[a][b]表示从节点a到节点b的距离
        //G[b][a]=c;   无向图
    }
    //Floyd求多源最短路
    for(int k=1;k<=n;k++)//枚举中转点
        for(int i=1;i<=n;i++)//枚举起点
            for(int j=1;j<=n;j++)//枚举终点
                if(G[i][k]+G[k][j]<G[i][j])//G[i][k]+G[k][j]中转路径长度
                    G[i][j]=G[i][k]+G[k][j];
    //查询结果节点x到节点y之间的最短路径
    int x,y;
    /*while(cin>>x>>y)
        cout<<G[x][y]<<endl;*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<G[i][j];
        cout<<endl;
    }
    return 0;
}