// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,2,3,4};
    vector<int> v1 = {5,6,7};
    vector<int> v2 = {8,9};
    vector<int>::iterator it1=v.begin(),it2 = v1.begin(), it3 = v2.begin();
    vector<vector<int>::iterator> iteratorsArray = { it1,it2,it3};
    cout<<"\n\ngoogle question"<<endl;
    queue<vector<int>::iterator> q;
    for(auto it:iteratorsArray){
        cout<<*it<<" ";
        q.push(it);
    }
    cout<<"\n\nimplementing final solution using queue"<<endl;
    while(!q.empty()){
        vector<int>::iterator it= q.front();
        q.pop();
        cout<<*it<<" ";
        if(it.hasNext()){
            vector<int>::iterator nextit=next(it,1);
            q.push(nextit);
        }
    }
    return 0;
}
