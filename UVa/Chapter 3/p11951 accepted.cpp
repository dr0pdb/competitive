#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define mes(i,a) memset(a,i,sizeof(a))
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;


int main(){
	std::ios::sync_with_stdio(false);

	int t;
	cin>>t;

	int n,m,k;
	int prices[101][101];
	F(tn, 1, t+1){
		cin>>n>>m>>k;
		F(i, 0, n){
			F(j, 0, m){
				cin>>prices[i][j];
				if (i>0)		
				{
					prices[i][j]+=prices[i-1][j];
				}
			}
		}

		int maxarea=0;
		int mincost=0;

		F(i, 0, n){
			F(j, i, n){
				int area = 0;
                int cost = 0;
                int start = 0;

                F(l, 0, m){
                	int colCost = prices[j][l];
                	if (i>0)
                	{
                		colCost-=prices[i-1][l];
                	}
                	cost+=colCost;
                	if (cost>k)
                	{
                		while(cost>k){
                			cost -= prices[j][start];
                            if(i > 0) cost += prices[i - 1][start];
                            start++;
                		}
                	}

                	area = (l-start+1)*(j-i+1);
                	if (area == maxarea)
                	{
                		if (cost<mincost)
                		{
                			mincost = cost;
                		}
                	}else if(area> maxarea){
                		mincost=cost;
                		maxarea = area;
                	}
                }
                
			}
		}
		cout<<"Case #"<<tn<<": "<<maxarea<<" "<<mincost<<"\n";
	}

	return 0;
}

