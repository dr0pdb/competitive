#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define MIN3(a,b,c) (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c))
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN2(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef long long ll;

int counter[105];
bool participated[105];
int penalty[105];
int tempP[105][11];
bool solved[105][11];

bool comp(int a, int b){
	if (counter[a]!=counter[b])
	{
		return counter[a]>counter[b];
	}else if(penalty[a] != penalty[b]){
		return penalty[a]<penalty[b];
	}else{
		return a<b;
	}
}

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	stringstream ss;
	int t;
	cin>>t;
    cin.ignore();cin.ignore();

	while(t--){
		
		memset(participated,false,sizeof(participated));
		memset(solved,false,sizeof(solved));
		memset(penalty, 0, sizeof(penalty));
		memset(tempP, 0, sizeof(tempP));
		memset(counter, 0, sizeof(counter));

		int contestant,problem,times;
		char l;
		string str;

		while(true){
            
			int contestant,problem,times;
			char l;
            
            string s, tmp;
            getline(cin, s);
            if(s.length() == 0) {break;if(t)cin.ignore();}
            int k = 0; 
            while(s[k] != ' ') {tmp += s[k]; k++;}
            contestant = stoi(tmp); k++;
            tmp = "";
            while(s[k] != ' ') {tmp += s[k]; k++;}
            problem = stoi(tmp); k++;
            tmp = "";
            while(s[k] != ' ') {tmp += s[k]; k++;}
            times = stoi(tmp); k++;
            l = s[s.length()-1];
            
			participated[contestant]=true;
			if (l=='C' && !solved[contestant][problem])
			{
				solved[contestant][problem]=true;
				penalty[contestant]+=times+tempP[contestant][problem];
				counter[contestant]++;
			}else if (l == 'I')
			{
				tempP[contestant][problem]+=20;
			}
		}

		std::vector<int> v;
		F(i, 1, 101){
			if (participated[i])
			{
				v.push_back(i);
			}
		}

		sort(v.begin(),v.end(),comp);
		F(i, 0, v.size()){
			cout<<v[i]<<" "<<counter[v[i]]<<" "<<penalty[v[i]]<<"\n";
		}
		if (t)
		{
			cout<<"\n";
		}
	}

	return 0;
}