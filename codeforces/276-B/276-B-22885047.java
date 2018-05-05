import java.util.*;

public class practice {
	
	public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
 	  String str= input.nextLine();
 	  char[] asarray= str.toCharArray();
	  int arraycounter[]= new int[26];
 	  int noofodd =0;
 	  
 	  for(int x=0;x<str.length();x++){
 		  arraycounter[asarray[x]-'a'] ++;
 		  }
 	  for(int x=0;x<26;x++){
 		  if(arraycounter[x]%2==1){
 			  noofodd++;
 			  }
 	  }
	  if(noofodd==0 || noofodd%2==1){
		  System.out.println("First");
	  }
	  else{
		  System.out.println("Second");
	  }
	  input.close();	
	   
	   }
	
	
	
}