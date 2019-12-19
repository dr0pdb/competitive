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

const int N = 101;
int r,c,k;
char mat[N][N], arr[N][N], sym[62];

void pre() {
    FOR(i, 0, 10) sym[i] = (char)(i + '0'); 
    FOR(i, 0, 26) sym[i + 10] = (char) (i + 'a');
    FOR(i, 0, 26) sym[i + 36] = (char) (i + 'A');
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    pre();
    int t; cin>>t;
    while(t--) {
        cin>>r>>c>>k;
        int rice = 0;
        FOR(i, 0, r) {
            FOR(j, 0, c) {
                cin>>arr[i][j];
                if(arr[i][j] == 'R') rice++;
                mat[i][j] = '#';
            }
        }

        int eqshare = rice / k;
        int extra = rice % k;
        int turn = 0, taken = 0;
        FOR(i, 0, r) {
            if((i % 2) == 0) {
                FOR(j, 0, c) {
                    mat[i][j] = sym[turn];
                    if(arr[i][j] == 'R') taken++;
                    if(taken == (eqshare + (extra > 0))) {
                        extra--;
                        if(turn < (k - 1)) {
                            turn++;
                            taken = 0;
                        }
                    }
                }
            } else {
                RFOR(j, c - 1, 0) {
                    mat[i][j] = sym[turn];
                    if(arr[i][j] == 'R') taken++;
                    if(taken == (eqshare + (extra > 0))) {
                        extra--;
                        if(turn < (k - 1)) {
                            turn++;
                            taken = 0;
                        }
                    }
                }
            }
        }
        FOR(i, 0, r) {
            FOR(j, 0, c) {
                cout<<mat[i][j];
            }
            cout<<endl;
        }
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}