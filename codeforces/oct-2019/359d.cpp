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

const int N = 3e5+1;
int arr[N],n;
vi res; int blen = -1;

const int K = 35;
int st[N][K];
int logg[N+1];

void pre() {
	logg[1] = 0;
	for (int i = 2; i <= N; i++)
    	logg[i] = logg[i/2] + 1;

    for (int i = 0; i < n; i++)
    	st[i][0] = arr[i];

	for (ll j = 1; j <= K; j++)
	    for (ll i = 0; i + (1LL << j) <= n; i++)
            st[i][j] = __gcd(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R) {
	int j = logg[R - L + 1];
	return __gcd(st[L][j], st[R - (1 << j) + 1][j]);
}

unordered_map<int,bool> um;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();
    cin>>n;
    FOR(i, 0, n) cin>>arr[i];
    pre();

    FOR(i, 0, n) {
        int l=i,r=i;
        int lo = 0, hi = i;
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            if(query(mid, i) == arr[i]) {
                l = min(l, mid);
                hi = mid - 1;
            } else lo = mid + 1;
        }

        lo = i, hi = n - 1;
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            if(query(i, mid) == arr[i]) {
                r = max(r, mid);
                lo = mid + 1;
            } else hi = mid - 1;
        }

        // cout<<i<<" "<<l<<" "<<r<<endl;
        if((r-l) > blen) {
            blen = r - l;
            res.clear(); um.clear(); 
            res.push_back(l + 1);
            um[l+1] = true;
        } else if(r - l == blen) {
            if(um.find(l+1) == um.end()) {
                res.push_back(l + 1);
                um[l+1] = true;
            }
        }
    }

    cout<<res.size()<<" "<<blen<<endl;
    sort(all(res)); for(int l : res) cout<<l<<" ";
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}/*
    I am stupid!
*/