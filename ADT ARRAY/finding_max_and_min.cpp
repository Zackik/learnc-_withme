/*
Đây là một bài quan trọng để phân tích toán số phép so sánh và best/worst case
ý tưởng chính
A = [5, 8, 2, 9, 6, 10, 7, -1, 4]

Min = -1
Max = 10

min = A[0];
max = A[0];
A[0] = 5

min = 5
max = 5

logic quan trọng nhất
Với mỗi A[i]

step1: kiểm tra min
if(A[i] < min) min = A[i];
nếu đúng -> cập nhật min

step 2: Nếu không nhỏ hơn min thì mới kiểm tra max
else ìf(A[i] > max) max = A[i]; Đây là quan trọng của bài

không dùng:
if (A[i] < min)
    min = A[i];

if (A[i] > max)
    max = A[i];

mà dùng:
if (A[i] < min)
    min = A[i];
else if (A[i] > max)
    max = A[i];

ví dụ chạy từng bước
array: [5, 8, 2, 9, 6, 10, 7, -1, 4]
min = 5
max = 5

8 < 5 → false
8 > 5 → true

min = 5
max = 8

2 < 5 → true

min = 2
max = 8


9 < 2 → false
9 > 8 → true

min = 2
max = 9

6 < 2 → false
6 > 9 → false
10 < 2 → false
10 > 9 → true
*/
#include <stdio.h>

void FindMinMax(int A[], int n, int *min, int *max)
{
    *min = A[0];
    *max = A[0];

    for (int i = 1; i < n; i++)
    {
        if (A[i] < *min)
        {
            *min = A[i];
        }
        else if (A[i] > *max)
        {
            *max = A[i];
        }
    }
}

int main()
{
    int A[] = {5, 8, 2, 9, 6, 10, 7, -1, 4};

    int n = sizeof(A) / sizeof(A[0]);

    int min, max;

    FindMinMax(A, n, &min, &max);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    return 0;
}
/*
i =1
min = A[0];
max = A[0];
for (int i = 1; i < n; i++)
              A[i]
                │
                ▼
        A[i] < min ?
          /          \
        YES           NO
         │             │
         ▼             ▼
    min = A[i]    A[i] > max ?
                       /     \
                     YES      NO
                      │        │
                      ▼        ▼
                 max = A[i]  Không đổi

*/