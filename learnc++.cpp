#include <stdio.h>
#include <stdlib.h>
// Day 1: Array Implementation
//Day 2: Insertion in Array
class Array {
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);
public:
    Array(){
        size = 10;
        length =0;
        A = new int[size];
    }
    Array(int sz){
        size = sz;
        length =0;
        A = new int[size];
    }
    ~Array(){
        delete []A;    
    }
    void Display();
    void Append(int x);
    void Insert(int index, int x);

    
    int LinearSearch(int key);
    int BinarySearch(int key);
    //int RBinarySearch(int a[], int l, int h, int key);
    int get(int index);
    int set(int index, int x);
    int max();
    int min();
    int sum();
    float avg();
    void reverse();
    void reverse2();
    void InsertSoft(int x);
    int isSoft();
    void Rearrange();
    Array* Merge(Array *arr2);
    Array* Union(Array *arr2);
    Array* Intersection(Array *arr2);
    Array* Difference(Array *arr2);
};

void Array::Display(){
    int i;
    printf("Elements are: ");
    for(i =0; i< length; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Array::Append(int x){
    if(length < size){
        A[length++] = x;
    }
}
void Array::Insert(int index, int x){
    if(index >= 0 && index <= length){
        // A[10] = 10, A[9] = 9, A[8] = 8, A[7] = 7, A[6] = 6, A[5] = 5, A[4] = 4, A[3] = 3, A[2] = 2, A[1] = 1, A[0] = 0
        // i = 10; i > 5; i-- A[10] = A[9]; A[9] = A[8]; A[8] = A[7]; A[7] = A[6]; A[6] = A[5];

        for(int i = length ; i > index; i--){
            // A[6] = A[5]; A[6] = 5; A[5] = 4; A[4] = 3; A[3] = 2; A[2] = 1; A[1] = 0; 
            // A[5] = A[4]; A[4] = A[3]; A[3] = A[2]; A[2] = A[1]; A[1] = A[0];
            // A[4] = A[3]; A[3] = A[2]; A[2] = A[1]; A[1] = A[0];
            A[i] = A[i-1];
        }
        //A[5] = 5; 
        A[index] = x;
        // A[5] = 5; A[4] = 4; A[3] = 3; A[2] = 2; A[1] = 1; A[0] = 0;
        //index = 12, A[5] = 12; A[4] = 4; A[3] = 3; A[2] = 2; A[1] = 1; A[0] = 0;
        // A[6] = 5; A[5] = 12; A[4] = 4; A[3] = 3; A[2] = 2; A[1] = 1; A[0] = 0;
        length++;
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

int Array::Delete(int index){
    int x =0;
    int i;
    
    if(index >= 0 && index < length){
        x = A[index];
        for(i = index; i < length -1; i++){
            A[i] = A[i+1];
        }
        length--;
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
int Array::LinearSearch(int key){
    int i;
    for(i =0; i < length; i++){
        if(key == A[i]){
            swap(& A[i],& A[0]);
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

int Array::BinarySearch(int key){
    int l,mid,h;
    l=0;
    h=length - 1;
    
    while(l <= h){
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

int Array::RBinSearch(int a[], int l, int h, int key){
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

int Array::get(int index){
        if(index >= 0 && index < length){
            return A[index];
        }
    return -1;
}

int Array::set(int index ,int x){
    if(index >= 0 && index < length){
        A[index] = x;
    }
    return -1;
}

int Array::max(){
    int max = A[0];
    for(int i =0; i < length; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

int Array::min(){
    int min = A[0];
    for(int i =0; i < length; i++){
        if(A[i] < min){
            min = A[i];
        }
    }
    return min;
}

int Array::sum(){
    int s =0;
    for(int i =0; i< length; i++){
        s += A[i];
    }
    return s;
}

float Array::avg(){
    return (float)sum(arr)/ length;
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

void Array::reverse() {

    int *B;
    int i, j;

    B = (int *)malloc(length * sizeof(int));

    for (i = length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = A[i];
    }

    for (i = 0; i < length; i++) {
        A[i] = B[i];
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


void Array::reverse2(){
    int i,j;
    for(i =0, j = length -1; i<j; i++, j--){
        swap(& A[i],& A[j]);
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

// void leftShift(struct Array *arr) {
//     int first = arr->A[0];

//     for(int i = 0; i < arr->length - 1; i++) {
//         arr->A[i] = arr->A[i + 1];
//     }

//     arr->A[arr->length - 1] = first;
// }

void Array::InsertSoft(int x){
    int i =length -1;
    if(i >= 0 && length == size){
        return;
    }
    while(A[i] > x){
        A[i + 1] = A[i];
        i --;
    }
    A[i + 1] = x;
    length++;
}

int Array::isSoft(){
    int i;
    for(i = 0;i < length-1; i++){
        if(A[i] > A[i + 1]){
            return 0;
        }
    }
    return 1;
}

void Array::Rearrange(){
    int i,j;
    i = 0;
    j = length-1;
    while(i < j){
        while(A[i]< 0)i++;
        while(A[j] >=0)j--;
        if(i < j) swap(& A[i],& A[j]);
    }
}


Array* Merge(Array *arr1){
    int i,j,k;
    i=j=k=0;
    Array *arr2 = new Array(length + arr1.length);
    while(i < length &&  j < arr1.length){
        if(A[i] < arr1.A[j]){
            arr2->A[k++] = A[i++];
        }
        else{
            arr2->A[k++] = A[j++];
        }
    }
    for(;i<length;i++){
        arr2->A[k++] = A[i];
    }
    for(;j<arr1.length;j++){
        arr2->A[k++] = arr1.A[j];
    }
    arr2->length = length + arr1.length;
    arr2->size = length + arr1.length;

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


Array* Union(Array *arr1)
{
    int i, j, k;
    i = j = k = 0;

    Array *arr2 = new Array(length + arr1.length);
        

    while (i < length && j < arr1.length)
    {
        if (A[i] < arr1.A[j])
        {
            arr2->A[k++] = A[i++];
        }
        else if (A[i] > arr1.A[j])
        {
            arr2->A[k++] = arr1.A[j++];
        }
        else
        {
            arr2->A[k++] = A[i++];
            j++;
        }
    }

    while (i < length)
    {
        arr2->A[k++] = A[i++];
    }

    while (j < arr1.length)
    {
        arr2->A[k++] = arr1.A[j++];
    }

    arr2->length = k;
    arr2->size = size + arr1.size;

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
// struct Array *Intersection(struct Array *arr, struct Array *arr1){
//     int i,j,k;
//     i=j=k=0;
//     struct Array *arr2 = (struct Array *)malloc(sizeof(struct Array));
//     while(i< arr->length && j< arr1->length){
//         if(arr->A[i] < arr1->A[j]){
//             i++;
//         }else if(arr->A[i] > arr1->A[j]){
//             j++;
//         }
//         else if(arr->A[i] == arr1->A[j]){
//             arr2->A[k++] = arr->A[i++];
//             j++;
//         }
//     }
//     arr2->length = k;
//     arr2->size = arr->length < arr1->length ? arr->length : arr1->length;
//     return arr2;
// }

Array *Intersection(Array *arr1)
{
    int i, j, k;

    i = j = k = 0;

    Array *arr2 = new Array(length + arr1.length);

    arr2->size = length < arr1.length
               ? length
               : arr1.length;

    

    while (i < length && j < arr1.length)
    {
        if (A[i] < arr1.A[j])
        {
            i++;
        }
        else if (A[i] > arr1.A[j])
        {
            j++;
        }
        else
        {
            arr2->A[k++] = A[i];

            i++;
            j++;
        }
    }

    arr2->length = k;

    return arr2;
}
Array *Difference(Array *arr1){
    int i, j, k;
    i = 0; j =0; k =0;
    Array *arr2 = new Array(length + arr1.length);
    while(i< length && j < arr1.length){
        if(A[i] < arr1.A[j]){
            arr2->A[k++] = A[i++];
        }
        else if(A[i]> arr1.A[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    for(;i<length;i++){
        arr2->A[k++] = A[i];
    }

    arr2->length =k;
    return arr2;
}
/*
              ┌──────────────┐
              │    START     │
              └──────┬───────┘
                     │
                     ▼
            ┌─────────────────┐
            │ i = 0, j = 0    │
            │ k = 0           │
            └────────┬────────┘
                     │
                     ▼
        ┌───────────────────────────┐
        │ i < A.length &&           │
        │ j < B.length ?            │
        └────────────┬──────────────┘
                  YES│
                     ▼
             ┌────────────────┐
             │   A[i] < B[j]  │
             └───────┬────────┘
                  YES│       │NO
                     │       ▼
                     │  ┌────────────────┐
                     │  │   A[i] > B[j]  │
                     │  └───────┬────────┘
                     │       YES│      │NO
                     │          │      │
                     ▼          ▼      ▼
          ┌──────────────┐ ┌────────┐ ┌─────────────┐
          │ result[k] =  │ │ j = j+1│ │ i = i+1     │
          │ A[i]         │ └───┬────┘ │ j = j+1     │
          │ k = k+1      │     │      └──────┬──────┘
          │ i = i+1      │     │             │
          └──────┬───────┘     │             │
                 │             │             │
                 └─────────────┴─────────────┘
                               │
                               ▼
                     quay lại kiểm tra
                     i < A.length &&
                     j < B.length
                               │
                              NO
                               ▼
                    ┌──────────────────┐
                    │ i < A.length ?   │
                    └────────┬─────────┘
                          YES│
                             ▼
                  ┌────────────────────┐
                  │ result[k] = A[i]   │
                  │ k = k + 1          │
                  │ i = i + 1          │
                  └─────────┬──────────┘
                            │
                            │ quay lại
                            ▼
                    ┌──────────────────┐
                    │ length = k       │
                    └────────┬─────────┘
                             │
                             ▼
                       ┌───────────┐
                       │   RETURN  │
                       │  result   │
                       └───────────┘
*/
int main()
{
    Array *arr;
    int ch;
    int x, index;
    
    printf("Enter size of Array ");
    scanf("%d", &sz);
    arr = new Array(sz);
    
    do{

    printf("Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    printf("Enter you choice ");
    scanf("%d", &ch);
    switch(ch){
        case 1: printf("Enter an element and index");
            scanf("%d%d", &x, &index);
            arr.Insert(index, x);
            break;
        case 2: printf("Enter index ");
            scanf("%d", &index);
            x = arr.Delete(index);
            printf("Deleted element is %d\n",x);
            break;
        case 3: printf("Enter element to search ");
            scanf("%d", &index);
            index = arr.LinearSearch(x);
            printf("Element index %d", index);
            break;
        case 4: printf("Sum is %d\n", arr.sum());
            break;
        case 5: arr.Display();
    }

    }
    while(ch<6);


    return 0;
}