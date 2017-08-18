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
int adjmat[105][105];
int main(){
	std::ios::sync_with_stdio(false);

	int t,n,r,cn=1;
	cin>>t;

	while(t--){
		cin>>n>>r;
		F(i, 0, n){
			F(j, 0, n){
				if (i==j)
				{
					adjmat[i][j]=0;
				}else{
					adjmat[i][j]=INF;	
				}
			}
		}

		int u,v;
		F(i, 0, r){
			cin>>u>>v;
			adjmat[u][v]=1;
			adjmat[v][u]=1;
		}

		int s,d;
		cin>>s>>d;

		//floyd marshall
		F(k, 0, n){
			F(i, 0, n){
				F(j, 0, n){
					adjmat[i][j] = min(adjmat[i][j],adjmat[i][k]+ adjmat[k][j]);
				}
			}
		}

		int ans=-1;
		F(i, 0, n){
			ans = max(ans, adjmat[s][i]+adjmat[i][d]);
		}

		cout<<"Case "<<cn++<<": "<<ans<<"\n";
	}
	return 0;
}

