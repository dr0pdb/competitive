/*
 * Another useful method has been shown in this video
 * https://www.youtube.com/watch?v=yCQN096CwWM&t=3s&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=15
 * */


#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
using namespace std;

int main(){
	//std::ios::sync_with_stdio(false);
	
	int n;
	scanf("%d",&n);
	int maxSum = -127*100*100,currSum;
	int arr[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &arr[i][j]);
			if (i>0)		
			{
				arr[i][j] += arr[i-1][j];
			}if (j>0)
			{
				arr[i][j]+= arr[i][j-1];
			}if (i>0 && j>0)
			{
				arr[i][j]-= arr[i-1][j-1];
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = i; k < n; ++k)
			{
				for (int l = j; l < n; ++l)
				{
					currSum = arr[k][l];

					if (i>0)
					{
						currSum-= arr[i-1][l];
					}
					if (j>0)
					{
						currSum -= arr[k][j-1];
					}
					if (i>0 && j>0)
					{
						currSum += arr[i-1][j-1];
					}
					if (currSum > maxSum)
					{
						maxSum = currSum;
					}
					
				}
			}
		}
	}

	printf("%d\n",maxSum);

	return 0;
}
