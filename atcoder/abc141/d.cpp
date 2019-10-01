/**
    __author__ : srv_twry
**/

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
const ll INF = 1e15+5;
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

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}

bool ge(const ll& a, const ll& b) { return a >= b; }
bool le(const ll& a, const ll& b) { return a <= b; }
bool eq(const ll& a, const ll& b) { return a == b; }
bool gt(const ll& a, const ll& b) { return a > b; }
bool lt(const ll& a, const ll& b) { return a < b; }
int sgn(const ll& x) { return le(x, 0) ? eq(x, 0) ? 0 : -1 : 1; }
/*----------------------------------------------------------------------*/

const int N = 1e5+5;
int n,m; 
ll cost[N], p2[50];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 	p2[0] = 1LL;
 	FOR(i, 1, 51) {
 		p2[i] = p2[i-1] * 2LL;
 	}
 	cin>>n>>m;
    priority_queue<double> pq;
 	FOR(i, 0, n) {
 		cin>>cost[i];
 		pq.push(cost[i]);
 	}
 	while(!pq.empty() && m) {
 		double tp = pq.top(); pq.pop();
 		tp /= 2.0; m--;
 		if(abs(tp) > eps) {
 			pq.push(tp);
 		}
 	}
 	ll ans = 0;
 	while(!pq.empty()) {
 		double tmp = pq.top(); pq.pop();
 		ans += static_cast<ll>(tmp);
 	}
 	cout<<ans;
    return 0;
}