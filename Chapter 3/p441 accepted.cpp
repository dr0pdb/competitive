#include<bits/stdc++.h> 

using namespace std;

//index1 is in the original array and the index2 is in the temp_arr
void combine(int arr[],int size, int psize, int index1,int temp_arr[],int index2){
    if (index2==psize)
    {
        for (size_t i = 0; i < psize; i++)
        {
            if (i !=(psize-1))
            {
                printf("%d ",temp_arr[i]);    
            }
            else
            {
                printf("%d",temp_arr[i]);
            }
            
        }
        printf("\n");
        return;
    }

    if (index1>=size)
    {
        return;
    }

    temp_arr[index2]=arr[index1];
    combine(arr,size,psize,index1+1,temp_arr,index2+1);

    combine(arr,size,psize,index1+1,temp_arr,index2);



}
void permute(int arr[],int size,int psize ){

    int temp_arr[psize];

    combine(arr,size,psize,0,temp_arr,0);
}
int main(){


int k;
int array[20];
bool first=true;
while (scanf("%d",&k)==1 && k)
{   
    
    if (!first)
    {
        printf("\n");    
    }
     first=false;    
    for (size_t i = 0; i < k; i++)
    {
        scanf("%d",array+i);
    }

    permute(array,k,6);
}    
 return 0;  
}

