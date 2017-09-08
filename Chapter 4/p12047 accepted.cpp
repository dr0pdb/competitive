#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

#define MAXM 10000+5
vii adjlist[MAXM];
vii revAdjlist[MAXM];

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	int t,n,m,source,target,limit;
	cin>>t;

	while(t--){
		cin>>n>>m>>source>>target>>limit;

		F(i, 0, n+1){
			adjlist[i].clear();
			revAdjlist[i].clear();
		}

		int u,v,wt;
		F(i, 0, m){
			cin>>u>>v>>wt;		
			adjlist[u].push_back(ii(v,wt));
			revAdjlist[v].push_back(ii(u,wt));
		}

		priority_queue<ii, vector<ii>, greater<ii> >pq;
		int dist[n+1],revDist[n+1];
		F(i, 0, n+1){
			dist[i]=INF;
			revDist[i]=INF;
		}
		dist[source]=0;
		pq.push(ii(0,source));
		
		while(!pq.empty()){
			ii curr = pq.top();
			pq.pop();

			int d = curr.first,ci = curr.second;
			if (d>dist[ci])
			{
				continue;
			}
			F(j, 0, adjlist[ci].size()){
				ii next = adjlist[ci][j];
				if (dist[ci]+ next.second < dist[next.first])
				{
					dist[next.first] = dist[ci]+next.second;
					pq.push(ii(dist[next.first],next.first));
				}
			}
		}

		revDist[target]=0;
		pq.push(ii(0,target));
		
		while(!pq.empty()){
			ii curr = pq.top();
			pq.pop();

			int d = curr.first,ci = curr.second;
			if (d>revDist[ci])
			{
				continue;
			}
			F(j, 0, revAdjlist[ci].size()){
				ii next = revAdjlist[ci][j];
				if (revDist[ci]+ next.second < revDist[next.first])
				{
					revDist[next.first] = revDist[ci]+next.second;
					pq.push(ii(revDist[next.first],next.first));
				}
			}
		}
		int ans = -INF;
		F(i, 1, n+1){
			F(j, 0, adjlist[i].size()){
				ii curr = adjlist[i][j];
				int wt = curr.second,v= curr.first;
				if (dist[i]+wt+revDist[v]<=limit)
				{
					ans = max(ans,wt);
				}
			}
		}
		if (ans == -INF)
		{
			cout<<-1;
		}else{
			cout<<ans;
		}
		cout<<"\n";
	}

	return 0;
}