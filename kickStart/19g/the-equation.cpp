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

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int t; cin>>t;
    ll n,m,arr;
    FOR(tn, 1, t+1) {
        cin>>n>>m;
        vii cnt(52, {0,0}); // 0 and 1

        FOR(i, 0, n) {
            cin>>arr;
            RFOR(j, 51, 0) {
                if(arr & (1LL << j)) {
                    cnt[j].ss++;
                } else {
                    cnt[j].ff++;
                }
            }
        }

        ll k = 0, counter = 0;
        ll minm[52];
        FOR(i, 0, 52) {
            minm[i] = min(cnt[i].ff * 1LL * (1LL << i), cnt[i].ss * 1LL * (1LL << i));
            if(i) minm[i] += minm[i-1];
        }

        RFOR(j, 51, 0) {
            ll tmp = cnt[j].ff * 1LL * (1LL << j);
            ll oneestimate = counter + tmp;
            if(j) oneestimate += minm[j-1];

            if(oneestimate <= m) {
                k |= (1LL << j);
                counter += tmp;
            } else {
                tmp = cnt[j].ss * 1LL * (1LL << j);

                ll zeroestimate = counter + tmp;
                if(j) zeroestimate += minm[j-1];

                if(zeroestimate > m) {
                    k = -1;
                    break;
                } else {
                    counter += tmp;
                }
            }
        }

        print_case(tn);
        cout<<k<<endl;
    }
   
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}