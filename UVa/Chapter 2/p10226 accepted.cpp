#include<bits/stdc++.h>

using namespace std;

int main(){

   int t,count;
   scanf("%d\n\n",&t);

   map<string,int> m;
   string temp;
   while (t--)
   {  
     count=0;
     m.clear();
     while (getline(cin,temp) && temp!="")
     {
        count++;
        if (m.find(temp) !=m.end() )
        {
          m[temp]++;
        }
        else
        {
          m[temp]=1;
        }

     }
     map<string,int>::iterator it=m.begin();
       
     for (it = m.begin(); it != m.end(); it++) {
			printf("%s %.4lf\n", (*it).first.data(),
					(double) (*it).second / (double) count * 100.0);
		}
    if(t){
        printf("\n");
    }
   }

    
    return 0;    
}



