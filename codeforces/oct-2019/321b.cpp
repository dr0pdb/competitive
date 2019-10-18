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

int jiron,cieln; 
map<int, int> ja, jd, ce;

int attackvsattack(map<int,int> &tce, map<int,int> &tja) {
    int profit = 0;

    while(tja.size() && tce.size()) {
        auto itr = tja.begin();
        auto itr2 = tce.end(); --itr2;
        if(itr2->ff >= itr->ff) {
            profit += itr2->ff - itr->ff;
            itr->ss--;
            if(itr->ss == 0) tja.erase(itr);
            itr2->ss--;
            if(itr2->ss == 0) tce.erase(itr2);
        } else break;
    }

    return profit;
}   

int solvecaseone() {
    int profit = 0;

    map<int,int> tjd = jd, tce = ce, tja = ja;
    for(auto itr : tjd) {
        int st = itr.ff, freq = itr.ss;
        while(freq--) {
            auto itr2 = tce.upper_bound(st); // x's strength > y's strength 
            if(itr2 == tce.end()) {
                // impossible to remove.
                profit = -INF;
                return profit;
            } else {
                itr2->ss--;
                if(itr2 -> ss == 0) {
                    tce.erase(itr2);
                }
            }
        }
    }

    while(tja.size() && tce.size()) {
        auto itr = tja.begin();
        auto itr2 = tce.begin();
        if(itr2->ff >= itr->ff) {
            profit += itr2->ff - itr->ff;
            itr->ss--;
            if(itr->ss == 0) tja.erase(itr);
            itr2->ss--;
            if(itr2->ss == 0) tce.erase(itr2);
        } else {
            profit += (itr2->ff * itr2->ss);
            tce.erase(itr2);
        }
    }

    if(tja.size()) return -INF;

    for(auto itr : tce) {
        profit += (itr.ff * itr.ss);
    }   

    return profit;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>jiron>>cieln;
    string s; int st;
    FOR(i, 0, jiron) {
        cin>>s>>st;
        if(s[0] == 'A') {
            ja[st]++;
        } else jd[st]++;
    }
    FOR(i, 0, cieln) {
        cin>>st;
        ce[st]++;
    }

    // removing all the defensive cards of jiro.
    int res = solvecaseone();
    // deb(res);
    res = max(res, attackvsattack(ce, ja));
    cout<<res;

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}