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

const int nax = 1e6+5;
int arr[nax];

// stores smallest prime factor for every number
int spf[nax];
int cnt[nax];
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < nax; i++)
        spf[i] = i;

    for (int i = 4; i < nax; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < nax; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < nax; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void getFactorization(int x)
{
    while (x != 1)
    {
        int c = 0, p = spf[x];
        while(x % p == 0) {
            x = x / spf[x];
            c++;
        }
        cnt[p] = max(cnt[p], c);
    }
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    memset(cnt, 0, sizeof(cnt));
    sieve();
    int n,k; cin>>n>>k;
    FOR(i, 0, n) {
        cin>>arr[i];
        getFactorization(arr[i]);
    }
    bool ok = true;
    while(k > 1) {
        ok &= (cnt[spf[k]] > 0);
        cnt[spf[k]]--;
        k /= spf[k];
    }
    if(ok) cout<<"Yes";
    else cout<<"No";
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}