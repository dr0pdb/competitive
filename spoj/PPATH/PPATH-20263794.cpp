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

const int N = 1e4;
bitset<N> bs;
vi primes;
int nprimes=0;
map<int,int> ind;
vi adjlist[1200];

bool adjacent(int a, int b){
	int counter=0;
	while(a){
		if(a%10	!= b%10){
			counter++;
		}
		a/=10;
		b/=10;
	}
	return counter==1;
}

void sieve(){
	bs.set();
	bs[0]=0;
	bs[1]=0;

	F(i, 2, N){
		if (bs[i])
		{
			if (i>=1000)
			{
				primes.push_back(i);
				ind[i]=nprimes++;
			}
			for (ll j = i*i; j < N; j+=i)
			{
				bs[j]=0;
			}
		}
	}
}

void buildGraph(){
	F(i, 0, primes.size()){
		F(j, i+1, primes.size()){

			if (adjacent(primes[i],primes[j]))
			{
				adjlist[i].push_back(j);
				adjlist[j].push_back(i);
			}
		}
	}
}

int main(){
 	// std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	sieve();

	buildGraph();
	vi dist;
	bool visited[1200];
 	int t;
 	t = nextint();

 	while(t--){
 		int a,b;
 		a = nextint(),b = nextint();
 		dist.assign(1200, INF);
 		memset(visited,false,sizeof(visited));
 		dist[ind[a]] = 0;
 		visited[ind[a]]=true;
 		queue<int> q;
 		q.push(ind[a]);

 		while(!q.empty()){
 			int curr = q.front();
 			q.pop();

 			visited[curr]=true;
 			F(i, 0, adjlist[curr].size()){
 				int v= adjlist[curr][i];
 				if (!visited[v])
 				{
 					dist[v] = min(dist[v],dist[curr]+1);
 					visited[v]=true;
 					q.push(v);
 				}
 			}
 		}
 		if (dist[ind[b]]==INF)
 		{
 			printf("Impossible\n");
 		}else{
 			printf("%d\n",dist[ind[b]]);
 		}
 	}
	return 0;
}
