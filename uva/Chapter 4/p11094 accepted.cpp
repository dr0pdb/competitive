#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
char matrix[25][25];
int maximum,current;
int m,n,currx,curry;
char land;

int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};

void dfs(int i, int j,bool isCurrentIsland){
	

	if (j==n)
	{
		j=0;
	}

	if (j==-1)
	{
		j=n-1;
	}

	if (i<0 || i==m|| matrix[i][j]!=land)
	{
		return;
	}

	if (!isCurrentIsland)
	{
		current++;
		if (current>maximum)	
		{
			maximum=current;
		}	
	}
	if (land !='w')
	{
		matrix[i][j]='w';
	}else{						//this just to make sure land is not denoted by 'w' in some cases
		matrix[i][j]='q';
	}
	

	for (int k = 0; k < 4; ++k)
	{
		dfs(i+dirx[k],j+diry[k],isCurrentIsland);
	}
	
}

int main()
{	
    std::ios::sync_with_stdio(false);
	
	while(cin>>m>>n && m>=0 &&n>=0 ){
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>matrix[i][j];
			}
		}
		cin>>currx>>curry;
		land=matrix[currx][curry];
	    maximum=0;
	    dfs(currx,curry,true);			//this to mark the current island as water as it should not be considered for the result
		for (int i = 0; i < m; ++i)
	    {
	    	for (int j = 0; j < n; ++j)
	    	{
	    		if (matrix[i][j]==land)
	    		{
	    			current=0;
	    			dfs(i,j,false);
	    		}
	    	}
	    }
	    cout<<maximum<<"\n";
	    cin.ignore();
    }
   	return  0;
	
} 
