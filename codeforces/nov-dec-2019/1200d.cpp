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

const int N = 2001;
int n, k;
char mat[N][N];
int alreadycool = 0;
int rmin[N], rmaxm[N];
int cmin[N], cmaxm[N];
int rr[N][N], bb[N][N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n>>k;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin>>mat[i][j];
        }
    }

    FOR(i, 0, n) {
        rmin[i] = rmaxm[i] = -1;
        FOR(j, 0, n) {
            if(mat[i][j] == 'B') {
                if(rmin[i] == -1) rmin[i] = j;
                rmaxm[i] = j;
            }
        }
        if(rmin[i] == -1) alreadycool++;
    }
    FOR(j, 0, n) {
        cmin[j] = cmaxm[j] = -1;
        FOR(i, 0, n) {
            if(mat[i][j] == 'B') {
                if(cmin[j] == -1) cmin[j] = i;
                cmaxm[j] = i;
            }
        }
        if(cmin[j] == -1) alreadycool++;
    }
    int res = 0;
    RFOR(i, n-1, 0) {
        RFOR(j, n - 1, 0) {
            if((rmin[i] >= j && rmaxm[i] <= j + k - 1)) bb[i][j] = 1; // current row is good
            if(i != n-1) bb[i][j] += bb[i+1][j];
            if(i + k < n && ((rmin[i+k] >= j && rmaxm[i+k] <= j + k - 1))) bb[i][j]--; // remove contribution of (i + k)(j) since it's not in range but has been added. 
        
            if((cmin[j] >= i && cmaxm[j] <= i + k - 1)) rr[i][j] = 1; // current col is good.
            if(j != n-1) rr[i][j] += rr[i][j+1];
            if(j + k < n && ((cmin[j+k] >= i && cmaxm[j+k] <= i + k - 1))) rr[i][j]--;
            
            res = max(res, alreadycool + bb[i][j] + rr[i][j]);
        }
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}