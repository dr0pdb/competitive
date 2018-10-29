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
inline int nextint(){ int temporary; scanf("%d",&temporary); return temporary; }
inline ll nextll(){ ll temporary; scanf("%lld",&temporary); return temporary; }
inline double nextdouble(){double temporary; scanf("%lf",&temporary); return temporary;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll leftChild(ll p ){return p<<1;}
ll rightChild(ll p ){return (p<<1)+1;}
inline ll mid(ll l, ll r){ return (l+r)/2;}
const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
#define deb(x )     cerr << #x << " here "<< x; 
#define endl    "\n"
#define pb push_back
#define mp make_pair
#define all(cc) (cc).begin(),(cc).end()

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

template<typename T > void modulize(T & a, const T & b) { if (a >= b) { a %= b; } }
ll mulmod(ll a, ll b, ll m) { ll q = (ll)(((ld)a*(ld)b) / (ld)m); ll r = a*b - q*m; if (r>m)r %= m; if (r<0)r += m; return r; }
template <typename T, typename S>T expo(T e, S n) { T x = 1, p = e; while (n) { if (n & 1)x = x*p; p = p*p; n >>= 1; }return x; }
template <typename T>T power(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mod(x*p, m); p = mod(p*p, m); n >>= 1; }return x; }
template <typename T>T powerL(T e, T n, T & m) { T x = 1, p = e; while (n) { if (n & 1)x = mulmod(x, p, m); p = mulmod(p, p, m); n >>= 1; }return x; }
template <typename T> T InverseEuler(T a, T & m) { return (a == 1 ? 1 : power(a, m - 2, m)); }

inline int two(int n) { return 1 << n; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
/*----------------------------------------------------------------------*/


vii g[1005][1005];
bool visited[1005][1005];
int t,r,c;

int getSerial(int i, int j) {
	return i * c + j;
}

vector<string> split(const string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

int findRow(string s) {
	int r = 0, mul = 1;
	RF(i, s.size()-1, 0) {
		r += mul * (s[i] - 'A');
		mul *= 10;
	}

	return r;
}

void dfs(int cx, int cy, vii &tops) {
	visited[cx][cy] = true;

	F(i, 0, g[cx][cy].size()) {
		ii next = g[cx][cy][i];
		int nx = next.first, ny = next.second;
		if(!visited[nx][ny]) {
			dfs(nx, ny, tops);
		}
	}

	tops.push_back(ii(cx, cy));
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while(t--) {
    	cin>>c>>r;
    	std::vector<vector<string> > mat(r, vector<string> (c));
    	vii dep[r][c];
    	bool det[r][c]; // value determined.
    	memset(det, true, sizeof(det));

    	F(i, 0, r) {
    		F(j, 0, c) {
    			cin>>mat[i][j];
    			if(mat[i][j][0] == '=') {
    				det[i][j] = false;
    			}
    			g[i][j].clear();
    		}
    	}

    	F(i, 0, r) {
    		F(j, 0, c) {
    			if(!det[i][j]) {
    				// parse and add edges.
    				std::vector<string> operands = split(mat[i][j].substr(1), '+');
    				int row, col;
    				string temp;

    				F(k, 0, operands.size()) {
    					string op = operands[k];
    					temp = "";
    					bool flag = false;

    					F(l, 0, op.size()) {
    						if(op[l] >= '1' && op[l] <= '9' && !flag) {
    							col = findRow(temp);
    							temp = "";
    							flag = true;
    						}
    						temp += op[l]; 
    					}
    					row = stoi(temp) - 1;
    					// cout<<" converted "<<operands[k]<<" to "<<row<<" "<<col<<endl;

    					if(!det[row][col]) {
    						g[row][col].push_back(ii(i, j));
    					}
    					dep[i][j].push_back(ii(row, col));
    				}
    			}
    		}
    	}

    	memset(visited, false, sizeof(visited));
    	vector<ii> tops;

    	// top sort.
    	F(i, 0, r) {
    		F(j, 0, c) {
    			if(!visited[i][j]) {
    				dfs(i, j, tops);
    			}
    		}
    	}

    	RF(i, tops.size()-1, 0) {
    		ii curr = tops[i];
    		int x = curr.first, y = curr.second;
    		if(!det[x][y]) {
    			// calc values
    			int val = 0;
    			F(j, 0, dep[x][y].size()) {
    				ii next = dep[x][y][j];
    				int nx = next.first, ny = next.second;
    				// cout<<" Adding value "<<mat[nx][ny]<<endl;
    				val += stoi(mat[nx][ny]);
    			}

    			mat[x][y] = to_string(val);
    		}
    	}

    	F(i, 0, r) {
    		F(j, 0, c) {
    			if(j) 
    				cout<<" ";
    			cout<<mat[i][j];
    		}
    		cout<<endl;
    	}
    }

    return 0;          
}/*
    
*/