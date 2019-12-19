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

const int N = 61;
char mat[N][N];
int r,c;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int t; cin>>t; bool alla, allp;
    while(t--) {
        cin>>r>>c; alla = true; allp = true;
        FOR(i, 0, r) {
            FOR(j, 0, c) {
                cin>>mat[i][j];
                if(mat[i][j] == 'A') allp = false;
                else alla = false;
            }
        }

        if(alla) {
            cout<<0<<endl;
            continue;
        } else if(allp) {
            cout<<"MORTAL\n";
            continue;
        }

        bool completerowcol = false, completerowcolboundary = false, pref = false, prefboundary = false;
        FOR(i, 0, r) {
            bool good = true;
            FOR(j, 0, c) good &= (mat[i][j] == 'A');

            completerowcol |= good;
            completerowcolboundary |= (good && (i == 0 || i == r - 1));
            pref |= (mat[i][0] == 'A' || mat[i][c - 1] == 'A');
            prefboundary |= (i == 0 || i == r - 1) && (mat[i][0] == 'A' || mat[i][c - 1] == 'A');
        }
        FOR(j, 0, c) {
            bool good = true;
            FOR(i, 0, r) good &= (mat[i][j] == 'A');

            completerowcol |= good;
            completerowcolboundary |= (good && (j == 0 || j == c - 1));
            pref |= (mat[0][j] == 'A' || mat[r-1][j] == 'A');
            prefboundary |= (j == 0 || j == c - 1) && (mat[0][j] == 'A' || mat[r-1][j] == 'A');
        }

        if(completerowcolboundary) {
            cout<<1<<endl;
            continue;
        } else if(completerowcol || prefboundary) {
            cout<<2<<endl;
            continue;
        }
        else if(pref) cout<<3<<endl;
        else cout<<4<<endl;
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}