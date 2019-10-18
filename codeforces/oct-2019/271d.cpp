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

template<typename T>
using maxpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using minpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

const int m = 1e9+7;
const int m2 = 1e9+9;
const int p = 31;
const int p2 = 71;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s; cin>>s;
    bool good[26];
    char c;
    FOR(i,0,26) {
        cin>>c;
        good[i] = (c == '1');
    }
    int k; cin>>k;
    vii hashes;
    FOR(i, 0, s.size()) {
        string sofar; int bads = 0;
        ll h = 0, h2 = 0;
        FOR(j, i, s.size()) {
            ll val = s[j]-'a'+1;
            h = ((h * p) + val)%m;
            h2 = ((h2 * p2) + val)%m2;
            sofar.push_back(s[j]);
            if(!good[s[j]-'a']) bads++;
            if(bads > k) break;
            hashes.push_back({h,h2});
        }
    }
    sort(all(hashes));
    cout<<distance(hashes.begin(), unique(all(hashes)));
    return 0;
}