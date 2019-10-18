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
/*----------------------------------------------------------------------*/

const int N = 5e4+1;
int v[N];
double ex[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n,k; cin>>t;
    FOR(tn, 1, t+1) {
        cin>>n>>k;
        memset(ex, 0, sizeof(ex));
        FOR(i, 0, n) {
            cin>>v[i];
            ex[0] += v[i];
        }
        ex[0] /= n;
        FOR(kk, 1, k+1) {
            ex[kk] = 0;
            FOR(i, 0, n) {
                ex[kk] += max(ex[kk-1], (double)v[i]);
            }
            ex[kk] /= n;
        }
        print_case(tn);  coud(ex[k], 6); cout<<endl;
    }
    return 0;
}