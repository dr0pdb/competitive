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

const int N = 1e6+5;
int unbalance[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int n; cin>>n;
    string s; cin>>s;
    int a = 0, b = 0;
    for(char c : s) {
        if(c == '(') a++;
        else b++;
    }
    int res = 0;
    if(n % 2 == 0 && abs(a - b) == 2) {
        int unbal = 0;

        if(a > b) {
            RFOR(i, n - 1, 0) {
                if(s[i] == ')') unbal++;
                else unbal--;

                if(unbal <= -3) {
                    cout<<0<<endl;
                    return 0;
                }
                unbalance[i] = unbal;
            }

            RFOR(i, n - 1, 0) {
                if(s[i] == '(') res++;
                if(unbalance[i] < 0) break;
            }
        } else {
            FOR(i, 0, n) {
                if(s[i] == '(') unbal++;
                else unbal--;

                if(unbal <= -3) {
                    cout<<0<<endl;
                    return 0;
                }

                unbalance[i] = unbal;
            }

            FOR(i, 0, n) {
                if(s[i] == ')') res++;
                if(unbalance[i] < 0) break;
            }
        }
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}