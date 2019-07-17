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

string s[2];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,k,t,tp,val;
    cin>>n>>k>>s[0]>>s[1];
    queue<iii> q; // t, tp, val.
    q.push({0, {0, 0}});
    while(!q.empty()) {
    	iii curr = q.front(); q.pop();
    	t = curr.ff; tie(tp, val) = curr.ss;
    	if(val < t) continue;
    	if(t >= n) break;
    	if(val + k >= n) {
    		cout<<"YES";
    		return 0;
    	}
    	if(s[tp][val+1] == '-') {
    		q.push({t+1, {tp, val+1}});
    	}
    	if(val > 0 && s[tp][val-1] == '-')
    		q.push({t+1, {tp, val-1}});
    	if(s[1-tp][val+k] == '-') {
    		q.push({t+1, {1-tp, val+k}});
    	}
    }
    cout<<"NO";

    return 0;
}