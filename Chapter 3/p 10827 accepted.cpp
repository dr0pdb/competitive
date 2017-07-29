#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	
	int mat[300][300];
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		F(i, 0, 2*n){
			F(j, 0, 2*n){
				if (i<n && j<n)
				{
					cin>>mat[i][j];
					mat[i+n][j] = mat[i][j+n] = mat[i+n][j+n]= mat[i][j];	
				}
				
				if(i>0){
					mat[i][j]+=mat[i-1][j];
				}if (j>0)
				{
					mat[i][j]+=mat[i][j-1];
				}if (i>0 && j>0)
				{
					mat[i][j]-=mat[i-1][j-1];
				}				
			}
		}

		int ans=-1000000000;
		F(i, 0, n){
			F(j, 0, n){
				F(k, i, i+n){
					F(l, j, j+n){
						int curr= mat[k][l];
						if (i>0)
						{
							curr-=mat[i-1][l];
						}
						if (j>0)
						{
							curr-=mat[k][j-1];
						}
						if (i>0 && j>0)
						{
							curr+=mat[i-1][j-1];
						}
						ans = max(ans,curr);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

