#include<bits/stdc++.h> 
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;

bool comparator(const pair<int, int> &a ,const pair<int, int> &b ){
    
    if(a.first != b.first) {
        return a.first>b.first;
    }else{
        return a.second<b.second;
    }
    
}

int main(){
    std::ios::sync_with_stdio(false);
    
   int n,k;
   cin>>n>>k;
   int t1,t2;
   vector< pair<int,int> >v;
   
   for(unsigned i = 0; i < n; ++i) {
       cin>>t1>>t2;
       v.push_back(make_pair(t1,t2));
    }
    
    sort(v.begin(),v.end(),comparator);
    int count=0;
    t1=v[k-1].first;
    t2=v[k-1].second;
    
    vector< pair<int,int> >::iterator itr=v.begin();
    for(itr=v.begin();itr !=v.end();++itr){
        if(itr->first==t1 && itr->second==t2) {
             count++;
        }
        if(itr->first<t1){
            break;
        }
    }
    cout<<count;

    return 0;  
}