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

const int N = 3e5+1;
int arr[N],minm[N];
set<int> s;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q,n; cin>>q;
    while(q--) {
        cin>>n; s.clear();
        FOR(i, 0, n+1) minm[i] = INF;

        FOR(i, 0, n) {
            cin>>arr[i];
            auto itr = s.upper_bound(arr[i]);
            if(itr != s.end()) {
                minm[arr[i]] = min(*itr, minm[arr[i]]);
            }
            s.insert(arr[i]);
        }
        int sz = s.size();
        int elem[sz], ps[sz]; int idx = 0;
        for(int e : s) {
            elem[idx] = e;
            ps[idx++] = minm[e]; 
        }
        int dp[sz+1]; // dp[i] = min element that needs to be put in the back when i smallest elements are absent.
        dp[sz] = INF;
        RFOR(i, sz-1, 0) {
            dp[i] = min(dp[i+1], ps[i]);
        }
        int res = INF;
        
        FOR(l, 0, sz) {
            int pos = lower_bound(elem, elem + sz, dp[l]) - elem;
            int r = sz - pos;
            res = min(res, (int)l + r);
        }
        cout<<res<<endl;
    }

    return 0;
}