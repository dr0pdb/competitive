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

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string a,b;
    cin>>a>>b;
    int ta=0, tha=0,tb=0, thb=0, mult = 1;
    bool flag = false;
    RF(i, a.size()-1, 0) {
    	if(a[i] == ':') {
    		mult = 1;
    		flag = true;
    		continue;
    	}
    	int tmp = mult * (a[i] - '0');
    	if(flag) {
    		tha += tmp;
    	} else {
    		ta += tmp;
    	}
    	
    	mult *= 10;
    }

    ta += 60*tha;
    mult=1; flag = false;
    RF(i, b.size()-1, 0) {
    	if(b[i] == ':') {
    		mult = 1;
    		flag = true;
    		continue;
    	}
    	int tmp = mult * (b[i] - '0');
    	if(flag) {
    		thb += tmp;
    	} else {
    		tb += tmp;
    	}
    	
    	mult *= 10;
    }

    tb += 60*thb;
    int ans = (ta + tb)/2;
    int hour = ans/60;
    int min = ans % 60;
    printf("%02d:%02d\n", hour, min);

    return 0;
}/*

*/