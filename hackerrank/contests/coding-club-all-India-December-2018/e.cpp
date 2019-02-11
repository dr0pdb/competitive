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
#define printCase() "Case #" << caseNum << ": "

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

int n,m,t;
std::vector<pair<int, ii>> edges;
bool taken[100005];

const int FINDSIZE = 100005;
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
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
    cin>>n>>m>>t;
    memset(taken, false, sizeof(taken));
    initialiseUnionFind();

    int u,v,w;
    F(i, 0, m) {
    	cin>>u>>v>>w;
    	u--; v--;
    	edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end(), greater<pair<int, ii> >());
    int cnt = 0;
   	F(i, 0, m) {
   		u = edges[i].second.first; v = edges[i].second.second;
   		if(!isSameSet(u, v)) {
   			join(u, v);
   			cnt++;
   			taken[i]=true;
   		}
   		if(cnt == n-1) 
   			break;
   	}

   	cnt = 0;
   	RF(i, m-1, 0) {
   		if(taken[i])
   			continue;

   		w = edges[i].first;
   		if(w > t) {
   			break;
   		}

   		t -= w;
   		cnt++;
   	}
   	cout<<cnt;

    return 0;
}/*

*/
