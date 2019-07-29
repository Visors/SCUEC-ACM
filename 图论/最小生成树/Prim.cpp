#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 105;
const int INF = 0x7fffffff;
int G[N][N];
int Dist[N];
int p, r;
long long tot = 0;
struct node
{
	int num;
	int dist;
	bool operator <(const node& x)const
	{
		return dist > x.dist;
	}
};
priority_queue <node> pq;
int main()
{
	while (cin >> p)
	{
		if (p == 0)
			return 0;
		cin >> r;
		if (r == 0) {
			cout << '0' << endl;
			continue;
		}
while(!pq.empty()) pq.pop();
		int n, m, Max = 0;
		for (int i = 1; i <= p; i++) {
			for (int j = 1; j <= p; j++) {
				if (i == j)
					G[i][j] = 0;
				else
					G[i][j] = INF;
			}
		}
		for (int i = 1; i <= r; i++) {
			cin >> n >> m >> Max;
			if (G[n][m] > Max)
				G[n][m] = G[m][n] = Max;
		}
		node a;
		for (int i = 1; i <= p; i++) {
			Dist[i] = G[1][i];
			a.num = i;
			a.dist = Dist[i];
			pq.push(a);
		}
		Dist[1] = -INF;
		tot = 0;
		int pcount = 1;
		while (1) {
			//if (pq.empty()) break;
			if (pcount == p) break;
			while (!pq.empty())
			{
				a = pq.top();
				pq.pop();
				if (Dist[a.num] != -INF && a.dist < INF) break;
			}
			tot += a.dist;
			Dist[a.num] = -INF;
			node k;
			for (int i = 1; i <= p; i++) {
				if (Dist[i] != -INF && G[a.num][i] < INF && G[a.num][i] < Dist[i]) {
					Dist[i] = G[a.num][i];
					k.num = i;
					k.dist = Dist[i];
					pq.push(k);
				}
			}
			pcount++;
		}
		cout << tot << endl;
	}
	return 0;
}