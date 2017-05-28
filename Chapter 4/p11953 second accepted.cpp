#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
int t,n,counter;
char matrix[105][105];
bool visited[105][105];

void dfs(int j , int k){
	

	//right
	if (j+1<n && !visited[j+1][k] && matrix[j+1][k]!='.' )
	{
		dfs(j+1,k);
	}
	//bottom
	if(k+1<n && !visited[j][k+1] && matrix[j][k+1]!='.'){
		dfs(j,k+1);
	}
    visited[j][k]=true;
}

int main()
{	
    std::ios::sync_with_stdio(false);
    
    cin>>t;

    for (int i = 1; i <= t; ++i)
    {
    	counter=0;
    	cin>>n;

    	for (int j = 0; j < n; ++j)
    	{
    		for (int k = 0; k < n; ++k)
    		{
    			cin>>matrix[j][k];
    			visited[j][k]=false;
    		}
    	}
        //dfs based flood fill
    	for (int j = 0; j < n; ++j)
    	{
    		for (int k = 0; k < n; ++k)
    		{
    			
				if (!visited[j][k] && matrix[j][k]=='x')
				{
					dfs(j,k);
                    counter++;
				}
				
    		}
    	}

    	cout<<"Case "<<i<<": "<<counter<<"\n";
    }
   	return  0;
} 
