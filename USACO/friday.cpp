/*
ID:Jonariguez7
PROG:friday
LANG:C++
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;

int month[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int cal(int year){
    if(year%4==0 && year%100!=0 || year%400==0) return 1;
    return 0;
}

int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    int i,j,n,k,day;
    int week[7];
    fill(week,week+7,0);
    day=6;      //1990.1.13 «÷‹¡˘
    week[day]++;
    scanf("%d",&n);
    for(i=1900;i<n+1900;i++){
        for(j=1;j<=12;j++){
            if(i==n+1900-1 && j==12) break;
            if(j==2){
                day=(day+month[j]+cal(i))%7;
                week[day]++;
            }
            else {
                day=(day+month[j])%7;
                week[day]++;
            }
        }
    }
    printf("%d %d %d %d %d %d %d\n",week[6],week[0],week[1],week[2],week[3],week[4],week[5]);
    return 0;
}
