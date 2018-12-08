import java.util.Scanner;

public class practice {
	public static void main(String args[]) {
		Scanner saurav = new Scanner(System.in);
		 long  n = saurav.nextLong();
		 long m= saurav.nextLong();
		 long a= saurav.nextLong();
		 long x;
		 long y;
		 long answer;
		 if(n%a==0){
			 x=n/a;
		 }
		 else{
			 x=n/a+1;
		 }
		 if(m%a==0){
			 y=m/a;
		 }
		 else{
			 y=m/a+1;
		 }
	     answer= x*y;
	     System.out.println(answer);
	}

}