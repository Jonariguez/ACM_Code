#include <stdio.h>
#include <string.h>

const int maxn=65535*2+10;
const int n=65535*2;
int cover[maxn*4],mark[maxn*4];

void XOR(int k){        //���������ȷ��(��cover[k]!=-1),ֱ�ӷ�ת�����ͺã�����תmark���
    if(cover[k]!=-1)
        cover[k]^=1;
    else
        mark[k]^=1;     //��ʵ��һ�������´�mark��ǣ�����pushDown��Ͳ���д��
}

void pushDown(int k){
    if(cover[k]!=-1){
        cover[k*2]=cover[k*2+1]=cover[k];
        mark[k*2]=mark[k*2+1]=0;
        cover[k]=-1;
    }
    if(mark[k]){
        XOR(k*2);
        XOR(k*2+1);
        mark[k]=0;
    }
}

void updatec(int a,int b,int v,int k,int l,int r){
    if(a<=l && r<=b){
        cover[k]=v;mark[k]=0;return ;
    }
    pushDown(k);
    int m=(l+r)/2;
    if(a<=m)
        updatec(a,b,v,k*2,l,m);
    if(b>m)
        updatec(a,b,v,k*2+1,m+1,r);
}

void updatem(int a,int b,int v,int k,int l,int r){
    if(a<=l && r<=b){
     //   mark[k]=v;
        if(cover[k]!=-1) cover[k]^=1;       //һ��Ҫע���������ֱ��mark[k]=v,��Ϊ���䷭ת����ת��Ľ��
        else mark[k]^=1;                    //��ȡ���ڷ�תǰ��״̬�ģ���������mark[k]һ��ʼ��1����ô�������
        return ;                            //v����1�Ļ��������ַ�תһ��mark[k]Ӧ��=0��������ֱ��mark[k]=v=1!!!!!!!
    }
    pushDown(k);
    int m=(l+r)/2;
    if(a<=m)
        updatem(a,b,v,k*2,l,m);
    if(b>m)
        updatem(a,b,v,k*2+1,m+1,r);
}

bool hash[n+5];

void query(int k,int l,int r){
    if(cover[k]==1){
        for(int i=l;i<=r;i++) hash[i]=true;
        return;
    }else if(cover[k]==0) return ;
    if(l==r) return ;
    pushDown(k);
    int m=(l+r)/2;
    query(k*2,l,m);
    query(k*2+1,m+1,r);
}

int main()
{
    int i,j,a,b;
    char op,l,r;
    cover[1]=mark[1]=0;
    int cnt=0;
    while(scanf("%c %c%d,%d%c",&op,&l,&a,&b,&r)!=EOF){
        a*=2;b*=2;
        if(l=='(') a++;
        if(r==')') b--;
        if(a>b){
            if(op=='I' || op=='C')
                cover[1]=mark[1]=0;
                continue;
        }
        if(op=='U')
            updatec(a,b,1,1,0,n);
        else if(op=='I'){
            if(a!=0) updatec(0,a-1,0,1,0,n);
            if(b!=n) updatec(b+1,n,0,1,0,n);
        }
        else if(op=='D')
            updatec(a,b,0,1,0,n);
        else if(op=='C'){
            if(a!=0) updatec(0,a-1,0,1,0,n);
            if(b!=n) updatec(b+1,n,0,1,0,n);
            updatem(a,b,1,1,0,n);
        }else if(op=='S'){
            updatem(a,b,1,1,0,n);
        }
        getchar();
   //     if(++cnt==5)
   //         break;
    }
    memset(hash,false,sizeof(hash));
    query(1,0,n);
    bool flag = false;
	int s = -1 , e;
	for (int i = 0 ; i <= n ; i ++) {
		if (hash[i]) {
			if (s == -1) s = i;
			e = i;
		} else {
			if (s != -1) {
				if (flag) printf(" ");
				flag = true;
				printf("%c%d,%d%c",s&1?'(':'[' , s>>1 , (e+1)>>1 , e&1?')':']');
				s = -1;
			}
		}
	}
	if (!flag) printf("empty set");
	puts("");
	return 0;
}




