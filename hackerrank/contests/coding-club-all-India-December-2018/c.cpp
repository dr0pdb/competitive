#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

string s = "155 216 225 44 166 222 203 44 205 210 226 203 215 44 166 44 205 222 210 202 44 216 204 44 223 210 233 203 44 141 231 140 62 44 232 216 225 44 206 166 226 203 44 224 216 44 204 210 215 202 44 224 206 203 44 223 225 214 44 216 204 44 224 206 203 44 214 166 231 210 214 225 214 44 201 216 215 215 203 201 224 203 202 44 201 216 214 220 216 215 203 215 224 223 64 13 13 150 230 216 44 124 203 213 213 44 216 204 44 224 206 203 44 205 222 210 202 44 210 223 44 201 216 215 215 203 201 224 203 202 44 210 204 44 224 206 203 232 44 103 63 202 210 222 203 201 224 210 216 215 63 230 210 223 203 44 166 202 211 166 201 203 215 224 44 166 215 202 44 200 216 224 206 44 216 204 44 224 206 203 214 44 166 222 203 44 215 216 215 63 233 203 222 216 64 13 13 141 216 224 203 112 44 205 222 210 202 160 66 162 160 66 162 44 166 215 202 44 205 222 210 202 160 215 63 100 162 160 66 162 44 166 222 203 44 215 216 224 44 201 216 215 215 203 201 224 203 202 44 166 215 202 44 223 210 214 210 213 166 222 13 13 140 216 224 210 226 166 224 210 216 215 44 224 216 44 203 215 201 222 232 220 224 44 204 222 216 214 44 201 216 202 203 204 216 222 201 203 223 44 100 106 100 130 55 210 224 44 230 166 223 44 166 201 224 225 166 213 213 232 44 204 225 215 44 224 216 44 223 216 213 226 203 56 \n\n\n\n\n\n\n\n 130 210 222 223 224 44 136 210 215 203 44 201 216 215 224 166 210 215 223 44 224 230 216 44 210 215 224 203 205 203 222 223 44 141 44 166 215 202 44 140 62 13 141 203 231 224 44 141 44 213 210 215 203 223 44 201 216 215 224 166 210 215 223 44 140 44 210 215 224 203 205 203 222 223 44 166 223 44 201 216 214 220 216 215 203 215 224 223 44 216 204 44 224 206 203 44 205 222 210 202 \n\n\n\n\n\n\n\n\n\n 100 44 114 115 44 141 62 140 44 114 115 44 100 66 66 66 13 66 44 114 115 44 124 216 214 220 216 215 203 215 224 223 44 114 115 44 100 66 163 111 \n\n\n\n\n\n\n\n\n 142 225 224 220 225 224 44 166 44 223 210 215 205 213 203 44 210 215 224 203 205 203 222 44 202 203 215 216 224 210 215 205 44 230 206 166 224 44 166 223 212 203 202 44 210 215 44 200 210 215 166 222 232 \n \n \n \n \n55 66 62 66 56 62 55 100 62 66 56 62 55 100 62 100 56 62 55 101 62 100 56 62 55 102 62 100 56 62 55 102 62 66 56 44 166 222 203 44 224 206 203 44 201 216 215 215 203 201 224 44 220 216 210 215 224 223 44 230 206 210 201 206 44 214 166 212 203 44 224 206 203 44 214 166 231 210 214 225 214 44 223 225 214";
string out = "";

long ConvertTo10(const string& input, int base)
{
    if(base < 2 || base > 36)
        return 0;
    
    bool isNegative = (input[0] == '-');    

    int startIndex = input.length()-1;
    int endIndex   = isNegative ? 1 : 0;
    
    long value = 0;
    int digitValue = 1;
    
    for(int i = startIndex; i >= endIndex; --i)
    {
        char c = input[i];
        
        // Uppercase it - NOTE: could be done with std::toupper
        if(c >= 'a' && c <= 'z')
            c -= ('a' - 'A');
        
        // Convert char to int value - NOTE: could be done with std::atoi
        // 0-9
        if(c >= '0' && c <= '9')
            c -= '0';
        // A-Z
        else
            c = c - 'A' + 10;
        
        if(c >= base)
            return 0;
        
        // Get the base 10 value of this digit    
        value += c * digitValue;
        
        // Each digit has value base^digit position - NOTE: this avoids pow
        digitValue *= base;
    }
    
    if(isNegative)
        value *= -1;
    
    return value;
}

ll grid[1005][1005];
bool visited[1005][1005];
int dirx[4]={0, 1, -1, 0};
int diry[4]={1, 0, 0, -1};
int n,m;

bool valid(int i, int j) {
	return i>= 0 && i < n && j >= 0 && j <m;
}

void dfs(ll i, ll j, ll &curr, ll &maxm) {
	visited[i][j]=true;
	curr += grid[i][j];
	maxm = max(maxm, curr);

	F(k, 0, 4) {
		int nx = i + dirx[k];
		int ny = j + diry[k];

		if(valid(nx, ny) && !visited[nx][ny] && grid[nx][ny]!= 0) {
			dfs(nx,ny, curr, maxm);
		} 
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
   //  stringstream ss(s);
   //  int num;
   //  while(ss>>num) {
   //  	long sum = ConvertTo10(to_string(num), 7);
	 	// out+=" ";
	 	// out += (char)sum;
   //  }
   //  cout<<out<<endl;
    cin>>n>>m;

    F(i, 0, n) {
    	F(j, 0, m) {
    		cin>>grid[i][j];
    	}
    }

    ll maxm = 0,curr=0;
    memset(visited, false, sizeof(visited));

    F(i, 0, n) {
    	F(j, 0, m) {
    		if(!visited[i][j] && grid[i][j]) {
    			curr = 0;
    			dfs(i, j, curr, maxm);
    		}
    	}
    }

    string ans = "";
    // ll mul = 1L;
    while(maxm>0) {
    	ans = (char)(maxm%2 + '0') + ans;
    	maxm/=2;
    }
    cout<<ans;

    return 0;
}/*

*/
