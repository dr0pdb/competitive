import java.util.*;
import java.io.*;
import java.math.*;

 class Main{

 	public static void main (String[] args) throws java.lang.Exception
	{
		BigInteger[] factorials = new BigInteger[21];

		factorials[0]=BigInteger.valueOf(1);
		for (int i=1; i<21; i++) {
			factorials[i]=BigInteger.valueOf(i).multiply(factorials[i-1]);
		}


		Scanner in = new Scanner(System.in);
		int t,cn=1;
		t = in.nextInt();
		in.nextLine();
		while(t!=0){
			String s;
			s = in.nextLine();
			int[] counter = new int[26];
			for (int i=0; i<s.length();i++) {
				counter[s.charAt(i)-'A']++;
			}
			BigInteger answer = factorials[s.length()];
			for (int i=0; i<26; i++) {
				answer = answer.divide(factorials[counter[i]]);
			}
			System.out.printf("Data set %d: %s\n",cn++,answer.toString());
			t--;
		}

		in.close();
    }
}
