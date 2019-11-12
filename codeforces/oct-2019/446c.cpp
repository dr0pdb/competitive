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

const ll MOD = 1000000009;
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

const int BLOCK_SIZE = 550;
const int N = 3e5+5;
int n,q;
ll arr[N], fib[N] = {0}, cfib[N] = {0}, lazy[2][BLOCK_SIZE] = {0}, csum[BLOCK_SIZE] = {0};

void pre() {
    fib[1] = fib[2] = 1; cfib[1] = 1; cfib[2] = 2;
    FOR(i, 3, N) {
        fib[i] = fib[i-1] + fib[i-2]; verify(fib[i]);
        cfib[i] = cfib[i-1] + fib[i]; verify(cfib[i]);
    }
}

void relax_block(int block) {
    if(!lazy[0][block]) return;

    int lo = block * BLOCK_SIZE;
    arr[lo] += lazy[0][block]; verify(arr[lo]);
    arr[lo+1] += lazy[1][block]; verify(arr[lo+1]);
    ll prev[2] = {lazy[0][block], lazy[1][block]};
    
    for(int i = lo + 2; i < min(n, lo + BLOCK_SIZE); i++) {
        ll tmp = (prev[0] + prev[1])%MOD;
        arr[i] += tmp; verify(arr[i]);

        prev[0] = prev[1];
        prev[1] = tmp;
    }
    lazy[0][block] = lazy[1][block] = 0;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    clock_t clk = clock();
    
    cin>>n>>q;
    FOR(i, 0, n) {
        cin>>arr[i];
        int block = i / BLOCK_SIZE;
        csum[block] += arr[i]; verify(csum[block]);
    }
    pre(); int t,l,r;
    while(q--) {
        cin>>t>>l>>r; l--; r--;

        int start = l / BLOCK_SIZE * BLOCK_SIZE;
        if(start < l) start += BLOCK_SIZE;
        int firstend = min(r, start - 1);

        int endstart = r / BLOCK_SIZE * BLOCK_SIZE;
        if(endstart < l) endstart = l;
        // cout<<l<<" "<<firstend<<" boys "<<endstart<<" "<<r<<endl;

        if(t == 1) {
            FOR(i, l, firstend+1) {
                arr[i] += fib[i - l + 1]; verify(arr[i]);
                csum[i / BLOCK_SIZE] += fib[i - l + 1]; verify(csum[i / BLOCK_SIZE]);
            }

            for(int i = firstend+1; i < endstart; i += BLOCK_SIZE) {
                int block = i / BLOCK_SIZE;
                int lo = i - l + 1, hi = i + BLOCK_SIZE - l;
                // cout<<lo<<" lo and hi mate "<<hi<<endl;
                // cout<<"adding "<<cfib[hi]<<" - "<<cfib[lo-1]<<" to block "<<block<<endl; 
                csum[block] += (cfib[hi] - cfib[lo-1] + MOD); verify(csum[block]);
                lazy[0][block] += fib[lo]; verify(lazy[0][block]);
                lazy[1][block] += fib[lo + 1]; verify(lazy[1][block]);
            }

            if(!(l == endstart && r == firstend)) {
                FOR(i, endstart, r + 1) {
                   arr[i] += fib[i - l + 1]; verify(arr[i]);
                    csum[i / BLOCK_SIZE] += fib[i - l + 1]; verify(csum[i / BLOCK_SIZE]);
                }
            }
        } else {
            ll res = 0;
            relax_block(l / BLOCK_SIZE);
            relax_block(r / BLOCK_SIZE);

            FOR(i, l, firstend+1) {
                res += arr[i]; verify(res);
            }
            
            for(int i = firstend+1; i < endstart; i+= BLOCK_SIZE) {
                res += csum[i / BLOCK_SIZE];
                verify(res);
            }

            if(!(l == endstart && r == firstend)) {
                FOR(i, endstart, r + 1) {
                    res += arr[i]; verify(res);
                }
            }
            cout<<res<<endl;
        }
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}