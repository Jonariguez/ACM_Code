#include <stdio.h>
#include <string.h>

const int maxn=200000+10;

int bit[maxn],n,a[maxn];        //aΪԭ���飬��Ϊ�����ǰ�ĳ��ĳ�y��BIT�Ĺ���������������Ӧ����������a[x]��y�Ĳ�ֵ

void add(int i,int v){
    while(i<=n){
        bit[i]+=v;
        i+=i&(-i);
    }
}

int sum(int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

int main()
{
    int i,kcase=1,x,y;
    char s[3];
    scanf("%d",&n);
    while(n){
        memset(bit,0,sizeof(bit));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            add(i,a[i]);
        }
        printf("Case %d:\n",kcase++);
        while(scanf("%s",s)){
            if(strcmp(s,"END")==0) break;
            scanf("%d%d",&x,&y);
            if(s[0]=='S'){
                add(x,y-a[x]);
                a[x]=y;
            }else{
                printf("%d\n",sum(y)-sum(x-1));
            }
        }
        scanf("%d",&n);
        if(n)
            printf("\n");
    }
    return 0;
}

