#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;


//Kieu_du_lieu tenmang[so luong];
//tenmang[index]
//chi so bat dau tu 0
bool nt(int n){
        for(int i=2; i<= sqrt(n); i++){
            if(n % i ==0) return false;
        }
        return n > 1;
}
int main(){
    //int a[100]; //400 bytes lien tiep
    // long long b[100];
    // double c[100];
    // char d[100];

    // int a[10] = {10,9,8,7,6,5,4,3,2,1};
    // int n; cin>>n;
    // int a[n];
    // for(int i =0; i< n; i++){
    //     cin>>a[i];
    // }
    // int sum =0;
    // for(int i =0; i<n; i++){
    //     sum += a[i];
    // }
    // cout<<sum;
    //kiem tra so nguyen to
    
    // int n; cin>>n;
    // int a[n];
    // for( int &x : a){
    //     cin>>x;
    // }
    
    // for(int y : a){
    //     cout<< y << " ";
    // }
    return 0;
}
