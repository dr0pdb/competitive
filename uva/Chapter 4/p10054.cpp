#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 10000000+10
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int leftChild(int p ){return p<<1;}
int rightChild(int p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
/*----------------------------------------------------------------------*/

const int N=100+10;
vii adjlist[N];

// bool visited[50+10];
int indeg[N];
list<int> cyc;

void EulerTour(list<int>:: iterator i, int u){
	F(j, 0, adjlist[u].size()){
		ii &v = adjlist[u][j];
		if (v.second)
		{
			v.second = 0;
			F(k, 0, adjlist[v.first].size()){
				ii &uu = adjlist[v.first][k];
				if (uu.first == u && uu.second)
				{
					uu.second = 0;
					break;
				}
			}
			EulerTour(cyc.insert(i, u), v.first);
		}
	}
}

int main(){
 	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int t,e;
	cin>>t;
	F(tn,1,t+1){
		cin>>e;
		F(i, 0, N){
			adjlist[i].clear();
			indeg[i]=0;
		}
		// memset(visited,false,sizeof(visited));

		int u,v;
		F(i, 0, e){
			cin>>u>>v;
			
			adjlist[u].push_back(ii(v,1));
			adjlist[v].push_back(ii(u,1));
			// visited[u]=false;
			// visited[v]=false;
			indeg[u]++;
			indeg[v]++;
		}

		int oddcount=0,start=-1;
		F(i, 1, 50+1){
			if (indeg[i]%2==1)
			{
				oddcount++;
				break;
			}else if (indeg[i] && start==-1)
			{
				start = i;
			}
		}
		cout<<"Case #"<<tn<<"\n";
		if (oddcount!=0)
		{
			cout<<"some beads may be lost\n\n";
			continue;
		}

		cyc.clear();
		EulerTour(cyc.begin(),start);
		// cout<<cyc.size()<<endl;
		vi vs;
		for (list<int>::iterator it = cyc.begin(); it != cyc.end(); it++){
			vs.push_back(*it);
		}
			
		F(i, 0, vs.size()-1){
			cout<<vs[i]<<" "<<vs[i+1]<<"\n";
		}
		cout<<vs[vs.size()-1]<<" "<<vs[0]<<"\n";
		cout<<"\n";
	}
	

	return 0;
}

