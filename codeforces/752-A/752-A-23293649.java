import java.util.*;
import java.io.*;


public class practice {
	
	
	public static void main (String[] args) throws java.lang.Exception{
      
		Scanner in=new Scanner(System.in);
		
		int n=in.nextInt();
		int m=in.nextInt();
		int k=in.nextInt();
	
		int lane;
		int desk;
		char side;
		
		if(k%2==0){
			side='R';
		}	
		else{
			side='L';
		}
	
		if(k%(2*m)==0){
			lane=(k/(2*m));
		}
		else{
		lane=(k/(2*m))+1;
		}
		
		
		desk=lane-1;
		desk=desk*2*m;
		desk=k-desk;
		desk/=2;
		
		if(side=='L'){
			desk+=1;
		}
		
		System.out.printf("%d %d %c", lane,desk,side);
		
		
	}	
	
}