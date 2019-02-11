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
/*----------------------------------------------------------------------*/

bool cmp(ii a, ii b) {
	if(a.first != b.first) {
		return a.first <= b.first;
	}
	return a.second >= b.second;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int v;
    cin>>v;

    ii a[9]; int b[10];
    F(i, 0, 9) {
    	cin>>a[i].first;
    	b[i+1] = a[i].first;
    	a[i].second = i+1;
    }
    sort(a, a+9, cmp);

    vi ans;
    while(v >= a[0].first) {
    	ans.push_back(a[0].second);
    	v -= a[0].first;
    }

    // deb(v);
    F(i, 0, ans.size()) {
    	if(!v) {
			break;
		}
    	RF(j, 9, ans[i]+1) {
    		if(b[j]-b[ans[i]] <= v) {
    			v -= b[j] - b[ans[i]];
    			ans[i]=j;
    			// deb(v);
    			break;
    		}
    	}
    }

    if(ans.size() == 0) {
    	cout<<-1;
    	return 0;
    }

    F(i, 0, ans.size()) {
    	cout<<ans[i];
    }

    return 0;
}/*

*/
