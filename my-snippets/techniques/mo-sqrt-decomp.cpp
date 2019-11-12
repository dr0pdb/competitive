#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll,ll> lll;

const ll MOD = 1000000007;
const ll INF = 1e9+5;
const double eps = 1e-7;
const double PI = acos(-1.0);

#define FOR(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define RFOR(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define ull unsigned long long
#define deb(x )     cerr << #x << " = "<< x << endl;
#define endl    "\n"
#define coud(a,d) cout << fixed << showpoint << setprecision(d) << a;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof(y))
#define all(x) (x).begin(), (x).end()
#define bitcount(x) __builtin_popcount(x)
#define cps CLOCKS_PER_SEC

inline void debug_vi(vi a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void debug_vll(vll a) {FOR(i, 0, a.size()) cout<<a[i]<<" ";}
inline void print_case(int tn) {cout<<"Case #"<<tn<<": ";}

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using maxpq = priority_queue<T>;
/*----------------------------------------------------------------------*/

struct query
{
	int l,r,k,index;
    query(int _l, int _r, int _k, int _index) {
        l = _l; r = _r; k = _k; index = _index;
    }
};
const int BOX_SIZE = 450;
bool cmp(query a, query b){
	if (a.l/BOX_SIZE != b.l/BOX_SIZE)
	{
		return a.l/BOX_SIZE < b.l/BOX_SIZE;
	}

	return a.r < b.r;
}

const int N = 1e5+5;
vector<query> queries;
bool used[N] = {false};
vi ans;

void add(int idx) {
    if(used[idx]) return;
    used[idx] = true;

    // update answer to include this idx.
}

void remove(int idx) {
    if(!used[idx]) return;
    used[idx] = false;

    // update answer variables to remove this idx.
}

void work_point( int pos, int oldL, int oldR, int newL, int newR ) {
	int oldIn = oldL <= pos && pos <= oldR;
	int newIn = newL <= pos && pos <= newR;

	if  (oldIn && !newIn) {
		remove(pos);
	}
 
	if  (!oldIn && newIn) {
		add(pos);
	}
}

int main(){
    std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    clock_t clk = clock();

    int q; cin>>q;

    // get queries from stdin.
    
    sort(all(queries), cmp);

    ans.resize(q);

    int start = 0 ,end = -1;
 	FOR(i, 0, q){
 		int l = queries[i].l;
 		int r = queries[i].r;

        for (int j = start; j != l; j > l ? j-- : j++)
			work_point(j, start, end, l, r);
		work_point(l, start, end, l, r);
 
		for (int j = end; j != r; j > r ? j-- : j++)
			work_point(j, start, end, l, r);
		work_point(r, start, end, l, r);
        
        start = l; end = r;
 		ans[queries[i].index]=0; // get answer.
 	}
    
    FOR(i, 0, q) {
        cout<<ans[i]<<endl;
    }

    cerr << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / cps << endl;
    return 0;
}