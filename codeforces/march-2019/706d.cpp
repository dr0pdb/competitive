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

int tot = 0;
int ch[5000001][2];
int s[5000001]; // contains the count of child.

void insert(int x) {
    int Root = 0;
    for (int i = 30; i >= 0; i --) {
        int tmp = (x >> i) & 1;
        if (!ch[Root][tmp]) {
            ch[Root][tmp] = ++ tot;
            s[tot] = 0;
            memset(ch[tot], 0, sizeof(ch[tot]));
        }
        Root = ch[Root][tmp];
        ++ s[Root];
    }
}

void del(int x) {
    int Root = 0;
    for (int i = 30; i >= 0; i --) {
        int tmp = (x >> i) & 1;
        Root = ch[Root][tmp];
        -- s[Root];
    }
}

int query(int x) {
    int Root = 0, ans = 0;
    for (int i = 30; i >= 0; i --) {
        int tmp = (x >> i) & 1;
        if (s[ch[Root][tmp ^ 1]]) ans += (1 << i), Root = ch[Root][tmp ^ 1];
        else Root = ch[Root][tmp];
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin>>q;
    insert(0);

    char c; int x;
    while(q--) {
    	cin>>c>>x;
    	if(c == '+') {
    		insert(x);
    	} else if (c == '-') {
    		del(x);
    	} else {
    		cout<<query(x)<<endl;
    	}
    }

    return 0;
}