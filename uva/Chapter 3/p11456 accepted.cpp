/*
 * Since we have to calculate lis and lds for the sequence starting at i, the best way to approach this problem
 * is to reverse the array first. Now we have to calculate lds and lis for sequence ending at i.
 * 
 * This answer was helpful-https://www.quora.com/What-is-an-intuitive-explanation-for-UVA-11456-Trainsorting/answer/Eugene-Yarovoi?srid=u9d08
 * */

#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);

	int arr[2020];
	int t,n;
	cin>>t;

	while(t--){
		cin>>n;
		RF(i, n-1, 0){
			cin>>arr[i];
		}

		//getting the LIS
		int lis[n];
		F(i, 0, n){
			lis[i]=1;
		}

		F(i, 1, n){
			F(j, 0, i){
				if (arr[j] < arr[i] && lis[j]+1 > lis[i])
				{
					lis[i]=lis[j]+1;
				}
			}
		}

		//getting the lds
		int lds[n];
		F(i, 0, n){
			lds[i]=1;
		}

		F(i, 1, n){
			F(j, 0, i){
				if (arr[j] > arr[i] && lds[j]+1 > lds[i])
				{
					lds[i]=lds[j]+1;
				}
			}
		}

		int answer = 0;
		F(i, 0, n){
			answer = max(answer, lis[i]+lds[i]-1);
		}
		cout<<answer<<"\n";
	}
	return 0;
}
