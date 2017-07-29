/*
#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int v;
vector<std::vector<int> > adjlist(2550);
int dist[2550],maxboom,firstboom;
bool visited[2550];

int main(){
	std::ios::sync_with_stdio(false);
	
	cin>>v;
	F(i, 0, v){
		int n,temp;
		cin>>n;

		while(n--){
			cin>>temp;
			adjlist[i].push_back(temp);
		}
	}

	int t;
	cin>>t;

	while(t--){
		int source;
		cin>>source;

		//resetting the values
		maxboom=-1;
		memset(visited, false, sizeof(visited));


		queue<int> q;
		q.push(source);
		visited[source]=true;
        dist[source]=0;
        
		while(!q.empty()){
			int curr = q.front();
			q.pop();
			F(i, 0, adjlist[curr].size()){
				int temp = adjlist[curr][i];
				if (!visited[temp])
				{
					dist[temp] = dist[curr]+1;
					visited[temp]=true;
                    q.push(temp);
				}
			}
			
		}
		if (!adjlist[source].size())
		{
			cout<<0<<"\n";
		}else{
			int freq[2550]={0};
			F(i, 0, v){
				freq[dist[i]]++;
			}

			F(i, 1, v+1){
				if (maxboom < freq[i])
				{
					maxboom = freq[i];
					firstboom = i;
				}
			}
            cout<<maxboom<<' '<<firstboom<<"\n";
		}

	}
	return 0;
}


*/