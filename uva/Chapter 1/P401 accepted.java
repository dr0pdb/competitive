import java.util.*;
import java.io.*;

 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
	BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		
		String s;

		
		
		while((s=br.readLine()) != null){
			
			boolean palindrome= ispalindrome(s);
			boolean mirrored= ismirrored(s);
			
			if(palindrome && mirrored){
				System.out.printf("%s -- is a mirrored palindrome.\n",s);
				System.out.println();
			}
			
			else if(palindrome){
				System.out.printf("%s -- is a regular palindrome.\n",s);
				System.out.println();
			}
			
			else if(mirrored){
				System.out.printf("%s -- is a mirrored string.\n",s);
				System.out.println();
			}
			else{
				System.out.printf("%s -- is not a palindrome.\n",s);
				System.out.println();
			}


        }

}

public static boolean ispalindrome(String p){
		
	 
	 String reversedstring= new StringBuilder(p).reverse().toString();
	 
	 	if(p.equals(reversedstring)){
		 return true;
	 }
	 	else{
		 return false;
	 }
	 
	}
	
	public static boolean ismirrored(String p){
		
		char[] mirror = new char[128];
		
		mirror['A'] = 'A'; mirror['E'] = '3'; mirror['H'] = 'H';
		mirror['I'] = 'I'; mirror['J'] = 'L'; mirror['L'] = 'J';
		mirror['M'] = 'M'; mirror['O'] = 'O'; mirror['S'] = '2';
		mirror['T'] = 'T'; mirror['U'] = 'U'; mirror['V'] = 'V';
		mirror['W'] = 'W'; mirror['X'] = 'X'; mirror['Y'] = 'Y';
		mirror['Z'] = '5'; mirror['1'] = '1'; mirror['2'] = 'S';
		mirror['3'] = 'E'; mirror['5'] = 'Z'; mirror['8'] = '8';
		
		for(int x=0;x<(p.length()+1)/2;x++){
			
			if(p.charAt(x)== mirror[p.charAt(p.length()-1-x)] || mirror[p.charAt(x)]== p.charAt(p.length()-1-x)){
			
				continue;
			}
			
			else{
				return false;
			}
			
			
			
		}
		
		return true;
	}
	
	


}
