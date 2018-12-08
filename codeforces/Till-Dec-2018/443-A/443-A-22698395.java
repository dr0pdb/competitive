import java.util.*;
public class practice {
	
	

	
	
	
	
	
	
	
	
	
public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
	  String s= input.nextLine();
	  
	  Set set = new HashSet();
	  for(int x=0; x<s.length(); x++){
	      if(s.charAt(x)=='{' || s.charAt(x)=='}' || s.charAt(x)==' ' || s.charAt(x)==',') {                                     
	       
	       }
	      else{
	    	  set.add(s.charAt(x));
	      }
	      }
	  
	  
	  System.out.println(set.size());
	  
	  input.close();	
	   
	   } 


}