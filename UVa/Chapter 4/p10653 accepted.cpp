#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int r,c;
int start[2],target[2];
int dist[1010][1010];
bool visited[1010][1010];

int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};

bool testit(int newx,int newy){
	if (newx <0 || newx>=r)
	{
		return false;
	}

	if (newy < 0 || newy >=c)
	{
		return false;
	}

	if (visited[newx][newy])
	{
		return false;
	}

	return true;
}

int main(){
	std::ios::sync_with_stdio(false);
	
	while(cin>>r>>c && r && c){
		int x;
		cin>>x;

		//resetting the values
		memset(visited, false, sizeof(visited));

		while(x--){
			int row,n,loc;
			cin>>row>>n;
			F(i, 0, n){
				cin>>loc;
				dist[row][loc]=-1;
				visited[row][loc]=true;
			}
		}

		cin>>start[0]>>start[1];
		cin>>target[0]>>target[1];

		//solve 
		queue<pair<int,int> >q;
		q.push(make_pair(start[0],start[1]));

		visited[start[0]][start[1]]=true;
		bool ansFound = false;
		dist[start[0]][start[1]]=0;

		while(!q.empty() && !ansFound){
			pair<int, int> curr = q.front();
			q.pop();
			visited[curr.first][curr.second]=true;

			F(i, 0, 4){
				int newx = curr.first+ dirx[i];
				int newy = curr.second + diry[i];
				if (testit(newx,newy))
				{
                    dist[newx][newy] = dist[curr.first][curr.second]+1;
					if (newx==target[0] && newy==target[1])
					{
						ansFound=true;
						break;
					}
					visited[newx][newy]=true;
					q.push(make_pair(newx, newy));
					
				}
			}
			
		}

		cout<<dist[target[0]][target[1]]<<"\n";
	}

	return 0;
}

