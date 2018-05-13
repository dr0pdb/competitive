#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
int t,n,counter;
char matrix[105][105];
int rowDir[]={0,1,0,-1};
int colDir[]={1,0,-1,0};
void dfs(int j,int k){
    
    if(j<0 || j>=n || k<0 || k>=n || matrix[j][k]=='.'){
        return;
    }
    	
    matrix[j][k]='.';	
	for (int i = 0; i < 4; ++i)
	{
		dfs(j+rowDir[i],k+colDir[i]);
	}
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
    		}
    	}
        //dfs based flood fill
    	for (int j = 0; j < n; ++j)
    	{
    		for (int k = 0; k < n; ++k)
    		{
    			
				if (matrix[j][k]=='x')
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
