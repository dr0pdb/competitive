import java.util.*;

public class practice {
	
	public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
 	  double r=input.nextDouble();
 	  double x=input.nextDouble();
 	  double y=input.nextDouble();
 	  double xnew=input.nextDouble();
 	  double ynew=input.nextDouble();
 	  
 	  double d= Math.sqrt((xnew-x)*(xnew-x)+(ynew-y)*(ynew-y));
 	  double answer= Math.ceil((d/r)*0.5);
 	  System.out.printf("%.0f",answer);
	  input.close();	
	   
	   }
	
	
	
}