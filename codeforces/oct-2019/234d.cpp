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

bool isfav[101] = {false};
int movie_favs[101] = {0}, movie_unknowns[101] = {0}, movie_maxs[101], movie_minm[101];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int m,k,t; cin>>m>>k;
    FOR(i, 0, k) {
        cin>>t;
        isfav[t] = true;
    }

    string s;
    int n,cnt,fv; cin>>n;
    FOR(i, 0, n) {
        cin>>s>>cnt;
        int non_favs = 0;
        FOR(j, 0, cnt) {
            cin>>fv;
            if(!fv) movie_unknowns[i]++;
            else if(isfav[fv]) movie_favs[i]++;
            else non_favs++;
        }
        // cout<<movie_favs[i]<<" "<<non_favs<<" "<<movie_unknowns[i]<<endl;
        movie_maxs[i] = movie_favs[i] + min(movie_unknowns[i], k - movie_favs[i]);
        movie_minm[i] = movie_favs[i] + (movie_unknowns[i] - min(movie_unknowns[i], m - k - non_favs));
        // deb(movie_maxs[i]); deb(movie_minm[i]);
    }

    FOR(i, 0, n) {
        int total_max = 0;
        FOR(j, 0, n) {
            if(i == j) continue;
            total_max = max(total_max, movie_maxs[j]);
        }
        if(movie_minm[i] >= total_max) {
            cout<<0<<endl;
            continue;
        }
        bool ans1 = false;
        FOR(j, 0, n) {
            if(i == j) continue;
            if(movie_maxs[i] < movie_minm[j]) ans1 = true;
        }
        if(ans1) {
            cout<<1<<endl;
            continue;
        }
        cout<<2<<endl;
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}