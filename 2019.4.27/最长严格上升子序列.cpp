#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5005;
int n, high[N], f[N];
int LIS()
{
    int ret = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        int Max = 0;
        for (int j = 1; j<i; j++)
            if (high[j]<high[i]) {
            Max = max(Max, f[j]);
        }
        f[i] = Max + 1;
    }
    for (int i = 1; i <= n; i++)
    ret = max(ret, f[i]);
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    cin >> high[i];
    cout << LIS() << endl;
    //system("pause");
    return 0;
}