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

const int N = 5205;
int matrix[N][N], dp[N][N],n;

string getNums(char c) {
	switch(c) {
		case '0': 
            return "0000"; 
        case '1': 
            return"0001"; 
        case '2': 
            return "0010"; 
        case '3': 
            return "0011"; 
        case '4': 
            return "0100"; 
        case '5': 
            return"0101"; 
        case '6': 
            return "0110"; 
        case '7': 
            return "0111"; 
        case '8': 
            return "1000"; 
        case '9': 
            return "1001"; 
        case 'A': 
        case 'a': 
            return "1010"; 
        case 'B': 
        case 'b': 
            return "1011"; 
        case 'C': 
        case 'c': 
            return "1100"; 
        case 'D': 
        case 'd': 
           return  "1101"; 
        case 'E': 
        case 'e': 
            return "1110"; 
        case 'F': 
        case 'f':
            return "1111"; 
	}

	return "";
}

vi getDivisors(int n) 
{ 
	vi facts;
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
            	facts.push_back(i);     
  
            else {
            	facts.push_back(i);
            	facts.push_back(n/i);
            } 
               
        } 
    } 
    return facts;
}

bool check(int x) {
	for(int i = x; i <= n; i+=x) {
		for(int j=x; j <= n; j+=x) {
			int sum = dp[i][j] - dp[i-x][j] - dp[i][j-x] + dp[i-x][j-x];
			if(sum != 0 && sum != x*x) {
				// cout<<x<<" x, "<<i<<" "<<j<<endl;
				return false;
			}
		}
	}

	return true;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n;
    string row;

    memset(dp, 0, sizeof(dp));

    F(i, 1, n+1) {
    	cin>>row;
    	F(j, 0, row.size()) {
    		string ret = getNums(row[j]);
    		F(k, 4*j+1, 4*j+5) {
    			matrix[i][k] = ret[k-1-4*j]-'0';
    			// cout<<matrix[i][k]<<" ";
    		}
    	}
    	// cout<<endl;
    }

    // cout<<endl<<endl;
    F(i, 1, n+1) {
    	F(j, 1, n+1) {
    		dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + matrix[i][j];
    		// cout<<dp[i][j]<<" ";
    	}
    	// cout<<endl;
    }

    vi divs = getDivisors(n);

    int ans = -1;
    for(int div : divs) {
    	if(check(div)) {
    		ans = max(ans, div);
    	}
    }

    cout<<ans;

    return 0;
}/*

*/