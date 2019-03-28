#include <iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits>
#include<math.h>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
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

#define MAX_N 10010

string P,T;
int prefix[MAX_N], n, m, ans; // n = size of text, m = size of pattern.

void kmpPreprocess() {
	int i = 0, j = -1; prefix[0] = -1;

	while (i < m) {
		while (j >= 0 && P[i] != P[j]) j = prefix[j];
		i++; j++;
		prefix[i] = j;
	} 
}

void kmpSearch() {
	int i = 0, j = 0; 

	while (i < n) {
		while (j >= 0 && T[i] != P[j]) j = prefix[j];
		i++; j++;
		if (j == m) {
			ans++;
			j = prefix[j]; // prepare j for the next possible match
		}
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int t;
	cin>>t;

	while(t--) {
		cin>>P>>T;
		ans = 0;
		m = P.size(); n = T.size();
		kmpPreprocess();
		kmpSearch();
		cout<<ans<<endl;
	}


    return 0;
}