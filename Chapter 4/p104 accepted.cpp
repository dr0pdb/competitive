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
	
	

	int n;
	while(cin>>n){

		//answer for going from i to j in k steps(edges)
		double ans[20][20][20]={0};
		int path[20][20][20];

		F(i, 0, n){
			F(j, 0, n){
				path[i][j][0]=i;
				if (i==j)
				{
					ans[i][j][0]=1.0;
				}else{
					cin>>ans[i][j][0];
				}
			}
		}

		bool ansFound=false;

		F(edges, 1, n){
			F(k, 0, n){
				F(i, 0, n){
					F(j, 0, n){
						double temp = ans[i][k][edges-1]*ans[k][j][0];
						if (temp> ans[i][j][edges])
						{
							ans[i][j][edges]=temp;
							path[i][j][edges]=k;
						}
					}
				}
			}
		}

		F(edges, 1, n){
			F(i, 0, n){
				if (ans[i][i][edges]>1.01)
				{
					int seq[edges];
					seq[edges]=path[i][i][edges];
					RF(j, edges-1, 0){
						seq[j] = path[i][seq[j+1]][j];
					}
					F(j, 0, edges+1){
						cout<<seq[j]+1<<" ";
					}
					cout<<seq[0]+1<<"\n";
					ansFound=true;
					break;
				}
			}
			if (ansFound)
			{
				break;
			}
		}

		if (!ansFound)
		{
			cout<<"no arbitrage sequence exists\n";
		}

	}

	return 0;
}