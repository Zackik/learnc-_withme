#include <bits/stdc++.h>
using namespace std;


bool nt(int n){
    for(int i = 2; i<= sqrt(n); i++){
        if( n % i ==0) return false;
    }
    return n>1;
}
int main(){
    //bai1: lie ke so nguyen trong ma tran
    // int t; cin>>t;
    // while(t--){
    //     int n, m; cin>>n>>m;
    //     int a[500][500];
    //     //nhap ma tran
    //     for(int i =0; i< n; i++){
    //         for(int j =0; j < m; j++) cin>> a[i][j];
    //     }
    //     map<int, int> mp;
    //     for(int i = 0; i< n; i++){
    //         for(int j =0; j< m; j++){
    //             if(nt(a[i][j]) && mp[a[i][j]] == 0){
    //                 cout<< a[i][j]<< " ";
    //                 mp[a[i][j]] = 1;
    //             }
    //         }
    //     }
    //     cout<<endl;
    // }

    //bai 2: phan tu lon nhat trong ma tran
    int t; cin>> t;
    while(t--){
        int n, m; cin>>n>>m;
        int a[500][500];
        //nhap ma tran
        for(int i =0; i<n; i++){
            for(int j =0l j <m; j++) cin>> a[i][j];
        }
        
    }

    return 0;
}