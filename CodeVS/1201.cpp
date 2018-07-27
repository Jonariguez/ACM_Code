/****************
*PID:cdvs1201
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
#define eps 1e-8

stack<string> st;

int main()
{
    string line;
    getline(cin,line);
    stringstream ss(line);
    string s;
    while(ss>>s)
        st.push(s);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
