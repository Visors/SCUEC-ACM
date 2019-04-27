#include<iostream>
#include<algorithm>
using namespace std;
const int N = 35, M = 30005;
int n, v, V[N], dp[M];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
    cin >> V[i];
    for (int i = 1; i <= n; i++)
    for (int j = v; j >= V[i]; j--)
    dp[j] = max(dp[j], dp[j - V[i]] + V[i]);
    cout << v - dp[v] << endl;
    //system("pause");
    return 0;
}
