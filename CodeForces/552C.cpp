/*
CF 552C 进制转换
题目大意：给定一个天平，砝码的重量为w的0~100次幂，
每种砝码只有一个，砝码可以放在左盘或者右盘。给定物
品的重量m，问是否有一种方案让天平两端平衡
解题思路：把m化为w进制，改进制数只能有0,1或者w-1，
若为w-1那么相当于在物品所放的盘里加一个砝码，然后在
另一盘加上w倍的砝码即可。直接w进制数当前位清0，将下
一位+1即可。最后看w进制数是否正好是一个01串即可

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,flag,m,w,k,bit[40];
    while(scanf("%d%d",&w,&m)!=EOF){
        k=0;flag=1;
        while(m){
            bit[k++]=m%w;
            m/=w;
        }
        for(i=0;i<k;i++){
            if(bit[i]==0 || bit[i]==1) continue;
            if(bit[i]>=w){
                bit[i]-=w;
                bit[i+1]++;
            }
            if(bit[i]==w-1)
                bit[i+1]++;
            else if(bit[i]>1){
                flag=0;break;
            }
        }
        if(flag)
            puts("YES");
        else puts("NO");
    }
    return 0;
}
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

bool solve(int w,int m){
    while(m>0){
        int v=m%w;
        if(v==0) m/=w;
        else if(v==1) m=(m-1)/w;
        else if(v==w-1) m=(m+1)/w;
        else return false;
    }
    return true;
}

int main()
{
    int i,j,m,w;
    while(scanf("%d%d",&w,&m)!=EOF){
        if(solve(w,m))
            puts("YES");
        else puts("NO");
    }
    return 0;
}
