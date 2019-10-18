#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int K = 501;
int d[K][K], sums[K], cnt[K],n,u,v,x,m,k;
 
int find_t(int ind) {
	return upper_bound(sums, sums+k, ind) - sums;
}
 
const int FINDSIZE = 1e5+1;
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
    cin>>n>>m>>k;
    FOR(i, 0, k) cin>>cnt[i];
    sums[0] = cnt[0];
    FOR(i, 1, k) {
    	sums[i] = sums[i-1] + cnt[i];
    }
    FOR(i, 0, k) {
		FOR(j, 0, k) {
			d[i][j] = INF;
		}    	
    }
    initialiseUnionFind();
    bool poss = true;
    FOR(i, 0, m) {
    	cin>>u>>v>>x; u--; v--;
    	int ux = find_t(u); int vx = find_t(v);
		d[ux][vx] = min(d[ux][vx],x);
		d[vx][ux] = min(d[vx][ux],x);
    	if(x == 0) {
			join(u,v);
		}
    }
    FOR(i, 0, k) {
    	if(!poss) break;
    	int start = (i > 0) ? sums[i-1]: 0;
    	int end = sums[i], prnt = findSet(start);
    	FOR(j, start+1, end) {
    		if(findSet(j) != prnt) {
    			poss = false;
    			break;
    		}
    	}
    }
    if(!poss) {
    	cout<<"No";
    	return 0;
    }
    cout<<"Yes\n";
    FOR(i, 0, k) d[i][i]=0;
    FOR(p, 0, k) {
    	FOR(i, 0, k) {
    		FOR(j, 0, k) {
    			d[i][j] = min(d[i][j], d[i][p] + d[p][j]);
    		}
    	}
    }
    FOR(i, 0, k) {
    	FOR(j, 0, k) {
    		if(j) cout<<" ";
    		if(d[i][j] >= INF) {
    			d[i][j] = -1;
    		}
    		cout<<d[i][j];
    	}
    	cout<<endl;
    }
 
    return 0;
}
