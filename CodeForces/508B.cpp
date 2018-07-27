/****************
*PID:508b div2
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
typedef long long LL;

const int maxn=100000+10;
char s[maxn];

int main()
{
    int i,j,n;
    while(scanf("%s",s+1)!=EOF){
        n=strlen(s+1);
        if((s[n]-'0')&1){
            int k=n,temp=s[n]-'0';
            for(i=n-1;i>0;i--){
                int x=s[i]-'0';
                if(x&1) continue;
                if(x<=temp){
                    k=i;
                }
            }
            if(k!=n){
                char c=s[n];s[n]=s[k];s[k]=c;//printf("??\n");
                printf("%s\n",s+1);continue;
            }
            k=0;temp=s[n]-'0';
            for(i=1;i<=n;i++){
                int x=s[i]-'0';
                if(x&1) continue;
                if(x>=temp){
                    k=i;
                }
            }
            if(k){
                char c=s[n];s[n]=s[k];s[k]=c;
                printf("%s\n",s+1);continue;
            }
            printf("-1\n");
        }else {
            stack<int> st;
            st.push(1);
            for(i=2;i<n;i++){
                int x=s[i]-'0';
                while(!st.empty() && s[st.top()]-'0'<x) st.pop();
                st.push(i);
            }
            stack<int> s2;
            while(!st.empty()){
                s2.push(st.top());st.pop();
            }
            int cnt=1,x;
            while(!s2.empty()){
                x=s2.top();
                if(x!=cnt) break;
                s2.pop();cnt++;
            }
          //  printf("cnt=%d x=%d\n",cnt,x);
            if(!s2.empty()){
                for(i=1;i<cnt;i++)
                    if((s[i]-'0')%2==0 && s[n]-s[i]>0) break;
                if(i<cnt){
                    char c=s[i];s[i]=s[n];s[n]=c;
                    printf("%s\n",s+1);continue;
                }else {
                    if((s[cnt]-'0')%2==0 && s[n]>=s[x]){
                        char c=s[cnt];s[cnt]=s[n];s[n]=c;
                        printf("%s\n",s+1);continue;
                    }else {
                        char c=s[cnt];s[cnt]=s[x];s[x]=c;
                        printf("%s\n",s+1);continue;
                    }
                }
            }else {
                for(i=1;i<n;i++)
                    if((s[i]-'0')%2==0 && s[i]<s[n]) break;
                char c=s[i];s[i]=s[n];s[n]=c;
                printf("%s\n",s+1);continue;
            }
        }
    }
    return 0;
}

