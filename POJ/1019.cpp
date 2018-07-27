/****************
*PID:poj1019
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

int main()
{
    LL i,j,n,res;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d",&n);
        LL now=1,sum=0;
        while(sum+now<n){
