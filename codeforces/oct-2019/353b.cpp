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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int n; cin>>n; n*= 2;
    vi freq(100, 0);
    vi idx[100];
    int arr[n], ans[n];
    FOR(i, 0, n) {
        cin>>arr[i];
        freq[arr[i]]++;
        idx[arr[i]].push_back(i);
    }
    int cnt[3] = {0};
    set<int> ss[3];
    FOR(i, 10, 100) {
        if(freq[i] > 1) {
            int turn = 1; if(cnt[1] > cnt[2]) turn = 2;
            while(freq[i]) {
                ans[idx[i].back()] = turn;
                freq[i]--;
                cnt[turn]++;
                ss[turn].insert(i);
                turn = 3 - turn;
                idx[i].pop_back();
            }
        }
    }
    FOR(i, 10, 100) {
        if(freq[i] == 1) {
            if(cnt[1] <= cnt[2]) {
                ans[idx[i].back()] = 1; cnt[1]++;
                ss[1].insert(i);
            } else {
                ss[2].insert(i);
                ans[idx[i].back()] = 2; cnt[2]++;
            }
            idx[i].pop_back();
            freq[i]--;
        }
    }
    cout<<ss[1].size() * ss[2].size()<<endl;
    FOR(i, 0, n) {
        cout<<ans[i]<<" ";
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}