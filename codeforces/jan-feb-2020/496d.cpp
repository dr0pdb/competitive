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

const int nax = 1e5+5;
vi p1, p2;
int arr[nax],n;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    cin>>n;
    p1.resize(n); p2.resize(n);
    FOR(i, 0, n) {
        cin>>arr[i];
        if(arr[i] == 1) p1[i]++;
        else p2[i]++;

        if(i) {
            p1[i] += p1[i-1];
            p2[i] += p2[i-1];
        }
    }
    vii res;
    FOR(t, 1, n + 1) {
        int idx = 0, awins = 0, bwins = 0, prefa = 0, prefb = 0;
        int lastwinner;

        while(idx < n) {
            if(idx) {
                prefa = p1[idx - 1];
                prefb = p2[idx - 1];
            }

            auto idx1 = distance(p1.begin(), lower_bound(p1.begin()+idx, p1.end(), prefa + t));
            auto idx2 = distance(p2.begin(), lower_bound(p2.begin()+idx, p2.end(), prefb + t));

            if(idx1 < idx2) {
                awins++;
                lastwinner = 0;
            }
            else {
                bwins++;
                lastwinner = 1;
            }

            idx = min(idx1, idx2) + 1;
        }
        if(lastwinner == 0 && bwins >= awins) continue;
        if(lastwinner == 1 && awins >= bwins) continue;
        if(idx == n && abs(awins - bwins)) res.push_back({max(awins, bwins), t});
    }
    sort(all(res));
    cout<<res.size()<<endl;
    for(ii a : res) {
        cout<<a.ff<<" "<<a.ss<<endl;
    }
    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}