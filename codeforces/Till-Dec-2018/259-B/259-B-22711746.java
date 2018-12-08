import java.util.*;
public class practice {
	
	

	
public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
	  int n11=input.nextInt();
	  int n12=input.nextInt();
	  int n13=input.nextInt();
	  int n21=input.nextInt();
	  int n22=input.nextInt();
	  int n23=input.nextInt();
	  int n31=input.nextInt();
	  int n32=input.nextInt();
	  int n33=input.nextInt();
	  int sum=(n12+n13+n21+n23+n31+n32)/2;
	  n11=sum-n12-n13;
	  n22=sum-n21-n23;
	  n33=sum-n31-n32;
	  System.out.println(n11+ " "+ n12 +" "+ n13);
	  System.out.println(n21+ " "+ n22 +" "+ n23);
	  System.out.println(n31+ " "+ n32 +" "+ n33);
	  
	  input.close();	
	   
	   } 
}