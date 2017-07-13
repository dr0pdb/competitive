#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

bool hasEdge[26]={false};


int main(){
	std::ios::sync_with_stdio(false);
	
	int t;
	cin>>t;
	string in;

	while(t--){
		memset(hasEdge,false,sizeof(hasEdge));

		
		int ne=0,nve=0,nv = 0;
		while(cin>>in){
			if (in[0] == '*')
			{
				break;
			}
			hasEdge[in[1]-'A']=true;
			hasEdge[in[3]-'A']=true;
			ne++;
		}

		
		string vertices;
		cin>>vertices;

		F(i, 0, vertices.length()){
			if (vertices[i] != ',')
			{
				nv++;
			}
		}

		F(i, 0, 26){
			if (hasEdge[i])
			{
				nve++;
			}
		}

		cout<<"There are "<<(-ne+nve)<<" tree(s) and "<<(nv-nve)<<" acorn(s)."<<"\n";
	}
	return 0;
}

