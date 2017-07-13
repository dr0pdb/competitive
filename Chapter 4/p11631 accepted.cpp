#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int p[200010],ranks[200010];
int n;
vector<pair<int, ii> > edgeList;

//if it is the representative then return itself otherwise return parent of it's immediate parent
int findSet(int i){
	return (p[i]==i)? i : p[i]=findSet(p[i]);
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

void join(int i, int j){
	if (!isSameSet(i,j))
	{
		int x = findSet(i),y = findSet(j);
		if(ranks[x] > ranks[y]){
			p[y] = x;
		}else{
			p[x] = y;
			if (ranks[x] == ranks[y])
			{
				ranks[y]++;
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	
	int v,e;

	while(cin>>v>>e && v && e){

		//reset the values
		F(i, 0, v){
			p[i]=i;
			ranks[i]=0;
		}
		edgeList.clear();

		int totalWt=0;
		int wt,x,y;
		F(i, 0, e){
			cin>>x>>y>>wt;
			totalWt+=wt;
			edgeList.push_back(make_pair(wt,make_pair(x,y)));
		}
		sort(edgeList.begin(),edgeList.end());

		int mstCost=0;
		F(i, 0, e){
			pair<int, ii> current = edgeList[i];
			if (!isSameSet(current.second.first, current.second.second))
			{
				mstCost+=current.first;
				join(current.second.first,current.second.second);
			}
		}

		cout<<totalWt-mstCost<<"\n";

	}

	return 0;
}

