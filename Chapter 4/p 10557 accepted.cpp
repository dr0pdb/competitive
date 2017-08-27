#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

#define INF 1000000000

/*
	The key idea is that if it's possible to visit the finish without dropping 
	at any point lower than 0 then it is winnable. Otherwise relax all the edges again n times
	If any edge can be relaxed that means there exists an energy replinishing cycle.
	So just check if from that relaxed edge we can visit finish by simple bfs.
*/

int n,wt,ne,to;
vector<vi> adjlist(105);
int evalue[105],dist[105];
bool visited[105];
int finish;

//returns whether the finish is visitable from u.
bool bfs(int u){
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(u);
	visited[u]=true;

	while(!q.empty()){
		int v = q.front();
		q.pop();
		visited[v] = true;

		F(i, 0, adjlist[v].size()){
			int z = adjlist[v][i];
			if (!visited[z])
			{	
				q.push(z);
			}
		}
	}
	return visited[finish];
}

int main(){
	std::ios::sync_with_stdio(false);
	
	while(cin>>n && n>0){
		F(i, 1, n+1){

			adjlist[i].clear();
			dist[i] = -1*INF;
			cin>>wt>>ne;
			evalue[i]=wt;
			F(j, 0, ne){
				cin>>to;
				adjlist[i].push_back(to);
			}
		}
		finish = n;
		dist[1]=100;
		bool visitable = false;

		F(i, 1, n){
			F(u, 1, n+1){
				if (dist[u]<=0)
				{
					continue;
				}
				F(j, 0, adjlist[u].size()){
					int v = adjlist[u][j];
					dist[v] = max(dist[v] , dist[u] + evalue[v]);
				}
			}
		}

		

		if (dist[finish] >=0)
		{
			visitable = true;
		}

		//relax again
		if (!visitable)
		{
			F(u, 1, n+1){
				if (dist[u]<=0)
				{
					continue;
				}
				F(j, 0, adjlist[u].size()){
					int v = adjlist[u][j];
					if (dist[v] < dist[u] + evalue[v] && bfs(u))
					{
						visitable = true;
						break;
					}
				}
			}
		}

		if (visitable)
		{
			cout<<"winnable\n";
		}else{
			cout<<"hopeless\n";
		}
	}	

	return 0;
}