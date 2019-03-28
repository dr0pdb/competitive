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
const int p = 31;
const int p2 = 71;
const ll m = 1e9+9;
ll p_pow[N], p2_pow[N];

void preProcess() {
    p_pow[0] = p; p2_pow[0]=p2;
    for (int i = 1; i < N; i++) {
        p_pow[i] = (p_pow[i-1] * p) % m;
        p2_pow[i] = (p2_pow[i-1] * p2) % m;
    }
}

int count_unique_substrings(string const& s, int l) {
    int n = s.size();
    vector<long long> h(n + 1, 0), h2(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
        h2[i+1] = (h2[i] + (s[i] - 'a' + 1) * p2_pow[i]) % m;
    }

    int cnt = 0;
    set<pair<ll,ll> > hs;
    for (int i = 0; i <= n - l; i++) {
        long long cur_h = (h[i + l] + m - h[i]) % m;
        cur_h = (cur_h * p_pow[n-i-1]) % m;
        long long cur_h_2 = (h2[i + l] + m - h2[i]) % m;
        cur_h_2 = (cur_h_2 * p2_pow[n-i-1]) % m;
        hs.insert({cur_h, cur_h_2});
    }
    return hs.size();
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n,k;
    cin>>t;
    string s;

    preProcess();
    while(t--) {
    	cin>>n>>k>>s;
    	cout<<count_unique_substrings(s, k);
    	if(t) cout<<endl;
    }

    return 0;
}