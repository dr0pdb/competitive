import java.util.Scanner;

public class practice{
public static void main (String args[]){
Scanner saurav=new Scanner(System.in);
String p=saurav.next();
String q=saurav.next();
int n=p.compareToIgnoreCase(q);
if(n<0){
	System.out.println(-1);
}
else if (n==0){
	System.out.println(0);

}
else if(n>0){
	System.out.println(1);
}
}
}