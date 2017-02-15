import java.util.*;

 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
	
 	Scanner input= new Scanner(System.in);
		
		int t=input.nextInt();
		int number=1;
		
		while(t-- !=0){
			
			int n=input.nextInt();
			
			int speeds[]= new int[n];
			int max=0;
			
			
			for(int x=0;x<n;x++){
				
			      	speeds[x]=input.nextInt();
			      	
			      	if(speeds[x]>max){
			      		max=speeds[x];
			      	}
				
				
				}
			System.out.printf("Case %d: %d\n",number ,max);
			number++;
		  }
		
			input.close();
		
        }
}
