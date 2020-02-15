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

    string s; cin>>s;
    vi idx[3]; int n = s.size();
    FOR(i, 0, n) {
        idx[s[i]-'a'].push_back(i);
    }
    int hi = n - 1;
    string res = ""; int req = n / 2, left = n / 2;
    string res2;
    FOR(i, 0, n) {
        if(!left) break;
        FOR(j, 0, 3) {
            while(!idx[j].empty() && idx[j].back() > hi) idx[j].pop_back();
        }
        if(left == 1) {
            res.push_back(s[i]);
            break;
        } else {
            int curr = s[i] - 'a';
            if(idx[curr].back() == i) continue;
            int chi = idx[curr].back();
            if((chi - i - 1) >= 2 * (left - 2)) {
                res.push_back(s[i]);
                res2.push_back(s[i]);
                hi = chi - 1;
                left -= 2;
            }
        }
    }
    reverse(all(res2));
    cout<<res + res2;
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}