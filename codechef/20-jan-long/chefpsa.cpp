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

const int nax = 2e5+5;
int arr[nax];
unordered_map<ll,int> freq;
ll fact[nax];

void pre() {
    fact[0] = 1;
    FOR(i, 1, nax) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

ll modInverse(ll a, ll m)
{
    return power(a, m - 2, m);
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    pre();
    int t,n; cin>>t;
    while(t--) {
        scanf("%d", &n);
        ll sm = 0; freq.clear();
        FOR(i, 0, 2*n) {
            scanf("%d", &arr[i]);
            sm += (ll)arr[i];
            freq[arr[i]]++;
        }
        ll target = sm / (n + 1);
        if(target * (n + 1) != sm || freq[target] < 2) {
            cout<<0<<endl;
            continue;
        }
        freq[target] -= 2;
        if(freq[target] == 0) {
            freq.erase(target);
        }
        ll res = fact[n - 1];
        for(auto a : freq) {
            ll comp = target - a.ff;
            if(comp < a.ff) continue;
            if(a.ff != comp) {
                ll f1 = a.ss, f2 = freq[comp];
                if(f1 != f2) {
                    res = 0;
                    break;
                }
                res *= power(2LL, f1, MOD); res %= MOD;
                res *= modInverse(fact[f1], MOD); res %= MOD;
            } else {
                ll f = a.ss;
                if(f & 1LL) {
                    res = 0;
                    break;
                }
                res *= modInverse(fact[f/2], MOD); res %= MOD;
            }
        }
        printf("%lld\n", res);
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}