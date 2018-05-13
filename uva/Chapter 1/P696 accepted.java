	In general, knights can be placed in a staggered pattern:

X.X.X
.X.X.
X.X.X

In this case, the closed form is ((m+1)/2)*((n+1)/2) + (m/2)*(n/2)

If one of the dimensions is 1, then you can fill the entire board with knights:

XXXXXXXX

If one of the dimensions is 2, then you can fill sets of 2 rows:

XX..XX..X
XX..XX..X





import java.util.*;
import java.io.*;

 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
	
	BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		
		while(true){
			
			String[] in= br.readLine().split(" ");
			int m=Integer.parseInt(in[0]);
			int n=Integer.parseInt(in[1]);
			
				if(m==0 && n==0){
				break;
				}
		
				int answer=tosolve(m,n);
				System.out.printf("%d knights may be placed on a %d row %d column board.\n",answer,m,n);
				
				
		}		
	}
	public static int tosolve(int p,int q){
		
		if(q>p){
			int temp=p;
			p=q;
			q=temp;
		}
		
		if(q==1){
			return p;
			
		}
		if(q==2){
			 int ans = (p / 4) * 4;
		      int remain = (p % 4) > 2 ? 2 : (p % 4);
		      ans += remain * 2;
		      return ans;
		      
		      }
		
		return	(((p + 1)/2) * ((q + 1)/2)) + (((p)/2) * ((q)/2));
		
		
	}


}
