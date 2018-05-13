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

#define INF 1000000000

int main(){
	std::ios::sync_with_stdio(false);

	int c,s,q,cn=1;
	
	while(cin>>c>>s>>q && c && s && q){
		int adjmat[c][c];
		F(i, 0, c){
			F(j, 0, c){
				adjmat[i][j]=INF;
			}
		}

		int u,v,wt;
		F(i, 0, s){
			cin>>u>>v>>wt;
			u--;
			v--;
			adjmat[u][v]=wt;
			adjmat[v][u]=wt;
		}

		//bellman-ford
		F(k, 0, c){
			F(i, 0, c){
				F(j, 0, c){
					adjmat[i][j] = adjmat[j][i]= min(adjmat[i][j],max(adjmat[i][k],adjmat[k][j]));
				}
			}
		}
		if (cn>1)
		{
			cout<<"\n";	
		}
		cout<<"Case #"<<cn++<<"\n";
		F(i, 0, q){
			int from,to;
			cin>>from>>to;
			from--;
			to--;
			if (adjmat[from][to] == INF)
			{
				cout<<"no path\n";
			}else{
				cout<<adjmat[from][to]<<"\n";	
			}
		}
		
	}
	return 0;
}

