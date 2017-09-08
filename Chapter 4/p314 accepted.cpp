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

struct node{
	int x,y,times,direction;
	node(int a, int b, int c ,int d){
		x = a;
		y = b;
		direction = c;
		times = d;
	}
};

int n,m;
int mat[55][55];
bool visited[55][55][4];

int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};

bool check(int i,int j){
	if (i<=0 || i>=m || j<=0 || j>=n)
	{
		return false;
	}
	if (mat[i-1][j] || mat[i][j] || mat[i][j-1] || mat[i-1][j-1])
	{
		return false;
	}
	return true;
}

int findTime(int sx,int sy, int ex , int ey, int cd){

	queue<node> q;
	if (check(sx,sy))
	{
		q.push(node(sx,sy,cd,0));
		visited[sx][sy][cd]=true;
	}

	while(!q.empty()){
		node curr = q.front();
		q.pop();

		if (curr.x==ex && curr.y==ey)
		{
			return curr.times;
		}

		if (!visited[curr.x][curr.y][(curr.direction+1)%4])
		{
			visited[curr.x][curr.y][(curr.direction+1)%4]=true;
			q.push(node(curr.x,curr.y,(curr.direction+1)%4,curr.times+1));
		}
		if (!visited[curr.x][curr.y][(curr.direction+3)%4])
		{
			visited[curr.x][curr.y][(curr.direction+3)%4]=true;
			q.push(node(curr.x,curr.y,(curr.direction+3)%4,curr.times+1));
		}

		F(i, 1, 4){
			if (check(curr.x+di[curr.direction]*i,curr.y+dj[curr.direction]*i))
			{
				if (!visited[curr.x+di[curr.direction]*i][curr.y+dj[curr.direction]*i][curr.direction])
				{
					visited[curr.x+di[curr.direction]*i][curr.y+dj[curr.direction]*i][curr.direction]=true;
					q.push(node(curr.x+di[curr.direction]*i,curr.y+dj[curr.direction]*i,curr.direction,curr.times+1));
				}
			}else break;
		}
	}

	return -1;
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	while(cin>>m>>n && (n+m)){
		memset(visited,false,sizeof(visited));
		F(i, 0, m){
			F(j, 0, n){
				cin>>mat[i][j];
			}
		}

		int start[2],end[2];
		string dir;
		cin>>start[0]>>start[1]>>end[0]>>end[1]>>dir;
		
		int currDir;
		if(dir[0]=='n') currDir=0;
        else if(dir[0]=='e') currDir=1;
        else if(dir[0]=='s') currDir=2;
        else currDir=3;

        int result = findTime(start[0],start[1],end[0],end[1],currDir);
        cout<<result<<"\n";
	}

	return 0;
}