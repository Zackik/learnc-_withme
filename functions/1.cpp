#include <iostream>
using namespace std;

// int sum_digit(long long n) {
//     int sum = 0;

//     for (; n > 0; n /= 10) {
//         sum += n % 10;
//     }

//     return sum;
// }
// int sum_digit(long long n){
//     int tong = 0;
//     while(n){
//         tong += n % 10;
//         n /= 10;
//     }
//     return tong;
// }
// int solve(int x, int y, int z){
//     cout<<"Thanh"<<endl;
//     cout<< 2*x << " "<< 3*y <<" "<< 4*z<<endl;
//     return x*y*z;
// }
bool check(long long n){
    int tong =1;
    while(n){
        tong += n % 10;
        n /= 10;
    }
    // if(tong % 10 == 8){
    //     return true;
    // }
    // return false;
    return tong % 10 ==8;
}
long long Giaithua(long long n){
    long long tong = 1;
    for(int i =1; i <=n; i++){
        tong *= i;
    }
    return tong;
}
bool chua6(int n){
    while(n){
        if(n % 10 ==6){
            return true;
        }
        n /= 10;
    }
    return false;
}
bool tongchan(int n){
    int tong =0;
    while(n){
        tong += n % 10;
        n /= 10;

    }
    return tong % 2 == 0;
}
bool chanle(int n){
    int le=0, chan=0;
    while(n){
        if(n % 2 ==0) ++chan;
        else ++le;
        n /= 10;
    }
    return le > chan;
    
}
int main() {
    // long long a;
    // cin >> a;

    // int kr = sum_digit(a);
    // cout << kr << endl;
    // int a, b, c;
    // cin >>a >>b >>c;
    // cout<< solve(a,b,c)<<endl;
    // long long x; cin >>x;
    // if(check(x)){
    //     cout<<"28\n";
    // }
    // else{
    //     cout<<"29\n";
    // }
    // long long n; cin>>n;
    // cout<< Giaithua(n) <<endl;
    int a,b;
    cin >>a >>b;
    for(int i =a; i <= b ; i++){
        if(chua6(i) && tongchan(i) && chanle(i)){
            cout<< i << " ";
        }
    }

    return 0;
}