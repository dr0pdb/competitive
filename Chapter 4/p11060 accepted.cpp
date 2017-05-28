#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;

//This will be used by the priority queue to sort the queue based on the order in which they were entered
struct compareval
{
    bool operator()(const int& a, const int& b)
    {
        return a > b;
    }
};

int main()
{	
    //std::ios::sync_with_stdio(false);
    int n,m,caseno=1,temp;
    string b1,b2;

    while(cin>>n && n>=0){

    	vector<int> adjList[n];
    	int indeg[n]={0};
    	unordered_map<string,int> maps;
    	string intString[n];		//to get the string key of the value

    	for (int i = 0; i < n; ++i)
    	{
    		cin>>b1;
    		maps[b1]=i;
    		intString[i]=b1;
    	}
    	cin>>m;
    	for (int i = 0; i < m; ++i)
    	{
    		cin>>b1>>b2;
    		adjList[maps[b1]].push_back(maps[b2]);
    		indeg[maps[b2]]++;
    	}
    	
        priority_queue<int,vector<int>, compareval> pq;
    	queue<int>result;
    	//topological sort

    	for (int i = 0; i < n; ++i)
    	{
    		if (!indeg[i])
    		{
    			pq.push(i);
    		}
    	}
    	while(!pq.empty()){
    		temp=pq.top();
            result.push(temp);
    		pq.pop();
    		for(auto itr = adjList[temp].begin(); itr !=adjList[temp].end(); ++itr){
    			indeg[*itr]--;
    			if (!indeg[*itr])
    			{
    				pq.push(*itr);
    			}
    		}
    	}


    	printf("Case #%d: Dilbert should drink beverages in this order:",caseno++);
    	while(!result.empty()){
    		temp=result.front();
    		result.pop();
    		cout<<" "<<intString[temp];
    	}
    	cout<<"."<<"\n\n";
    }
   	return 0;
} 
