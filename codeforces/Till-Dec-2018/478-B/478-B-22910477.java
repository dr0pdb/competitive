import java.util.*;

public class practice {
	
	public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
 	  long n=input.nextLong();
 	  long m=input.nextLong();
 	  long min;
 	  long max;
 	  
	  max=((n-m+1)*(n-m))/2;
	  
	  if(n%m==0){
		  min=(n*(n/m-1))/2;
		  }
	  else{
		  long remainder=n%m;
		  long k=n/m;
		  min= ((remainder)*(k+1)*k)/2 + (m- remainder)* (k*(k-1))/2;
	  }
	  System.out.printf("%d %d", min,max);
	  
	  
	  input.close();	
	   
	   }
	
	
	
}