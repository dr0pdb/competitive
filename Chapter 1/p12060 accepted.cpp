#include<bits/stdc++.h>
using namespace std;


int geti() {
  char c;int ret = 0;bool start = false;
  while(true) {
    c = getchar();
    if((c- '0' < 0 || c- '0' > 9) && !start) continue;
    if((c-'0' < 0 || c -'0' > 9) && start) break;
    if(start) ret *= 10;
    start = true;
    ret += c-'0';
  }
  return ret;
}

int num_length(int n) {
  return int(log10(n)) + 1;
}

int gcd(int a, int b){
  if (b==0)
  {
    return a;
  }
  else
  {
    return gcd(b,a%b);
  }
}

int main(){
  
  int caseno=1;
  int temp,no;
  long long sum;
  while (true)
  {
    
    scanf("%d",&no);
    if (!no)
    {
      break;
    }
    
    printf("Case %d:\n",caseno++);
    sum=0;

    for (int i = 0; i < no; i++)
    {
      scanf("%d",&temp);
      sum+=temp;
    }

    int quotient,remain;
    if(sum>=0){
      quotient=sum/no;
      remain=sum%no;
      
      if (!remain)
      {
        printf("%d\n",quotient);
      }
      else
      {
            int gcd_numbers=gcd(no,remain);

            if (gcd_numbers>1)
            {
              no/=gcd_numbers;
              remain/=gcd_numbers;
            }

            if(quotient)
            {
                int length_quotient=num_length(quotient);
                int length_no=num_length(no);

                for (size_t i = 0; i < length_quotient; i++)
                {
                  printf(" ");
                }
                  printf("%*d\n",length_no,remain);
                  printf("%d",quotient);
                 for (size_t i = 0; i < length_no; i++)
                {
                  printf("-");
                }
                  printf("\n");
                for (size_t i = 0; i < length_quotient; i++)
                {
                  printf(" ");
                }
                printf("%d\n",no);  
            }
            else
            {
              int length_no=num_length(no);
              printf("%*d\n",length_no,remain);
              for (size_t i = 0; i < length_no; i++)
              {
                printf("-");
              }
              printf("\n");
              printf("%d\n",no);
            }
            
      }  

    }
    else
    {
      quotient=sum/no;
      remain=abs(sum%no);
      
      if (!remain)
      { 
          printf("- ");
          printf("%d\n",abs(quotient));
      }
      else
      {
            int gcd_numbers=gcd(no,remain);

            if (gcd_numbers>1)
            {
              no/=gcd_numbers;
              remain/=gcd_numbers;
            }

            if (quotient)
            {
                  int length_quotient=num_length(abs(quotient));
                  int length_no=num_length(no);

                  for (size_t i = 0; i < length_quotient+2; i++)
                  {
                    printf(" ");
                  }
                  printf("%*d\n",length_no,remain);
                  printf("- ");
                  printf("%d",abs(quotient));
                  for (size_t i = 0; i < length_no; i++)
                  {
                    printf("-");
                  }
                  printf("\n");
                  for (size_t i = 0; i < length_quotient+2; i++)
                  {
                    printf(" ");
                  }
                  printf("%d\n",no);
            }

            else
            {
                int length_no=num_length(no);
                printf("  %*d\n",length_no,remain);
                printf("- ");
                for (size_t i = 0; i < length_no; i++)
                {
                  printf("-");
                }
                printf("\n");
                printf("  %d\n",no);

            }
            
      }

    }



  }

  return 0;    
}
