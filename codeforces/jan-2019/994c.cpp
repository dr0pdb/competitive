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

int cnt[505][505];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    ii sq[2][4];
    set<int> sx,sy;
    F(i, 0, 2) {
    	F(j, 0, 4) {
    		cin>>sq[i][j].first>>sq[i][j].second;
    		if(i == 0) {
    			sx.insert(sq[i][j].first);
    			sy.insert(sq[i][j].second);
    		}
    	}
    	sort(sq[i], sq[i]+4);
    }
    memset(cnt, 0, sizeof(cnt));
    int sxvals[2], syvals[2];
    auto itr = sx.begin(); sxvals[0] = *itr; itr++;
    sxvals[1]=*itr;
    itr = sy.begin(); syvals[0]=*itr; ++itr;
    syvals[1]=*itr;
    F(i, sxvals[0], sxvals[1]+1) {
    	F(j, syvals[0], syvals[1]+1) {
    		cnt[i+250][j+250]++;
    	}
    }

    int disp=0,y=sq[1][0].second;
    sxvals[0]=sq[1][0].first; sxvals[1]=sq[1][3].first;
    while(sxvals[0]<=sxvals[1]) {
    	F(i, sxvals[0], sxvals[1]+1) {
    		cnt[i+250][y+disp+250]++;
    		// cout<<"Writing to "<<i+250<<" "<<y+disp+250<<endl;
			// cout<<"Writing to "<<i    		
    		if(disp) {
    			cnt[i+250][y-disp+250]++;
    		}
    	}
    	disp++;
    	sxvals[0]++; sxvals[1]--;
    }

    int maxm=1;
    F(i, 0, 505) {
    	F(j, 0, 505) {
    		maxm = max(maxm, cnt[i][j]);
    	}
    }

    if(maxm == 2) {
    	cout<<"YES";
    } else {
    	cout<<"NO";
    }

    return 0;
}/*

*/
