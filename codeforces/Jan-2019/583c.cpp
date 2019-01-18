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

const int N = 250005;
int arr[N];
map<int,int> m;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;
    F(i, 0, n*n) {
    	cin>>arr[i];
    	m[arr[i]]++;
    }

    vi ans;
    ans.push_back(m.rbegin()->first);
    m.rbegin()->second--;
    if(m.rbegin() -> second == 0) {
    	auto itr = m.end(); itr--;
    	m.erase(itr);
    }

    while(ans.size() < n) {
    	auto itr = m.end(); --itr;
    	int num = itr->first;
    	itr->second--;
    	if(itr->second == 0) {
    		m.erase(itr);
    	}

    	for(auto num2: ans) {
    		int g = __gcd(num, num2);
    		auto itr2 = m.find(g);
    		m[g]-=2;
    		if(m[g] == 0) {
    			m.erase(itr2);
    		}
    	}

    	ans.push_back(num);
    }

    debug_vi(ans);

    return 0;
}/*

*/