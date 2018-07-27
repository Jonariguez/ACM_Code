/****************
*PID:la3882
*Auth:Jonariguez
*****************
约瑟夫
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,n,m,k;
    while(scanf("%d%d%d",&n,&k,&m)){
        if(n==0 && m==0 && k==0) break;
        int f=0;            //因为一开始先杀死了一个m，然后用n-1个人约瑟夫，所以我们只需求到n-1的结果f
        for(i=2;i<n;i++)
            f=(f+k)%i;      //n-1个人的时候死的是f，
        f=(f+m)%n;          //n->n-1时是数了m个，所以这次要+m才推回去，最后结果+1表示题目的下标从1开始
        printf("%d\n",f+1);
    }
    return 0;
}
