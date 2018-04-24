#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int n,m;

	while(cin>>n>>m && n && m){
		
		int matrix[n][m];

		F(i, 0, n){
			F(j, 0, m){
				cin>>matrix[i][j];
			}
		}

		int q;
		cin>>q;

		while(q--){
			int low, high;
			cin>>low>>high;

			int ans=-1000000000;
			F(i, 0, n){
				auto itr = lower_bound(matrix[i],matrix[i]+m,low);
				int x1 = itr-matrix[i],y1=i,x2=x1,y2=i;
				
				while(x2<m && y2<n && matrix[x2][y2]<=high){
					x2++;
					y2++;
				}
				ans = max(ans, y2-y1);
			}
			cout<<ans<<"\n";
		}
		cout<<"-\n";
	}
	return 0;
}