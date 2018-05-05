#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	cin>>n;

 	vii exams;
 	int x,y;
	F(i, 0, n){
		cin>>x>>y;
		exams.push_back(ii(x,y));
	}

	sort(exams.begin(),exams.end());
	int last=-1;
	F(i, 0, n){
		ii curr = exams[i];
		if (curr.second >= last)
		{
			last = curr.second;
		}else{
			last = curr.first;
		}
	}

	cout<<last;

	return 0;
}