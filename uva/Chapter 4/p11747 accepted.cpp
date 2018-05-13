#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int p[1010],ranks[1010];
int n;
vector<pair<int, ii> > edgeList(25010);
vector<int> results;
//if it is the representative then return itself otherwise return parent of it's immediate parent
int findSet(int i){
	return (p[i]==i)? i : p[i]=findSet(p[i]);
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

void join(int i, int j,int wt){
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
	}else{
		results.push_back(wt);
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
		results.clear();
		
		//getting the input
		int x,y,w;
		F(i, 0, e){
            cin>>x>>y>>w;
			edgeList[i] = make_pair(w,make_pair(x,y));
		}

		sort(edgeList.begin(),edgeList.begin()+ e);

		F(i, 0, e){
			pair<int, ii> current = edgeList[i];
			join(current.second.first,current.second.second,current.first);
		}

		sort(results.begin(),results.end());
		if (results.size() == 0)
		{
			cout<<"forest";
		}else{
			F(i, 0, results.size()){
				if (!i)
				{	
					cout<<results[i];
				}else{
					cout<<" "<<results[i];
				}
			}
		}
		cout<<"\n";
	}

	return 0;
}

