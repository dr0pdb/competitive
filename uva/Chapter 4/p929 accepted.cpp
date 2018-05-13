#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef pair<int,ii> iii;

int n,m;
int dist[1000][1000],matrix[1000][1000];

int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};

bool check(int x, int y){
	return !(x <0 || x>=n || y<0 || y>=m);
}

int main(){
	std::ios::sync_with_stdio(false);
	int p;
	cin>>p;

	while(p--){
		
		
		//getting the input
		cin>>n>>m;
		

		//clearing the values
		F(i, 0, n){
			F(j, 0, m){
				dist[i][j]=1000000000;
			}
		}

		//getting the input
		F(i, 0, n){
			F(j, 0, m){
				cin>>matrix[i][j];
			}
		}

		//solve
		priority_queue<iii, vector<iii> , greater<iii> > pq;
		pq.push(iii(matrix[0][0],ii(0,0)));
		dist[0][0]=matrix[0][0];

		while(!pq.empty()){
			iii front = pq.top();
			pq.pop();

			int d = front.first;
			int ux = front.second.first;
			int uy = front.second.second;
			if (dist[ux][uy] < d)	
			{
				continue;
			}
			F(j, 0, 4){
				int vx = ux+dirx[j],vy= uy+diry[j];
				if(check(vx,vy)){
					if (dist[ux][uy]+ matrix[vx][vy] < dist[vx][vy])
					{
						dist[vx][vy] = dist[ux][uy]+ matrix[vx][vy]; 
						pq.push(iii(dist[vx][vy],ii(vx,vy)));
					}
				}
				
			}
		}
        
		//printing the results
		cout<<dist[n-1][m-1]<<"\n";
	}
	
	return 0;
}

