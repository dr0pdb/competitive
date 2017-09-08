#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int x,y,p1,p2;
int dist[2010][2010];
int mall[2010][2010];
queue<ii>q;

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

bool check(int x, int y) {
    return x >= 0 && x < 2000 &&
           y >= 0 && y < 2000;
}

int bfs(){
	while(!q.empty()){
		ii curr = q.front();
		q.pop();

		F(i, 0, 4){
			int nx= curr.first+di[i];
			int ny = curr.second+dj[i];
			if (check(nx, ny))		
			{
				if (dist[nx][ny]==-1)
				{
					dist[nx][ny] = dist[curr.first][curr.second]+1;
					if (mall[nx][ny]==2)
					{
						return dist[nx][ny];
					}
					q.push(ii(nx,ny));
				}
			}
		}
	}
	return -1;
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
		
	while(cin>>p1 && p1){
		cin.ignore();
		memset(mall, 0, sizeof(mall));
		memset(dist,-1,sizeof(dist));

		q = queue<ii>();

		F(i, 0, p1){
			cin>>x>>y;
			mall[x][y]=1;
			q.push(ii(x,y));
			dist[x][y]=0;
		}

		cin>>p2;
		F(i, 0, p2){
			cin>>x>>y;
			mall[x][y]=2;
		}

		int ans = bfs();
		cout<<ans<<"\n";
	}

	return 0;
}