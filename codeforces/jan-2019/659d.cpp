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

int cx[1005], cy[1005];

int get(int i) {
	int dir = 0;
	if(cy[i] == cy[i+1]) {
		if(cx[i+1] < cx[i]) {
			dir = 1;
		}
	} else {
		if(cy[i+1] > cy[i]) {
			dir = 2;
		} else {
			dir = 3;
		}
	}
	return dir;
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n,cnt=0;
    cin>>n;

    F(i, 0, n+1) {
		cin>>cx[i]>>cy[i];	
    }

    F(i, 1, n) {
    	int dir[2];
    	dir[0] = get(i-1); dir[1]=get(i);
    	switch(dir[0]) {
    		case 0:
    			if(dir[1] == 2) {
    				cnt++;
    			}
    			break;
			case 1:
				if(dir[1] == 3) {
					cnt++;
				}
				break;
			case 2:
				if(dir[1] == 1) {
					cnt++;
				}
				break;
			default:
				if(dir[1] == 0) {
					cnt++;
				}
    	}
    }

    cout<<cnt;

    return 0;
}/*

*/
