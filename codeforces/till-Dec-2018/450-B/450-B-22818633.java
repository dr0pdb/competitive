import java.util.*;
public class practice {
	
	public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
	  
	  
	  int x=input.nextInt();
	  int y=input.nextInt();
	  int n=input.nextInt();
	  
	  int[] f= new int[6];
	  f[0]=x;
	  f[1]=y;
	  f[2]=y-x;
	  f[3]=-x;
	  f[4]=-y;
	  f[5]=x-y;
	  
	  int rem = n%6;
	  if(rem==0){
		  rem+=6;
	  }
	  int answer= f[rem-1]%1000000007 ;
	  if(answer>=0){
		  System.out.println(answer);
	  }
	  else{
		  System.out.println(answer+1000000007 );
	  }
	  
	  input.close();	
	   
	   }
	
	
	
}