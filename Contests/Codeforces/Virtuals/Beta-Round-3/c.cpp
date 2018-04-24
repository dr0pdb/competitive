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
const ll INF = LONG_LONG_MAX;
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

void check(int counter , bool &threex, bool &threeo, char curr) {
	if (counter == 3)
	{
		if (curr == 'X')
		{
			threex = true;
		} else {
			threeo = true;
		}
	}
}

int solve(char game[3][3]){
	bool threex = false, threeo = false;
	int counter;
	char curr;
	F(i, 0, 3){
		F(j, 0, 3){
			counter = 1;
			curr = game[i][j];
			if (curr == '.')
			{
				continue;
			}

			// down
			RF(k, j-1, 0){
				if (game[i][k] == curr)
				{
					counter++;
				} else {
					break;
				}
			}
			
			check(counter, threex, threeo, curr);

			counter = 1;
			// up
			F(k, j+1, 3){
				if (game[i][k] == curr)
				{
					counter++;
				} else {
					break;
				}
			}
			check(counter, threex, threeo, curr);

			counter = 1;
			// right
			F(k, i+1, 3){
				if (game[k][j] == curr)
				{
					counter++;
				} else {
					break;
				}
			}

			check(counter, threex, threeo, curr);


			counter = 1;
			// left
			RF(k, i-1, 0){
				if (game[k][j] == curr)
				{
					counter++;
				} else {
					break;
				}
			}

			check(counter, threex, threeo, curr);

			counter = 1;
			//down-right
			F(k, 1, 3){
				if (j-k < 0 || i+k>=3)
				{
					break;
				}

				if (game[i+k][j-k] == curr)
				{
					counter++;
				} else {
					break;
				}
			}

			check(counter, threex, threeo, curr);

			counter = 1;
			//up-left
			F(k, 1, 3){
				if (i-k < 0 || j+k>=3)
				{
					break;
				}

				if (game[i-k][j+k] == curr)
				{
					counter++;
				} else {
					break;
				}
			}

			check(counter, threex, threeo, curr);
		}
	}

	if (threex && threeo)
	{
		return -1;
	} else if (threex)
	{
		return 1;
	} else if (threeo)
	{
		return 2;
	} 
	return 0;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    char game[3][3];
    int x=0,zero=0;
    bool gamedone = true;
    F(i, 0, 3){
    	F(j, 0, 3){
    		cin>>game[i][j];
    		if (game[i][j]=='X')
    		{
    			x++;
    		} else if (game[i][j]=='0')
    		{
    			zero++;
    		} else {
    			gamedone = false;
    		}
    	}
    }

    if (x-zero >= 2 || zero > x)
    {
    	cout<<"illegal";
    	return 0;
    }
	
	int winner = solve(game);
	if (winner==1)
	{
		if (x != 1 + zero)
		{
			cout<<"illegal";
			return 0;
		}
		cout<<"the first player won";
	} else if (winner == 2)
	{
		if (zero != x)
		{
			cout<<"illegal";
			return 0;
		}
		cout<<"the second player won";
	} else if(winner == -1) {
		cout<<"illegal";
	}else if(x > zero){
		cout<< "second";
	} else {
		if (gamedone)
		{
			cout<<"draw";
		} else {
			cout<<"first";
		}
	}    
    return 0;          
}/*
    Wrong :(
*/
 