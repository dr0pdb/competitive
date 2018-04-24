
\\ we can check the characters of guess one by one by adding it in a temporary set. if the char can be added to the set that means it was not present in the set earlier. if it was already present then 
\\ we can just continue with the loop otherwise we have to check whether this char is in the target word.. if it is then we should delete this char from target word. if it is not present then counter++ 
\\ if the target word gets empty earlier than counter goes to 7 then you win.. if counter gets to 7 then you loose.. if none happens then chickened out.






import java.util.*;
import java.io.*;

 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
	BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		
		
		while(true){
			
			int number=Integer.parseInt(br.readLine());
			boolean chickened=true;
			
			if(number==-1){
				break;
			}
			else{
				
			System.out.println("Round "+number );	
				
			String targetword= br.readLine();
			String guessedword=br.readLine();
			
			
			
			Set<Character> temp= new HashSet<Character>();
			int counter=0;
			
			for(int x=0;x<guessedword.length();x++){
				
				char c=guessedword.charAt(x);
				
				boolean isaddable=temp.add(c);
				if(!isaddable){
					continue;
				}
				else{
					if(targetword.indexOf(c)>-1){
						targetword=targetword.replace(""+c, "");
						if(targetword.length()==0){
							System.out.println("You win.");
							chickened=false;
							break;
						}
						
						
					}
					
					else{
						counter++;
						if(counter==7){
							System.out.println("You lose.");
							chickened=false;
							break;
						}
					}
					
					
				}
				
				
			}
			
			if(chickened){
				System.out.println("You chickened out.");
			}
				
				
			
				}
		}
	
	
		


        }
}
