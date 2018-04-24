import java.util.*;

 class Main{
	public static void main (String[] args) throws java.lang.Exception
	{
	Scanner input= new Scanner(System.in);
		
		while(input.hasNext()){
		
			
			int t=input.nextInt();
		
            if(t==0){
            	break;
            }
            
            else{
             
        		int originx=input.nextInt();
        		int originy=input.nextInt();
            	
        		while(t-- !=0){
        			
        			int coordx=input.nextInt();
        			int coordy=input.nextInt();
        			
        			if(coordx== originx || coordy==originy){
        				System.out.println("divisa");
        			}
        			
        			if(coordx>originx && coordy>originy){
        				System.out.println("NE");
        			}
        			

        			if(coordx>originx && coordy<originy){
        				System.out.println("SE");
        			}
        			
        			if(coordx<originx && coordy>originy){
        				System.out.println("NO");
        			}
					if(coordx<originx && coordy<originy){
						System.out.println("SO");
					}
        		}
        		
            }
		
		
		}
		
				
		 	input.close();


        }
}
