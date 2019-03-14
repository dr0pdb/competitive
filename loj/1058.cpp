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

ii coords[1005];
map<ii,vector<ii>> m;

ii get_slope(int i, int j) {
	if(i > j) return get_slope(j, i);
	int dx = coords[j].first - coords[i].first;
	int dy = coords[j].second - coords[i].second;

	if(dy < 0) {
		dx *= -1;
		dy *= -1;
	}

	int g = __gcd(abs(dx), dy);
	if(g) {
		dx /= g;
		dy /= g;
	}

	return {dx, dy};
}

int main(){
    // std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int t,n;
	cin>>t;

	F(tn, 1, t+1) {
		cout<<"Case "<<tn<<": ";
		cin>>n;
		m.clear();
		F(i, 0, n) {
			cin>>coords[i].first>>coords[i].second;
		}

		F(i, 0, n) {
			F(j, i+1, n) {
				ii slope = get_slope(i, j);
				m[slope].push_back({i, j});
			}
		}

		int ans = 0;

		for(auto itr: m) {
			ii slope = itr.first;
			vector<ii> pts = itr.second;
			if(pts.size() < 2) continue;

			F(i, 0, pts.size()) {
				F(j, i+1, pts.size()) {
					ii pa = pts[i], pb = pts[j];
					ii slp1 = get_slope(pa.first, pb.first);
					ii slp2 = get_slope(pa.first, pb.second);
					ii slp3 = get_slope(pa.second, pb.first);
					ii slp4 = get_slope(pa.second, pb.second);
					
					if((slp1 == slp4 && slp2 != slp3) || (slp2 == slp3 && slp1 != slp4)) {
						ans++;
						break;
					}
				}
			}
		}

		ans /= 2;
		cout<<ans<<endl;
	}

    return 0;
}/*

*/