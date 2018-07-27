/****************
*PID:hdu5479
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
char str[maxn];

int main()
{
    int i,left,right,n,T;
    scanf("%d",&T);
    while(T--){
        stack<char> s;
        int res=0;
        char ch;
        scanf("%s",str);
        n=strlen(str);
        for(i=0;i<n;i++){
            if(s.empty())
                s.push(str[i]);
            else if(str[i]==')' && s.top()=='('){
                res++;s.pop();
            }else if(str[i]=='(')
                s.push(str[i]);
        }
        printf("%d\n",res);
    }
    return 0;
}
