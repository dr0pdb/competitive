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

vi prefix(string &s) {
    int n = s.size();
    vi ret(n);
    FOR(i, 1, n) {
        int j = ret[i - 1];
        while(j > 0 && s[j] != s[i]) j = ret[j - 1];
        if(s[i] == s[j]) j++;
        ret[i] = j;
    }
    return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
   
    string s; cin>>s; int n = s.size();
    vi pref = prefix(s);
    vector<bool> valid(n + 1);
    int vcount = 1;
    valid[n] = true;
    int idx = pref[n - 1];
    while(idx > 0) {
        vcount++;
        valid[idx] = true;
        idx = pref[idx - 1];
    }
    vi ans(s.size() + 1);
    FOR(i, 0, s.size()) ans[pref[i]]++;
    RFOR(i, n-1, 1) {
        ans[pref[i-1]] += ans[i];
    }
    FOR(i, 1, n+1) ans[i]++;
    cout<<vcount<<endl;
    FOR(i, 1, n+1) {
        if(!valid[i]) continue;
        cout<<i<<" "<<ans[i]<<endl;
    }
    cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}