import java.util.*;

 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
	
	Scanner input= new Scanner(System.in);
		
		while(input.hasNext()){
			
		String time=input.nextLine();
		StringTokenizer tokens= new StringTokenizer(time,":");
		
		double hour=Integer.parseInt(tokens.nextToken());
		double min=Integer.parseInt(tokens.nextToken());
		
		if(hour==0 && min==0){
			break;
		}
		
		else{
			
			double angle1= (30.0*hour)+((min/60.0)*30.0);
			double angle2=min*(360.0/60.0);
			
			double answer= Math.abs(angle1-angle2);
			
			if(answer>180.0){
				answer=360.0-answer;
			}
			
			System.out.printf("%.3f\n",answer);
		}
			
	}
		
		
		
		
			input.close();

        }
}
