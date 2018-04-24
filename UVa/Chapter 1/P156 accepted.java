
\\ the main idea is to convert the string into lower case and sort the characters alphabetically
\\those words which occur only once are to be printed



import java.util.*;
import java.io.*;
import java.math.*;
 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
	Scanner input= new Scanner(System.in);
		Map<String,Integer> counting= new HashMap<String,Integer>();
		List<String> words= new ArrayList<String>();
		
		while(input.hasNext()){
			
			String word=input.next();
			if(word.equals("#")){
				break;
			}
			
			words.add(word);
			
			String editedword=edittheword(word);
			if(!counting.containsKey(editedword)){
				counting.put(editedword, 0);
			}
			
			
			counting.put(editedword, counting.get(editedword)+1);
			
			
			
		}
		
		List<String> ananagrams= new ArrayList<String>();
		
		for(String word:words){
			if(counting.get(edittheword(word))==1){
				ananagrams.add(word);
			}
		}
		
		Collections.sort(ananagrams);
		
		for(String s:ananagrams){
			System.out.println(s);
		}
	
	
		input.close();
	

        }

	public static String edittheword(String s){
		
		char[] a= s.toLowerCase().toCharArray();
		Arrays.sort(a);
		return new String(a).intern();
		
		
			
	}
	
	

}
