#include<bits/stdc++.h>
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
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
inline void debug_vi(vi a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {F(i, 0, a.size()) cout<<a[i]<<" ";}
/*----------------------------------------------------------------------*/

struct FenwickTree2D {
    vector<vector<int>> bit;
    int n, m;

    FenwickTree2D(int n, int m) {
        this->n = n + 1;
        this->m = m + 1;
        bit.assign(n + 1, vector<int> (m + 1, 0));
    }

    // x and y as zero based index.
    int sum(int x, int y) {
        int ret = 0;
        for (int i = x+1; i > 0; i -= i & (-i))
            for (int j = y+1; j > 0; j -= j & (-j))
                ret += bit[i][j];
        return ret;
    }

    // x and y as zero based index.
    void add(int x, int y, int delta) {
        for (int i = x+1; i < n; i += i & (-i))
            for (int j = y+1; j < m; j += j & (-j))
                bit[i][j] += delta;
    }
};

bool marked[1005][1005];

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t,q,tp,x,y,x1,y1; cin>>t;
   	F(tn, 1, t+1) {
   		cin>>q;

      printf("Case %lld:\n", tn);
   		// cout<<"Case "<<tn<<":\n";
   		FenwickTree2D ft(1005, 1005);
   		memset(marked, false, sizeof(marked));
   		while(q--) {
        scanf("%d %d %d", &tp, &x, &y);
   			// cin>>tp>>x>>y;
        x++; y++;
   			if(tp) {
          scanf("%d %d", &x1, &y1);
   				// cin>>x1>>y1; 
          x1++; y1++;
   				printf("%d\n", ft.sum(x1, y1) + ft.sum(x-1, y-1) - ft.sum(x1, y-1) - ft.sum(x-1, y1));
          // cout<<ft.sum(x1, y1) + ft.sum(x-1, y-1) - ft.sum(x1, y-1) - ft.sum(x-1, y1)<<endl;
   			} else {
   				if(marked[x][y]) continue;
   				marked[x][y] = true;
   				ft.add(x, y, 1);
   			}
   		}
   	}

    return 0;
}/*

*/
