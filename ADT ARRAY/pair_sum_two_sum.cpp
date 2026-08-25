/*
int A[] = {6,3,8,10,16,7,5,2,9,14};
int k = 10;

3 + 7 = 10
8 + 2 = 10
Brute Force O(n²)
        ↓
Hashing O(n)
        ↓
Nếu array sorted → Two Pointer O(n)

*/

/*brute force
A[i] + A[j] = k ?
6  3  8  10  16  7  5  2  9  14
↑

6 + 3  = 9
6 + 8  = 14
6 + 10 = 16
...
6  3  8  10  16  7  5  2  9  14
   ↑

3 + 8
3 + 10
3 + 16
3 + 7  ← 10
*/
#include <iostream>
using namespace std;

int main(){
    int A[] = {6,3,8,10,16,7,5,2,9,14};
    int n = sizeof(A) / sizeof(A[0]);

    int k = 10;
    for(int i =0; i< n - 1; i++){
        for(int j = i + 1; j < n; j ++){
            if(A[i] + A[j] == k)
            {
                cout<< A[i] << " + " << A[j] << " = "<< k<< endl;
            }
        }
    }
    return 0;
}
/*
Tại sao j = i+ 1, đay la một điểm rất quan trọng
for(int j = 0; j < n; j ++)
mà
for(int j = i + 1; j < n; j++)
i = 1 → A[i] = 3

j = 2 → 3 + 8
j = 3 → 3 + 10
j = 4 → 3 + 16
j = 5 → 3 + 7

complexity
for(int i =0; i < n - 1; i++) -> O(n)
for(int j = i + 1; j < n; j ++) -> O(n)
Time Complexity = O(n²)
Space Complexity = O(1)

*/

/*
Hash table
3 → tìm 7
8 → tìm 2
10 → tìm 0
16 → tìm -6
...
ta sử dụng hash table để kiểm tra phần tử cần tìm trong O(1) trung bình
needed = K - A[i]

K = 10

A[i] = 6

needed = 10 - 6
       = 4
H[4]
6  3  8  10  16  7  5  2  9  14
A[i] = 6

needed = 10 - 6
       = 4
H[4]
H[6] = 1

A[i] = 3

needed = 10 - 3
       = 7
H[7]
H[3] = 1
A[i] = 8

needed = 10 - 8
       = 2
H[2]
H[8] = 1

A[i] = 7

needed = 10 - 7
       = 3
H[3]

*/
int main(){
    int A[] = {6,3,8,10,16,7,5,2,9,14};
    int n = sizeof(A) / sizeof(A[0]);

    int k = 10;

    int H[17] = {0};

    for(int i =0; i < n; i++){
        int needed = k - A[i];
        //kiem tra needed da xuat hien chua
        if(needed >= 0 && H[needed] != 0){
            cout<< needed << " + " << A[i] << " = " << k<< endl;
        }
        //danh dau A[i] da xuat hien
        H[A[i]]++;
    }
    return 0;
}
/*
H[A[i]]++
Đây là cực kỳ quan trọng
int needed = k - A[i];
if(H[needed] != 0){
}
H[A[i]]++;


không nên dảo thành
H[A[i]]++;

if (H[needed] != 0)
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    int A[] = {6,3,8,10,16,7,5,2,9,14};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 10;
    unordered_set<int> H;
    for(int i =0; i < n; i++){
        int needed = k - A[i];
        if(HH.find(needed) != H.end()){
            cout<< needed << " + " << A[i] << " = "<< k<< endl;
        }
        H.insert(A[i]);
    }
    return 0;
}

/*
DSA rất quan trọng two pointer trên mảng đã sắp xếp. Nó là hước nâng cấp rõ ràng  từ cách O(n^2) sang O(n).
int A[] = {1, 3, 4, 6, 8, 9, 12, 14};
K = 10;
ý tưởng
i =0;
j = n - 1;
i →                         ← j
1   3   4   6   8   9   12   14
sum = A[i] + A[j];

trường hợp 1: sum == k
A[i] + A[j] == k
i++
j++
vì cả hai phần tử đã được sử dụng

trường hợp 2: sum < k
1 + 8 =9
tần tăng tổng i ++
không tăng j, vì giảm j sẽ làm tổng nhỏ hơn nữa
trường hợp 3
1 + 14 = 15
càn giảm tổng
vì mảng đã sắp xếp, giảm j: j--;

*/
void findPair(int A[], int n, int k){
    int i =0;
    int j = n -1;
    while(i < j){
        int sum = A[i] = A[j];
        if(sum == k){
            cout<< A[i] << " + " << A[j] << " = " << k<< endl;
            i++;
            j--;
        }
        else if(sum < k){
            i++;
        }
        else{
            j--;
        }
    }
}
int main(){
    int A[] = {1,3,4,6,8,9,12,14};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 10;
    findPair(A,n,k);
    return 0;

}
/*
          START
            |
            v
       i = 0, j = n-1
            |
            v
         i < j ?
        /       \
      NO         YES
      |            |
     END           v
              sum=A[i]+A[j]
                    |
          +---------+---------+
          |         |         |
       sum == K   sum < K   sum > K
          |         |         |
          v         v         v
       output     i++       j--
          |         |         |
          v         v         v
        i++,j-- ----+---------+
                    |
                    v
                 i < j
*/
