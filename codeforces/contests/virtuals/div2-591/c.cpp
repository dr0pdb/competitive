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

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using maxpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using minpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int N = 2e5+5;
ll p[N],x,a,y,b,n;
ll k;

ll lcm(ll a, ll b)  {  
    return (a*b)/__gcd(a, b);
}

bool check(ll ticks) {
    ll ta = ticks / a;
    ll tb = ticks / b;
    ll commons = ticks / lcm(a, b);
    ll res = 0;
    FOR(i, 0, commons) {
        res += 1LL * (x + y) * p[i];
    }
    ta -= commons; tb -= commons;
    ll xx = x, yy = y;
    if(xx < yy) {
        swap(xx, yy);
        swap(ta, tb);
    }
    FOR(i, commons, commons + ta) {
        res += 1LL * xx * p[i];
    }

    FOR(i, commons + ta, commons + ta + tb) {
        res += 1LL * yy * p[i];
    }

    return res >= k;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q; cin>>q;
    while(q--) {
        cin>>n;
        FOR(i, 0, n) {
            cin>>p[i];
            p[i] /= 100;
        }
        sort(p, p+n, greater<ll>());
        cin>>x>>a>>y>>b>>k;
        ll lo = 1, hi = n, res = INF;
        while(lo <= hi) {
            ll mid = (lo + hi)/2;
            if(check(mid)) {
                res = min(res, mid);
                hi = mid - 1;
            } else lo = mid + 1;
        }
        if(res == INF) res = -1;
        cout<<res<<endl;
    }

    return 0;
}