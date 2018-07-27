/****************
*ID:ZOJ2865
*Auth:Jonariguez
*****************
 * S(n,k)=1/(k+1) *[(n+1)^(k+1) - C[k+1][2]*S(n,k-1) - C[k+1][3]*S(n,k-2)-...-C[k+1][k]*S(n,1) - n -1]
 * ������k==1  S(n,1)= n*(n+1)/2
*/


import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static final int maxn=105;
	public static final BigInteger FLAG = BigInteger.ZERO.subtract(BigInteger.ONE);
	public static BigInteger[][] c = new BigInteger[maxn][maxn];
	public static BigInteger[] ans = new BigInteger[maxn];

	public static void Init(){
		for(int i=0;i<maxn;i++){
			for(int j=0;j<=i;j++){
				if(j==0 || j==i)
					c[i][j]=BigInteger.ONE;
				else
					c[i][j]=c[i-1][j].add(c[i-1][j-1]);
			}
		}
	}

	public static BigInteger solve(BigInteger n,int k){
		if(ans[k].compareTo(FLAG)!=0)		//ans���仯��ans[k]!=-1˵���Ѿ�������ˣ�����ֱ�ӷ���
			return ans[k];
		if(k==1){					//k=1ʱ������1+2+3+..+n������n*(n+1)/2,Ҳ���ǵݹ������
			ans[k]= (n.add(BigInteger.ONE).multiply(n)).divide(BigInteger.valueOf(2));
			return ans[k];
		}
		BigInteger temp = BigInteger.ONE;
		for(int i=0;i<=k;i++){				//��(n+1)^(k+1)
			temp=temp.multiply(n.add(BigInteger.ONE));
		}
		temp=temp.subtract(n.add(BigInteger.ONE));
		BigInteger sum = BigInteger.ZERO;
		for(int i=1;i<k;i++){				//��ÿһ��C[k+1][i+1]*S(n,k-i)
			BigInteger t = c[k+1][i+1].multiply(solve(n,k-i));
			sum=sum.add(t);
		}
		ans[k]= temp.subtract(sum).divide(BigInteger.valueOf(k+1));		//�������ǰ���ϵ��k+1
		return ans[k];
	}

	public static void main(String[] args){
		Init();
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			BigInteger n = in.nextBigInteger();
			int k = in.nextInt();
			for(int i=0;i<maxn;i++)
				ans[i]=FLAG;
			System.out.println(solve(n,k));
		}
	}
}
