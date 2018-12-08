import java.util.*;
public class practice {
	
	

	
	
	
	
	
	
	
	
	
public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
	  String s = input.nextLine();
	  int counter1=0;
	  int counter2=0;
	  int counter3=0;
	  for(int x=0; x<s.length();x+=2){
		  if(s.charAt(x)=='1'){
			  counter1 ++;
		  }
		  if(s.charAt(x)=='2'){
			  counter2 ++;
		  }
		  if(s.charAt(x)=='3'){
			  counter3 ++;
		  }
		  
	  }
	  boolean first=true;
	  
	  for(int y=0;y<counter1;y++){
		  if(first==true){
			  System.out.print(1);
			  first=false;
		  }
		  else{
		  System.out.printf("+1");
	           }
	  }
	  
	 
	  for(int z=0;z<counter2;z++){
		  if(first==true){
			  System.out.print(2);
			  first=false;
		  }
		  else{System.out.printf("+2");
	  }
		  }
	 
		  
	  for(int p=0;p<counter3;p++){
		  if(first==true){
			  System.out.print(3);
			  first=false;
		  }
		  else{System.out.printf("+3");
	  }
		  }
	  
		  
	  
		  
	  
	  
	  input.close();	
	}
	
	
	
	

}