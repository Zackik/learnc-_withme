/*
| Câu | Bài toán                                   | Ý tưởng                    | Time   |
| --- | ------------------------------------------ | -------------------------- | ------ |
| 1   | 3 phép đảo mảng                            | Left Rotation `K` lần      | `O(n)` |
| 2   | 500 số trong `[0,100]`, đếm tần suất `>50` | Frequency Array            | `O(n)` |
| 3   | Sorted array, tìm cặp có **hiệu** `S`      | Two pointers               | `O(n)` |
| 4   | Tìm phần tử không phải Min/Max             | Median của 3 phần tử       | `O(1)` |
| 5   | Tìm phần tử lớn thứ hai                    | Tìm Max rồi tìm Second Max | `O(n)` |

câu 1 Ba lần đảo mảng
1 2 3 4 5 6 7 8
k =4
Reverse(1..K)
Reverse(K+1..N)
Reverse(1..N)

Left Rotate K
1 2 3 4 | 5 6 7 8
5 6 7 8 1 2 3 4
Reverse(A[0..K-1])
Reverse(A[K..N-1])
Reverse(A[0..N-1])
Left Rotation by K
complexity mỗi lần reverse là O(n)
O(n) + O(n) + O(n)
= O(3n)
= O(n)

500 students
score ∈ [0,100]
51, 52, 53, ..., 100
int freq[50] = {0};
Score    Frequency

51       10
52       12
53       7
...
100      3
freq[score - 51]++;

câu 3: softed array + difference = s
Đây là chỗ transcript dễ gây nhầm
A = [2, 4, 8, 9, 13, 16, 19]
S = 10
A[j] - A[i] = 10
19 - 9 = 10
i = 0
j = 1
A[j] - A[i] < S

*/
void FindDifference(int A[], int n, int s){
    int i =0;
    int j = 1;
    while(j < n && i < n){
        int diff = A[j] - A[i];
        if(diff = s){
            printf("%d - %d = %d\n", A[j], A[i], s);
            return;
        }
        else if(diff < s){
            j++;
        }
        else{
            i++;
        }
    }
}
/*
while(i < j && j <n) để đảm bảo hai trỏ không trỏ cùng phần tử
complexity i và j chỉ di chuyển về phía trước không có lồng nhau
Time = O(n)
Space = O(1)

Sorted Array
      ↓
Two Pointers
      ↓
O(n)

Câu 4: Tìm phần tử không phải min và max
đây là câu rất hay A= [3,8,7,5,9,12,4]
min = 3
max = 12
không cần duyệt toàn bộ mảng, đây là insight quan trọng nhất 
A[0] = 3
A[1] = 8
A[2] = 7
Nhưng có một lưu ý, nếu duplicate [3, 3, 3, 8, 12]
thì việc chỉ lấy 3 phần tử đầu tiên không đảm bảo tìm được phần tử khác min/max. 
Cách tìm median của 3 số
ta có thể tìm số ở giữa
a = 3
b = 8
c = 7
*/
int middleOfThree(int a, int b, int c){
    if((a >= b && a <= c) || (a >= c && a <= b)){
        return a;
    }
    if((b >= a && b <= c) || (b >= c && b <= a)){
        return b;
    }
    return c;
}

/*
A = [5, 8, 2, 15, 9, 10]
15 largest
10 second largest

*/
void FindSecondLargest(int A[], int n){
    int max = A[0];
    int second = A[0];
    for(int i = 1; i < n; i++){
        if(A[i] > max){
            second = max;
            max = A[i];
        }
        else if(A[i] > second && A[i] != max){
            second = A[i];
        }
    }
    printf("Max = %d\n", max);
    printf("Second Max = %d\n", second);
}
/*
5 8 2 15 9 10
max = 5
second = 5

8:
max = 8
second = 5

2:
không đổi

15:
second = 8
max = 15

9:
second = 9

10:
second = 10
                    ARRAY
                      │
        ┌─────────────┼─────────────┐
        │             │             │
    Unsorted        Sorted       Limited Range
        │             │             │
        │             │             └── Frequency Array
        │             │
        │             ├── Two Pointer
        │             │
        │             └── Rotation
        │
        ├── Brute Force
        │      ↓
        │     O(n²)
        │
        └── Hashing
               ↓
              O(n)



Nested Loop        → thường O(n²)

Hash Table         → thường có thể giảm xuống O(n)

Sorted Array
+ Two Pointers     → thường O(n)

Single Scan        → thường O(n)
*/