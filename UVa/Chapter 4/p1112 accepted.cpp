#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

vector<vector<ii> > adjlist(110);
int n,m,e,t;
int dist[110];

int main(){
	std::ios::sync_with_stdio(false);
	int p;
	cin>>p;

	while(p--){
		//cin.ignore();
		
		//getting the input
		cin>>n>>e>>t>>m;
		e--;

		//clearing the values
		F(j, 0, n){
			adjlist[j].clear();	
			dist[j]=1000000;
		}

		int from,to,wt;
		while(m--){
			cin>>from>>to>>wt;
			from--;
			to--;
			adjlist[to].push_back(ii(from,wt));
		}

		//solve
		priority_queue<ii, vector<ii> , greater<ii> > pq;
		pq.push(ii(0,e));
		dist[e]=0;

		while(!pq.empty()){
			ii front = pq.top();
			pq.pop();

			int d = front.first;
			int u = front.second;
			if (dist[u] < d)	
			{
				continue;
			}
			F(j, 0, adjlist[u].size()){
				ii v = adjlist[u][j];
				if (dist[u]+ v.second < dist[v.first])
				{
					dist[v.first] = dist[u]+ v.second;
					pq.push(ii(dist[v.first],v.first));
				}
			}
		}
        
		int answer=0;
		F(i, 0, n){
			if (dist[i] <= t)
			{
				answer++;
			}
		}
		cout<<answer<<"\n";
		if (p)
		{
			cout<<"\n";
		}
	}
	
	return 0;
}

