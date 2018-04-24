#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int n,m;
std::vector<std::vector<int> > adjlist(30);
map<string,int> strInt;
std::vector<string> intStr(30);
int num[30],low[30],visited[30],dfsCounter,numSoFar;
vi s;
bool scc;

void dfs(int u){
	
	num[u]=low[u]= dfsCounter++;
	s.push_back(u);
	visited[u]= true;

	F(i, 0, adjlist[u].size()){
		int v = adjlist[u][i];
		
		if (num[v] == -1)
		{
			dfs(v);
		}	

		if (visited[v])
		{
			low[u] = min(low[u],low[v]);
		}
	}
	
	if (low[u]==num[u])
	{
		bool first=true;	
		
		while(true){
			int v = s.back();
			s.pop_back();
			visited[v]=false;

			if (first)
			{
				cout<<intStr[v];
				first = false;
			}else{
				cout<<", "<<intStr[v];
			}

			if (u == v)
			{
				break;
			}
		}
        cout<<"\n";
	}
	
}


int main(){
	std::ios::sync_with_stdio(false);

	int t=1;
    bool start=true;
	while(cin>>n>>m){
	       
        if((!n) && (!m)){
            break;
        }
        
		//resetting the values
		F(i, 0, n){
			adjlist[i].clear();
			num[i]=-1;
			low[i]=-1;
			visited[i]=false;

		}
		s.clear();
		dfsCounter = 0;
		numSoFar=0;
		strInt.clear();
        intStr.clear();
        
		//getting the input
		string v,w;
		F(i, 0, m){
			cin>>v>>w;
            if (strInt.find(v) == strInt.end())
            {
            	strInt[v]=numSoFar;
            	intStr[numSoFar++]=v;
            }
            if (strInt.find(w) == strInt.end())
            {
            	strInt[w]=numSoFar;
            	intStr[numSoFar++]=w;
            }

			adjlist[strInt[v]].push_back(strInt[w]);
		}
        if(!start){
            cout<<"\n";
        }
        start=false;
        cout<<"Calling circles for data set "<<t++<<":\n";

		//solve
		F(i, 0, n){
			if (num[i] == -1)
			{
				dfs(i);
			}
		}
        
	}

	return 0;
}

