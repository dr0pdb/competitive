#include<bits/stdc++.h>

using namespace std;

int main(){

  int n;
  int type,value;
  bool ss,qq,pqq;

  while (scanf("%d",&n)==1)
  {
     ss=qq=pqq=true;
     stack<int>s;
     queue<int>q;
     priority_queue<int>pq;

     while (n--)
     {
                    scanf("%d %d",&type,&value);
            if (type==1)
            {
                if (ss)
                {
                    s.push(value);
                }
                if (qq)
                {
                    q.push(value);
                }
                if (pqq)
                {
                    pq.push(value);
                }
            }

            else
            {
                if (ss)
                {
                        if (!s.empty() && value==s.top())
                    {
                        s.pop();
                    }else
                    {
                        ss=false;
                    }

                }
                
                if (qq)
                {
                    if (!q.empty() && value==q.front())
                    {
                        q.pop();
                    }else
                    {
                        qq=false;
                    }    
                }

                if (pqq)
                {
                        if (!pq.empty() && value==pq.top())
                    {
                        pq.pop();
                    }else
                    {
                        pqq=false;
                    }

                }

                
                
           }

    }
        if(ss && !pqq && !qq)
            printf("stack\n");
        else if(!ss && !pqq && qq)
            printf("queue\n");
        else if(!ss && pqq && !qq)
            printf("priority queue\n");
        else if(pqq || qq || ss)
            printf("not sure\n");
        else
            printf("impossible\n");
    }

    return 0;    
}

