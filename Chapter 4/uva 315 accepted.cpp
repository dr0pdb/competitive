#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

vector<std::vector<int> > adjlist(105);
int n,dfs_num[105],dfs_low[105],dfsNumberCounter,dfs_parent[105],dfs_root,rootCounter;
bool isArticulate[105];

void dfs(int u){
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;

	F(i, 0, adjlist[u].size()){
		int v = adjlist[u][i];
		
		if (dfs_num[v] == -1)
		{
			dfs_parent[v] = u;

			if (u == dfs_root)
			{
				rootCounter++;
			}

			dfs(v);

			if (dfs_low[v] >= dfs_num[u])
			{
				isArticulate[u]=true;
			}

			dfs_low[u] = min(dfs_low[u],dfs_low[v]);

		}else if(v != dfs_parent[u]){
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	while(cin >> n && n){

		//resetting the values
		F(i, 0, n){
			adjlist[i].clear();
			dfs_num[i] = -1;
			dfs_low[i] = -1;
			dfs_parent[i] = i;
			isArticulate[i]= false; 
		}
		dfsNumberCounter = 0;

		//getting the input
		string input;
		while(getline(cin,input)){
			if (input == "0") break;

			istringstream iss(input);
			int u,v;
			iss>>u;
			u--;
			while(iss>>v){
				v--;
				adjlist[u].push_back(v);
				adjlist[v].push_back(u);
			}
		}

		//solve 
		F(i, 0, n){
			if (dfs_num[i] == -1)
			{
				dfs_root = i;
				rootCounter = 0;
				dfs(i);

				isArticulate[i] = (rootCounter > 1);				
			}
		}

		int counter=0;
		F(i, 0, n){
			if(isArticulate[i]){
				counter++;
			}
		}

		cout<<counter<<"\n";
	}
	return 0;
}