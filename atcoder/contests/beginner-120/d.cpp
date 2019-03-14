#include<bits/stdc++.h>
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

const ll FINDSIZE = 1e5+5;
ll p[FINDSIZE],sizes[FINDSIZE];

//if it is the representative then return itself otherwise return parent of it's immediate parent
ll findSet(ll i){
	return (p[i]==i)? i : p[i]=findSet(p[i]);
}

bool isSameSet(ll i, ll j){
	return findSet(i) == findSet(j);
}

void join(ll i, ll j){
	if (!isSameSet(i,j))
	{
		ll x = findSet(i),y = findSet(j);
		if(sizes[x] < sizes[y]){
			p[x] = y;
			sizes[y]+=sizes[x];
			
		}else{
			p[y] = x;
			sizes[x]+=sizes[y];
		}

	}
}

void initialiseUnionFind(){
	for(ll i=0;i<FINDSIZE;i++){
		p[i] = i;
		sizes[i] = 1;
	}
}

vll ans;
vector<lll> edges;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    initialiseUnionFind();

    ll n,m,u,v;
    cin>>n>>m;

    ans.resize(m);

    F(i, 0, m) {
    	cin>>u>>v; u--; v--;
    	edges.push_back({u, v});
    }

    ll curr = n*(n-1LL)/2LL;
	RF(i, m-1, 0) {
		ans[i] = curr;
		if(isSameSet(edges[i].first, edges[i].second)) continue;
		curr -= sizes[findSet(edges[i].first)]*1LL*sizes[findSet(edges[i].second)];
		join(edges[i].first, edges[i].second);
	}

	F(i, 0, m) {
		cout<<ans[i]<<endl;
	}

    return 0;
}/*

*/