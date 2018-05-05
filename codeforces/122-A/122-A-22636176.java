import java.util.Scanner;

public class practice {
	public static void main(String args[]) {
		Scanner saurav = new Scanner(System.in);
		  int n=saurav.nextInt();
		  int a[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
		  int x=0;
		  for(int y=0;y<a.length;y++){
			  if(n%a[y]==0){
				  x=1;
			  }
			
			}
		  if(x==1){
				System.out.println("YES");
			}  
			else{
				System.out.println("NO");
			  
		  }
	
	
	}

}