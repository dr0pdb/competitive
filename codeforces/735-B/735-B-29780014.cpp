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
	//std::ios::sync_with_stdio(false);
	
	double ans=0.0;
	int n,n1,n2;
	cin>>n>>n1>>n2;

	int arr[n];
	F(i, 0, n){
		cin>>arr[i];
	}
	sort(arr, arr+n,greater<int>());
	int a=min(n1,n2);
	int b=max(n1,n2);

	double s=0;
	F(i, 0, a){
		s+=arr[i];
	}
	s/=(double)a;
	ans+=s;
	s=0;
	F(i, a, a+b){
		s+=arr[i];
	}

	s/=(double)b;
	ans+=s;
	printf("%.8f\n",ans);
	return 0;
}