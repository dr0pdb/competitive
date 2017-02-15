import java.util.*;

 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
	
	Scanner input= new Scanner(System.in);
		
		while(input.hasNext()){
			
			int t=input.nextInt();
			while(t-- !=0){
				
			int sum=input.nextInt();
			int diff=input.nextInt();
			
			if(sum<diff || (sum+diff)%2!=0 || (sum-diff)%2!=0){
				System.out.println("impossible");
			}
			
			else{
				
				int a=(sum+diff)/2;
				int b=(sum-diff)/2;
				System.out.printf("%d %d\n",a,b);
				
				
			}
				
				
				
			}
			
			
			
			
			
		}
		
		
		
		input.close();

        }
}
