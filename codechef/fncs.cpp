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

const int block = 320;
const int N = 1e5+5;
ull arr[N],n;
ii func[N];
ll cnt[block][N]; // count the number of funcs in the block including pos in their [L, R].
ull csum[block]; // sum of function values of a block.

struct FenwickTree {
    vector<ull> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTree(ull a[], ull nn)
        : FenwickTree(nn) {
        for (size_t i = 0; i < nn; i++)
            add(i, a[i]);
    }

    ull sum(int idx) {
        ull ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    // l and r should be given as 0 based indexes.
    ull sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    // idx as zero based.
    void add(int idx, ll delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

void pre(FenwickTree &ft) {
    memset(cnt, 0, sizeof(cnt));
    memset(csum, 0, sizeof(csum));

    for(int i = 0; i < n; i += block) {
        int bn = i / block;

        FOR(j, i, min((int)n, i + block)) {
            cnt[bn][func[j].ff]++;
            cnt[bn][func[j].ss + 1]--;
        }

        FOR(j, 1, n) {
            cnt[bn][j] += cnt[bn][j-1];
        }
    }

    FOR(i, 0, n) {
        int bn = i / block;

        ull res = ft.sum(func[i].ff, func[i].ss);
        csum[bn] += res;
    }
}

void update(FenwickTree &ft, int idx, ll val) {
    ll delta = val - arr[idx];
    arr[idx] = val;
    ft.add(idx, delta);

    for(int i = 0; i < n; i += block) {
        int bn = i / block;
        csum[bn] += delta * cnt[bn][idx];
    }
}

ull query(FenwickTree &ft, int lo, int hi) {
    ull res = 0;

    for(int i = lo; i <= hi;) {
        if(i % block == 0 && i + block - 1 <= hi) { // complete block.
            res += csum[i / block];
            i += block;
        } else {
            res += ft.sum(func[i].ff, func[i].ss);
            i++;
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
    FOR(i, 0, n) cin>>arr[i];
    FOR(i, 0, n) {
        cin>>func[i].ff>>func[i].ss;
        func[i].ff--; func[i].ss--;
    }
    FenwickTree ft(arr, n);
    pre(ft);

    // cout<<"csum and cnt\n";
    // for(int i = 0; i < n; i+=block) {
    //     cout<<"block number: "<<i/block<<endl;
    //     cout<<"csum: "<<csum[i / block]<<"\n cnt: ";
    //     FOR(j, 0, n) {
    //         cout<<j<<" : "<<cnt[i/block][j]<<"   ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;

    int q,t,x,y; cin>>q;
    while(q--) {
        cin>>t>>x>>y; x--;
        if(t == 1) {
            update(ft, x, y);
        } else {
            y--;
            cout<<query(ft, x, y)<<endl;
        }
    }
   
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}