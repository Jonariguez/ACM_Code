/****************
*PID:la4119
*Auth:Jonariguez
*****************
*/
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<string>
#include<vector>
#include<iostream>
#include<cassert>
using namespace std;
typedef long long LL;

struct Polynomial{
    vector<int> a,e;
    void parse_polynomial(string exp){  //exp不带括号，左右两边的括号传入实参的时候已经处理掉了
        int i=0,len=exp.size();
        while(i<len){
            int sign=1;
            if(exp[i]=='+') i++;
            if(exp[i]=='-'){
                sign=-1;i++;
            }
            int v=0;
            while(i<len && isdigit(exp[i]))     //系数的绝对值
                v=v*10+(exp[i++]-'0');
            if(i==len){ //常数项
                a.push_back(v);e.push_back(0);
            }else {
                assert(exp[i]=='n');
                if(v==0) v=1;       //无系数，则按1处理
                v*=sign;
                if(exp[++i]=='^'){
                    a.push_back(v);
                    v=0;i++;
                    while(i<len && isdigit(exp[i]))
                        v=v*10+(exp[i++]-'0');
                    e.push_back(v);
                }else {
                    a.push_back(v);e.push_back(1);
                }
            }
        }
    }
    int mod(int x,int MOD){
        int n=a.size(),res=0,i,j;
        for(i=0;i<n;i++){
            int m=a[i];
            for(j=0;j<e[i];j++)
                m=(LL)m*x%MOD;
            res=((LL)res+m)%MOD;
        }
        return res;
    }
};

int main()
{
    int i,j,kcase=1;
    string exp;
    while(cin>>exp){
        if(exp[0]=='.') break;
        printf("Case %d: ",kcase++);
        int yes=1;
        Polynomial poly;
        int pos=exp.find('/');
        poly.parse_polynomial(exp.substr(1,pos-2));
        int D=0;
        while(++pos<exp.size())
            D=D*10+(exp[pos]-'0');
        for(i=1;i<=poly.e[0]+1;i++)
            if(poly.mod(i,D)!=0){
                yes=0;break;
            }
        if(yes)
            printf("Always an integer\n");
        else printf("Not always an integer\n");
    }
    return 0;
}
