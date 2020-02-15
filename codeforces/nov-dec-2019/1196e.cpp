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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int q,b,w; cin>>q;
    vii res;
    while(q--) {
        cin>>b>>w;
        int a = min(b, w);
        res.clear();
        int coord = 2;
        FOR(i, 0, a) {
            res.push_back({2, coord});
            res.push_back({2, coord + 1});
            coord += 2;
        }
        assert(coord == (2*a + 2));
        b -= a; w -= a;
        if(b) {
            res.push_back({2, 1});
            b--;
        }
        if(w) {
            res.push_back({2, coord});
            w--;
        }

        if(b <= 2*a && w <= 2*a) {
            int ci = 2;
            while(b > 0) {
                if(ci >= coord) break;
                res.push_back({1, ci});
                ci += 2; b--;
            }
            ci = 2;
            while(b > 0) {
                res.push_back({3, ci});
                ci += 2; b--;
            }
            ci = 3;
            while(w > 0) {
                if(ci >= coord) break;
                res.push_back({1, ci});
                ci += 2; w--;
            }
            ci = 3;
            while(w > 0) {
                res.push_back({3, ci});
                ci += 2; w--;
            }
        }

        if(b || w) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(auto itr : res) {
            cout<<itr.ff<<" "<<itr.ss<<endl;
        }
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}