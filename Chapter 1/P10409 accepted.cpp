#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<string>
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

		string direction;
		int top=1,front=2,back=5,down=6,right=4,left=3;
		
		while (n-- !=0)
		{
			cin>>direction;

			if (direction=="north")
			{
				int formerfront=front;
				int formerback=back;
				int formertop=top;
				int formerdown=down;
				
				front=formertop;
				top=formerback;
				back=formerdown;
				down=formerfront;
				

			}

			if (direction=="south")
			{
				int formerfront=front;
				int formerback=back;
				int formertop=top;
				int formerdown=down;

				front=formerdown;
				top=formerfront;
				back=formertop;
				down=formerback;


			}
			
			if (direction=="east")
			{
				int formerleft=left;
				int formerright=right;
				int formertop=top;
				int formerdown=down;

				right=formertop;
				top=formerleft;
				left=formerdown;
				down=formerright;
			}

			if (direction=="west")
			{
				int formerleft=left;
				int formerright=right;
				int formertop=top;
				int formerdown=down;

				right=formerdown;
				top=formerright;
				left=formertop;
				down=formerleft;

			}
		}

		cout<<top<<endl;
	}


	return 0;
}

