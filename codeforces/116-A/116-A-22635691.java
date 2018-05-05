import java.util.Scanner;

public class practice {
	public static void main(String args[]) {
		Scanner saurav = new Scanner(System.in);
		  int n=saurav.nextInt();
		  int a;
		  int b;
		  int x;
		  int people=0;
		  int max=0;
		  for(int y=0; y<n; y++){
			  a=saurav.nextInt();
			  b=saurav.nextInt();
			  x=b-a;
			  people+=x;
			  if(people>max){
				  max=people;
			  }
			  
		  }
		  
		  System.out.println(max); 
	
	
	}

}