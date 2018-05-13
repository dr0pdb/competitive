#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int n;
vector<vector<int> > adjlist(200);
int num[200],low[200],parent[200],dfsCounter;
vector<pair<int, int> > bridges(200);

void dfs(int u){
	num[u] = low[u] = dfsCounter++;

	F(i, 0, adjlist[u].size()){
		int v = adjlist[u][i];

		//unvisited , tree edge
		if (num[v] == -1)
		{
			parent[v] = u;

			dfs(v);

			if (low[v] > num[u])
			{
				int t1,t2;
				t1= min(u,v);
				t2 = max(u,v);
				bridges.push_back(make_pair(t1,t2));
			}
			low[u] = min(low[u],low[v]);
		}else if(parent[u] != v){
			//back edge
			low[u] = min(low[u],num[v]);	
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	while(cin>>n){

		//resetting the values
		F(i, 0, n){
			num[i]=-1;
			parent[i]=i;
			low[i]=0;
			adjlist[i].clear();

		}
		dfsCounter=0;
		bridges.clear();

		//getting the input
		int u,v;
		F(i, 0, n){
			cin>>u;
			string temps;
			cin>>temps;

			int k = temps[1]-'0';
			F(j, 0, k){
				cin>>v;
				adjlist[u].push_back(v);
				//adjlist[v].push_back(u);
			}

		}

		//solve
		F(i, 0, n){
			if (num[i] == -1)
			{
				dfs(i);
			}
		}
        sort(bridges.begin(),bridges.end());
		//printing the values
		cout<<bridges.size()<<" critical links\n";
		F(i, 0, bridges.size()){
			cout<<bridges[i].first<<" - "<<bridges[i].second<<"\n";
		}
		cout<<"\n";
	}

	return 0;
}

