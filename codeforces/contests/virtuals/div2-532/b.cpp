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

const int M = 1e5+5;
int arr[M],freq[M];

bool cmp(ii a, ii b) {
	return a.first >= b.first;
}

priority_queue<ii, vii, std::function<bool(ii, ii)> > pq(cmp);
int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,cnt=0,f=0;
    cin>>n>>m;

    memset(freq, 0, sizeof(freq));
    F(i, 0, m) {
    	cin>>arr[i];
    	if(freq[arr[i]] == 0) f++;
    	freq[arr[i]]++;
		pq.push({freq[arr[i]], arr[i]});
		while(!pq.empty() && pq.top().first < freq[pq.top().second]) {
			pq.pop();
		}

		if(!pq.empty() && pq.top().first == cnt + 1 && f==n) {
			cnt++;
			cout<<1;
			continue;
		}
    	cout<<0;
    }

    return 0;
}/*

*/
