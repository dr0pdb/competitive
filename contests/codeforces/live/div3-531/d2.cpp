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

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;

    string s;
    cin>>s;

    int cnt[3];
    memset(cnt, 0, sizeof(cnt));

    vector<deque<int> > pos(3);
    bool issue = false;
    F(i, 0, n) {
    	int curr = s[i]-'0';
    	pos[curr].push_back(i);
    	cnt[curr]++;
    	if(cnt[curr] > n/3) {
    		issue = true;
    	}
    }

    if(issue) {
		while(cnt[0] > n/3 && cnt[2] < n/3) {
			s[pos[0].back()]='2';
			pos[0].pop_back();
			cnt[0]--; cnt[2]++;	
		}

		while(cnt[0] > n/3 && cnt[1] < n/3) {
			s[pos[0].back()]='1';
			pos[0].pop_back();
			cnt[0]--; cnt[1]++;
		}

    	while(cnt[1] > n/3 && cnt[0] < n/3) {
    		s[pos[1].front()]='0';
    		pos[1].pop_front();
    		cnt[0]++; cnt[1]--;
    	}

    	while(cnt[1] > n/3 && cnt[2] < n/3) {
    		s[pos[1].back()]='2';
			pos[1].pop_back();
			cnt[1]--; cnt[2]++;
    	}

    	while(cnt[2] > n/3 && cnt[0] < n/3) {
    		s[pos[2].front()]='0';
    		pos[2].pop_front();
    		cnt[0]++; cnt[2]--;
    	}

    	while(cnt[2] > n/3 && cnt[1] < n/3) {
    		s[pos[2].front()]='1';
			pos[2].pop_front();
			cnt[2]--; cnt[1]++;
    	}
    } 

    cout<<s;

    return 0;
}/*

*/
