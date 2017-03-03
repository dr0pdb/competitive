#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    
    int t;
    cin>>t;
    int testcase=1;

    while(t-- !=0){

        vector<string> answer;
        
        string website;
        int maximum=0;

        for(int x=0;x<10;x++){

                cin>>website;

                int value;
                cin>>value;

                if(value>maximum){
                    maximum=value;
                    answer.clear();
                    answer.push_back(website);
                
                }
        
                  else if(value==maximum){
                
                    answer.push_back(website);
                
                }
        
            }
        
            cout<<"Case #"<<testcase++<<":"<<endl;
            
            for(int x=0;x<answer.size();x++){
            
                cout<<answer[x]<<endl;
            }
            





    }


    return 0;
}

