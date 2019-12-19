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

const int N = 2e5+5;
ii segs[N];
bool enabled[N];
vector<iii> events; // time, type and idx. type = 1 for openers and 0 for closers.

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int k,n; cin>>n>>k;
    FOR(i, 0, n) {
        cin>>segs[i].ff>>segs[i].ss;
        events.push_back({segs[i].ff, {1, i}});
        events.push_back({segs[i].ss + 1, {0, i}});
    }
    sort(all(events));
    memset(enabled, true, sizeof(enabled));
    map<int, vi> freq;
    int cnt = 0, tm, tp, idx;
    vi disabled;

    for(auto e : events) {
        tm = e.ff; tie(tp, idx) = e.ss;
        if(tp == 0) {
            if(enabled[idx]) cnt--;
        } else {
            cnt++;
            freq[segs[idx].ss].push_back(idx);

            if(cnt == k + 1) {
                auto itr = freq.rbegin();

                int disidx = itr->ss.back();
                itr->ss.pop_back();
                if(itr->ss.empty()) freq.erase(freq.find(itr->ff));
                
                enabled[disidx] = false;
                disabled.push_back(disidx);
                cnt--;
            }
        }
    }

    cout<<disabled.size()<<endl;
    for(int a : disabled) cout<<a+1<<" ";
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}