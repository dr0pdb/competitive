#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
std::vector<int> graph,sum;
std::vector<bool> visited;

int dfs(int i){
	visited[i]=true;
	int curr=0;
	if (graph[i] !=-1 && !visited[graph[i]])
	{
		curr+=1+dfs(graph[i]);
	}
	visited[i]=false;
	return sum[i]=curr;
}

int main()
{	
    //std::ios::sync_with_stdio(false);
    int t,n,u,v;
    cin>>t;

	for (int i = 1; i <=t; ++i)
    {
    	cin>>n;
    	
    	graph.assign(n+1,-1);
    	sum.assign(n+1,-1);
    	visited.assign(n+1,false);

    	for (int j = 1; j <= n; ++j)
    	{
    		cin>>u>>v;
    		graph[u]=v;
    	}

    	for (int j = 1; j <=n; ++j)
    	{
    		if (sum[j] ==-1)
    		{
    			dfs(j);
    		}
		}
		int max_index=0,max_score=-1;
		for (int j = 1; j <= n; ++j)
		{     
			if(sum[j]>max_score){
				max_score=sum[j];
				max_index=j;
			}
		}
        printf("Case %d: %d\n",i,max_index);
    }
    
	return 0;
} 
