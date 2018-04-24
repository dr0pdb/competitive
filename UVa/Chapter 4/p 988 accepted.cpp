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

int n;
bool visited[1000];
stack<int> topSort;
vi adjlist[1000];

void dfs(int index){
	visited[index]=true;

	F(i, 0, adjlist[index].size()){
		if (!visited[adjlist[index][i]])
		{
			dfs(adjlist[index][i]);
		}
	}
	topSort.push(index);
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	

	bool first=true;

	while(cin>>n){
		memset(visited,false,sizeof(visited));
		F(i, 0, n){
			adjlist[i].clear();
		}
		if (!first)
		{
			cout<<"\n";
		}
		first=false;
		int out;

		F(i, 0, n){
			cin>>out;
			int v;
			F(j, 0, out){
				cin>>v;
				adjlist[i].push_back(v);
			}
		}

		dfs(0);
		int dp[n];
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		int ans = 0;
		while(!topSort.empty()){
			int u= topSort.top();
			topSort.pop();
			F(i, 0, adjlist[u].size()){
				int v = adjlist[u][i];
				dp[v]+=dp[u];
			}
			if (!adjlist[u].size())
			{
				ans+=dp[u];
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}