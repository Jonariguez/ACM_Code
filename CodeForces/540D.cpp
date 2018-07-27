/*
概率dp
不会dp，看着别人的做的，就是从多到少算
一次不同种族相遇就少一个
*/
#include <stdio.h>
#include <string.h>

const int maxn=100+5;
double dp[maxn][maxn][maxn];

int main()
{
    int i,j,k,r,s,p;
    while(scanf("%d%d%d",&r,&s,&p)!=EOF){
        memset(dp,0,sizeof(dp));
        dp[r][s][p]=1;
        for(i=r;i>=0;i--){
            for(j=s;j>=0;j--){
                for(k=p;k>=0;k--){
                    double temp=(i+j+k)*(i+j+k-1)/2-(i-1)*i/2-(j-1)*j/2-(k-1)*k/2;
                    //r s, kill s,so j-1
                    if(i>0 && j>0)
                        dp[i][j-1][k]+=dp[i][j][k]*i*j/temp;
                    //s p, kill p,so k-1
                    if(j>0 && k>0)
                        dp[i][j][k-1]+=dp[i][j][k]*j*k/temp;
                    //r p, kill r,so i-1
                    if(i>0 && k>0)
                        dp[i-1][j][k]+=dp[i][j][k]*i*k/temp;
                }
            }
        }
        double R=0,S=0,P=0;
        for(i=1;i<=r;i++)
            R+=dp[i][0][0];
        for(i=1;i<=s;i++)
            S+=dp[0][i][0];
        for(i=1;i<=p;i++)
            P+=dp[0][0][i];
        printf("%.10f %.10f %.10f\n",R,S,P);
    }
    return 0;
}
