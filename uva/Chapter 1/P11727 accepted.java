import java.util.*;
import java.lang.Math;
 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
          Scanner input = new Scanner(System.in);
			int T = input.nextInt();
			for (int x=0;x<T; x++){
	            int p1=input.nextInt();
	            int p2=input.nextInt();
	            int p3=input.nextInt();
	            int answer = Math.max(Math.min(p1,p2), Math.min(Math.max(p1,p2),p3));
	            System.out.println("Case "+(x+1)+": "+answer );
			}
			input.close();
		}
}
