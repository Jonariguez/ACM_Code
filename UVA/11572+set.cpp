/*
尺取(set)
*/
#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;

const int maxn=1000000+5;
int a[maxn];

int main()
{
    int i,j,T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        set<int> st;
        int s=0,t=0,res=0;  //s是区间开头，t是区间末尾
        while(t<n){
            while(t<n && !st.count(a[t]))
                st.insert(a[t++]);
            res=max(res,t-s);
            st.erase(a[s++]);
        }
        printf("%d\n",res);
    }
    return 0;
}
