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

const int N = 105;
string arr[N];
vi topsort;
bool g[N][N], poss;
int visited[30];

void dfs(int curr) {
	if(!poss) return;
	visited[curr] = 1;
	for(int nxt = 0; nxt < 26; ++nxt) {
		if(curr == nxt || g[curr][nxt] == false) continue;
		if(!visited[nxt]) {
			dfs(nxt);
		} else if(visited[nxt] == 1) {
			poss = false;
			return;
		}
	}
	visited[curr] = 2;
	topsort.push_back(curr);
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, maxm=0;
    cin>>n;
	FOR(i, 0, n) {
		cin>>arr[i];
		maxm = max(maxm, (int)arr[i].size());
	}
	memset(g, false, sizeof(g));
	FOR(i, 0, n) {
		FOR(j, i+1, n) {
			bool flag = false;
			FOR(k, 0, min(arr[i].size(), arr[j].size())) {
				if(arr[i][k] == arr[j][k]) continue;
				char a = arr[i][k], b = arr[j][k];
				g[a-'a'][b-'a']=true;
				flag = true;
				break;			
			}

			if(!flag && (arr[i].size() > arr[j].size())) {
				cout<<"Impossible";
				return 0;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	poss = true;
	FOR(i, 0, 26) {
		if(!visited[i] && poss) dfs(i);
	}
	if(poss) {
		reverse(topsort.begin(), topsort.end());
		FOR(i, 0, topsort.size()) {
			cout<<(char)(topsort[i] + 'a');
		}
	} else {
		cout<<"Impossible";
	}

    return 0;
}