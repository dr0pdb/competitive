import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            long n = in.nextLong();
            
            long n1= n/3;
            long n2=n/5;
            long n3=n/15;
            
            if(3*n1==n){
                n1--;
            }
            if(5*n2==n){
                n2--;
            }
            if(15*n3==n){
                n3--;
            }
            long sum1=3*((n1*(n1+1))/2);
            long sum2=5*((n2*(n2+1))/2);
            long sum3=15*((n3*(n3+1))/2);
            
            System.out.println(sum1+sum2-sum3);
        }
    }
}

