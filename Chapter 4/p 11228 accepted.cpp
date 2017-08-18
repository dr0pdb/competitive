#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int p[1005],ranks[1005];
int n,r;
vii coordinates;
std::vector<pair<double,ii> > edgeList;

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

double distance(int x1,int y1,int x2, int y2){
	return pow(((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)),0.5);
}

void buildEdgeList(){
	edgeList.clear();
	F(i, 0, n){
		F(j, i,n){
			ii one = coordinates[i];
			ii two = coordinates[j];
			double dist = distance(one.first,one.second,two.first,two.second);
			edgeList.push_back(make_pair(dist,ii(i,j)));
		}
	}
}

void resetUF(){
	F(i, 0, n+1){
		p[i]=i;
		ranks[i]=0;
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	cin>>t;

	F(tn, 1, t+1){
		cin>>n>>r;
		coordinates.clear();

		int x,y;
		F(i, 0, n){
			cin>>x>>y;
			coordinates.push_back(ii(x,y));
		}

		resetUF();
		buildEdgeList();
		sort(edgeList.begin(),edgeList.end());

		double states=1,costroad=0,costtrack=0;

		F(i, 0, edgeList.size()){
			pair<double,ii> curr = edgeList[i];
			if (!isSameSet(curr.second.first,curr.second.second))
			{
				if (curr.first<=(double)r)
				{
					costroad+=curr.first;
					join(curr.second.first,curr.second.second);
				}else{
					states++;
					costtrack+=curr.first;
					join(curr.second.first,curr.second.second);
				}
			}
		}

		cout<<"Case #"<<tn<<": "<<states<<" "<<round(costroad)<<" "<<round(costtrack)<<"\n";
	}

	return 0;
}