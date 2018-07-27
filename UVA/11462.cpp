/****************
*PID:uva11462
*Auth:Jonariguez
*****************
¼ÆÊýÅÅÐò
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

inline int readint(){
    char c=getchar();
    while(!isdigit(c))
        c=getchar();
    int x=0;
    while(isdigit(c)){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x;
}

int buf[10];

inline void writeint(int i){
    int p=0;
    if(i==0) buf[p++]=0;
    else while(i){
        buf[p++]=i%10;
        i/=10;
    }
    for(int j=p-1;j>=0;j--)
        putchar('0'+buf[j]);
}

int c[110];

int main()
{
    int i,n,x;
    while(n=readint()){
        memset(c,0,sizeof(c));
        for(i=0;i<n;i++){
            x=readint();
            c[x]++;
        }
        int flag=0;
        for(i=0;i<=100;i++){
            while(c[i]){
                if(flag) printf(" ");
                flag=1;
                writeint(i);
                c[i]--;
            }
        }
        printf("\n");
    }
    return 0;
}
