import java.util.*;

 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
	
		Scanner input= new Scanner(System.in);
		
		while(input.hasNext()){
			
		String line=input.nextLine();
		
			if(line.equals("DONE")){
				break;
			}
		
		
			else{
				
				
				
				StringBuilder sb= new StringBuilder();
				
				for(int x=0;x<line.length();x++){
					if(Character.isAlphabetic(line.charAt(x))){
						sb.append(Character.toLowerCase(line.charAt(x)));
					}
					
				}
				
				String cleanstring= sb.toString();
				
				boolean ispalindrome= true;
				
				for(int x=0;x<cleanstring.length() && ispalindrome;x++){
					ispalindrome=cleanstring.charAt(x)==cleanstring.charAt(cleanstring.length()-1-x);
				}
				
				if(ispalindrome){
					System.out.println("You won't be eaten!");
				}
				else{
					System.out.println("Uh oh..");
				}
				
 			}
			
		
	}
		
		
		
		
		input.close();

        }
}
