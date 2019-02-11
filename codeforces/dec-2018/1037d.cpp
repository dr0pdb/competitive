#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RF(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define SIEVELIM 10000000+10
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
#define ull unsigned long long
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define deb(x )     cerr << #x << " here "<< x << endl;
#define endl    "\n"
#define printCase() "Case #" << caseNum << ": "

inline bool is_palindrome(const string& s){ return std::equal(s.begin(), s.end(), s.rbegin()); }

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);
/*----------------------------------------------------------------------*/

const int N = 200005;
int n,from,to;
vi g[N];
int dist[N],arr[N],num[N],par[N],num2[N];
bool visited[N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    // Pay attention to TLE in case of cin/cout. n >= 10^6.
    // Pay attention to overflow.
   	cin>>n;
   	dist[0]=0;
   	F(i, 0, n-1) {
   		cin>>from>>to;
   		from--; to--;
   		g[from].push_back(to);
   		g[to].push_back(from);
   	}

   	queue<int> q;
   	q.push(0);
   	memset(visited, false, sizeof(visited));
   	visited[0]=true;
    par[0]=-1;
    int cnt = 0;
   	while(!q.empty()) {
   		int curr = q.front(); q.pop();
      num[curr]=cnt++;

   		F(i, 0, g[curr].size()) {
   			int next = g[curr][i];
   			if(!visited[next]) {
   				visited[next]=true;
   				q.push(next);
   				dist[next] = dist[curr] + 1;
   			  par[next] = curr;
        }
   		}
   	}

   	F(i, 0, n) {
   		cin>>arr[i];
   		arr[i]--;
      num2[arr[i]]=i;
   	}
   	
   	if(arr[0] != 0) {
   		cout<<"No";
   		return 0;
   	}

    int maxm=0;
    bool valid= true;
    F(i, 1, n) {
      if((num[par[i]] < num2[par[i]] && num[i] >= num2[i]) || (num[par[i]] > num2[par[i]] && num[i] <= num2[i])) {
        valid = false;
        break;
      }

      if(dist[arr[i]] < maxm) {
        valid = false;
        break;
      }

      maxm = max(maxm, dist[arr[i]]);
    }

    if (valid)
    {
      cout<<"Yes";
    } else {
      cout<<"No";
    }
   	
    return 0;
}/*

*/
