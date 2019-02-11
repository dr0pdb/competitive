import java.util.Scanner;

public class practice{
public static void main (String args[]){
Scanner saurav=new Scanner(System.in);
int n=saurav.nextInt();
int sum1=0;
int sum2=0;
int sum3=0;
for(int y=1;y<=n;y++){
	int p=saurav.nextInt();
	int q=saurav.nextInt();
	int r=saurav.nextInt();
    sum1+=p;
    sum2+=q;
    sum3+=r;
}
if(sum1==0 && sum2==0 && sum3==0){
	System.out.println("YES");

}
else{
	System.out.println("NO");
}


 }
}