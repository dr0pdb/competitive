import java.util.*;
public class practice {
	
	

	public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
	  
	  int n=input.nextInt();
	  int home[]= new int[n];
	  int away[]= new int[n];
	  int max=0;
	  
	  
	  for (int x=0;x<n;x++){
		  home[x]=input.nextInt();
		  if(home[x]>max){
			  max=home[x];
		  }
		  away[x]=input.nextInt();
		  if(away[x]>max){
			  max=away[x];
		  }
	  }
	  int[] temp = new int[max+1];
	  for(int i=0;i<n;i++)
      {
          
          temp[home[i]]++;
      }
              for(int i=0;i<n;i++)
      {
          
         System.out.println((n-1+temp[away[i]])+" "+(n-1-temp[away[i]]));
         
      } 
	  
	 
	  
	  input.close();	
	   
	   } 
}