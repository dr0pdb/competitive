import java.util.*;

 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
	
	Scanner input= new Scanner(System.in);
		
		while(input.hasNext()){
			
			double height=input.nextDouble();
			double climb=input.nextDouble();
			double slide=input.nextDouble();
			double fatigue=input.nextDouble();
			
			if(height==0){
				break;
			}
			
			else{
	
				int dayno=0;
				double position=0;
				double decrement=(climb*fatigue)/100;
				
				
				while(1>0){
					dayno++;
					position=position+climb;
					if(position>height){
						System.out.printf("success on day %d\n",dayno);
						break;
					}
					else{
						
						position-=slide;
						if(position<0){
							System.out.printf("failure on day %d\n",dayno );
							break;
						}
						
						if(climb-decrement>0){
							
							climb=climb-decrement;
							
						}
						
						else{
							climb=0;
						}
						
						
					}
					
				
				
				}
				
				
				
			}
			
			
		}
		

		
		
		
		
		input.close();

        }
}
