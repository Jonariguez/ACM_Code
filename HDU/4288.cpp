/*
����Ҳ�С���������������
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef __int64 ll;

const int maxn=100000+10;
vector<int> a;

int main()
{
    int i,j,n,q;
    char s[10];
    while(scanf("%d",&q)!=EOF){
        n=0;
        a.clear();
        vector<int>::iterator it;
        while(q--){
            scanf("%s",s);
            int x;
            if(s[0]=='a'){
                scanf("%d",&x);
                it=lower_bound(a.begin(),a.end(),x);
                a.insert(it,x);
                n++;
            }else if(s[0]=='d'){
                scanf("%d",&x);
                it=lower_bound(a.begin(),a.end(),x);
                a.erase(it);
                n--;
            }else {
                ll res=0;
                for(i=2;i<n;i+=5)   //����ֱ�Ӳ���Ϊ5����Ҫ++��if�ж�
                    res+=a[i];
                printf("%I64d\n",res);
            }
        }
    }
    return 0;
}

