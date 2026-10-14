#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long
// #define ll long long
// void xinchao(){
//     cout<<"Hoc lap trinh";
// }
// void printNumber(int n){
//     cout<< n << endl;
// }
// void display(ll x, ll y, ll z){
//     cout<< y<<x<<z<<endl;
//     cout<< x + y + z<<endl;
//     cout<<"KET THUC"<<endl;
// }

// int getNumber(){
//     return 100;
// }
int sum_digit(long long n) {
    int sum = 0;

    for (; n > 0; n /= 10) {
        sum += n % 10;
    }

    return sum;
}
int main(){
    
    // ll x; cin>>x;
    // ll y; cin >> y;
    // ll z; cin>>z;
    // display(x, y, z);
    // cou<< getNumber(23)<<endl;
    // int kq = getNumber(23);
    // cout<< kq <<endl;
    long long a; cin >> a;
    int kr = sum_digit(a);
    cout << kr << endl;

    return 0;


}