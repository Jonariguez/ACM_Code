#include <stdio.h>
#include <string.h>

const int maxn=65535+5;
const int n=131072;
int cover[maxn*8],mark[maxn*8];     //cover 0 1 0 mark xor

struct pp{
    int Start,End;
}ss[maxn];

void XOR(int k){
    if(cover[k]!=-1)
        cover[k]^=1;
    else mark[k]^=1;
}

void pushDown(int k){
    if(cover[k]!=-1){
        cover[k*2]=cover[k*2+1]=cover[k];
        mark[k*2]=mark[k*2+1]=0;//mark[k]=0;
        cover[k]=-1;
    }
    if(mark[k]){
        mark[k*2]=mark[k*2+1]=mark[k];
        XOR(k*2);
        XOR(k*2+1);
        mark[k]=0;
    }
}

void updatec(int a,int b,int k,int l,int r,int c){
    if(a<=l && r<=b){
        cover[k]=c;mark[k]=0;return ;
    }
    pushDown(k);
    int m=(l+r)/2;
    if(a<=m)
        updatec(a,b,k*2,l,m,c);
    if(b>m)
        updatec(a,b,k*2+1,m+1,r,c);
}

void updatem(int a,int b,int k,int l,int r,int c){
    if(a<=l && r<=b){
        mark[k]=c;return ;
    }
    pushDown(k);
    int m=(l+r)/2;
    if(a<=m)
        updatem(a,b,k*2,l,m,c);
    if(b>m)
        updatem(a,b,k*2+1,m+1,r,c);
}

int tot;
bool hash[n*2];

/*
void query(int k,int l,int r){
    if(cover[k]==1){
  //  printf("cover[%d]=%d\n",k,cover[k]);
        s[tot].Start=l;s[tot++].End=r;
        return ;
    }else if(cover[k]==0) return ;
    if(l==r) return ;
    int m=(l+r)/2;
    pushDown(k);
    query(k*2,l,m);
    query(k*2+1,m+1,r);
}*/

void query(int k,int l,int r){
    if(cover[k]==1){
        for (int it = l ; it <= r ; it ++)
			hash[it] = true;
        return ;
    }else if(cover[k]==0) return ;
    if(l==r) return ;
    int m=(l+r)/2;
    pushDown(k);
    query(k*2,l,m);
    query(k*2+1,m+1,r);
}

int main()
{
    int i,j,a,b;
    char op,l,r;
    int cnt=0;
    cover[1]=mark[1]=0;
  //  memset(cover,-1,sizeof
    while(scanf("%c %c%d,%d%c",&op,&l,&a,&b,&r)!=EOF){
        a*=2;b*=2;
        if(l=='(') a++;
        if(r==')') b--;
        if(a>b){
            if(op=='I' || op=='C')
                mark[1]=cover[1]=0;
            continue;
        }
        if(op=='U'){
            updatec(a,b,1,0,n,1);
        }
        else if(op=='I'){
            updatec(0,a-1,1,0,n,0);
            updatec(b+1,n,1,0,n,0);
        }
        else if(op=='D')
            updatec(a,b,1,0,n,0);
        else if(op=='C'){
            updatec(0,a-1,1,0,n,0);
            updatec(b+1,n,1,0,n,0);
            updatem(a,b,1,0,n,1);
        }else if(op=='S')
            updatem(a,b,1,0,n,1);
        getchar();
    //    if(++cnt==5)
    //        break;
    }
    tot=0;
    query(1,0,n);
    /*
    if(tot==0){
        printf("empty set\n");return 0;
    }
    int f;
    bool flag=false;
    if(tot==1){
        if(s[0].Start&1)
            printf("(%d,",s[0].Start/2);
        else printf("[%d,",s[0].Start/2);
        if(s[0].End&1)
            printf("%d) ",s[0].End/2+1);
        else printf("%d] ",s[0].End/2);
        return 0;
    }
    for(i=0;i<tot;i++){
        f=s[i].Start;
        while(i<tot-1 && s[i].End==s[i+1].Start-1)
            i++;
        if(flag) printf(" ");
        flag=true;
        if(f&1)
            printf("(%d,",f/2);
        else printf("[%d,",f/2);
        if(s[i].End&1)
            printf("%d) ",s[i].End/2+1);
        else printf("%d] ",s[i].End/2);
    }*/
    bool flag = false;
	int s = -1 , e;
	for (int i = 0 ; i <= maxn ; i ++) {
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
