//1
void test(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", i);
    }
}
/*
Big-O là gì?
=> Big-O là khi n tăng rất lớn, số lượng công việc tăng theo tốc độ nào.
|         n | `1` |       `n` |              `n²` | `log₂n` |
| --------: | --: | --------: | ----------------: | ------: |
|        10 |   1 |        10 |               100 |      ~3 |
|       100 |   1 |       100 |            10,000 |      ~7 |
|     1,000 |   1 |     1,000 |         1,000,000 |     ~10 |
| 1,000,000 |   1 | 1,000,000 | 1,000,000,000,000 |     ~20 |

Big-O bỏ qua hằng số và các thành phần nhỏ hơn.
10n      → O(n)
n + n    → O(n)
100n + 50 → O(n)
n² + n   → O(n²)

Bài 1
code: for (int i = 0; i < n; i++) {
    printf("%d", i);
}

i < n có nghĩa i =0 -> run
i = 1 -> run
...
i = n -> stop
có tổng cộng n lần. Do đó printf() = n
và complexity là O(n)
quy tắc for(i= 0; i <n; i ++) -> n lần -> O(n)

///////////////////////////
Bài 2: Hai vòng lặp lồng nhau
code for(int i = 0; i < n; i++){
        for(int j =0; j <n; j++){
            printf("%d %d", i, j);
        }
}
Lấy n =3 thì vòng ngoài i =0, i = 1, i=2 -> có 3 lần
mỗi lần i chạy tròng vòng chạy j =0, j = 1, j = 2 -> có 3 lần
do đó 3 * 3 = 9
nếu n : n * n = n^2
vậy printf() = n^2 và complexity O(n^2)
Đây là điều cực kỳ quan trọng trong hai vòng lồng nhau.

//////////////////////
Bài 3 Hai vòng tuần tự
for(int i = 0; i < n; i++){
    printf("%d", i);
}
for(int j =0; j < n; j++){
    printf("%d", j);
}
vòng 1 n 
vòng 2 n
tổng n + n = 2n, mà Big-O bỏ hằng số 2 còn lại O(n)
Phân biệt 
1             → O(1)

n             → O(n)

2n            → O(n)

n + n         → O(n)

n² + n        → O(n²)

///////////////////////////////////
Bài 4 n * 10
for(int i =0; i < n ; i++){
    for(int j = 0; j < 10; j++){
        printf("%d", i);
    }
}
vòng ngoài n lần
vòng trong 10 lần
tổng n * 10 = 10n
Big-O bỏ hằng số 10 còn O(n)
n = 10      → 100
n = 100     → 1,000
n = 1,000   → 10,000
n = 1,000,000 → 10,000,000
Nó vẫn tăng tuyến tính theo n

/////////////////////////////////
Bài 5 - Vòng lặp phụ thuộc i
for(int i =0; i < n ; i++){
    for(int j = 0; j < i; j++){
        printf("%d", j);
    }
}
n = 5
i =0
j < 0 -> 0 lần
////
 i = 1
 j = 0 -> 1 lần
 ////
 i = 2
 j = 0,1 -> 2 lần
 ///
 i =3 -> 3 lần
 i = 4 -> 4 lần

 tổng 0 + 1 + 2 + 3 + 4
 với n: 0 + 1 + 2 + 3 + .... + (n - 1)
 có công thức n(n - 1) /2
 khai triển (n^2 - n)/2 bỏ hằng số O(n^2)

 ////////////////

baì 6  i *= 2
for(int i = 0; i < n; i *= 2)
i = 0 sau i = 0 * 2 =0
cách sửa 
for(int i = 1; i < n ; i *= 2)
1
2
4
8
16
32
64
...
nếu n = 100 thì
1
2
4
8
16
32
64
khoảng 7 lần 
ta có 2^k ~ n
lấy log k ~ log2n
Do đó O(log n)
///////////
Bài 7 - hiểu log n thật sự
int i = 1;
while(i < n){
    printf("%d", i);
    i *=2;
}
i = 2^k , 2^k >= n
=> k ~ log2n
-> O(log n).
/////////////////////
Bài 8 i/=2
int i =n;
while(i > 1){
    printf("%d", i);
    i /=2;
}
Đây là ngược lại của bài 7
n = 32
32
 ↓ /2
16
 ↓ /2
8
 ↓ /2
4
 ↓ /2
2
 ↓ /2
1
có 5 lần
vì 
n
n/2
n/4
n/8
...
1
sau k lần n / 2^k = 1
=> n = 2^k
k = log2n -> O(log n)
i *= 2 -> O(log n)
i /= 2 -> o(log n)
//////////////
Bài 9
While(l <= h){
    mid = (l + h)/2;
    if(key == A[mid]){
        return mid;
    }
    else if(key < A[mid]){
        h = mid - 1;
    }
    else{
        l = mid + 1;
    }
}

N
↓
N/2
↓
N/4
↓
N/8
↓
...
1
Đây là O(log n)
n = 16
16 -> 8 -> 4 -> 2 -> 1
~log2^16 = 4

Best case
key ngay mid: 1 comparison -> O(1)

worst case
đi xuống đến cuối: O(log n)

Average Case : O(log n)

/////////////
Bài 10 n * log n
for(int i = 0; i < n; i++){
    int j = 1;
    while(j < n){
        printf("%d", j);
        j *= 2;
    }
}
phân tích từ trong ra ngoài
vòng ngoài: n
vòng trong log n
vì vòng trong nằm trong vòng ngoài: n * log n
=> O(n log n)
Đây là pattern cực kỳ quan trọng:
for n times
    something O(log n)

-> O(n log n)

//////////////
Bài 11 n^2 log n
for(int i = 0; i <n; i++){
    for(int j =0; j < n; j++){
        int k = 1;
        while(k < n){
            k *= 2;
        }
    }
}
có 3 tầng 
tầng 1: n
tầng 2: n
tằng 3 : log n
nhân: n * n * log n
O(n^2 log n)

/////////
Bài 12 Find Max
int findMax(int A[], int n){
    int max = A[0];
    for(int i = 1; i < n; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}
vòng lặp luôn:
i = 1
2
3
...
n-1
có n -1 lần
nhưng n - 1 vẫn là O(n)

Best case: Dù A[0] đã là max vẫn phải kiểm tra toàn bộ -> O(n)
Average  Case: Vẫn duyệt toàn bộ: O(n)
Worst Case: Vẫn duyệt toàn bộ O(n)
do đó:
Best    = O(n)
Average = O(n)
Worst   = O(n)
 Đây là ví dụ phổ biến để hiểu best case không nhất thiết phải là O(1).

//////////////////////////////////
Bài 13 Linear Search
for(int i =0; i <n; i++){
    if(A[i] == key){
        return i;
    }
}
Best case: Key nằm ngay A[0] chỉ lần 1 lần -> O(1)
Worst case: Key nằm A[n-1] hoặc không tồn tại n -> O(n)
Average: Nếu giả sử key có xác suất nằm đều ở mọi vị trí:
1 + 2 + 3 + 4 + 5 + .. + n
trung bình (1 + n)/2 ~ n/2 bỏ hằng số O(n)
Do đó:
Best    = O(1)
Average = O(n)
Worst   = O(n)

//////////////////////
Bài 14 Binary Search Bằng tay
Mảng [10, 15, 20, 25, 30, 35, 40, 45, 50]
find key = 45
có 9 phần tử
l =0
h = 8
tính mid = (0 + 8)/ 2 =4
A[4] = 30
45 > 30
tìm bên phải
l = 5
h = 8
mid = (5 + 8)/2 =6
A[6] = 40
45 > 40
l = 7
l = 8
mid = (7 + 8)/2 = 7
A[7] = 45
tổng cộng 3 comparisons đây là trực quan của O(log n)

///////////////////
Bài 15 n log n
for(int i = 1; i < n; i *= 2){
        for(int j = 0; j < n; j ++){
            printf("%d", i);
        }
}
outer: i = 1, 2, 4, 8,..
-> logn 
Inner: j = 0,1,2,..., n-1
-> n
hai vòng lồng log n * n
-> O(n log n)
/////////////

Bài 16 không phải cứ hai for là n^2
for(int i =0; i <n; i++){
    for(int j = i; j < n; j++){
        printf("%d %d", i ,j);
    }
}
n = 5
i =0
j = 0 1 2 3 4 
5 lần 
/////
i = 1
j = 1 2 3 4 
4 lần
////
i =2
j = 2 3 4
3 lần
////
i = 3
j = 3 4
2 lần
//
i = 4
j = 4
1 lần
///
Tổng: 5 + 4 + 3 + 2 + 1
với n: n + (n - 1) + (n - 2) + .. + 1
công thức: n(n + 1) /2
khai triển: (n^2 - n)/2
bỏ hằng số O(n^2)
Nhưng hãy nhìn kỹ nó vẫn O(n^2)  nhưng không phải n * n chính xác.
Dây là sự khác biệt giữa Exact number of operations và Asymptotic complexity
/////////////
Bài 17 Recursion
void fun(int n){
    if(n <= 1){
        return;
    }
    fun(n/2);
} 
Đây là cách rất quan trọng để học complexity của đệ quy.
Giả sử n = 16
fun(16)
fun(8)
fun(4)
fun(2)
fun(1)
chuỗi
16
 ↓
8
 ↓
4
 ↓
2
 ↓
1

có log2n
T(n) = T(n/2) + O(1)
Đây là recurrence kinh điển
kết quả:
T(n) = O(log n)

                  CODE
                    │
                    ↓
          Có vòng lặp không?
             /             \
           Không            Có
            ↓               ↓
          O(1)       Có bao nhiêu tầng?
                         │
               ┌─────────┼─────────┐
               ↓         ↓         ↓
              1         2+       recursion
               │         │          │
              O(n)     Nhân       phân tích
                        số vòng    recurrence


*/