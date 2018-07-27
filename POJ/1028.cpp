/****************
*PID:poj1028
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+20;

int main()
{
    int i,j,v;
    string op,web;
    stack<string> Back,forw;
    web="http://www.acm.org/";
    while(cin>>op){
        if(op[0]=='Q') break;
        if(op[0]=='V'){
            Back.push(web);
            while(!forw.empty())
                forw.pop();
            cin>>web;
            cout<<web<<endl;
        }else if(op[0]=='B'){
            if(Back.empty())
                printf("Ignored\n");
            else {
                forw.push(web);
                web=Back.top();Back.pop();
                cout<<web<<endl;
            }
        }else if(op[0]=='F'){
            if(forw.empty())
                printf("Ignored\n");
            else {
                Back.push(web);
                web=forw.top();forw.pop();
                cout<<web<<endl;
            }
        }else
            cout<<web<<endl;
    }
    return 0;
}
