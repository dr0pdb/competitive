#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

int n,m,k,u,v,w;
const int N = 1e5+5;
bool special[N];
vector<iii> edges;

const int FINDSIZE = N;
int p[FINDSIZE],sizes[FINDSIZE], cnt[FINDSIZE];
bool done = false;

//if it is the representative then return itself otherwise return parent of it's immediate parent
int findSet(int i){
	return (p[i]==i)? i : p[i]=findSet(p[i]);
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

bool join(int i, int j){
	if (!isSameSet(i,j))
	{
		int x = findSet(i),y = findSet(j);
		if(sizes[x] < sizes[y]){
			p[x] = y;
			sizes[y]+=sizes[x];
			cnt[y] += cnt[x];
		}else{
			p[y] = x;
			sizes[x]+=sizes[y];
			cnt[x]+=cnt[y];
		}

		if(cnt[x] == k || cnt[y] == k) {
			done = true;
		}

		return true;
	}

	return false;
}

void initialiseUnionFind(){
	for(int i=0;i<FINDSIZE;i++){
		p[i] = i;
		sizes[i] = 1;
		cnt[i]= (special[i]) ? 1 : 0;
	}
}


int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    cin>>n>>m>>k;
    memset(special, false, sizeof(special));

    F(i, 0, k) {
    	cin>>u;
    	u--; special[u]=true;
    }

    F(i, 0, m) {
    	cin>>u>>v>>w;
    	u--; v--;
    	edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());
    initialiseUnionFind();
    ll ans = -1;
    F(i, 0, m) {
    	if(done) {
    		break;
    	}

    	u = edges[i].second.first, v = edges[i].second.second;
    	w = edges[i].first;

    	if(join(u, v)) {
    		ans = w;
    	}
    }
    F(i, 0, k) {
    	if (i)
    	{
    		cout<<" ";
    	}
    	cout<<ans;
    }

    return 0;
}/*

*/
