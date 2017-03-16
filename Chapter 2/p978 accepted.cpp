#include<bits/stdc++.h>
using namespace std ;


int main(){
 std :: multiset <int > G , B ;
 std :: multiset <int> :: iterator fit ,it ;
 vector < int > storeG , storeB ;
 int n , i  ,  j , k , x , y ,battles , ng ,nb;
 scanf("%d",&n);
  while ( n-- ){
         G.clear ()  ; B.clear() ;
         storeB.clear() ; storeG.clear() ;
       scanf("%d %d %d" , &battles ,&ng ,&nb);
       for ( i = 0 ; i < ng ; i++)
       {
             scanf("%d",&x);
             G.insert ( x );
       }
       for ( i = 0 ; i < nb; i++)
       {
             scanf("%d",&x);
             B.insert ( x );
       }
      
      while ( G.size() > 0 && B.size() > 0)
      {     storeG.clear() ; storeB.clear() ;
             
             for ( i = 0 ; i < battles ; i++)
              {
                    it = G.end() ; it -- ;
                    fit = B.end() ; fit-- ;
                    if ( *it > *fit)
                    {
                          G.erase(it); B.erase(fit);
                          storeG.push_back ( *it - *fit);
                    }
                    else if ( *it < *fit)
                    {
                          G.erase(it); B.erase(fit);
                          storeB.push_back ( *fit - *it);
                    }
                    else
                        {   
                            G.erase(it); B.erase(fit);
                        }

                
                    if (G.size() == 0 || B.size() == 0)
                    break ;
              }
              
              for ( int z = 0 ; z < storeB.size() ; z++)
                        B.insert( storeB [z] );
              for ( int z = 0 ; z < storeG.size() ; z++)
                     G.insert ( storeG [z] );
            
      }

      
      if ( G.size() == 0 && B.size() == 0)
      {
           printf("green and blue died\n");
      }
      else if (G.size() > 0)
      { 
          printf("green wins\n");
            it = G.end() ;
          do {
              it --;
              printf("%d\n",*it);
          }
          while ( it != G.begin());

      }
      else if (B.size() > 0)
      {
          printf("blue wins\n");
          it = B.end() ;
          do {
              it --;
              printf("%d\n",*it);
          }
          while ( it != B.begin());
          
      }
      if (n)
      printf("\n");
  }


    return 0;

}


/*
 * Wrong implementation of the same idea. Here accidently the program assumes that battles are held one by one not simultaneously
 * 
 * 
 * #include<bits/stdc++.h>

using namespace std;

int main(){

  int t;
  scanf("%d",&t);
  multiset<int>g,b;
  int field,nog,nob,temp;
  int minm,tempb,tempg;

  while (t--)
  {
      g.clear();
      b.clear();
      scanf("%d %d %d",&field,&nog,&nob);
      for (int i = 0; i < nog; i++)
      {
          scanf("%d",&temp);
          
          g.insert(temp);
      }
      for (int i = 0; i < nob; i++)
      {
          scanf("%d",&temp);
          
          b.insert(temp);
      }
      
      while (!g.empty() && !b.empty())
      {
            minm=min(field,min(nob,nog));
            
            for (int i = 0; i < minm; i++)
            {   
                multiset<int>::iterator itr1=b.end();
                multiset<int>::iterator itr2=g.end();
            

                    --itr1;
                    --itr2;
                
                 tempb=*itr1;
                 tempg=*itr2;   

                if (tempb>tempg)
                {
                  b.insert(tempb-tempg);
                  g.erase(tempg);
                  b.erase(tempb);
                
                  --nog;  
                }
                 if (tempb<tempg)
                {
                 g.insert(tempg-tempb);
                  g.erase(tempg);
                  b.erase(tempb);
               
                    --nob;
               
                }
                if (tempb==tempg)
                {
                    --nob;
                    --nog;
                    g.erase(tempg);
                    b.erase(tempb);
               
                }
                if (g.empty() || b.empty())
                {
                    break;
                }
                
                
            }    
      }

      if (!b.empty())
      {
          printf("blue wins\n");
          
          for  (int x: b)
          {
              printf("%d\n",x);
          }
      }

        else if (!g.empty())
      {
          printf("green wins\n");
         
          for  (int x: g)
          {
              printf("%d\n",x);
          }
      }

      else
      {
          printf("green and blue died\n");
      }

      printf("\n");
  }
    return 0;    
}




 * 
 * */
