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

const int N = 1e5+5;
ll arr[N];
int n;

const int maxx = 5e6+10;
#define intt ll
intt trie[maxx][2], finish[maxx];
intt nxt = 1;
int bits = 41;

void insert (ll s){
    intt node = 0;
    for (int i = bits; i >= 0; i--) {
        ll val = ((1LL << i) & s) > 0;
        if(trie[node][val] == 0) {
            node = trie[node][val] = nxt;
            nxt++;
        } else {
            node = trie[node][val];
        }
    }
    finish[node] = 1;
    finish[nxt - 1] = 1;
}

intt find (ll s) {
    intt idx = 0;
    ll res = 0;
    for (int i = bits; i >= 0; i--) {
        ll val = ((1LL << i) & s) > 0;
        if (trie[idx][1 - val] == 0)
            idx = trie[idx][val];
        else {
            res |= (1LL << i);
            idx = trie[idx][1 - val];
        }
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n;
    ll x = 0, res = 0, cumf = 0;
    FOR(i, 0, n) {
        cin>>arr[i];
        x ^= arr[i];
    }
    insert(0LL);
    res = max(res, x);
    FOR(i, 0, n) {
        cumf ^= arr[i];
        res = max(res, find(cumf ^ x));
        insert(cumf);
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}