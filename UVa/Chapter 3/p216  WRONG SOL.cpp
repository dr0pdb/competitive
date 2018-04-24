#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;

int x[8],y[8],n;
double distances[8][8];

//8 and 2^8
int memo[8][256];
int nextc[8];

double  solve(int prev , int visitedMask){
	
	//everything has been visited
	if (visitedMask == (1<<n)-1)
	{
		return 0;
	}

	if (memo[prev][visitedMask] != -1)
	{
		return memo[prev][visitedMask];
	}

	double returnAns = 1000000000;
	F(i, 0, n){
		//if it has not been visited yet
		if (i != prev && !(visitedMask & (1 << i)))
		{
			double temp = distances[prev][i] + solve(i, visitedMask | (1<< i));
			
			if (temp < returnAns)
			{
				returnAns = temp;
				nextc[prev]= i;
			}
		}
	}

	return memo[prev][visitedMask] = returnAns;
}

int main(){
	std::ios::sync_with_stdio(false);

	int caseNo=1;
	while(cin>>n && n){
		F(i, 0, n){
			cin>>x[i]>>y[i];
		}

		F(i, 0, n){
			F(j, i+1, n){
				double a = x[j]-x[i];
                double b = y[j]-y[i];
				distances[i][j] = sqrt(a*a + b*b) + 16;
				distances[j][i] = distances[i][j];
			}
		}
		memset(memo,-1,sizeof(memo));
		memset(nextc, -1, sizeof(nextc));

		//printing the answer
		double ans = solve(0,1);
		cout<<"**********************************************************"<<"\n";
		cout<<"Network #"<<caseNo++<<"\n";
		
		std::cout << std::setprecision(2) << std::fixed;
		int i=0,counter=0;
		while(counter < n-1){
			cout<<"Cable requirement to connect ("<<x[i]<<","<<y[i]<<") to ("<<x[nextc[i]]<<","<<y[nextc[i]]<<") is "<<distances[i][nextc[i]]<<" feet."<<"\n";
			i = nextc[i];
            counter++;
		}
		cout<<"Number of feet of cable required is "<<ans<<".\n";
	}
	return 0;
}