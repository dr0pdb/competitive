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
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

#define MOD 10000
bool visited[10000+10];

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int l,u,r,tn=1;
	vi values(12);
	while(cin>>l>>u>>r && (l+u+r)){

		memset(visited,false,sizeof(visited));

		int value;
		F(i, 0, r){
			cin>>value;
			values[i]=value;
		}

		queue<int> q;
		q.push(l);
		visited[l]=true;
		int dist[MOD];
		F(i, 0, MOD){
			dist[i]=INF;
		}
		dist[l]=0;
		while(!q.empty()){
			int curr = q.front();
			q.pop();
			F(i, 0, r){
				int value = curr + values[i];
				value%=MOD;
				if (!visited[value])
				{
					dist[value] = dist[curr]+1;
					visited[value]=true;
					q.push(value);
				}
			}
		}
		cout<<"Case "<<tn++<<": ";
		if (dist[u]==INF)
		{
			cout<<"Permanently Locked\n";
		}else{
			cout<<dist[u]<<"\n";
		}
	}

	return 0;
}