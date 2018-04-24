import java.util.*;
import java.io.*;
import java.math.*;

 class Main{

	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner in = new Scanner(System.in);
		int n;
		while(in.hasNext()){
			n = in.nextInt();
			BigInteger fact = BigInteger.valueOf(1);
            for(int i = 1; i <= n; i++) {
                fact = fact.multiply(BigInteger.valueOf(i));
            }
            System.out.printf("%d!\n", n);
            System.out.println(fact.toString());
		}
		in.close();
    }
}
