import java.util.*;
public class practice {
	
	

	
public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
	  int n=input.nextInt();
	  int m=input.nextInt();
	  int task[]= new int[m];
	  long counter=0;
	  for(int x=0;x<m;x++){
		  task[x]=input.nextInt();
		  if(x==0){ counter+=task[x]-1;
			  
		  }
		  else {
			  if(task[x]>=task[x-1])
			  {
			  counter+= task[x]- task[x-1];
		  }
		  else{
			  counter+=n- task[x-1]+ task[x];
		  }
		  }
	  }
	  System.out.println(counter);
	  
	  
	  
	  
	  
	  input.close();	
	   
	   } 


}