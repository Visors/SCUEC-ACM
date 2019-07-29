#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1005, INF=0x7f7f7f7f;
int a[maxn],f[maxn];
int n, ans=-INF;
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[i]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            if(a[j]<a[i])
                f[i]=max(f[i],f[j]+1);
 for(int i=1;i<=n;i++)
 ans=max(ans,f[i]);
 printf("%d\n",ans);
 return 0;
}