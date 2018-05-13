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

#define INF 1000000000
int adjmaty[26][26];
int adjmatm[26][26];

void reset(){
	F(i, 0, 26){
		F(j, 0, 26){
			if (i==j)
			{
				adjmaty[i][j]=0;
				adjmatm[i][j]=0;
			}else{
				adjmaty[i][j]=INF;
				adjmatm[i][j]=INF;	
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int e;
	while(cin>>e && e){
		char type,dir,from,to;
		int wt;

		reset();

		F(i, 0, e){
			cin>>type>>dir>>from>>to>>wt;
			if (type=='Y')
			{
				if (from==to)
				{
					continue;
				}
				adjmaty[from-'A'][to-'A']=wt;
				if (dir=='B')
				{
					adjmaty[to-'A'][from-'A']=wt;
				}
			}else{
				if (from==to)
				{
					continue;
				}
				adjmatm[from-'A'][to-'A']=wt;
				if (dir=='B')
				{
					adjmatm[to-'A'][from-'A']=wt;
				}
			}
		}
		char start1,start2;
		cin>>start1>>start2;

		F(k, 0, 26){
			F(i, 0, 26){
				F(j, 0, 26){
					adjmatm[i][j] = min(adjmatm[i][j],adjmatm[i][k]+adjmatm[k][j]);
					adjmaty[i][j] = min(adjmaty[i][j],adjmaty[i][k]+adjmaty[k][j]);
				}
			}
		}

		int total=INF;
		vector<char> pos;
		F(i, 0, 26){
			if (adjmaty[start1-'A'][i]+ adjmatm[start2-'A'][i] < total)
			{
				total = adjmaty[start1-'A'][i]+ adjmatm[start2-'A'][i];
				pos.clear();
				pos.push_back(char(i+'A'));
			}else if (adjmaty[start1-'A'][i]+ adjmatm[start2-'A'][i] == total)
			{
				pos.push_back(char(i+'A'));
			}
		}		
		if (total==INF)
		{
			cout<<"You will never meet.\n";
		}else{
			sort(pos.begin(),pos.end());
			cout<<total;
			F(i, 0, pos.size()){
				cout<<" "<<pos[i];
			}
			cout<<"\n";
		}
	}
	return 0;
}

