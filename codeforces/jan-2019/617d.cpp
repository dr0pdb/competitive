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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int coord[3][2],ans=INF;
    F(i, 0, 3) {
    	cin>>coord[i][0]>>coord[i][1];
    }
    vi arr = {0,1,2};
    int startdir[2] = {0, 1};
    do {
    	F(di, 0, 2) {
    		int cnt=0, dir=startdir[di];
	    	int f = arr[0], s = arr[1];
	    	bool flag1 = false,flag2=false;
	    	if(coord[s][startdir[di]]-coord[f][startdir[di]] < 0) dir += 2;
	    	if(coord[s][startdir[di]] != coord[f][startdir[di]]) {
	    		flag1 = true;
	    	}

	    	if(coord[s][1-startdir[di]] != coord[f][1-startdir[di]]) {
	    		dir = startdir[1 - di];
		    	if(coord[s][1-startdir[di]]-coord[f][1-startdir[di]] < 0) dir += 2;
	    		if(flag1) cnt++;
	    		flag2 = true;
	    	}
	    	
	    	f = arr[1]; s = arr[2];
	    	flag1 = false;

	    	int cd = startdir[di];
	    	if(flag2) {
	    		cd = 1 - cd;
	    	}
	    	if(dir > 1) {
	    		if(coord[s][cd] > coord[f][cd]) {
	    			dir -= 2;
	    			cnt++;
	    		}
	    	} else {
	    		if(coord[s][cd] - coord[f][cd] < 0) {
	    			dir += 2;
	    			cnt++;
	    		}
	    	}

	    	if(coord[s][1-cd] != coord[f][1-cd]) {
	    		cnt++;
	    	}
	    	// debug_vi(arr); cout<<endl; 
	    	ans = min(ans, cnt+1);
	    	// deb(cnt+1);
	    	// deb(ans);
    	}
    } while(next_permutation(arr.begin(), arr.end()));
    cout<<ans;

    return 0;
}/*

*/