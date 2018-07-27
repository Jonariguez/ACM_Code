#include <stdio.h>
#include <string.h>
#include <stack>
#include <string>   //°üº¬isalpha
using namespace std;

struct Matrix{
    int a,b;
    Matrix(int a=0,int b=0):a(a),b(b){}
}m[30];

stack<Matrix> s;
char expr[10000];

int main()
{
    int i,n,k;
    char name[5];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",name);
        k=name[0]-'A';
        scanf("%d%d",&m[k].a,&m[k].b);
    }
    while(scanf("%s",expr)!=EOF){
        int len=strlen(expr);
        bool error=false;
        int res=0;
        for(i=0;i<len;i++){
            //if(isalpha(expr[i]))
            if(expr[i]>='A' && expr[i]<='Z')
                s.push(m[expr[i]-'A']);
            else if(expr[i]==')'){
                Matrix m2=s.top();s.pop();
                Matrix m1=s.top();s.pop();
                if(m1.b!=m2.a){
                    error=true;break;
                }
                res+=m1.a*m1.b*m2.b;
                s.push(Matrix(m1.a,m2.b));
            }
        }
        if(error)
            printf("error\n");
        else
            printf("%d\n",res);
    }
    return 0;
}
