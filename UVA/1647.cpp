/*打表找规律
 * n=1  ans=0
 * n=2  ans=1
 * n=3  ans=1
 * n=4  ans=3
 * n=5  ans=5
 * n=6  ans=11
 * n=7  ans=21
 * n=8  ans=43
 * n=9  ans=85
 * n=10 ans=171
 */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args){
		BigInteger[] f = new BigInteger[1010];
		f[1]=BigInteger.valueOf(0);
		for(int i=2;i<=1000;i++){
			f[i]=f[i-1].multiply(BigInteger.valueOf(2));
			if(i%2==0)
				f[i]=f[i].add(BigInteger.valueOf(1));
			else
				f[i]=f[i].subtract(BigInteger.valueOf(1));
		}
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			int n=in.nextInt();
			System.out.println(f[n]);
		}
	}
}
