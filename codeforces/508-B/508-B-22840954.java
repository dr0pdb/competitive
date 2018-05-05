import java.util.*;

public class practice {
	
	public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
 	  String number= input.nextLine();
 	  char[] arraydigit= number.toCharArray();
	  
 	  
 	  int position=-1;
 	  for(int x=0;x<number.length();x++){
 		  if(arraydigit[x]%2==0){
 			  position=x;
 			  if(arraydigit[x]<arraydigit[number.length()-1]){
 				  char temp1= arraydigit[x];
 				  char temp2=arraydigit[number.length()-1];
 				  arraydigit[x]=temp2;
 				 arraydigit[number.length()-1]=temp1;
 				 System.out.println(arraydigit);
 				 position=-2;
 				 break;
 				 
 				 
 			  }
 			  
 		  }
 	  }
 	  if(position >=0){
 		char temp1=arraydigit[position];
 		char temp2=arraydigit[number.length()-1];
 		arraydigit[position]= temp2;
 		arraydigit[number.length()-1]=temp1;
 		System.out.println(arraydigit);
 	  }
 	  if(position==-1){
 		  System.out.println("-1");
 	  }
	  
	  input.close();	
	   
	   }
	
	
	
}