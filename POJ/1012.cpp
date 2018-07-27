/****************
*PID:poj1012
*Auth:Jonariguez
*****************
接下来说说m的取值范围：我们考察一下只剩下k+1个人时候
情况，即坏人还有一个未被处决，那么在这一轮中结束位置
必定在最后一个坏人，那么开始位置在哪呢？这就需要找K+2个
人的结束位置，然而K+2个人的结束位置必定是第K+2个人或者
第K+1个人，这样就出现两种顺序情况：GGGG.....GGGXB 或
GGGG......GGGBX (X表示有K+2个人的那一轮退出的人）所以有
K+1个人的那一轮的开始位置有两种可能即第一个位置或K+1的
那个位置，限定m有两种可能：t(k+1) 或 t(k+1)+1; t>=1;

*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int k,Joseph[15]={0};

bool judge(int m){
    int i,n=k*2,f=0;
    for(i=0;i<k;i++){
        f=(f+m-1)%(n-i);    //之所以m-1，是因为编号从0开始，第m个即m-1号，m-1号被杀，则后面的那个前移到m-1号
        if(f<k)                                                          //故开始的位置还是m-1号（当然要再%(n-i)
            return false;
    }
    return true;
}


int main()
{
    int i,j,m;
    for(k=1;k<14;k++){
        int t=k+1;
        while(1){
            if(judge(t)){
                Joseph[k]=t;
                break;
            }else if(judge(t+1)){
                Joseph[k]=t+1;
                break;
            }
            t+=k+1;
        }
    }
    while(scanf("%d",&k),k)
        printf("%d\n",Joseph[k]);
    return 0;
}

