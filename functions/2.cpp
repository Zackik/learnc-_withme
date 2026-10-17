#include <iostream>
#include <math.h>
using namespace std;


void xinchao(){
    cout<<"Xin chao"<<endl;
}

int tong(int a){
    return a * (a + 1) / 2;
}
//s = 1/1 + 1/2 + 1/3 + .. + 1/n
float tong2(int n){
    float res = 0;
    for(int i =1 ; i <= n; i++){
        res+= 1.0 /i;
    }
    return res;

}
//xay dung ham kiem tra so nguyen to, tham so int
//true false
bool nt(int n){
    for(int i = 2; i<= sqrt(n); i++){
        if(n % i ==0){
            return false;
        }
    }
    return n > 1;
}
//kiem tra xem tong chu so cua 1 so co phai so nguyen to hay khong
int tong3(int n){
    int sum = 0;
    while(n){
        sum += n %10;
        n /= 10;
    }
    return sum;
}
int main(){
    int n = 124;
    int sum = tong3(n);
    if(nt(sum)){
        cout<< "1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
    return 0;
}