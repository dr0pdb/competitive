#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);


	//The problem is very similar to the max 2-d range sum problem but in 3-d
	int t;
	cin>>t;

	while(t--){
		cin.ignore();

		int a,b,c;
		cin>>a>>b>>c;

		long long memo[a][b][c];

		//setting the memo table
		F(i, 0, a){
			F(j, 0, b){
				F(k, 0, c){
					long long temp;
					cin>>temp;
					if(i>0)temp+= memo[i-1][j][k];
					if(j>0)temp+= memo[i][j-1][k];
					if(k>0)temp+= memo[i][j][k-1];
					if(i>0 && j>0)temp-= memo[i-1][j-1][k];
					if(j>0 && k>0)temp-= memo[i][j-1][k-1];
					if(i>0 && k>0)temp-= memo[i-1][j][k-1];
					if(i>0 && j>0 && k>0)temp+=memo[i-1][j-1][k-1];
					memo[i][j][k]= temp;
				}
			}
		}

		//finding the answer
		long long answer = LLONG_MIN;
		F(i, 0, a){
			F(j, 0, b){
				F(k, 0, c){
					F(i2, i, a){
						F(j2, j, b){
							F(k2, k, c){
								long long sum = memo[i2][j2][k2];
								/*
									Sum contains the sum of all elements from (0,0,0) to (i2,j2,k2)
									so we need to subtract the unnecessary sum
								*/	
								if(i>0)sum-= memo[i-1][j2][k2];
								if(j>0)sum-= memo[i2][j-1][k2];
								if(k>0)sum-= memo[i2][j2][k-1];
								if(i>0 && j>0)sum+= memo[i-1][j-1][k2];
								if(j>0 && k>0)sum+= memo[i2][j-1][k-1];
								if(i>0 && k>0)sum+= memo[i-1][j2][k-1];
								if(i>0 && j>0 && k>0)sum-=memo[i-1][j-1][k-1];

								//saving the max value of sum
								if (sum > answer)
								{
									answer = sum;
								}
							}
						}
					}
				}
			}
		}

		cout<<answer<<"\n";
		if (t)
		{
			cout<<"\n";
		}
	}

	return 0;
}