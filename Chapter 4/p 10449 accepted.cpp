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

int dist[200+5];
int n,busyness[200+5],tn=1;
vector<vii> adjlist(200+5);

int main(){
	std::ios::sync_with_stdio(false);
	
	while(cin>>n){

		int b;
		F(i, 1, n+1){
			cin>>b;
			busyness[i]=b;
			dist[i]=INF;
			adjlist[i].clear();
		}

		int r,from,to;
		cin>>r;

		while(r--){
			cin>>from>>to;
			int distance = busyness[to]-busyness[from];
			distance*=(distance*distance);
			adjlist[from].push_back(ii(distance,to));
		}

		dist[1]=0;
		int q,finish;
		cin>>q;

		F(i, 1, n){
			F(u, 1, n+1){
				if (dist[u] ==INF)
				{
					continue;
				}
				F(j, 0, adjlist[u].size()){
					ii curr = adjlist[u][j];
					int d = curr.first;
					int v = curr.second;

					dist[v] = min(dist[v],dist[u] + d);
				}
			}
		}

		//checking for negative cycles
		F(u, 1, n+1){
			F(j, 0, adjlist[u].size()){
				if (dist[u]==INF)
				{
					continue;
				}
				ii curr = adjlist[u][j];
				int d = curr.first;
				int v = curr.second;

				if (dist[v] > dist[u] + d && dist[v]!=-1*INF)
				{
					dist[v] = -1*INF;
				}
			}
		}
		cout<<"Set #"<<tn++<<"\n";

		while(q--){
			cin>>finish;

			if (dist[finish]<3 || dist[finish] == INF)
			{
				cout<<"?\n";
			}else{
				cout<<dist[finish]<<"\n";
			}
		}
	}
	return 0;
}