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

struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0); // initialize with freq 0.
    int tm = (tl + tr) / 2;
    return new Vertex(build(tl, tm), build(tm+1, tr));
}

// returns the k-th largest element.
int query(Vertex* rq, Vertex* lq, int tl, int tr, int k) {
    if (tl == tr) {
        assert(k == 1);
        return tl;
    }

    int tm = (tl + tr) / 2;

    int leftcap = (rq->l->sum - lq->l->sum);
    if(leftcap >= k) {
        return query(rq->l, lq->l, tl, tm, k);
    }
    return query(rq->r, lq->r, tm+1, tr, k - leftcap);
}

Vertex* update(Vertex* v, int tl, int tr, int pos) {
    if (tl == tr)
        return new Vertex(1); // mark as present.
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos));
}

const int N = 1e5+5;
int arr[N];
map<int, int> numtoidx;
vi idxtonum;
vector<Vertex*> roots;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int n,m; cin>>n>>m;
    FOR(i, 0, n) {
        cin>>arr[i];
        numtoidx[arr[i]] = 0;
    }
    int cnt = 0;
    for(auto &itr : numtoidx) {
        itr.ss = cnt++;
        idxtonum.push_back(itr.ff);
    }
    roots.push_back(build(0, n-1));
    FOR(i, 0, n) {
        roots.push_back(update(roots.back(), 0, n-1, numtoidx[arr[i]]));
    }
    int l,r,k;
    while(m--) {
        cin>>l>>r>>k;
        cout<<idxtonum[query(roots[r], roots[l-1], 0, n-1, k)]<<endl;
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}
