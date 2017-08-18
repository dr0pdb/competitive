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
	//std::ios::sync_with_stdio(false);

	int adjmat[100][100];
	bool present[100];
	int u,v,cn=1;
		

	while(cin>>u>>v && u && v){
		memset(present,false,sizeof(present));

		F(i, 0, 100){
			F(j, 0, 100){
				adjmat[i][j]=INF;
			}
		}

		u--;
		v--;
		adjmat[u][v]=1;
		present[u]=true;
		present[v]=true;
		while(cin>>u>>v && u && v){
			u--;
			v--;
			adjmat[u][v]=1;
			present[u]=true;
			present[v]=true;
		}

		//counting the number of nodes
		int nn=0;
		F(i, 0, 100){
			if (present[i])
			{
				nn++;
			}
		}

		//floyad marshall
		F(k, 0, 100){
			F(i, 0, 100){
				F(j, 0, 100){
					adjmat[i][j]= min(adjmat[i][j],adjmat[i][k]+adjmat[k][j]);
				}
			}
		}

		double sum=0.0;

		F(i, 0, 100){
			F(j, 0, 100){
				if (i!=j && adjmat[i][j] != INF)
				{
					sum+=adjmat[i][j];
				}
			}
		}
		printf("Case %d: average length between pages = %.3f clicks\n",cn++,sum/(nn*(nn-1)));
	}
	return 0;
}

