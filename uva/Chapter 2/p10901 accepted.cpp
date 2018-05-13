#include<bits/stdc++.h> 

using namespace std;

int main(){

    int maxc,t,noc,count;
    int testcase;
    int temp;
    string dir;

    int timing[10050],leaving[10050];
    queue<int> q[2]; 


    scanf("%d",&testcase);
    while (testcase--)
    {
        int curSide=0;
        int current_time=0;

        scanf("%d %d %d",&maxc,&t,&noc);
        for (size_t i = 0; i < noc; i++)
        {
            cin>>temp>>dir;
            if (dir[0]=='l')
            {
                q[0].push(i);
            }else{
                q[1].push(i);
            }
            timing[i]=temp;
        }

        while (!q[0].empty() || !q[1].empty())
        {
            int next_time;
            if (q[0].empty())
            {
                next_time=timing[q[1].front()];
            }
            else if (q[1].empty())
            {
                next_time=timing[q[0].front()];
            }else
            {
                next_time=min(timing[q[0].front()],timing[q[1].front()]);
            }
            current_time=max(current_time,next_time);
            count=0;    
            while((timing[q[curSide].front()]<=current_time) && (!q[curSide].empty()) && (count<maxc))
            {
                leaving[q[curSide].front()]=current_time+t;
                q[curSide].pop();
                count++;
            }

            current_time +=t;
            curSide ^=1;
        }

        for (size_t i = 0; i < noc; i++)
        {
            printf("%d\n",leaving[i]);
        }
        if (testcase)
        {
            printf("\n");
        }
    }

    return 0;
}

