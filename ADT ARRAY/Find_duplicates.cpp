/*
int A[] = {3,6,8,8,10,12,15,15,20};

3
6
8  ← duplicate
8  ← duplicate

10
12

15 ← duplicate
15 ← duplicate
15 ← duplicate

20

8  → xuất hiện 2 lần
15 → xuất hiện 3 lần

Tại sao mảng đã sắp xếp lại quan trọng ?
3 6 8 8 10 12 15 15 15 20
các phần tử liền kề nhau

A[i] == A[i + 1]
A[2] = 8
A[3] = 8

8 == 8

*/

#include <iostream>
using namespace std;

int main(){
    int A[] = {3,6,8,8,10,12,15,15,20};

    int n = sizeof(A) / sizeof(A[0]);
    for(int i = 0; i< n; i++){
        if(A[i] == A[i + 1]){
            cout<<"Duplicates: "<< A[i] << endl;
        }
    }
    return 0;
}
/*
dùng lastDuplicate
int lastDuplicate = 0;
if(A[i] == A[i + 1] && A[i] != lastDuplicate)

*/
#include <iostream>
using namespace std;

int main(){
    int A[] = [3,6,8,8,10,12,15,15,20];
    int n = sizeof(A) / sizeof(A[0]);

    int lastDuplicate = 0;
    for(int i = 0; i < n -1; i++){
        if(A[i] == A[i + 1] && A[i] != lastDuplicate){
            cout<<"Duplicate: "<< A[i] << endl;
            lastDuplicate = A[i];
        }
    }
    return 0;
}
/*
3 6 8 8 10 12 15 15 15 20
    ↑ ↑

A[i] == A[i + 1]

8 != lastDuplicate
cout << 8;
lastDuplicate = 8;


15 15 15

15 != 8

lastDuplicate = 15;
15 == lastDuplicate

lastDuplicate
      ↓
lưu duplicate cuối cùng
      ↓
duplicate tiếp theo giống nó?
      ↓
     Có
      ↓
Không in

8  → 2 lần
15 → 3 lần
3 6 8 8 10 12 15 15 15 20
    ↑    ↑
    i    j

A[i] == A[j]

3 6 8 8 10 12 15 15 15 20
    ↑ ↑
    i j

3 6 8 8 10 12 15 15 15 20
    ↑   ↑
    i   j
3 6 8 8 10 12 15 15 15 20
    ↑       ↑
    i       j


j - i
*/

//count duplicate
int main(){
    int A[] = {3,6,8,8,10,12,15,15,20};

    int n = sizeof(A) / sizeof(A[0]);

    for(int i =0; i < n -1; i++){
        if(A[i] == A[i + 1]){
            int j = i+1;

            while(j < n && A[j] == A[i]){
                j++;
            }
            cout<< A[i] << " appears " << j - i << " times " << endl;
            i = j - 1;
        }
    }
    return 0;
}
/*
8 appears 2 times
15 appears 3 times


for (...)
{
    while (...)
    {
        j++;
    }
}
    O(n²)

                    Duplicate
                       │
             ┌─────────┴─────────┐
             ↓                   ↓
       Array sorted        Array unsorted
             │                   │
             ↓                   ↓
       Two pointers        Hash Table
             │                   │
             ↓                   ↓
          O(n) time            O(n) avg
          O(1) space           O(n) space

*/

/*
int A[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};

int H[21] = {0};
0 → 1 → 2 → ... → 19 → 20
*/
int main(){
    int A[] = {3,6,8,8,10,12,15,15,15,20};
    int n = sizeof(A) / sizeof(A[0]);

    int maxValue = 20;

    //Hash table
    int H[21] = {0};

    //count occurrences
    for(int i = 0; i < n; i++){
        H[A[i]]++;
    }
    //Find dupliactes
    for(int i = 0; i <= maxValue; i++){
        if(H[i] > 1){
            cout<< i << " appears " << H[i] << " times"<< endl;
        }
    }
    return 0;
}

//unordered_map
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int A[] = {15,3,8,20,15,6,10,8,15,12};
    int n = sizeof(A) / sizeof(A[0]);
    unordered_map<int, int> freq;
    for(int i =0; i < n; i++){
        freq[A[i]]++;
    }
    for(auto  x : freq){
        if(x.second > 1){
            cout<< x.first << " appears "<< x.second << " times" << endl;
        }
    }
    return 0;
}
/*
H[A[i]]++

     ↓

Direct Address Table

     ↓

Hashing concept

     ↓

unordered_map

     ↓

Frequency counting pattern
*/