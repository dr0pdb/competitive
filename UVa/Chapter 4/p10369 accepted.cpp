#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;

int p[510],ranks[510];
vector<pair<double, ii> > edgeList;
double answer;
vector <pair<int,int> >vertices;
int s,posts;


//if it is the representative then return itself otherwise return parent of it's immediate parent
int findSet(int i){
	return (p[i]==i)? i : p[i]=findSet(p[i]);
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

void join(int i, int j,double wt){
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
	//std::ios::sync_with_stdio(false);
	
	int t;
	cin>>t;

	while(t--){
		cin>>s>>posts;

		//clearing the values
		F(i, 0, posts){
			p[i]=i;
			ranks[i]=0;
		}
		answer = -1;
		edgeList.clear();
		vertices.clear();

		int x,y;
		F(i, 0, posts){
			cin>>x>>y;
			vertices.push_back(make_pair(x,y));
		}

		//calculating the distance between each node
		F(i, 0, posts){
			F(j, i+1, posts){
				pair<int,int> p1,p2;
				p1 = vertices[i];
				p2 = vertices[j];

				double dist = sqrt((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
				edgeList.push_back(make_pair(dist,make_pair(i,j)));
			}
		}

		sort(edgeList.begin(),edgeList.end());
		int edges_used = 0;
		//finding the forest
		F(i, 0, edgeList.size()){
			pair<double, ii> curr = edgeList[i];
			if (!isSameSet(curr.second.first,curr.second.second))
			{
				join(curr.second.first,curr.second.second,curr.first);
				edges_used++;
			}

			if (edges_used == posts-s)
			{
				answer = curr.first;
				break;
			}
		}

		//printing the answer
		printf("%.2f\n",answer);

	}
	return 0;
}

