#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
#define iis pair<ii,int>
iis arr[N], arr2[N];
vector<iii> prospects;

const int FINDSIZE = N;
int p[FINDSIZE],sizes[FINDSIZE];

//if it is the representative then return itself otherwise return parent of it's immediate parent
int findSet(int i){
	return (p[i]==i)? i : p[i]=findSet(p[i]);
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

void join(int i, int j){
	if (!isSameSet(i,j))
	{
		int x = findSet(i),y = findSet(j);
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
	for(int i=0;i<FINDSIZE;i++){
		p[i] = i;
		sizes[i] = 1;
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    initialiseUnionFind();
    int n,u,v;
    cin>>n;

    FOR(i, 0, n) {
    	cin>>arr[i].ff.ff>>arr[i].ff.ss;
    	arr[i].ss = i;
    	arr2[i].ss = i;
    	arr2[i].ff.ss = arr[i].ff.ff;
    	arr2[i].ff.ff = arr[i].ff.ss;
    }
    sort(arr, arr+n);
    sort(arr2, arr2+n);
    ll ans = 0;
    FOR(i, 0, n-1) {
    	u = arr[i].ss; v = arr[i+1].ss;
    	prospects.push_back({abs(arr[i].ff.ff - arr[i+1].ff.ff), {u, v}});
    }
    FOR(i, 0, n-1) {
    	u = arr2[i].ss; v = arr2[i+1].ss;
    	prospects.push_back({abs(arr2[i].ff.ff - arr2[i+1].ff.ff), {u, v}});
    }
    sort(prospects.begin(), prospects.end());
    FOR(i, 0, prospects.size()) {
    	tie(u,v) = prospects[i].ss;
    	if(!isSameSet(u, v)) {
    		join(u, v);
    		ans += (ll)prospects[i].ff;
    	}
    }
    cout<<ans;

    return 0;
}