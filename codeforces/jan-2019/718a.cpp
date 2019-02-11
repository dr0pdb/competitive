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

vector<char> num;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,t,pos=-1;
    cin>>n>>t;
    char c;
    F(i, 0, n) {
    	cin>>c;
    	num.push_back(c);
    }
    bool dot=false;
    F(i, 0, n) {
    	if(num[i]=='.') {
    		dot = true;
    		continue;
    	} else if(num[i] >= '5' && dot) {
    		pos=i;
    		break;
    	}
    }

    if(pos >= 0) {
    	while(t > 0) {
    		pos--;
    		if(num[pos]=='.') break;
			num[pos]++;
			num.erase(num.begin()+pos+1, num.end());
    		if(num.back() < '5' || num.back() == '.') {
    			break;
    		}
    		t--;
    	}

    	if(num.back() == '.') {
    		dot = false;
    		num.pop_back();		
		}

		// F(i, 0, num.size()) {
		// 	cout<<num[i];
		// }
		// cout<<endl;

    	// round the num.
    	if(t > 0 && dot) {
    		int doti=-1;
    		F(i, 0, num.size()) {
    			if(num[i]=='.') {
    				doti = i;
    				break;
    			}
    		}
    		bool ins = false;
    		if(num[doti+1] >= '5') {
    			num.erase(num.begin()+doti, num.end());
    			int sz = num.size(), carry=1;
    			RF(i, sz-1, 0) {
    				int val = num[i]-'0' + carry;
    				num[i] = (val%10) + '0';
    				carry = val/10;
    			}

    			if(carry) {
    				cout<<1;
    			}
    		}
    	}
    }


    F(i, 0, num.size()) {
    	cout<<num[i];
    }
    return 0;
}/*

*/