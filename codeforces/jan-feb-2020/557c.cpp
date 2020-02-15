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

const int nax = 1e5+5;
ii arr[nax];
map<int,int> freq;

bool cmp(ii a, ii b) {
    return a.ss < b.ss;
}

struct FenwickTree
{
    vector<int> bit; // binary indexed tree
    int sz;

    FenwickTree(int sz2)
    {
        this->sz = sz2 + 1;
        bit.assign(sz2 + 1, 0);
    }

    FenwickTree(vector<int> a)
        : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    // l and r should be given as 0 based indexes.
    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    // idx as zero based.
    void add(int idx, int delta)
    {
        for (++idx; idx < sz; idx += idx & -idx)
            bit[idx] += delta;
    }
};

unordered_map<int,vi> idxs;

int n;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    cin>>n;
    FOR(i, 0, n) {
        cin>>arr[i].ff;
        freq[arr[i].ff]++;
    }
    FOR(i, 0, n) cin>>arr[i].ss;
    sort(arr, arr+n, cmp);
    FOR(i, 0, n) {
        idxs[arr[i].ff].pb(i);
    }
    int g = 0, gcost = 0;
    FenwickTree costs(n), present(n);
    FOR(i, 0, n) {
        costs.add(i, arr[i].ss);
        present.add(i, 1);
    }
    int res = INT_MAX;
    for(auto itr = freq.rbegin(); itr != freq.rend(); ++itr) {
        // treat current val as the max.
        int l = itr -> ff; int cnt = itr->ss;

        for(int idx : idxs[l]) {
            costs.add(idx, -arr[idx].ss);
            present.add(idx, -1); // mark as removed.
        }
        
        int toremove = max(0, n - g - cnt - cnt + 1);
        if(toremove) {
            // find smallest position in the present F.T with value toremove
            int lo = 0, hi = n - 1, pos = n - 1;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                if(present.sum(mid) < toremove) {
                    lo = mid + 1;
                } else {
                    pos = min(mid, pos);
                    hi = mid - 1;
                }
            }
            res = min(res, gcost + costs.sum(pos));
        } else {
            res = min(res, gcost); // only remove the greater ones.
        }

        // update trees
        for(int idx : idxs[l]) {
            g++;
            gcost += arr[idx].ss;
        }
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}