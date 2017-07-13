#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;

//11 and 2^11
int memo[11][2048];
int world[15][2];	//x and y- 0th index has the starting point
int x,y,n;

//Helper method to return the distance between two beepers based on indexing
int dis(int i1, int i2){
	return abs(world[i1][0]-world[i2][0]) + abs(world[i1][1] - world[i2][1]);
}

int solve(int prev , int bmask){
	
	//we have visited all the beepers, time to go home
	if(bmask == ((1 << n) - 1))
        return dis(prev,0);

	if (memo[prev][bmask] != -1)
	{
		return memo[prev][bmask];
	}

	int answer = 1000000000;

	F(i, 1, n){
		if (i != prev && !(bmask & (1<<i)))
		{
            int changed = ((1<<i) | bmask);
			int temp = dis(prev, i) + solve(i, changed);
            if(temp < answer){
                answer = temp;
            }
		}	
	}

	return memo[prev][bmask] = answer;
}

int main(){
	std::ios::sync_with_stdio(false);
	
	int t;
	cin>>t;

	
	while(t--){
		cin>>x>>y;
		F(i,0,10){
            F(j,0,1024){
                memo[i][j] = -1;
            }
        }

		cin>>world[0][0]>>world[0][1];
		cin>>n;
        n++;
		F(i, 1, n){
			cin>>world[i][0]>>world[i][1];
		}

		int ans = solve(0,1);
		cout<<"The shortest path has length "<<ans<<"\n";
	}	

	return 0;
}