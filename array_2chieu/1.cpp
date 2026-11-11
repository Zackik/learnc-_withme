#include <bits/stdc++.h>
using namespace std;

//mang 2 chieu
void nhap(int a[][100], int n, int m){
    for(int i =0; i< n; i++){
        for(int j =0; j <m; j++) cin>> a[i][j];
    }
}



int main(){
    // int a[5][10] = {{1,2,4}, {3,4,5}}; //50 ptu
    // int n , m; cin>>n>>m;
    // int a[100][100];
    // nhap(a,m,n);
    // for(int i=0; i <n; i++){
    //     for(int j =0; j < m; j++){
    //         cin>> a[i][j];
    //     }
    // }
    //duyet theo hang
    // for(int i =0; i< n; i++){
    //     for( int j =0; j < m; j++){
    //         cout<< a[i][j];
    //     }
    //     cout<< endl;
    // }
    // char c[100][100];
    // for(int i =0; i< n; i++){
    //     for(int j =0; j <m; j++){
    //         cin>>c[i][j];
    //     }
    // }
    // for(int i =0; i< n; i++){
    //     for(int j =0; j < m; j++){
    //         cout<<c[i][j];
    //     }
    //     cout<<endl;
    // }
    // int n; cin>>n;
    // vector<int> a[n];
    // for(int i =0; i< n; i++){
    //     int m; cin>>m;
    //     for(int j =0; j < m; j++){
    //         int x; cin>> x;
    //         a[i].push_back(x);
    //     }
    // }
    // for(int i=0; i< n; i++){
    //     for(int j =0; j < a[i].size(); j++){
    //         cout<< a[i][j]<< ' ';
    //     }
    //     cout<<endl;
    // }

    // int n, m; cin>>n;
    // string a[n];
    // cin.ignore();
    // for(int i =0; i< n; i++){
    //     getline(cin, a[i]);
    // }
    // for(int i=0; i< n; i++){
    //     cout<< a[i]<<endl;
    // }

    int n,m,k;
    cin>>n>>m>>k;
    int a[n][m][k];
    for(int i =0; i<n; i++){
        for(int j =0; j<m; j++) cin>>a[i][j];
    }
    for(int i=0; i<m; i++){
        for(int j =0; j <n; j++){
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}