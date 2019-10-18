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

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}
/*----------------------------------------------------------------------*/

ll val; string vs;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t; cin>>t;
    FOR(tn, 1, t+1) {
        cin>>val; vs = to_string(val);
        string res, res2;
        FOR(i, 0, vs.size()) {
            int d = vs[i] - '0';
            if(d % 2 == 0) {
                res.push_back(vs[i]);
                res2.push_back(vs[i]);
            } else {
                res.push_back((vs[i] - 1));
                FOR(j, i + 1, vs.size()) {
                    res.push_back('8');
                }
                if(d != 9) {    
                    res2.push_back(vs[i] + 1);
                    FOR(j, i + 1, vs.size()) res2.push_back('0');
                } else res2.clear();
                break;
            }
        }
        ll ans = val - stoll(res);
        if(!res2.empty()) ans = min(ans, stoll(res2) - val);
        print_case(tn); cout<<ans<<endl;
    }    
    return 0;
}