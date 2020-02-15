#include<bits/stdc++.h>
#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "
inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }
const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
#define ff first
#define ss second
/*----------------------------------------------------------------------*/

class TheHexagonsDivOne {
public:
    ll res = 0;
    int k,n;
    int cnt[10];
    int center, circle[6];

    void backtrack(int p, int used = 0) {
        if(p == 6) {
            ll t = 1;
            FOR(i, 0, used) {
                t *= max(0LL, k - i);

                FOR(j, 0, cnt[i]) {
                    t *= max(0LL, n/k - j);
                }
            }
            res += t;
            return;
        }

        FOR(i, 0, used + 1) { // try every used color or the next color.
            circle[p] = i;
            cnt[i]++;
            if(i != center &&
                ((p == 0) || (i != circle[p - 1])) &&
                ((p == 5) || (i != circle[p + 1]))) {
                backtrack(p + 1, max(used, (int)i + 1));
            }
            cnt[i]--;            
        }
    }

    ll count(int _n, int _k) {
        n = _n; k = _k;
        memset(cnt, 0, sizeof(cnt));
        center = 0;
        circle[0] = 1; circle[1] = 2;
        cnt[0] = cnt[1] = cnt[2] = 1;
        backtrack(2, 3);
        return res /= 6;
    }

    long long count(int n) {
        return count(2*n, n);
    }
};