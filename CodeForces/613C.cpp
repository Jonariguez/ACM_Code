/****************
*PID:615c div2
*Auth:Jonariguez
*****************
string里的substr(i,j)是以i开头，长度是j的
而不是以j结束的子串。。。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> res;
int vis[33];

int main()
{
    int i,j,n,m,k;
    string s,t,in;
  //  cout<<string::npos;
    cin>>s>>t;
    m=s.length();
    for(i=0;i<m;i++)
        vis[s[i]-'a']++;
    n=t.length();
    for(i=0;i<n;i++)
        if(vis[t[i]-'a']==0) break;
    if(i<n){
        puts("-1");return 0;
    }
    in=s;
    for(i=0;i<m;i++)
        in[i]=s[m-1-i];
 //   cout<<in<<endl;
    k=0;
    int last=0,cnt=0;
    for(i=n;i>=1;i--){
        //    printf("i=%d\n",i);
        int len=i-last;
        string temp="";
        temp=t.substr(last,len);
       // cout<<temp<<endl;
        int pp=s.find(temp,0);
      //  cnt++;
      //  if(cnt==11) break;
      //  printf("%d\n",pp);
        if(pp!=-1){
            k++;res.push_back(pp);res.push_back(pp+temp.length()-1);
            if(i==n) break;
            last=i;
            i=n+1;//t=t.substr(i-1,n);
            continue;
        }
        pp=in.find(temp,0);
        if(pp!=-1){
            k++;res.push_back(in.length()-1-pp);res.push_back(in.length()-1-pp+1-temp.length());
            if(i==n) break;
            last=i;
            i=n+1;//t=t.substr(i-1,n);
            continue;
        }
    }
    if(k==0) k=-1;
    printf("%d\n",k);
    for(i=0;i<res.size();i+=2)
        printf("%d %d\n",res[i]+1,res[i+1]+1);
    return 0;
}
