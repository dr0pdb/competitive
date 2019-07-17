#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
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

const int N = 1e3+1;
iii peeps[N];
map<int, vi> m;
int allocation[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,k,profit=0,cnt=0; cin>>n;
    FOR(i, 0, n) {
    	cin>>peeps[i].ff.ss>>peeps[i].ff.ff;
    	peeps[i].ss = i;
    }
    sort(peeps, peeps+n);
    cin>>k; int tmp;
    FOR(i, 0, k) {
    	cin>>tmp;
    	m[tmp].push_back(i);
    }
    memset(allocation, -1, sizeof(allocation));
    RFOR(i, n-1, 0) {
    	int needed = peeps[i].ff.ss;
    	auto itr = m.lower_bound(needed);
    	if(itr != m.end()) {
    		allocation[peeps[i].ss] = itr->second.back();
    		cnt++;
    		profit += peeps[i].ff.ff;
    		itr->second.pop_back();
    		if(itr->second.empty()) {
    			m.erase(itr);
    		}
    	}
    }
    cout<<cnt<<" "<<profit<<endl;
    FOR(i, 0, n) {
    	if(allocation[i] == -1) continue;
    	cout<<i+1<<" "<<allocation[i]+1<<endl;
    }

    return 0;
}