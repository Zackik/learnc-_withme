#include <stdio.h>
#include <stdlib.h>
// Day 1: Array Implementation
//Day 2: Insertion in Array
struct Array {
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("Elements are: ");
    for(i =0; i< arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Append(struct Array *arr, int x){
    if(arr->length < arr->size){
        arr->A[arr->length++] = x;
    }
}
void Insert(struct Array *arr, int index, int x){
    if(index >= 0 && index <= arr->length){
        // A[10] = 10, A[9] = 9, A[8] = 8, A[7] = 7, A[6] = 6, A[5] = 5, A[4] = 4, A[3] = 3, A[2] = 2, A[1] = 1, A[0] = 0
        // i = 10; i > 5; i-- A[10] = A[9]; A[9] = A[8]; A[8] = A[7]; A[7] = A[6]; A[6] = A[5];

        for(int i = arr->length ; i > index; i--){
            // A[6] = A[5]; A[6] = 5; A[5] = 4; A[4] = 3; A[3] = 2; A[2] = 1; A[1] = 0; 
            // A[5] = A[4]; A[4] = A[3]; A[3] = A[2]; A[2] = A[1]; A[1] = A[0];
            // A[4] = A[3]; A[3] = A[2]; A[2] = A[1]; A[1] = A[0];
            arr->A[i] = arr->A[i-1];
        }
        //A[5] = 5; 
        arr->A[index] = x;
        // A[5] = 5; A[4] = 4; A[3] = 3; A[2] = 2; A[1] = 1; A[0] = 0;
        //index = 12, A[5] = 12; A[4] = 4; A[3] = 3; A[2] = 2; A[1] = 1; A[0] = 0;
        // A[6] = 5; A[5] = 12; A[4] = 4; A[3] = 3; A[2] = 2; A[1] = 1; A[0] = 0;
        arr->length++;
    }
}
//Mở sẻ ra là size 4 , length 3 
//i = arr->length= 4, A[4] = A[3]; A[3] = A[2]; A[2] = A[1]; A[1] = A[0];
//Việc này là kéo mảng từ phải sang trái để chừa ra một vị trí trống cho phần tử mới được chèn vào.
//length ++ để tăng độ dài của mảng sau khi chèn phần tử mới vào.
/*  
void Insert(struct Array *arr, int index, int x){
if(index >= 0 && index <= arr->length){
for(int i = arr->length ; i > index; i--)
    A[i] = A[i-1];
arr->A[index] = x;
arr->length++;


             Insert
                │
                ▼
       index hợp lệ?
          /          \
        Không         Có
         │             │
       Stop            ▼
                  length == size?
                    /       \
                  Có        Không
                  │            │
               realloc         │
                  │            │
                  └─────┬──────┘
                        ▼
                 Dịch phải → trái
                        │
                        ▼
                  A[index] = x
                        │
                        ▼
                    length++


*/

int Delete(struct Array *arr, int index){
    int x =0;
    int i;
    
    if(index >= 0 && index < arr->length){
        x = arr->A[index];
        for(i = index; i < arr->length -1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        printf("Deleted element is: %d\n", x);
        return x;
    }
    return 0;
}


/*
int Delete(struct Array *arr, int index){
    int x =0;
    if(index >= 0 && index < arr->length){
        int x = arr->A[index];
        for(int i = index; i < arr->length -1; i++){
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}




                  ┌──────────────┐
                  │    START     │
                  └──────┬───────┘
                         │
                         ▼
              ┌──────────────────────┐
              │  index >= 0 AND      │
              │  index < arr->length?│
              └──────────┬───────────┘
                    NO ↙       ↘ YES
                      │          │
                      ▼          ▼
               ┌──────────┐   ┌────────────────┐
               │ return 0 │   │ x = arr->A[index]│
               └──────────┘   └───────┬────────┘
                                      │
                                      ▼
                             ┌────────────────┐
                             │    i = index   │
                             └───────┬────────┘
                                     │
                                     ▼
                          ┌─────────────────────┐
                          │ i < arr->length - 1?│
                          └──────────┬──────────┘
                                NO ↙       ↘ YES
                                  │          │
                                  │          ▼
                                  │   ┌─────────────────┐
                                  │   │ arr->A[i] =     │
                                  │   │ arr->A[i + 1]   │
                                  │   └────────┬────────┘
                                  │            │
                                  │            ▼
                                  │   ┌────────────────┐
                                  │   │     i++        │
                                  │   └───────┬────────┘
                                  │           │
                                  │           └──────┐
                                  │                  │
                                  │                  ▼
                                  │        ┌─────────────────────┐
                                  │        │ i < length - 1 ?    │
                                  │        └─────────────────────┘
                                  │
                                  ▼
                         ┌─────────────────┐
                         │ arr->length--  │
                         └────────┬────────┘
                                  │
                                  ▼
                             ┌──────────┐
                             │ return x │
                             └────┬─────┘
                                  │
                                  ▼
                             ┌──────────┐
                             │   END    │
                             └──────────┘
*/

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/*
flowchart TD
    A([Start]) --> B[Declare int temp]
    B --> C[temp = *x]
    C --> D[*x = *y]
    D --> E[*y = temp]
    E --> F([End])
*/
int LinearSearch(struct Array *arr, int key){
    int i;
    for(i =0; i < arr->length; i++){
        if(key == arr->A[i]){
            swap(&arr->A[i], &arr->A[0]);
            //swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}
/*
              ┌─────────┐
              │  Start  │
              └────┬────┘
                   ↓
               i = 0
                   ↓
          ┌─────────────────┐
          │ i < arr->length?│
          └───────┬─────────┘
             No   │   Yes
             ↓    │    ↓
        return -1 │  key == A[i]?
             ↓    │    │
            End   │    ├── No → i++ ──┐
                  │    │              │
                  │    └── Yes        │
                  │         ↓         │
                  │      swap()       │
                  │         ↓         │
                  │      return i     │
                  │         ↓         │
                  └──────── End ←─────┘
*/

int BinarySearch(struct Array arr, int key){
    int l,mid,h;
    l=0;
    h=arr.length - 1;
    
    while(l <= h){
        mid = (l + h)/2;
        if(key == arr.A[mid]){
            return mid;
        }
        else if(key < arr.A[mid]){
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return -1;
}
// l =0 , h = arr.length-1=> 15(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14)
//mid = (l + h)/ 2 => mid == key return mid 
// key < mid => h = mid - 1 (key =15(arr.A[4]), mid = 18(arr.A[5])) h = mid - 1= 5 -1 = 4(arr.A[4])
// key > mid => l = mid + 1 ( key = 16 mid 13) l = mid + 1 
/*              Start
                ↓
             l = 0
                ↓
        h = length - 1
                ↓
            l <= h ?
           /       \
         No         Yes
         ↓           ↓
      return -1   mid=(l+h)/2
         ↓           ↓
        End       key == A[mid]?
                  /          \
                Yes           No
                 ↓             ↓
             return mid    key < A[mid]?
                 ↓          /        \
                End       Yes         No
                           ↓           ↓
                       h=mid-1      l=mid+1
                           \           /
                            ↖─────────↙
*/

int RBinSearch(int a[], int l, int h, int key){
    int mid;
    if(l <= h){
        mid = (l + h)/2;
        if(key == a[mid]){
            return mid;
        }
        else if(key < a[mid]){
            return RBinSearch(a, l, mid -1, key);
        }
        else{
            return RBinSearch(a, mid + 1, h, key);
        }
    }
    return -1;

}
/*
flowchart TD
    A([Start]) --> B{l <= h?}

    B -- No --> C[return -1]
    C --> Z([End])

    B -- Yes --> D[mid = (l + h) / 2]
    D --> E{key == a[mid]?}

    E -- Yes --> F[return mid]
    F --> Z

    E -- No --> G{key < a[mid]?}

    G -- Yes --> H[Recursive Call: RBinSearch a, l, mid-1, key]
    H --> Z

    G -- No --> I[Recursive Call: RBinSearch a, mid+1, h, key]
    I --> Z
*/

int get(struct Array arr, int index){
        if(index >= 0 && index < arr.length){
            return arr.A[index];
        }
    return -1;
}

int set(struct Array *arr,int index ,int x){
    if(index >= 0 && index < arr->length){
        arr->A[index] = x;
    }
    return -1;
}

int max(struct Array arr){
    int max = arr.A[0];
    for(int i =0; i < arr.length; i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
}

int min(struct Array arr){
    int min = arr.A[0];
    for(int i =0; i < arr.length; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;
}

int sum(struct Array arr){
    int s =0;
    for(int i =0; i< arr.length; i++){
        s += arr.A[i];
    }
    return s;
}

float avg(struct Array arr){
    return (float)sum(arr)/ arr.length;
}

// void reverse(struct Array *arr){
//     int *B;
//     int i,j;
//     B = (int *)malloc(arr->length * sizeof(int));
//     for(i = arr->length-1, j =0; i >=0; i--, j++){
//         B[i] = arr->A[i];
//     }
//     for(i =0; i< arr->length; i++){
//         arr->A[i] = B[i];
//     }
// }

void reverse(struct Array *arr) {

    int *B;
    int i, j;

    B = (int *)malloc(arr->length * sizeof(int));

    for (i = arr->length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = arr->A[i];
    }

    for (i = 0; i < arr->length; i++) {
        arr->A[i] = B[i];
    }

    free(B);
}
/*
Index:    0   1   2   3    4
          ↓   ↓   ↓   ↓    ↓
A:        2   4   6   8   10


| Lần | `i` | `j` |      `B[j] = A[i]` |
| --: | --: | --: | -----------------: |
|   1 |   4 |   0 | `B[0] = A[4] = 10` |
|   2 |   3 |   1 |  `B[1] = A[3] = 8` |
|   3 |   2 |   2 |  `B[2] = A[2] = 6` |
|   4 |   1 |   3 |  `B[3] = A[1] = 4` |
|   5 |   0 |   4 |  `B[4] = A[0] = 2` |

*/


void reverse2(struct Array *arr){
    int i,j;
    for(i =0, j = arr->length -1; i<j; i++, j--){
        swap(&arr->A[i], &arr->A[j]);
    }
}
/*
Index:  0   1   2   3   4
A:      2   4   6   8  10
        ↑           ↑
        i           j

i = 0
j = 4

swap(A[0], A[4])

i < j
2 < 2 → false

reverse2()
Time  = O(n)
Space = O(1)
Big-O is O(n)
*/

// void leftShift(struct Array *arr){
//     int first = arr->A[0];
//     for(int i =0; i < arr->length -1; i++){
//         arr->A[i] = arr->A[i + 1];
//     }
//     arr->A[length -1] = first;

// }

void leftShift(struct Array *arr) {
    int first = arr->A[0];

    for(int i = 0; i < arr->length - 1; i++) {
        arr->A[i] = arr->A[i + 1];
    }

    arr->A[arr->length - 1] = first;
}

void InsertSoft(struct Array *arr, int x){
    int i = arr->length -1;
    if(i >= 0 && arr->length ==arr->size){
        return;
    }
    while(arr->A[i] > x){
        arr->A[i + 1] = arr->A[i];
        i --;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSoft(struct Array arr){
    int i;
    for(i = 0;i < arr.length-1; i++){
        if(arr.A[i] > arr.A[i + 1]){
            return 0;
        }
    }
    return 1;
}

void Rearrange(struct Array *arr){
    int i,j;
    i = 0;
    j = arr->length-1;
    while(i < j){
        while(arr->A[i]< 0)i++;
        while(arr->A[j] >=0)j--;
        if(i < j) swap(&arr->A[i], &arr->A[j]);
    }
}


struct Array* Merge(struct Array *arr, struct Array *arr1){
    int i,j,k;
    i=j=k=0;
    struct Array *arr2 = (struct Array *)malloc(sizeof(struct Array));
    while(i < arr->length &&  j < arr1->length){
        if(arr->A[i] < arr1->A[j]){
            arr2->A[k++] = arr->A[i++];
        }
        else{
            arr2->A[k++] = arr1->A[j++];
        }
    }
    for(;i<arr->length;i++){
        arr2->A[k++] = arr->A[i];
    }
    for(;j<arr1->length;j++){
        arr2->A[k++] = arr1->A[j];
    }
    arr2->length = arr->length + arr1->length;
    arr2->size = arr->length + arr1->length;

//soft
int k1;
    for(int h=0; h< arr2->length; h++){
        int i1=0,j1=arr2->length-1;
        while(i1<j1){
            while(arr2->A[i1]<0)i1++;
            while(arr2->A[j1]>0)j1--;
            if(i1<j1)swap(&arr2->A[i1], &arr2->A[j1]);
        }
    }
    //comparisons
    for(int i = 0; i < arr2->length - 1; i++)
{
    for(int j = i + 1; j < arr2->length; j++)
    {
        if(arr2->A[i] > arr2->A[j])
        {
            swap(&arr2->A[i], &arr2->A[j]);
        }
    }
}
    return arr2;
}


struct Array* Union(struct Array *arr, struct Array *arr1)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr2 =
        (struct Array *)malloc(sizeof(struct Array));

    while (i < arr->length && j < arr1->length)
    {
        if (arr->A[i] < arr1->A[j])
        {
            arr2->A[k++] = arr->A[i++];
        }
        else if (arr->A[i] > arr1->A[j])
        {
            arr2->A[k++] = arr1->A[j++];
        }
        else
        {
            arr2->A[k++] = arr->A[i++];
            j++;
        }
    }

    while (i < arr->length)
    {
        arr2->A[k++] = arr->A[i++];
    }

    while (j < arr1->length)
    {
        arr2->A[k++] = arr1->A[j++];
    }

    arr2->length = k;
    arr2->size = arr->size + arr1->size;

    return arr2;
}
/*
              ┌───────────────┐
              │    START      │
              └───────┬───────┘
                      │
                      ▼
            ┌───────────────────┐
            │ i = j = k = 0     │
            └─────────┬─────────┘
                      │
                      ▼
        ┌────────────────────────────┐
        │ i < arr.length AND         │
        │ j < arr1.length ?          │
        └────────────┬───────────────┘
                     │
              ┌──────┴──────┐
             YES            NO
              │              │
              ▼              ▼
    ┌─────────────────┐   ┌────────────────────┐
    │ arr[i] < arr1[j]│   │ Copy remaining     │
    │      ?          │   │ elements of arr    │
    └───────┬─────────┘   └─────────┬──────────┘
            │                       │
        ┌───┴───┐                   ▼
       YES      NO                  ┌────────────────────┐
        │        │                  │ Copy remaining     │
        ▼        ▼                  │  elements of arr1  │
 ┌────────────┐ ┌─────────────────┐ └─────────┬──────────┘
 │arr2[k]=    │ │ arr[i] >        │           │
 │arr[i]      │ │ arr1[j] ?       │           ▼
 │i++, k++    │ └───────┬─────────┘      ┌───────────┐
 └─────┬──────┘         │                │ length=k  │
       │            ┌────┴────┐           └─────┬─────┘
       │           YES       NO                 │
       │            │          │                 ▼
       │            ▼          ▼            ┌───────────┐
       │     ┌────────────┐ ┌────────────┐  │   RETURN  │
       │     │arr2[k]=    │ │arr2[k]=    │  │   arr2    │
       │     │arr1[j]     │ │arr[i]      │  └─────┬─────┘
       │     │j++, k++    │ │i++, j++, k++│       │
       │     └─────┬──────┘ └──────┬─────┘        ▼
       │           │               │          ┌────────┐
       └───────────┴───────────────┴─────────►│  END   │
                                              └────────┘
*/


int main()
{
    struct Array arr = {{-4, -2, 6, 8, 10}, 10, 5};

    struct Array arr1 = {{-16, 1, 3, 5, 7}, 10, 5};

    struct Array *arr2;

    arr2 = Union(&arr, &arr1);

    Display(*arr2);

    free(arr2);

    return 0;
}