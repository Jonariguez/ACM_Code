/****************
*ID:uva400
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxcol=60;
const int maxn=100+5;
string file[maxn];

void print(string str,int len,char c){
    cout<<str;
    for(int i=0;i<len-str.length();i++)
        printf("%c",c);
}

int main()
{
    int i,j,M,n;
    while(scanf("%d",&n)!=EOF){
        M=0;
        for(i=0;i<n;i++){
            cin>>file[i];
            M=max(M,(int)file[i].length());
        }
        int col=(60-M)/(M+2)+1,row=(n+col-1)/col;
        print("",60,'-');
        printf("\n");
        sort(file,file+n);
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                int x=j*row+i;
                if(x<n)
                    print(file[x],j==col-1?M:M+1,' ');
            }
            printf("\n");
        }
    }
    return 0;
}
