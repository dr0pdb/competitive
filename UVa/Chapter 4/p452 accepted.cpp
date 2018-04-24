#include<bits/stdc++.h>
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
#define INF 1000000000
#define EPS 1e-7
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

bool present[26];
bool visited[26];
int timing[26];
int finalTime[26];
vi dependencies[26];

void reset(){
	memset(present, false, sizeof(present));
	memset(visited, false, sizeof(visited));
	memset(timing, 0, sizeof(timing));
	F(i, 0, 26){
		dependencies[i].clear();
	}
	memset(finalTime, 0, sizeof(finalTime));
}

int computeAns(int index){

	int &currTime = finalTime[index];

	if (!visited[index])
	{
		currTime = 0;
		F(i, 0, dependencies[index].size()){
			currTime = max(currTime,computeAns(dependencies[index][i]));
		}

		currTime+=timing[index];
		visited[index]=true;
	}
	return currTime;
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	int t;
	string s;
	cin>>t;

	cin.ignore();
	cin.ignore();
	while(t--){
		reset();
		while(getline(cin,s) && s!=""){
			int vertex = s[0]-'A';
			present[vertex]=true;
			stringstream ss(s);
			char c;
			int cost;
			string dep;
			ss>>c>>cost>>dep;
			timing[vertex]=cost;
			F(i, 0, dep.size()){
				dependencies[vertex].push_back(dep[i]-'A');
				present[dep[i]-'A']=true;
			}
		}

		F(i, 0, 26){
			if (present[i])
			{
				computeAns(i);
			}
		}

		int ans = -1;
		F(i, 0, 26){
			ans = max(ans,finalTime[i]);
		}
		cout<<ans<<"\n";
		if (t)
		{
			cout<<"\n";
		}
	}	

	return 0;
}