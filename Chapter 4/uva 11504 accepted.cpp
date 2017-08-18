#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define mes(i,a) memset(a,i,sizeof(a))
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

vi alist[100000];
vi revalist[100000];

void fillOrder(int index, bool visited[],stack<int> &s){
	visited[index] = true;

	F(i, 0, alist[index].size()){
		int curr = alist[index][i];
		if (!visited[curr])
		{
			fillOrder(curr, visited, s);
		}
	}
	s.push(index);
}

void dfs(int index,bool visited[]){
	visited[index]=true;

	F(i, 0, alist[index].size()){
		int curr = alist[index][i];
		if (!visited[curr])
		{
			dfs(curr, visited);
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	int t,n,m;
	cin>>t;

	while(t--){
		cin>>n>>m;

		F(i, 0, n){
			alist[i].clear();
			revalist[i].clear();
		}


		int u,v;
		F(i, 0, m){
			cin>>u>>v;
			u--;
			v--;
			alist[u].push_back(v);
			revalist[v].push_back(u);
		}

		//dfs on the  graph
		stack<int> s;
		bool visited[n]={false};
		F(i, 0, n){
			if (!visited[i])
			{
				fillOrder(i,visited,s);
			}
		}

		//second dfs on the graph in the reverse postorder.
		int scc=0;
		mes(false, visited);
		while(!s.empty()){
			int v = s.top();
			s.pop();

			if (!visited[v])
			{
				scc++;
				dfs(v,visited);
			}
		}
		cout<<scc<<"\n";
	}
	return 0;
}