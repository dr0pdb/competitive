import java.util.*;
public class practice {
	
	

	
public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
	  int n=input.nextInt();
	  int[] h= new int[n];
	  int result=0;
	  for(int x=0;x<n;x++){
		  h[x]=input.nextInt();
	  }
	  for(int x=0;x<n;x++){
		  if(x==0){
			  result+=h[x]+1;
		  }
		  if(x==n-1){
			  
		  }
		  else{
			  if(h[x]<=h[x+1]){
				  result+=h[x+1]-h[x]+2;
			  }
			  else{
				  result+=h[x]-h[x+1]+2;
			  }
		  }
	  }
	  System.out.println(result);
	  
	  
	  
	  input.close();	
	   
	   } 
}