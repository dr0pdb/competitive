#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int p[105],ranks[105];
int n,m;
std::vector<pair<int,ii> > edgeList;

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

	while(t--){
		cin>>n>>m;
		edgeList.clear();

		int a,b,c;
		F(i, 0, m){
			cin>>a>>b>>c;
			a--;
			b--;
			edgeList.push_back(make_pair(c, ii(a,b)));
		}

		sort(edgeList.begin(), edgeList.end());
		resetUF();

		int mst_cost=0;
		bool usedInMst[m]={false};

		F(i, 0, edgeList.size()){
			pair<int,ii> curr = edgeList[i];
			if (!isSameSet(curr.second.first,curr.second.second))
			{
				mst_cost+=curr.first;
				join(curr.second.first,curr.second.second);
				usedInMst[i] = true;
			}
		}

		int second_min_mst = 1000000,temp=0;
		

		F(i, 0, edgeList.size()){
			int dontuse;
			if (usedInMst[i])
			{
				dontuse = i;
			}else{
				continue;
			}
			temp=0;
            resetUF();
			F(j, 0, edgeList.size()){

				pair<int,ii> curr = edgeList[j];
				if (!isSameSet(curr.second.first,curr.second.second) && j!=dontuse)
				{
					temp+=curr.first;
					join(curr.second.first,curr.second.second);
				}
			}
			if (temp<mst_cost)
			{
				continue;
			}
			second_min_mst = min(second_min_mst,temp);
		}
		cout<<mst_cost<<" "<<second_min_mst<<"\n";
	}

	return 0;
}