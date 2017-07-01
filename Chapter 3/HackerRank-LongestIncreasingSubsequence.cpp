/*
	From Hackerrank algorithm section
*/

#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;
int s[1000050]={0};

int bSearch(int start, int end , int target){
	while(end-start > 1){
		int mid = start + (end-start)/2;
		if (s[mid] >= target)
		{
			end = mid;
			if (s[mid] == target)
			{
				break;
			}
		}else{
			start = mid;
		}
	}
	return end;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;

	int len=0;
	int temp;
	F(i, 0, n){
		cin>>temp;
		if (i==0)
		{
			s[i]=temp;
			len++;
		}else{
			if (temp < s[0] )
			{
				s[0]=temp;
			}else if (temp > s[len-1])
			{
				s[len++]=temp;
			}else{
				//replace the smallest number larger than temp
				int pos = bSearch(-1,len-1,temp);
				s[pos]= temp;
			}
		}

	}
	cout<<len;
	return 0;
}