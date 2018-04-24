#include <stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	
	while (true)
	{
		int n;
		cin>>n;

		if (n==0)
		{
			break;
		}

		else
		{
			cout<<"Printing order for "<<n<<" pages:"<<endl;
			if (n%4==0)
			{
				

				for (int i = 1; i <=n/4; i++)
				{
					cout<<"Sheet "<<i<<", front: "<<n-2*(i-1)<<", "<<(2*i)-1<<endl;
					cout<<"Sheet "<<i<<", back : "<<2*i<<", "<<n-((2*i)-1)<<endl;
				}



			}
			
			else
			{
				int x;
				x=n+(4-n%4);

				
				for (int i = 1; i <=n/4+1; i++)
				{
					//front part
					
					if (x-2*(i-1)>n && (2*i)-1<=n)
					{
					cout<<"Sheet "<<i<<", front: "<<"Blank"<<", "<<(2*i)-1<<endl;	
					}
					
					if (x-2*(i-1)<=n && (2*i)-1>n)
					{
						cout<<"Sheet "<<i<<", front: "<<x-2*(i-1)<<", "<<"Blank"<<endl;
					}
					if (x-2*(i-1)>n && (2*i)-1>n)
					{
						
					}
					if(x-2*(i-1)<=n && (2*i)-1<=n)
					{
					cout<<"Sheet "<<i<<", front: "<<x-2*(i-1)<<", "<<(2*i)-1<<endl;	
					}
					
					// back part
					if (2*i>n && x-((2*i)-1)<=n)
					{
					cout<<"Sheet "<<i<<", back : "<<"Blank"<<", "<<x-((2*i)-1)<<endl;	
					}
					
					if (2*i<=n && x-((2*i)-1)>n)
					{
						cout<<"Sheet "<<i<<", back : "<<2*i<<", "<<"Blank"<<endl;
					}
					if (2*i>n && x-((2*i)-1)>n)
					{
						
					}
					if(2*i<=n && x-((2*i)-1)<=n)
					{
					cout<<"Sheet "<<i<<", back : "<<2*i<<", "<<x-((2*i)-1)<<endl;	
					}
					







					
				}




			}


		}

	}
	




	return 0;
}

