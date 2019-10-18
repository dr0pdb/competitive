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
const ll INF = 1e18+1;
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

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 1001;
ll mat[N][N];
ll row[N] = {0}, col[N] = {0}, totr = 0, totc = 0;
vll a, b;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,m,k,p; cin>>n>>m>>k>>p;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin>>mat[i][j];
            row[i] += mat[i][j];
            col[j] += mat[i][j];
        }
    }
    maxpq<ll> rpq, colpq;
    FOR(i, 0, n) rpq.push(row[i]);
    FOR(i, 0, m) colpq.push(col[i]);
    a.resize(k + 1, 0); b.resize(k + 1, 0);
    FOR(l, 1, k + 1) {
        ll curr = rpq.top(); rpq.pop();
        a[l] += a[l-1] + curr;
        rpq.push(curr - p * m);

        curr = colpq.top(); colpq.pop();
        b[l] += b[l-1] + curr;
        colpq.push(curr - p * n);
    }
    ll res = -INF;
    FOR(i, 0, k+1) {
        res = max(res, a[i] + b[k-i] - (p * (k - i) * i));
    }
    cout<<res;
    return 0;
}