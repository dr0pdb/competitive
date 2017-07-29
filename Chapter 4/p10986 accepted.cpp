#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

vector<vector<ii> > adjlist(20010);
int n,m,s,t;
int dist[20010];
int main(){
	std::ios::sync_with_stdio(false);
	int p;
	cin>>p;

	F(i, 1, p+1){
		
		cin>>n>>m>>s>>t;
		int from,to,wt;

		//clearing the values
		F(j, 0, n){
			adjlist[j].clear();	
			dist[j]=1000000;
		}

		F(j, 0, m){
			cin>>from>>to>>wt;
			adjlist[from].push_back(make_pair(to,wt));
			adjlist[to].push_back(make_pair(from,wt));
		}

		//solve
		priority_queue<ii, vector<ii> , greater<ii> > pq;
		pq.push(ii(0,s));
		dist[s]=0;

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
        if(dist[t] == 1000000){
            cout<<"Case #"<<i<<": "<<"unreachable"<<"\n";    
        }else{
            cout<<"Case #"<<i<<": "<<dist[t]<<"\n";
        }
		
	}
	
	return 0;
}

