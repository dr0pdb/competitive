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

vi ans;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    string s;
    cin>>s;

    int sz=s.size(),a=0,b=0;
    F(i, 0, sz) {
    	if(s[i] == '(') a++;
    	else if(s[i] == ')') b++;
    	else {
    		ans.push_back(1);
    		b++;
    	}
    	if(b > a) {
    		cout<<-1;
    		return 0;
    	}
    }

    int cnt=0,ind=0, cnt2=0;
    RF(i, sz-1, 0) {
    	if(s[i] == '#') {
    		ind=i;
    		break;
    	}
    	if(s[i] == ')') cnt++;
    	else cnt--;
 	}

 	F(i, 0, ind) {
 		if(s[i] == '(') cnt2++;
 		else cnt2--;
 	}

 	int sz2 = ans.size();
 	ans[sz2-1]+= cnt2-cnt-1;
 	F(i, 0, sz2) {
 		cout<<ans[i]<<endl;
 	}

    return 0;
}/*

*/
