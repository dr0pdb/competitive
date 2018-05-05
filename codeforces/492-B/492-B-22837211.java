import java.util.*;
import java.lang.*;
public class practice {
	
	public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
	  int nolantern=input.nextInt();
	  long length=input.nextLong();
	  long[] position = new long[nolantern];
	  
	  for(int x=0; x<nolantern;x++){
		  position[x]=input.nextLong();
	  }
	  Arrays.sort(position);
	  double difference;
	  double max= Math.max(position[0], length-position[nolantern-1]);
	  for(int x=1;x<nolantern;x++){
		  difference=(position[x]-position[x-1])*0.5;
		  if(difference>max){
			  max=difference;
		  }
	  }
	  System.out.printf("%.10f",max);
	  
	  input.close();	
	   
	   }
	
	
	
}