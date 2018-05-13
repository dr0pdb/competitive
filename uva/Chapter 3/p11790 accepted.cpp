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

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int t,n;
	cin>>t;

	int ht[3000],width[3000],lis[3000],lds[3000];
	int maxin,maxdec;

	F(tn, 1, t+1){
		cin>>n;
		F(i, 0, n){
			cin>>ht[i];
		}
		F(i, 0, n){
			cin>>width[i];
		}
		maxin=0,maxdec=0;
		F(i, 0, n){
			int tempin,tempdec;
			lis[i]=width[i];
			lds[i]=width[i];
			tempin = width[i];
			tempdec = width[i];
			F(j, 0, i){
				if (ht[j]<ht[i])
				{
					lis[i] = max(lis[i],tempin+ lis[j]);
				}
				if (ht[j]>ht[i])
				{
					lds[i] = max(lds[i],tempdec+lds[j]);
				}
			}
			maxin = max(maxin,lis[i]);
			maxdec = max(maxdec,lds[i]);
		}

		cout<<"Case "<<tn<<". ";
		if (maxin>=maxdec)
		{
			cout<<"Increasing ("<<maxin<<"). Decreasing ("<<maxdec<<").\n";
		}else{
			cout<<"Decreasing ("<<maxdec<<"). Increasing ("<<maxin<<").\n";
		}
	}

	return 0;
}