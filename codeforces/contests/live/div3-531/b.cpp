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

const int N = 5005;
int arr[N];
map<int, vi> m;
bool used[N],done[N][N];

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    int k,n;
    cin>>n>>k;

    F(i, 0, n) {
    	cin>>arr[i];
    	m[arr[i]].push_back(i);
    }

    bool valid = true;
    // memset(arr, -1, sizeof(arr));s
    memset(used, false, sizeof(used));
    memset(done, false, sizeof(done));

    F(i, 0, k) {
    	done[i+1][arr[i]]=true;
    	arr[i] = i+1;
    	used[i]=true;
    }

   	for(auto itr: m) {
   		if(itr.second.size() > k) {
   			valid = false;
   			break;
   		}

   		vi id = itr.second;
   		for(auto curr: id) {
   			int color = 1;
   			while(done[color][itr.first]) {
   				color++;
   			}

   			if(!used[curr]) {
   				used[curr] = true;
   				arr[curr]=color;
   				done[color][itr.first]=true;
   			}
   		}
   	}

   	if(!valid) {
   		cout<<"NO";
   		return 0;
   	}
   	cout<<"YES\n";
   	F(i, 0, n) {
   		cout<<arr[i]<<" ";
   	}

    return 0;
}/*

*/
