/*
ID:Jonariguez7
PROG:beads
LANG:C++
*/
#include <stdio.h>
#include <string.h>
//#define F(x-1) (x-1+n)%n

int n;
char str[800];

int cal(int s,int t){
    int sum_l=0,sum_r=0,r=0,w=0,b=0;
    while(s<t){
        if(str[s]=='b' && r || str[s]=='r' && b) break;
        sum_l++;
        if(str[s]=='b') b++;
        if(str[s]=='r') r++;
        s++;
    }
    if(s==t) return n;
    b=r=0;
    while(s<=t){
        if(str[t]=='b' && r || str[t]=='r' && b) break;
        sum_r++;
        if(str[t]=='b') b++;
        if(str[t]=='r') r++;
        t--;
    }
    return sum_r+sum_l;
}

int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    int i,m;
    scanf("%d",&n);
    scanf("%s",str);
    int maxv=-1,v;
    m=n;
    for(i=0;i<n;i++){
        int t=cal(i,m-1);
        if(maxv<t) maxv=t;
        str[m++]=str[i];
    }
    printf("%d\n",maxv,v);
    return 0;
}
