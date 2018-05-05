#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define SIEVELIM 10000000
#define MOD 1000000000+7
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

bool visited[100010];
vector<long long int> adjlist[100010];
long long int color[100010];
long long int a=0,b=0;

void dfs(long long int i){
	visited[i]=true;

	F(j, 0, adjlist[i].size()){
		int curr = adjlist[i][j];
		if (!visited[curr])
		{
			color[curr]=1-color[i];
			if (color[curr]==0)
			{
				a++;
			}else{
				b++;
			}
			dfs(curr);
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	long long int n;
	cin>>n;

	memset(visited, false, sizeof(visited));
	memset(color,-1,sizeof(color));

	long long int u,v;
	F(i, 0, n-1){
		cin>>u>>v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}

	F(i, 1, n+1){
		if (!visited[i])
		{
			if (a<b)
			{
				color[i]=0;
				a++;
			}else{
				color[i]=1;
				b++;
			}
			dfs(i);
		}
	}
	

	long long int ans = a*b + 1- n;


	if (ans>0)
	{
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}