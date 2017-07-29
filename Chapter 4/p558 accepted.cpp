#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef pair<int,ii> iii;

int main(){
	std::ios::sync_with_stdio(false);

	int t,n,m;
	cin>>t;

	while(t--){
		cin>>n>>m;

		vector<vector<ii> > adjlist(n);
		int x,y,wt;

		F(i, 0, m){
			cin>>x>>y>>wt;
			adjlist[x].push_back(ii(y,wt));
		}

		vi dist(n,1000000);
		dist[0]=0;

		//run bellman ford
		F(i, 0, n-1){
			F(j, 0, n){
				F(k, 0, adjlist[j].size()){
					ii v = adjlist[j][k];
					dist[v.first] = min(dist[v.first],dist[j]+v.second);
				}
			}
		}

		bool possible = false;
		F(j, 0, n){
			F(k, 0, adjlist[j].size()){
				ii v = adjlist[j][k];
				if (dist[v.first] > dist[j]+ v.second)
				{
					possible = true;
				}
			}
		}

		if (possible)
		{
			cout<<"possible"<<"\n";
		}else{
			cout<<"not possible"<<"\n";
		}
	}

	return 0;
}

