#include<cstdio>
const int N = 50;
int w[N];
int n,V;
int ans=0x7fffffff;
void dfs(int num,int totw)
{
    if(totw>V) return ;
    if(num==n+1){
        //if(totw>V) return ; 非剪枝，这样会TLE
        if(V-totw<ans) ans=V-totw;
        return ;
    }
    dfs(num+1,totw);
    dfs(num+1,totw+w[num]);
}
int main()
{
    scanf("%d",&V);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}