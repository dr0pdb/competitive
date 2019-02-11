import java.util.*;
public class practice {
	
	

	
	
	
	
	
	
	
	
	
public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
	  int n= input.nextInt();
	  int soldiers[]= new int[n];
	  int max=0;
	  int min=100;
	  int counter=0;
	  int indexmax=0;
	  int indexmin=0;
	  for(int x=0;x<n;x++){
		  soldiers[x]=input.nextInt();
		  
         if(soldiers[x]>max){
        	 max=soldiers[x];
        	 indexmax=x;
        	 
         }
         if(soldiers[x]<=min){
        	 min=soldiers[x];
        	 indexmin=x;
         }
         
	  }
	  if(indexmax>indexmin){
		  System.out.println(indexmax+ n-2- indexmin);
	  }
	  else{
	  System.out.println(indexmax+ n-1- indexmin);
	  }
	  
	  
	  
	  input.close();	
	}
	
	
	
	

}