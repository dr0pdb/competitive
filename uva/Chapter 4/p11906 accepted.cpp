#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define mes(i,a) memset(a,i,sizeof(a))
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int t,r,c,w,m,n;
char mat[100][100];
int kvalue[100][100];

int dir[2][4]={
	{1,1,-1,-1},{1,-1,1,-1}
};

bool check(int u, int v){
	if (u<0 || u>=r || v<0 || v>=c)
	{
		return false;
	}
	return true;
}

int givek(int u, int v){	

	int ans=0;
	set<ii> vis;

	F(i, 0, 4){
		int p=u+dir[0][i]*m;
		int q=v+dir[1][i]*n;
		if (check(p,q) && mat[p][q]=='0' && vis.find(ii(p,q))==vis.end())
		{
			vis.insert(ii(p,q));
			ans++;
		}
        p=u+dir[0][i]*n;
	    q=v+dir[1][i]*m;
        //cout<<p<<"ssdsfsfsfs"<<q<<endl;
		if (check(p,q) && mat[p][q]=='0' && vis.find(ii(p,q))==vis.end())
		{
			vis.insert(ii(p,q));
			ans++;
		}
	}
	return ans;
}

void solve(int x, int y){
	if (!check(x,y))
	{
		return;
	}

	kvalue[x][y] = givek(x,y);
    
	F(i, 0, 4){
		int p=x+dir[0][i]*m;
		int q=y+dir[1][i]*n;
		if (check(p,q) && kvalue[p][q]==-1 && mat[p][q]=='0')
		{
			solve(p,q);
		}
        
        p=x+dir[0][i]*n;
	    q=y+dir[1][i]*m;
        if (check(p,q) && kvalue[p][q]==-1 && mat[p][q]=='0')
		{
			solve(p,q);
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	
	cin>>t;

	F(tn, 1, t+1){
		cin>>r>>c>>m>>n;
		mes('0', mat);
		mes(-1,kvalue);

		cin>>w;
		int x,y;
		F(i, 0,w){
			cin>>x>>y;
			mat[x][y]='1';
		}

		solve(0,0);

		//counting the answers
		int odd=0,even=0;
		F(i, 0, r){
			F(j, 0, c){
				if (kvalue[i][j] == -1)
				{
					continue;
				}
				else if (kvalue[i][j]%2)
				{
					odd++;
				}else{
					even++;
				}
			}
		}

		cout<<"Case "<<tn<<": "<<even<<" "<<odd<<"\n";
	}

	return 0;
}