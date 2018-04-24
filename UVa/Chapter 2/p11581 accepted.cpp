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

int mat[10000][3][3];
int dirx[4]={1,0,-1,0};
int diry[4]={0,1,0,-1};

bool isValid(int x, int y){
	return (x>=0 && x<3)&& (y>=0 && y<3);
}

bool completed(int iteration){
	F(i, 0, 3){
		F(j, 0, 3){
			if (mat[iteration][i][j])
			{
				return false;
			}
		}
	}
	return true;
}

int solve(int iteration){

	if (completed(iteration))	
	{
		return -1;
	}

	F(i, 0, 3){
		F(j, 0, 3){
            int cell=0;
			F(k, 0, 4){
				int p = i + dirx[k];
				int q = j + diry[k];
				if (isValid(p, q) && mat[iteration][p][q])
				{
					cell++;
				}
			}
				mat[iteration+1][i][j]=cell%2;
		}
	}
	
	return 1 + solve(iteration+1);
}

int main(){
	//std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int t;
	cin>>t;


	while(t--){
		F(i, 0, 3){
			F(j, 0, 3){
				scanf("%1d",&mat[0][i][j]);
			}
		}

		cout<<solve(0)<<"\n";

	}

	return 0;
}