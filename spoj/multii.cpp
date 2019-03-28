#include<bits/stdc++.h>
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

const int N = 10005;
bool visited[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,tmp,tn=1;
    while(cin>>n>>m) {
	    set<int> forbidden;
    	FOR(i, 0, m) {
    		cin>>tmp;
    		forbidden.insert(tmp);
    	}
    	vi digs;
    	FOR(i, 0, 10) {
    		if(forbidden.find(i) != forbidden.end()) continue;
    		digs.push_back(i);
    	}
    	cout<<"Case "<<tn++<<": ";
    	memset(visited, false, sizeof(visited));
    	queue<pair<string,int> > q;
    	bool found = false;
    	for(int num : digs) {
    		if(num == 0) continue;
    		string val = to_string(num);
			q.push({val, num % n});
			visited[num%n]=true;
			if(num % n == 0) {
				cout<<val<<endl;
				found = true;
				break;
			}
    	}
    	if(found) continue;

    	while(!q.empty()) {
    		if(found) break;
    		string val = q.front().first;
    		m = q.front().second; q.pop();

    		FOR(i, 0, digs.size()) {
    			int nextm = (m * 10 + digs[i])%n;
    			if(!visited[nextm]) {
    				val += to_string(digs[i]);
	    			if(nextm == 0) {
	    				cout<<val<<endl;
	    				found = true;
	    				break;
	    			}
	    			visited[nextm]=true;
	    			q.push({val, nextm});
	    			val.pop_back();
    			}
    		}
    	}

    	if (!found)
    	{
    		cout<<-1<<endl;
    	}
    }

    return 0;
}