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

#define MAXM 10005

int main(){
	std::ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

	int arr[MAXM];
	int n,t;

	while(cin>>n && n){
		F(i, 0, n){
			cin>>arr[i];
		}
		if (t++)
		{
			cout<<"\n";
		}
		sort(arr,arr+n);

		int boxes = 1,counter=1;
		F(i, 1, n){
			if (arr[i]==arr[i-1])
			{
				counter++;
			}else{
				boxes = max(boxes,counter);
				counter=1;
			}
		}
		boxes = max(boxes,counter);
		cout<<boxes<<"\n";
		F(i, 0, boxes){
			cout<<arr[i];
			for (int j = i+boxes; j < n; j+=boxes)
			{
				cout<<" "<<arr[j];
			}
			cout<<"\n";
		}

	}

	return 0;
}