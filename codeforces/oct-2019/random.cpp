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

// int solution(vector<int> &a, vector<int> &b) {
//     int n = a.size();
//     if(n <= 1) return 0;
//     long long left1 = a[0], left2 = b[0];
//     long long right1 = 0, right2 = 0;
//     for(int i = n - 1; i >= 1; i--) {
//         right1 += 1LL * a[i];
//         right2 += 1LL * b[i];
//     }
//     int res = 0;
//     for(int i = 1; i < n; i++) {
//         if(left1 == right1 && left2 == right2 && left1 == left2) res++;
//         left1 += a[i]; right1 -= a[i];
//         left2 += b[i]; right2 -= b[i];
//     }
//     return res;
// }

int dp(int idx, int mask, vector<string> &arr) {
    if(idx == arr.size()) return 0;
    
}

int solution(vector<string> &arr) {

}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    vector<int> a = {4, -1, 0, 3}, b = {-2, 5, 0, 3};
    cout<<solution(a, b)<<endl;
    vector<int> a1 = {2, -2, -3, 3}, b1 = {0, 0, 4, -4};
    cout<<solution(a1, b1)<<endl;

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}