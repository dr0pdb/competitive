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

const int N = 1e5+5;
int arr[N], maxm;

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,n,res; cin>>t;
    while(t--) {
        scanf("%d", &n);
        unordered_map<int, int> um; res = 0; maxm = 0;
        FOR(i, 0, n) {
            scanf("%d", &arr[i]);
            maxm = max(maxm, arr[i]);
            um[arr[i]]++;
        }
        unordered_set<int> used;
        RFOR(i, n-1, 0) {
            um[arr[i]]--;
            if(used.find(arr[i]) != used.end()) continue;
            if(arr[i] == 1) {
                res = max(res, (int)i);
                continue;
            }
            int val = arr[i], cnt=0;
            while(val <= maxm) {
                auto itr = um.find(val);
                if(itr != um.end()) cnt += itr->second;    
                val += arr[i];
            }
            res = max(res, cnt);
            used.insert(arr[i]);
        }
        printf("%d\n", res);
    }

    return 0;
}