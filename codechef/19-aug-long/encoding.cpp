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

const int N = 1e5+5;
ll dp[N][10];
ll p[N];

void pre() {
	p[0] = 1LL;
	FOR(i, 1, N) {
		p[i] = p[i-1] * 10LL;
		p[i] %= MOD;
	}
}

string findDiff(string str1, string str2 = "1") 
{ 
    string str = ""; 
  
    int n1 = str1.length(), n2 = str2.length(); 
  
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    int carry = 0; 
  
    for (int i=0; i<n2; i++) 
    { 
      
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
          
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    for (int i=n2; i<n1; i++) 
    { 
        int sub = ((str1[i]-'0') - carry); 
          
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
              
        str.push_back(sub + '0'); 
    } 
  
    reverse(str.begin(), str.end());   
    return str; 
}

ll calc(int rev, int past) {
	if(rev < 0) return 0;
	ll &ret = dp[rev][past];
	if(ret >= 0) return ret;
	ret = 0;

	FOR(i, 0, 10) {
		ret += calc(rev - 1,  i); ret %= MOD;
		if(i != past) {
			ret += (((i * p[rev]) % MOD ) * p[rev])%MOD;
		}
		ret %= MOD;
	}
	return ret;
}

ll f(int idx, int past, string &num, vll &cnt) {
	ll ret = 0; int n = num.size();
	if(idx == n) return ret;

	int dig = num[idx] - '0';
	FOR(i, 0, dig) {
		ret += calc(n - idx - 2, i); ret %= MOD;
		if(past != i) {
			ret += (((i * p[n - idx - 1])%MOD) * p[n - idx - 1]) % MOD;
		}
		ret %= MOD;
	}
	ret += f(idx+1, dig, num, cnt); ret %= MOD;
	if(past != dig) {
		ret += ((dig * p[n - idx - 1]) % MOD * cnt[idx + 1] ) % MOD;
	}
	ret %= MOD;
	return ret;
}

string l,r;

vll create_count(string num) {
	int n = num.size();
	vll ret(n+1, 0);
	ret[n] = 1; ll pp = 1LL;
	RFOR(i, n-1, 0) {
		ret[i] = ret[i+1] + (num[i] - '0') * pp;
        pp *= 10; pp %= MOD;
		ret[i] %= MOD;
	}
	return ret;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t; cin>>t; 
    memset(dp, -1, sizeof(dp)); pre(); int nl,nr;
    while(t--) {
    	cin>>nl>>l>>nr>>r; l = findDiff(l);
    	vll cntr = create_count(r), cntl = create_count(l);
    	cout<<(f(0, -1, r, cntr) - f(0, -1, l, cntl) + MOD)%MOD;
        if (t) cout<<endl;
    }
    // string tmp = "110"; vll cnt = create_count(tmp);
    // for(auto num: cnt) {
    // 	cout<<num<<" ";
    // }
    // cout<<calc(1, 0);
    // cout<<endl;
    // cout<<f(0, -1, tmp, cnt)<<endl;
    // FOR(i, 1, 1e5) {
    //     string tmp = to_string(i);
    //     vll cnt = create_count(tmp);
    //     cout<<f(0, -1, tmp, cnt)<<endl;
    // }
    return 0;
}
