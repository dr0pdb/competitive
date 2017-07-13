#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int p[200010],ranks[200010];
std::map<string, int> si;
int n;
int sizes[200010];

//if it is the representative then return itself otherwise return parent of it's immediate parent
int findSet(int i){
	return (p[i]==i)? i : p[i]=findSet(p[i]);
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

int join(int i, int j){
	if (!isSameSet(i,j))
	{
		int x = findSet(i),y = findSet(j);
		if(sizes[x] < sizes[y]){
			p[x] = y;
			return sizes[y]+=sizes[x];
			
		}else{
			p[y] = x;
			return sizes[x]+=sizes[y];
		}

	}
	return sizes[findSet(i)];
}

int main(){
	std::ios::sync_with_stdio(false);
	
	int t;
	cin>>t;
	int f;
	string a,b;

	while(t--){

		cin>>f;

		//reset the values
		F(i, 0, 2*f){
			p[i]=i;
			ranks[i]=0;
			sizes[i]=1;
		}
		n=0;
		si.clear();

		F(i, 0, f){
			cin>>a>>b;
			if (si.find(a) == si.end() )
			{
				si[a]=n++;
			}
			if(si.find(b) == si.end()){
				si[b]=n++;
			}

			int ans = join(si[a],si[b]);

			//print the values
			cout<<ans<<"\n";
		}
	}

	return 0;
}

