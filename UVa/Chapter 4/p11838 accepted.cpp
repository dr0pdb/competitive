#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int n,m;
std::vector<std::vector<int> > adjlist(2010);
int num[2010],low[2010],visited[2010],dfsCounter,numberScc;
vi s;
bool scc;

void dfs(int u){
	
	if(!scc){
		return;
	}
	num[u]=low[u]= dfsCounter++;
	s.push_back(u);
	visited[u]= true;

	F(i, 0, adjlist[u].size()){
		int v = adjlist[u][i];
		
		if (num[v] == -1)
		{
			dfs(v);
		}	

		if (visited[v])
		{
			low[u] = min(low[u],low[v]);
		}
	}

	if (low[u]==num[u])
	{
		numberScc++;
		if (numberScc > 1)
		{
			scc = false;
			return;
		}

		while(true){
			int v = s.back();
			s.pop_back();
			visited[v]= false;

			if (u == v)
			{
				break;
			}
		}
	}
}


int main(){
	std::ios::sync_with_stdio(false);

	while(cin>>n>>m && n && m){

		//resetting the values
		F(i, 0, n){
			adjlist[i].clear();
			num[i]=-1;
			low[i]=0;
			visited[i]=false;

		}
		s.clear();
		scc = true;
		dfsCounter = 0;
		numberScc=0;

		//getting the input
		int v,w,p;
		F(i, 0, m){
			cin>>v>>w>>p;
            v--;
            w--;
			adjlist[v].push_back(w);
			if (p == 2)
			{
				adjlist[w].push_back(v);
			}
		}

		//solve
		F(i, 0, n){
			if (num[i] == -1)
			{
				dfs(i);
			}
		}

		//Result
		if (scc)
		{
			cout<<1<<"\n";
		}else{
			cout<<0<<"\n";
		}

	}

	return 0;
}

