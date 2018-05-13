/*
	This quora answer was useful 
	https://www.quora.com/How-do-I-solve-maximum-product-subarray-problems/answer/Gautam-Kumar-2?srid=u9d08
*/


import java.util.*;
import java.io.*;
import java.math.*;

 class Main{
	
	public static void main (String[] args) throws java.lang.Exception
	{
		boolean start =true;
		Scanner in = new Scanner(System.in);
		int temp;

		BigInteger prev_max_prod = BigInteger.valueOf(0), prev_min_prod = BigInteger.valueOf(0),current_max_prod = BigInteger.valueOf(0), current_min_prod = BigInteger.valueOf(0), answer = BigInteger.valueOf(0);
		while(in.hasNext()){
			temp = in.nextInt();

			if (temp == -999999) {
				start = true;
				System.out.println(answer.toString());
			}else{
				if (start) {
					prev_min_prod = BigInteger.valueOf(temp);
					prev_max_prod = BigInteger.valueOf(temp);
					answer = BigInteger.valueOf(temp);
					start = false;
				}else{
					BigInteger tempb = BigInteger.valueOf(temp);			
					current_max_prod = tempb.max(prev_max_prod.multiply(tempb).max(prev_min_prod.multiply(tempb)));	
					current_min_prod = tempb.min(prev_max_prod.multiply(tempb).min(prev_min_prod.multiply(tempb)));

					answer = answer.max(current_max_prod);
					prev_max_prod = current_max_prod;
					prev_min_prod = current_min_prod;
				}
			}

		}
    }
}
