#include <iostream>

using namespace std;

//O(logn)
// bool nt(int n){
//     for(int i = 2; i<= sqrt(n); i++){
//         if(n % i ==0){
//             return false;
//         }
//     }
//     return n > 1; //vì sao n > 1? vì nếu n = 1 thì không phải là số nguyên tố
// }
//O(n)
// bool nt2(int n){
//     for(int i = 2; i<=n; i++){
//         if(n % i ==0){
//             return false;
//         }
//     }
//     return true;
// }

int main(){
    // int a = 10;//o(1)
    // int b = 20;//O(1)
    // for(int i =0; i<=n; i++){
    //     cout<< i<<endl;//O(n)
    // }
    //O(5*10)
    // int cnt =0;
    // for(int i =1; i<=5; i++){
    //     for(int j =1; j<=10; j++){
    //         cout<< "Hello!"<<endl;
    //         cnt++;
    //     }
    // }
    // cout<< cnt<<endl;
    //O(n)
    //Tim 2 so trong mang co tong lon nhat
    int n; 
    cin>>n;
    int a[n];
    int val = -1e9;
    for(int i =0; i<= n; i++){
        cin>>a[i];
    }
    for(int i=0; i<=n; i++){
        cout<<a[i] <<endl;
    }
    for(int i=0; i< n; i++){
        for(int j = i+1 ; j <n; j++){
            if(a[i] + a[j] > val){
                val = a[i] + a[j];
            }
        }
    }


}