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
const ll INF = 1e15+5;
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

const int N = 501;
ll dist[N][N],x[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n; cin>>n; 
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin>>dist[i][j];
        }
    }
    FOR(i, 0, n) {
        cin>>x[i]; x[i]--;
    }
    vll ans;
    bool pres[N]; memset(pres, false, sizeof(pres));
    RFOR(l, n-1, 0) {
        int k = x[l];
        pres[k] = true;
        ll res = 0;
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                if(i == j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                if(pres[i] && pres[j])
                    res += dist[i][j];
            }
        }
        ans.push_back(res);
    }
    reverse(ans.begin(), ans.end());
    for(ll res : ans) {
        cout<<res<<" ";
    }
    return 0;
}