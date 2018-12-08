import java.util.*;
public class practice {
	
	

	
	
	
	
	
	
	
	
	
public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
	  int n= input.nextInt();
	  int in[]= new int[n];
	  int p;
	  for (int x=1;x<=n;x++){
		  p=input.nextInt();
		  in[p-1]=x;
	  }
	  for(int q:in){
		  System.out.printf("%d ", q);
	  }
	  
	  
	  
	  input.close();	
	}
	
	
	
	

}