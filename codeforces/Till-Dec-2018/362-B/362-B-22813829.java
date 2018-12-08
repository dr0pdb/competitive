import java.util.*;
public class practice {
	
	

	public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
	  
	  int n=input.nextInt();
	  int m=input.nextInt();
	  int[] dirtystairs= new int[m];
	  
	  boolean answer= true;
	  for(int x=0;x<m;x++){
		  dirtystairs[x]=input.nextInt();
		  }
	  
	  Arrays.sort(dirtystairs);
	  
	  if(m==0){
		  
	  }
	  else{
	  
	       if(dirtystairs[0]==1 || dirtystairs[m-1]==n ){
		  answer=false;
		 }
	  
		  
          else{  
		  for(int x=0;x<m-2;x++){
			 if(dirtystairs[x+1]==dirtystairs[x]+1 && dirtystairs[x+2]==dirtystairs[x]+2   ){
				 answer=false;
				 break;
			 }
			  
		  }
		}
		  
	  }
	  if(answer){
		  System.out.println("YES");
	  }
	  else{
		  System.out.println("NO");
	  }
	  input.close();	
	   
	   } 
}