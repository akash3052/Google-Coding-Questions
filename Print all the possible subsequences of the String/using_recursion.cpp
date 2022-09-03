#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void  allPossibleSub(string ip, string op, int index, vector<string> &res){
    if(index == ip.length()){
        res.push_back(op);
        return;
    }
    allPossibleSub(ip,op,index+1,res);
    allPossibleSub(ip,op+ip[index], index+1, res);
    return;
}

int main() {
    string ip = "abc",op= "";
    int index = 0;
    vector<string> ans ;
    allPossibleSub(ip, op, index, ans);
    for(auto sub :ans)
        cout<<sub<<endl;
}
