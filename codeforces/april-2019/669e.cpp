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

struct FenwickTree {
    vector<map<int,int> > bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, map<int,int>());
    }

    int sum(int idx, int val) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
        	if(bit[idx].find(val) != bit[idx].end())
            	ret += bit[idx][val];
        }
        return ret;
    }

    // l and r should be given as 0 based indexes.
    int sum(int l, int r, int val) {
        return sum(r, val) - sum(l - 1, val);
    }

    // idx as zero based.
    void increment(int t, int value, int delta) {
        for (++t; t < n; t += t & -t)
            bit[t][value] += delta;
    }
};

const int N = 1e5+5;
vector<vi> q;
map<int,int> m;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
   	//freopen("output.txt", "w", stdout);
    int n,tmp[3];
    cin>>n;
    q.resize(n);

    FOR(i, 0, n) {
    	FOR(j, 0, 3) {
    		cin>>tmp[j];
    	}
    	m[tmp[1]]=1;
    	q[i] = {tmp[0], tmp[1], tmp[2]};
    }
    int cnt = 1;
    for(auto &itr : m) {
    	itr.ss = cnt++;
    }
    FOR(i, 0, n) {
    	q[i][1] = m[q[i][1]];
    }

    FenwickTree ft(cnt+5);
    FOR(i, 0, n) {
    	switch(q[i][0]) {
    		case 1: {
    			ft.increment(q[i][1], q[i][2], 1);
    			break;
    		}
			case 2: {
				ft.increment(q[i][1], q[i][2], -1);
				break;
			}
			default: {
				cout<<ft.sum(q[i][1], q[i][2])<<endl;
			}
    	}
    }

    return 0;
}