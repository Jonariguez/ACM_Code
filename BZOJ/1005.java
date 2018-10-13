package BZOJ1005;
/*
 * BZOJ-1005
 * 运用purfer序列的知识求解，并运用了组合
 */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static int n,d[]=new int[1005];
	static BigInteger p[]=new BigInteger[1005];
	static BigInteger res;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int i,j,yes=1,sum=0,cnt=0;
		n=in.nextInt();
		for(i=1;i<=n;i++) {
			d[i]=in.nextInt();
			if(d[i]==0 || d[i]>n-1)
				yes=0;
			if(d[i]==-1) 
				continue;
			sum+=d[i]-1;
			cnt++;
		}
		if(n==1) {
			if(d[1]==0 || d[1]==-1)
				System.out.println(1);
			else System.out.println(0);
		}else if(n==2) {
			if((d[1]==1 && d[2]==-1) || (d[1]==-1 && d[2]==1))
				System.out.println(1);
			else System.out.println(0);
		}else if(yes==0)
			System.out.println(0);
		else {
			p[0]=BigInteger.ONE;
			for(i=1;i<=n;i++) 
				p[i]=p[i-1].multiply(BigInteger.valueOf(i));
			res=p[n-2-sum];
			for(i=1;i<=n;i++) {
				if(d[i]<=1) continue;
				res=res.multiply(p[d[i]-1]);
			}
			res=p[n-2].divide(res);
			BigInteger temp=BigInteger.valueOf(n-cnt);
			for(i=1;i<=n-2-sum;i++)
				res=res.multiply(temp);
			System.out.println(res);
		}
	}
}
