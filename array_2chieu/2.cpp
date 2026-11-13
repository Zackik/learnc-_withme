#include <bits/stdc++.h>
using namespace std;

int main(){
    // int n; cin>>n;
    // int a[n];
    // for(int &x : a) cin>> x;
    // int q; cin>> q;
    // while(q--){
    //     int l, r; cin>>l>>r;
    //     int sum =0;
    //     for(int i=l; i <= r; i++){
    //         sum += a[i];
    //     } 
    //     cout<< sum <<endl;
    // }
    // int n; cin>>n;
    // int a[n + 1];
    // for(int i=1 ; i< n; i++) cin>> a[i];
    // int prefix[n + 1] = {0};
    // for(int i = 1; i<=n; i++){
    //     prefix[i] = prefix[i -1] + a[i];
    // }
    // int q; cin >> q;
    // while(q--){
    //     int l, r; cin>> l>>r;
    //     cout<< prefix[r] - prefix[l -1] << endl;//O(1)
    // }
    /*
    doan code dang su prefix sum de tinh tong cac phan tu trong doan [l,r] voi do phuc tap O(1) cho moi truy van.
    tuy nhien, code hien tai co mot so can sua
    int n; cin>> n;
    int a[n+1];
    for(int i= 1; i<= n; i++){
    cin>> a[i];}
    int prefix[n+ 1] = {0};
    for(int i= 1; i<= n ; i++){
    prefix[i]= prefix[i-1] + a[i];}
    int q; cin>> q;
    while(q--){
    int l, r;
    cin>>l>>r;
    cout<< prefix[r] - prefix[l -1] <<endl;}
    giai thich prefix sum
    a = {0,2,4,1,5,3};
    ta co chi so bat dau tu 1
    cong thuc: prefix[i] = prefix[i-1] + a[i];
    | i | a[i] | prefix[i] |
|---|---:|---:|
| 0 | 0 | 0 |
| 1 | 2 | 2 |
| 2 | 4 | 6 |
| 3 | 1 | 7 |
| 4 | 5 | 12 |
| 5 | 3 | 15 |
y nghia: prefix[1] = 2: tong tu vi tri 1 den 1
prefix[2] = 6: tong tu 1 den 2
prefix[3] = 7: tong tu 1 den 3
prefix[5]= 15: tong tu vi tri 1 den 5
tai sao phai lay prefix[r] - prefix[l -1]
gia su can tinh tong doan [2,4]
Index:   1  2  3  4  5
a[i]:    2  4  1  5  3
ta can: a[2] + a[3] + a[4] = 4 + 1 + 5= 10
trong khi: prefix[4] = 2 + 4 + 1 + 5 = 12
prefix[1] = 2
lay: sum(2,4) = prefix[4] - prefix[1] = 12 - 2 = 10
ban chat: prefix[r] chua tong tu dau mang den r. ta tru phan khong thuoc doan prefix[l-1]
| Công việc | Độ phức tạp |
|---|---|
| Nhập mảng | O(n) |
| Xây dựng Prefix Sum | O(n) |
| Mỗi truy vấn | O(1) |
| q truy vấn | O(q) |
| Tổng thể | O(n + q) |
luu y loi trong code ban dau
for(int i = 1; i<= n; i++)
mot diem can nho khi hoc thuat toan:
prefix sum giup bai toan tinh toan doan tu viec duyet tung phan tu O(n) thanh phep tru hai gia tri O(1)
    */
    // int n,m; cin>>n>>m;
    // int a[n+1][m+1];
    // for(int i = 1; i<=n; i++){
    //     for(int j = 1; j <=m; j++) cin>> a[i][j];
    // }
    // int q; cin>>q;
    // while(q--){
    //     int h1, h2, c1,c2;
    //     cin>>h1>>h2>>c1>>c2;
    //     int sum =0;
    //     for(int i =h1; i <= h2; i++){
    //         for(int j = c1; j<= c2; j++){
    //             sum +=a[i][j];
    //         }
    //     }
    //     cout<<sum<<endl;
    // }
    int n, m; cin>>n>>m;
    int a[n+1][m+1];
    for(int i=1; i<=n; i++){
        for(int j = 1; j<= m; j++) cin>>a[i][j];
    }
    int pre[n+1][m+1];
    for(int i=1; i<=n; i++){
        for(int j =1; j<= m; j++){
            pre[i][j] = pre[i-1][j]+pre[i][j-1] - pre[i-1][j-1] + a[i][j]; 
        }
    }
    int q; cin>>q;
    while(q--){
        int h1, h2, c1, c2; cin>>h1>>h2>>c1>>c2;
        cout<< (pre[h2][c2] - pre[h1 - 1][c2] - pre[h2][c1 -1] + pre[h1- 1][c1-1])<<endl;
    }

    return 0;
}