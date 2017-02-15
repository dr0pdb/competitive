import java.util.*;
import java.io.*;

 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
	

		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		String s;
		int testcase=1;
			
		
		while((s=br.readLine()) !=null && !s.equals("0 0") ){
			
			StringTokenizer st= new StringTokenizer(s);
			int noreq= Integer.parseInt(st.nextToken());
			int noproposals=Integer.parseInt(st.nextToken());
			
			String name;
			for(int x=0;x<noreq;x++){
				name=br.readLine();
			}
			
			double selectedprice=0.0;
			int selectedreqmet=0;
			String selectedname="";
			
			for(int x=0;x<noproposals;x++){
				
				String currentname=br.readLine();
				st=new StringTokenizer(br.readLine());
				double currentprice=Double.parseDouble(st.nextToken());
				int currentreqmet=Integer.parseInt(st.nextToken());
				
				
				for(int y=0;y<currentreqmet;y++){
					name=br.readLine();
				}
				
				
				if(currentreqmet>selectedreqmet || ((currentreqmet== selectedreqmet) && currentprice<selectedprice) ){
					selectedname=currentname;
					selectedprice=currentprice;
					selectedreqmet=currentreqmet;
				}
				
				
			}
			
			if(testcase>1){
				System.out.println();
			}
			
			System.out.printf("RFP #%d\n",testcase);
			System.out.println(selectedname);
			testcase++;
		}
		

        }
}
