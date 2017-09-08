#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int area[105][105];
int t,r,c;
int dp[105][105]; //dp[i][j] stores the highest length ending at i,j.

int dfs (int x, int y)
{
    if ( dp [x] [y] != -1 ) return dp [x] [y];
 	
 	//important to initialise at 0,serves for the base cases
    int up = 0, down = 0, right = 0, left = 0;
 
    if ( x != 0 && area [x - 1] [y] < area [x] [y] )
        up = dfs (x - 1, y) + 1;
 
    if ( x != r - 1 && area [x + 1] [y] < area [x] [y] ) 
        down = dfs (x + 1, y) + 1;
 
    if ( y != 0 && area [x] [y - 1] < area [x] [y] ) 
        left = dfs (x, y - 1) + 1;
 
    if ( y != c - 1 && area [x] [y + 1] < area [x] [y] ) 
        right = dfs (x, y + 1) + 1;
 
    return dp [x] [y] = max (up, max (down, max (right, left)));
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	

	string s;
	cin>>t;

	while(t--){
		memset(dp,-1,sizeof(dp));
		cin>>s>>r>>c;
		F(i, 0, r){
			F(j, 0, c){
				cin>>area[i][j];
			}
		}

		int ans = -INF;

		F(i, 0, r){
			F(j, 0, c){
				ans = max(ans,dfs(i,j));
			}
		}
		cout<<s<<": "<<ans+1<<"\n";

	}

	return 0;
}