/*
	Unable to find out why it is not getting accepted :(
*/

#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
int main()
{	
    std::ios::sync_with_stdio(false);
	int t,v,e,t1,t2,fcount,tcount,current,ans;
	cin>>t;
	bool isPoss;

	while(t--){
		cin>>v>>e;
		vector<int> adjList[v];
		bool visited[v]={false};
		bool color[v]={false};
		fcount=1;
		tcount=0;
		isPoss=true;
		ans=0;

		for (int i = 0; i < e; ++i)
		{
			cin>>t1>>t2;
			adjList[t1].push_back(t2);
			adjList[t2].push_back(t1);
		}
		stack<int>s;
		for (int i = 0; i < v && isPoss; ++i)
		{	
			fcount=1;
			tcount=0;
			if (!visited[i])
			{
				s.push(i);
				while(!s.empty() && isPoss){
					current=s.top();
					s.pop();
					visited[current]=true;
					for(auto itr = adjList[current].begin(); itr != adjList[current].end(); ++itr){
						if (!visited[*itr])
						{
							s.push(*itr);
							color[*itr]=!color[current];
							if (color[*itr])
							{
								tcount++;
							}else{
								fcount++;
							}
						}else if(color[*itr]==color[current]){
							isPoss=false;
							break;
						}
					}
				}
                if (tcount==0)
			     {
				    ans+=1;
			     }else{
				    ans+=min(fcount,tcount);
			     }
            }

		}
		if (!isPoss)
		{
			cout<<-1<<"\n";
		}else{
			cout<<ans<<"\n";
		}

	}
	
   	return  0;
	
} 
