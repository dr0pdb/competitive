	#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;

#define INF 1000000000
int memo[310][310];
int coin_left[40],coin_right[40];
int m,s;

int change(int x , int y){
	if (x<0 || y <0)
	{
		return INF;
	}

	if (x == 0 && y==0)
	{
		return 0;
	}

	if (memo[x][y] !=-1)
	{
		return memo[x][y];
	}

	int minValue = INF;

	F(i, 0,m){
		int temp = 1 + change(x-coin_left[i],y-coin_right[i]);
		if (temp < minValue)
		{
			minValue = temp;
		}
	}	

	return memo[x][y]= minValue;
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
    cin>>n;
	while(n--){

		cin>>m>>s;

		F(i, 0, m){
			cin>>coin_left[i]>>coin_right[i];
		}
		memset(memo, -1, sizeof(memo));
        
        RF(i, s, 0){
            RF(j, s, 0){
        	   change(i,j);	
            }	
        }
		
		//searching for the answer from the memo
		bool solFound=false;
		int ans= INF;
		F(i, 0, 310){
			F(j, 0, 310){
				if ((i*i+j*j == s*s) && memo[i][j] < ans && memo[i][j] != -1)
				{   
					solFound = true;
					ans=memo[i][j];
				}
			}
		}

		if (solFound)
		{
			cout<<ans<<"\n";
		}else{
			cout<<"not possible"<<"\n";
		}

	}
	
	return 0;
}