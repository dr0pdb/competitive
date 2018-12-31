import java.math.BigInteger;
import java.util.*;
import java.io.*;

 class Main{
    public static void main (String[] args) throws java.lang.Exception
    {
        int[] coins = { 1, 1, 2, 3 };
        int len = 4;
        int MAX = 1001;
        BigInteger [] ways;
        ways = new BigInteger[MAX];
        Arrays.fill(ways, BigInteger.ZERO);
        ways[0] = BigInteger.ONE;
        int coin = 0;
        for (int j = 0; j < MAX; j++)
            for (int i = 0; i < len; i++)
                if (j - coins[i] >= 0)
                    ways[j]=ways[j].add(ways[j - coins[i]]);
 
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            System.out.println(ways[in.nextInt()]);
        }
    }
}
