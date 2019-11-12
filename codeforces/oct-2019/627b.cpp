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

const int N = 2e5+5;
int n,k,a,b,q;
int arr[N];

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n, limit;

    FenwickTree(int n, int _limit) {
        this->n = n + 1;
        this->limit = _limit;
        bit.assign(n + 1, 0);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    // l and r should be given as 0 based indexes.
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    // idx as zero based.
    void add(int idx, int delta) {
        if(arr[idx] + delta > limit) {
            delta = max(0, limit - arr[idx]);
        }
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>k>>a>>b>>q;
    int tp, d, aa;
    FenwickTree ftb(n, b), fta(n, a);
    while(q--) {
        cin>>tp;
        if(tp == 1) {
            cin>>d>>aa; d--; 
            ftb.add(d, aa);
            fta.add(d, aa);
            arr[d] += aa;
        } else {
            cin>>d; d--;
            int res = 0;
            int idx = d - 1;
            if(idx >= 0) {
                res += ftb.sum(0, idx);
            }
            int idx2 = k + d - 1;
            if(idx2 < n - 1) {
                res += fta.sum(idx2 + 1, n - 1);
            }
            cout<<res<<endl;
        }
    }
   
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}