import java.util.*;

 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
	Scanner input= new Scanner(System.in);
		
		
		
		
		while(input.hasNext()){
			int minimum=500001;
			boolean possible=false;
			int participants=input.nextInt();
			int budget=input.nextInt();
			int noofhotels=input.nextInt();
			int noofweeks=input.nextInt();
			int totalcost;
		
		for(int x=0;x<noofhotels;x++){
			
			int priceperperson=input.nextInt();
			totalcost=priceperperson*participants;
			int noofbed[]= new int[noofweeks];
			int max=0;
			
				for(int y=0;y<noofweeks;y++){
					
				  noofbed[y]=input.nextInt();
				  if(noofbed[y]>max){
					  max=noofbed[y];
				  }
				  
				}
			  
			if(max>=participants && totalcost<=budget){
				
				possible=true;
				if(totalcost<minimum){
					minimum=totalcost;
				}
				
				
			}	
				
			
		}
		
		if(possible==false){
			System.out.println("stay home");
		}
		else{
			System.out.println(minimum);
		}
		
		}
		
		
		input.close();

        }
}
