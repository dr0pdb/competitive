import java.util.*;
import java.io.*;
import java.math.*;

 public class Main{
	
 	public static BigInteger factorial(int b){
 		if (b == 1) {
 			return BigInteger.valueOf(1);
 		}
 		BigInteger result = BigInteger.valueOf(b);
 		return result.multiply(factorial(b-1));
 	}

	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner in = new Scanner(System.in);
		int a,b;
		a = in.nextInt();
		b= in.nextInt();

		if (a<b) {
			b=a;
		}

		BigInteger result = factorial(b);
		System.out.println(result.toString());
    }
}