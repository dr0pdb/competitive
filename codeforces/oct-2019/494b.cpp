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

inline int add(int a, int b, int p = MOD){ ll c = a + b; if(c >= p) c -= p; return c;}
inline int sub(int a, int b, int p = MOD){ int c = a - b; if(c < 0) c += p; return c;}
inline int mul(int a, int b, int p = MOD){ return (a * 1ll * b) % p;}
/*----------------------------------------------------------------------*/

vi prefix(string s) {
    s.push_back('#');
    int n = s.size();
    vi p(s.size());
    FOR(i, 1, n) {
        int j = p[i - 1];
        while(j > 0 && s[i] != s[j]) j = p[j - 1];
        if(s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

vii kmp(string txt, string pat, vi &p) {
    pat.push_back('#'); vii res;
    int nn = txt.size(), j = 0; int n = pat.size(); n--;
    FOR(i, 0, nn) {
        while(j > 0 && txt[i] != pat[j]) j = p[j-1];
        if(txt[i] == pat[j]) j++;
        if(j == n) {
            res.push_back({i-j+1, i});
        }
    }
    return res;
}

bool cmp(ii a, ii b) {
    if(a.ss != b.ss) return a.ss < b.ss;
    return a.ff < b.ff;
}

const int N = 1e5+5;
bool good[N];
int a[N] = {0}, q1[N] = {0}, q2[N] = {0};

int bsearch(vii &pos, int start) {
    int lo = 0, hi = pos.size(), res = -1; hi--;
    while(lo <= hi) {
        int mid = (lo + hi)/ 2;
        if(pos[mid].ss < start) {
            lo = mid + 1;
            res = max(res, mid);
        } else hi = mid - 1;
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    string s,t; cin>>s>>t;
    vi pref = prefix(t);
    vii pos = kmp(s, t, pref);
    sort(all(pos), cmp);
    int sz = pos.size();
    
    memset(good, false, sizeof(good));
    FOR(i, 0, pos.size()) {
        good[pos[i].ss + 1] = true;
    }

    FOR(i, 1, s.size() + 1) {
        if(!good[i]) a[i] = a[i-1];
        else {
            a[i] = add(i - (int)t.size() + 1, q2[i - (int)t.size()]);
        }

        q1[i] = add(q1[i-1], a[i]);
        q2[i] = add(q2[i-1], q1[i]);
    }
    cout<<q1[s.size()];
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}