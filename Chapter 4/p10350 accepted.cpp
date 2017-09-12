#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int n,m;
stack<int> topsort;

void dfs(int u,const vector<vector<ii> >  &adjlist, vector<bool> &visited){
	visited[u]=true;

	F(i, 0, adjlist[u].size()){
		ii v = adjlist[u][i];
		if(!visited[v.first]){
			dfs(v.first,adjlist,visited);
		}
	}
	
	topsort.push(u);
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	string name;
	while(cin>>name){

		cin>>n>>m;
		vector<std::vector<ii> >  adjlist(n*m);
		F(i, 0, n-1){
			F(j, 0, m){
				F(k, 0, m){
					int times;
					cin>>times;
					adjlist[i*m+j].push_back(ii((i+1)*m+k,times));
				}
			}
		}

		std::vector<bool> visited(n*m,false);
		F(i, 0, n*m){
			if (!visited[i])
			{
				dfs(i,adjlist,visited);
			}
		}
		
		int ans = INF;
		std::vector<int> dist(n*m,INF);
		while(!topsort.empty()){
			int curr = topsort.top();
			topsort.pop();

			//ground floor
			if (curr<m)
			{
				dist[curr]=0;
			}

			//topfloor
			if (curr>=(n-1)*m)
			{
				ans = min(ans,dist[curr]);
			}

			//in-between
			//relaxing the edge
			F(i, 0, adjlist[curr].size()){
				ii v = adjlist[curr][i];
				dist[v.first] = min(dist[v.first],dist[curr]+v.second);
			}
		}

		ans+=2*(n-1);
		cout<<name<<"\n"<<ans<<"\n";
	}

	return 0;
}