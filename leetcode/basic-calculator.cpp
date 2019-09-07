/**
    __author__ : srv_twry
**/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}

bool ge(const ll& a, const ll& b) { return a >= b; }
bool le(const ll& a, const ll& b) { return a <= b; }
bool eq(const ll& a, const ll& b) { return a == b; }
bool gt(const ll& a, const ll& b) { return a > b; }
bool lt(const ll& a, const ll& b) { return a < b; }
int sgn(const ll& x) { return le(x, 0) ? eq(x, 0) ? 0 : -1 : 1; }
/*----------------------------------------------------------------------*/

// supports only + and -.
int calculate(string s) {
	int sign = 1, res = 0, curr = 0;
	for(char c : s) {
		if(isdigit(c)) {
			curr = 10 * curr + c - '0';
		} else if(c == '+') {
			res += sign * curr;
			sign = 1;
			curr = 0;
		} else if(c == '-') {
			res += sign * curr;
			sign = -1;
			curr = 0;
		}
	}
	res += sign * curr;
	return res;
}

// handles + , - and (). Basic Calculator I on Leetcode.
int calculate2(string s) {
	int sign = 1, res = 0, curr = 0;

	stack<int> st;
	for(char c : s) {
		if(isdigit(c)) {
			curr = 10 * curr + c - '0';
		} else if(c == '+') {
			res += sign * curr;
			sign = 1;
			curr = 0;
		} else if(c == '-') {
			res += sign * curr;
			sign = -1;
			curr = 0;
		} else if(c == '(') {
			st.push(res);
			st.push(sign);
			res = 0, curr = 0, sign = 1;
		} else if(c == ')') {
			res += sign * curr;
			curr = 0;
			sign = st.top(); st.pop();
			res = st.top() + sign * res; st.pop();
		}
	}
	res += sign * curr;
	return res;
}

// handles +, -, * and /. Basic Calculator II on Leetcode.
// Better solution here: https://leetcode.com/problems/basic-calculator-ii/discuss/63003/Share-my-java-solution/239365
// with O(1) space and a lot cleaner.
int calculate3(string s) {
	int res = 0, curr = 0;
	vector<int> st;
	char lastoperator = '+';
	int n = s.size();
	for(int i = 0; i < s.size(); i++) {
		char c = s[i];
		if(isdigit(c)) {
			curr = 10 * curr + (c - '0');
		} 
		if(c == ' ') continue;
		else if(!isdigit(c) || i == n - 1) {
			if (lastoperator == '+')
			{
				st.push_back(curr);
			} else if(lastoperator == '-') {
				st.push_back(-curr);
			} else if(lastoperator == '*') {
				int tmp = st.back() * curr;
				st.pop_back();
				st.push_back(tmp);
			} else {
				int tmp = st.back() / curr;
				st.pop_back();
				st.push_back(tmp);
			}
			lastoperator = c;
			curr = 0;
		}
	}

	for(int t : st) res += t;
	return res;	
}

int calculate4(string s) {
	int res = 0;

	
	
	return res;	
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // cout<<calculate("123 + 13")<<endl;
    // cout<<calculate("123 + 13 - 12 + 12 + 1")<<endl;
    // cout<<calculate("19 - 20 + 12")<<endl;
    // cout<<calculate("14 +12-10+144+17")<<endl;


    // cout<<calculate2("123 + 13")<<endl;
    // cout<<calculate2("123 + 13 - 12 + 12 + 1")<<endl;
    // cout<<calculate2("19 - 20 + 12")<<endl;
    // cout<<calculate2("(1+(4+5+2)-3)+(6+8)")<<endl;
    

    cout<<calculate3("3+2*2*2")<<endl;
    cout<<calculate3("3/2")<<endl;
    cout<<calculate3("3+5/2")<<endl;
    cout<<calculate3("2147483647")<<endl; // handle overflow
    cout<<calculate3("0-2147483647")<<endl;
    cout<<calculate3("1-1+1")<<endl;
    return 0;
}