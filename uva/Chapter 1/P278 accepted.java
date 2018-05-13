import java.util.*;
import java.io.*;

 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
	
BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		
		int testcases= Integer.parseInt(br.readLine());
		
		while(testcases-- !=0){
			String s=br.readLine();
			String[] spl= s.split(" ");
			char type= spl[0].charAt(0);
			
			int m=Integer.parseInt(spl[1]);
			int n=Integer.parseInt(spl[2]);
			
			if(type=='r'){
				System.out.println(Math.min(m, n));
			}
			if(type=='k'){
				System.out.println((((m + 1)/2) * ((n + 1)/2)) + (((m)/2) * ((n)/2)));
			}
			if(type=='Q'){
				System.out.println(Math.min(m, n));
			}
			if(type=='K'){
				System.out.println(((m+1)/2)*((n+1)/2));
			}
		}

        }
}
