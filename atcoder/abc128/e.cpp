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
const ll INF = 1e9+10;
const double eps = 1e-9;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

const int N = 2e5+5;
set<int> blocked;
vector<iii> events;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,d,q,s,t,x; cin>>n>>q;
    FOR(i, 0, n) {
    	cin>>s>>t>>x;
    	events.push_back({s - x, {1, x}});
    	events.push_back({t - x, {-1, x}});
    }
    sort(events.begin(), events.end());
    int idx = 0;
    FOR(i, 0, q) {
    	cin>>d;
    	while(idx < events.size() && events[idx].ff <= d) {
    		int xx = events[idx].ss.ss;
    		if(events[idx].ss.ff == 1) {
    			blocked.insert(xx);
    		} else {
    			auto itr = blocked.find(xx);
    			blocked.erase(itr);
    		}
    		idx++;
    	}
    	if(blocked.empty()) {
    		cout<<-1<<endl;
    	} else {
    		cout<<*blocked.begin()<<endl;
    	}
    }

    return 0;
}