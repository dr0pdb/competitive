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
				
				String reversedstring=new StringBuilder(cleanstring).reverse().toString();
				
				
				if(cleanstring.equals(reversedstring)){
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
