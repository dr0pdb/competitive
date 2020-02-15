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

const int N = 7005;
vll a,b;
bool dominates[N][N];
int domcount[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int n; cin>>n; a.resize(n); b.resize(n);
    memset(domcount, 0, sizeof(domcount));
    FOR(i, 0, n) cin>>a[i];
    FOR(i, 0, n) cin>>b[i];

    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if(!((a[i] & a[j]) == a[i])) {
                dominates[i][j] = true;  
                domcount[i]++; 
            }
        }
    }
    vector<bool> inqueue(n, false);
    queue<int> todelete; ll res = 0;
    FOR(i, 0, n) {
        res += b[i];
        if(domcount[i] == (n - 1)) {
            todelete.push(i);
            inqueue[i] = true;
        }
    }
    vector<bool> done(n, false);
    int delcount = 0;
    while(!todelete.empty()) {
        int curr = todelete.front(); todelete.pop();
        if(done[curr]) continue;
        // deb(curr);
        res -= b[curr]; delcount++;
        done[curr] = true;
        FOR(i, 0, n) {
            if(done[i]) continue;
            if(dominates[i][curr]) domcount[i]--;
            if(domcount[i] == (n - delcount - 1) && !inqueue[i]) {
                todelete.push(i); 
                inqueue[i] = true;
            }
        }
    }
    cout<<res;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}