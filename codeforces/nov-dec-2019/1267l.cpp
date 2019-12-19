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
#define verify(x) if(x >= MOD) x -= MOD;

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

vector<char> countSort(vector<char> alphs) {
    int freq[26] = {0};
    vector<char> res;

    for(char c : alphs) {
        freq[c - 'a']++;
    }

    FOR(i, 0, 26) {
        while(freq[i]) {
            res.push_back((char)(i + 'a'));
            freq[i]--;
        }
    }

    return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int n,l,k; cin>>n>>l>>k;
    vector<char> v(n*l);
    k--;
    FOR(i, 0, n*l) {
        cin>>v[i];
    }
    v = countSort(v);
    vector<string> ans(n);
    int lasti = 0, idx = 0, nxt = 0;
    FOR(i, 0, n*l) {
        if(ans[idx].size() == l) {
            nxt = i;
            break;
        }
        ans[idx].push_back(v[i]);
        if(i && v[i] != v[i-1]) lasti = idx;
        if(lasti == k) {
            nxt = i + 1;
            break;
        }
        if(idx == k) idx = lasti;
        else idx++;
    }
    while(ans[k].size() < l) ans[k].push_back(v[nxt++]);
    FOR(i, 0, n) {
        while(ans[i].size() < l) ans[i].push_back(v[nxt++]);
        cout<<ans[i]<<endl;
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}