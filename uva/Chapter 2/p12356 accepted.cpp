#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    unsigned int s, b, l, r;
	
    vector<int> left(110000), right(110000);
    while (scanf("%d %d", &s, &b), (s || b)) {
        for (int i = 0; i <= s; i++) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        
        while (b--) {
            scanf("%d %d", &l, &r);
            if (left[l] < 1) printf("* ");
            else printf("%d ", left[l]);
            if (right[r] > s) printf("*\n");
            else printf("%d\n", right[r]);
            
            left[right[r]] = left[l];
            right[left[l]] = right[r];
        }
        printf("-\n");
    }
    return 0;
}
// timeout in actually deleting the elements

/*
 * #include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v;
    int total,reports;
    int lrange,rrange;
    while (true)
    {   
        scanf("%d %d",&total,&reports);
        if (!total && !reports )
        {
          break;
        }
        for (size_t i = 0; i < total; i++)
        {
          v.push_back(i+1);
        }

        while (reports--)
        {
          scanf("%d %d",&lrange,&rrange);
          vector<int>::iterator itr1= find(v.begin(),v.end(),lrange);
          vector<int>::iterator itr2= find(v.begin(),v.end(),rrange);
          int distance=itr2-itr1;
          v.erase(itr1,itr2+1);
            
          itr1-=distance;


          bool hasLeft=false;
          bool hasRight=false;
          if (itr1 != (v.begin()-1))
          {
            hasLeft=true;
          }
          if (itr2 != v.end())
          {
            hasRight=true;
          }

          if (hasLeft && hasRight)
          {
             
            printf("%d %d\n",*itr1,*itr2);
          }
          else if (hasLeft && !hasRight)
          {
              
            printf("%d *\n",*itr1);
          }
          else if (!hasLeft && hasRight)
          {
              
            printf("* %d\n",*itr2);
          }else
          {
              
            printf("* *\n");
          }  
          
        }
        printf("-\n");
    }  
    return 0;    
}
* */
