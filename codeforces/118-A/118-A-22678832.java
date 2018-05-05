import java.util.*;
public class practice {
	
	
static char[] vowels = {'a','e','i','u','y','o'};
	
	
	public static boolean isvowel(char c){
		for(int y=0;y<6;y++){
			if(c== vowels[y]){
				return true;
			}
		} 
		return false; 
	 }	
	
	
public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
	  String string = input.nextLine();
	  string = string.toLowerCase();
	  for(int x=0;x<string.length();x++){
		  if(!isvowel(string.charAt(x))){
			  System.out.printf(".%c",string.charAt(x));
			  }
	  }
	 
	 input.close();	
	}
	
	
	
	

}