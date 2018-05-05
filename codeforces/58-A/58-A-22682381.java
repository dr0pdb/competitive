import java.util.*;
public class practice {
	
	

	
	
	
	
	
	
	
	
	
public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
	  String s = input.nextLine();
	  int counter=0;
	  while(counter<s.length() && s.charAt(counter)!='h'){
		  counter++;
	  }
	  counter++;
	  while(counter<s.length() && s.charAt(counter)!='e'){
		  counter++;
	  }
	  counter++;
	  while(counter<s.length() && s.charAt(counter)!='l'){
		  counter++;
	  }
	  counter++;
	  while(counter<s.length() && s.charAt(counter)!='l'){
		  counter++;
	  }
	  counter++;
	  while(counter<s.length() && s.charAt(counter)!='o'){
		  counter++;
	  }
	 if(counter<s.length()){
		 System.out.println("YES");
	 }
	 else{
		 System.out.println("NO");
	 }
	  
	  
	  input.close();	
	}
	
	
	
	

}