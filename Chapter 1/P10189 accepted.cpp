#include <stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	long Flag=0;
	int testcase=1;
	int n;
	int m;
	while (true)
	{
	
	cin>>n>>m;
	if (n==0 && m==0)
	{
		break;
	}
	
	else
		{
			char minefield[n][m];
			int  answer[n][m];

			for(int x=0;x<n;x++){
    		
    		
    		for(int y=0;y<m;y++){
    			cin>>minefield[x][y];
    			
    		}
    		
    	}
    	
		for(int x=0;x<n;x++){
    		
    		
    			for(int y=0;y<m;y++){
    			
    				if(minefield[x][y]=='*'){
    					answer[x][y]=-1;
    					continue;
    				}
    				
    				int count=0;
    				
    				if(x-1>=0 && y-1>=0 && minefield[x-1][y-1]=='*'){
    					count++;
    				}
    				if(y-1>=0 && minefield[x][y-1]=='*'){
    					count++;
    				}
    				if(x+1<n && y-1>=0 && minefield[x+1][y-1]=='*'){
    					count++;
    				}
    				if(x-1>=0 && minefield[x-1][y]=='*'){
    					count++;
    				}
    				if(x+1<n && minefield[x+1][y]=='*'){
    					count++;
    				}
    				if(x-1>=0 && y+1<m && minefield[x-1][y+1]=='*'){
    					count++;
    				}
    				if(y+1<m && minefield[x][y+1]=='*'){
    					count++;
    				}
    				if(y+1<m && x+1<n && minefield[x+1][y+1]=='*'){
    					count++;
    				}
    				
    				answer[x][y]=count;
    				
    		}
    		
    	}
			
			if (Flag==1)
			{printf("\n");
			}

        	Flag = 1;

			cout << "Field #" << testcase << ":\n";
    		
    		for(int x=0;x<n;x++){
    			for(int y=0;y<m;y++){
    				
					if (answer[x][y]==-1)
					{
						cout << '*';
					}
					else
					{
					cout << answer[x][y];		
					}
				
    	
    			}
				cout << "\n";
    		}
    		testcase++;
    		

		}

	}
	return 0;
}

