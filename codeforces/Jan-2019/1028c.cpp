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
/*----------------------------------------------------------------------*/

const int N = 132680;
ii b[N], t[N]; int x[2],y[2];
map<int, int> mx,my,mx2,my2;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;

    F(i, 0, n) {
    	F(j, 0, 2) {
    		cin>>x[j]>>y[j];
    	}
    	b[i] = {x[0], y[0]};
    	t[i] = {x[1], y[1]};
    	mx[x[0]]++; mx2[x[1]]++;
    	my[y[0]]++; my2[y[1]]++;
    }

    F(i, 0, n) {
    	mx[b[i].first]--; my[b[i].second]--;
    	mx2[t[i].first]--; my2[t[i].second]--;
    	int bxmax=INT_MIN, bymax=INT_MIN;
    	int txmin=INT_MAX, tymin=INT_MAX;
    	auto itr = mx.end(); itr--;
    	if(itr->second == 0) {
    		itr--;
    	}
    	bxmax = itr->first;
    	itr = my.end();
    	itr--;
    	if(itr->second == 0) {
    		itr--;
    	}
    	bymax = itr->first;

    	itr = mx2.begin();
		if(itr->second == 0) {
    		itr++;
    	}
    	txmin = itr->first;
    	itr = my2.begin();
		if(itr->second == 0) {
    		itr++;
    	}
    	tymin = itr->first;

    	if(bxmax <= txmin && bymax <= tymin) {
    		cout<<bxmax<<" "<<bymax;
    		return 0;
    	}

    	mx[b[i].first]++; my[b[i].second]++;
    	mx2[t[i].first]++; my2[t[i].second]++;
    }

    return 0;
}/*

*/
