import java.util.*;
import java.io.*;

 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		int n,p;
		int[] arr;

		while(t-- >0){
			n= in.nextInt();
			p = in.nextInt();
			arr = new int[p];
			for (int i=0;i<p ;i++ ) {
				arr[i]= in.nextInt();
			}
			boolean solFound = false;
			for(int i = 0 ; i< (1<<p); i++){
				int sum = 0;
				for (int j=0;j<p ;j++ ) {
					if ((i & (1<<j)) >0){
						sum+=arr[j];
					}
				}
				if (sum == n) {
					solFound= true;
					break;
				}
			}
			if (solFound) {
				System.out.println("YES");
			}else{
				System.out.println("NO");
			}
		}

    }
}
