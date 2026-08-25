/*
Bài toán 
A = {3, 7, 4, 9, 12, 6 , 1 ,11 ,2, 10}
các số cần có là 1 -> 12
nhưng đang thiếu 5, 8

PHương pháp hash table 
Index:  0 1 2 3 4 5 6 7 8 9 10 11 12
H:      0 0 0 0 0 0 0 0 0 0  0  0  0

Ví dụ A[i] = 3 H[3] = 1
A[i] = 7 -> H[7] = 1
A[i] = 4 -> H[4] = 1
A[i] = 9 -> H[9] = 1
...

Index:  0 1 2 3 4 5 6 7 8 9 10 11 12
H:      0 1 1 1 1 0 1 1 0 1  1  1  1

Nhìn vào 5 và 8 là các phần tử bị thiếu
*/
//c
#include <stdio.h>
#include <stdlib.h>
int main(){
    int A[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};
    int n = sizeof(A) / sizeof(A[0]);

    int low = 1;
    int high = 12;
    //Hash table
    int *H = (int *)calloc(high + 1, sizeof(int));
    if(H== NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    //Mark existing elements
    for(int i =0; i<n; i++){
        H[A[i]]++;

    }
    //Find missing elements
    for(int i  = low; i<= high; i++){
        if(H[i] ==0){
            printf("Missing element: %d\n", i);
        }
    }
    free(H);
    return 0;
}
/*
Missing element: 5
Missing element: 8

*/

//c++
#include <iostream>
using namespace std;
int main(){
    int A[] = {3,7,4,9,12,6,1,11,2,10};
    int n = sizeof(A) / sizeof(A[0]);
    int low = 1;
    int high = 12;

    //Hash table
    int H[13] = {0};
    //Danh dau cac phan tu da xuat hien
    for(int i =0; i <n; i++){
        H[A[i]]++;
    }

    //Tim phan tu bij thieu
    for(int i = low; i <= high; i++){
        if(H[i] == 0){
            cout<<"Missing element: "<<i<<endl;
        }
    }
    return 0;
}
/*
H[A[i]]++;
A[i] = 3 == H[3]++;
H[3] = 0 => H[3] = 1
H[3] = 2 if 2 time

if(H[i] ==0) find missing elements

*/
/*
c++ - model

*/
#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    int A[] = {3,7,4,9,12,6,1,11,2,10};
    int n = sizeof(A) / sizeof(A[0]);

    int low = 1;
    int high = 12;
    unordered_set<int> H;
    //Insert elements
    for(int i = 0;i< n; i++){
        H.insert(A[i]);
    }
    //find missing elements
    for(int i = low; i<= high; i++){
        if(H.find(i) == H.end()){
            cout<<"Missing element: "<< i<< endl;
        }
    }
    return 0;
}
/*
| Cách            | Ý nghĩa            | Average Time |
| --------------- | ------------------ | -----------: |
| `int H[13]`     | Direct addressing  |         O(n) |
| `unordered_set` | Hash Table thực tế |         O(n) |
| Nested loop     | Brute force        |        O(n²) |

int n = sizeof(A) / sizeof(A[0]);

sizeof(A[0]) 4 byte
sizeof(A) / sizeof(A[0]) 40 / 4 = 10
int n = 10
 why

int n = 10; nếu sau thay đổi mảng sẽ sai

*/
/*
Array
  ↓
Direct Address Table
  ↓
Hashing
  ↓
Hash Table
  ↓
unordered_set / unordered_map

int H[13] = {0};
Index:  0 1 2 3 4 5 6 7 8 9 10 11 12
        --------------------------------
H:      0 0 0 0 0 0 0 0 0 0  0  0  0
khi A[i] = 7;
H[A[i]]++;
H[7]++;
Index:  0 1 2 3 4 5 6 7 8 9 10 11 12
        --------------------------------
H:      0 0 0 0 0 0 0 1 0 0  0  0  0

Đay là tư duy "truy cập trực tiếp"
thông thường nếu muốn tìm 7 trong
int A[] = {3, 7, 4, 9, 12};
phải duyệt 3->7

H[5] ==0
for(int i =0; i < n; i++){
H[A[i]]++;
}
Index:  0 1 2 3 4 5 6 7 8 9 10 11 12
H:      0 1 1 1 1 0 1 1 0 1  1  1  1

H[1] = 1  → có 1
H[2] = 1  → có 2
H[3] = 1  → có 3
H[4] = 1  → có 4
H[5] = 0  → thiếu 5
H[6] = 1  → có 6
H[7] = 1  → có 7
H[8] = 0  → thiếu 8

if(H[i] == 0) cout<<i;

*/

/*
A = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10}
for(int x = 1; x<= 12; x++){
bool found = false;
for(int i =0; i<n; i++){
if(A[i] == x){
found = true;
break;
}
}
if(!found) cout<<x<<endl;
}

       n
       ↓
for x ─────────────────┐
                       │
                       ↓
                 for i → n
n × n = n²

int H[13] = {0};
for(int i = 0; i<n; i++){
    H[A[i]]++;

}
A[i] = 7
   ↓
H[7] = 1

for (int i = 1; i <= 12; i++)
{
    if (H[i] == 0)
        cout << i << endl;
}

Duyệt A → O(n)
Duyệt H → O(n)


O(n) + O(n)
= O(2n)
= O(n)

             Bài toán
                │
       ┌────────┴────────┐
       ↓                 ↓
   Không thêm RAM      Thêm RAM
       │                 │
       ↓                 ↓
   O(n²) time          O(n) time
                         │
                         ↓
                    Hash Table
*/