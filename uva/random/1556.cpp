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

#define maxx 40005
#define intt int

map<int,int> trie[maxx]; intt finish[maxx];
intt nxt = 1;
int cnt = 0;
map<string, int> si;
vector<string> is;

void insert (vector<string> &v){
    intt node = 0;
    for (intt i = 0; i < v.size(); i++) {
        if(trie[node].find(si[v[i]]) == trie[node].end()) {
            node = trie[node][si[v[i]]] = nxt;
            nxt++;
        } else {
            node = trie[node][si[v[i]]];
        }
    }
    finish[nxt - 1] = 1;
}

void printAll (int idx, int layer) {
	for(auto itr: trie[idx]) {
		FOR(j, 0, layer) {
			cout<<" ";
		}
		cout<<is[itr.first]<<endl;
		printAll(itr.second, layer+1);
	}
}

/*
	Split string on the basis of delimiter.
*/
vector<string> split(const string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

vector<vector<string> > allDirs;

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    while(cin>>n) {
    	allDirs.clear();
    	FOR(i, 0, maxx) {
    		trie[i].clear();
    	}
    	memset(finish, 0, sizeof(finish));
    	cnt = 0; si.clear(); is.clear();

    	string s;
	    FOR(i, 0, n) {
	    	cin>>s;
	    	vector<string> dirs = split(s, '\\');
	    	allDirs.push_back(dirs);
	    	for(auto d: allDirs[i]) {
	    		if(si.find(d) == si.end()) {
	    			si[d] = cnt++;
	    			is.push_back(d);
	    		}
	    	}
	    }
	    cnt = 0;
	    sort(is.begin(), is.end());
	    si.clear();
	    FOR(i, 0, is.size()) {
	    	si[is[i]]=cnt++;
	    }

	    for (int i = 0; i < allDirs.size(); ++i)
	    {
	    	insert(allDirs[i]);
	    }

	    printAll(0, 0);
	    cout<<endl;
    }

    return 0;
}