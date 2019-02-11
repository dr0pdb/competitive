import java.util.*;
public class practice {
	
	

	
public static void main (String[] args) throws java.lang.Exception{
	  Scanner input = new Scanner(System.in);
	  int d=input.nextInt();
	  int sumtime=input.nextInt();
	  int mintime[]= new int[d];
	  int maxtime[]= new int[d];
	  int studytime[]= new int[d];
	  int summin=0;
	  int summax=0;
	  for(int x=0; x<d;x++){
		  mintime[x]=input.nextInt();
		  maxtime[x]=input.nextInt();
		  summin+=mintime[x];
		  summax+=maxtime[x];
	  }
	  if(sumtime>=summin && sumtime<=summax){
		  for(int x=0;x<d;x++){
			  studytime[x]= mintime[x];
			  sumtime-=studytime[x];
		  }
		  for(int x=0;x<d;x++){
			  if (maxtime[x]- mintime[x]<sumtime){
				  studytime[x]=maxtime[x];
			      sumtime-=maxtime[x]- mintime[x];
			  }
			  else{
				  studytime[x]+=sumtime;
				  break;
			  }
			  
		  }
		  System.out.println("YES");
		  for(int x=0;x<d;x++){
			  System.out.printf("%d ",studytime[x] );
		  }
	  }
	  
	      else{
		  System.out.println("NO");
	  }
	      input.close();	
	   
	   } 
}