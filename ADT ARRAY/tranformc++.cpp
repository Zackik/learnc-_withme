#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Array {
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:
    Array() {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz) {
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array() {
        delete[] A;
    }

    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    
    int LinearSearch(int key);
    int BinarySearch(int key);
    int RBinarySearch(int a[], int l, int h, int key);
    
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
    
    Array* Merge(Array *arr1);
    Array* Union(Array *arr1);
    Array* Intersection(Array *arr1);
    Array* Difference(Array *arr1);
};

void Array::Display() {
    int i;
    printf("Elements are: ");
    for (i = 0; i < length; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Array::Append(int x) {
    if (length < size) {
        A[length++] = x;
    }
}

void Array::Insert(int index, int x) {
    if (index >= 0 && index <= length) {
        for (int i = length; i > index; i--) {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
}

int Array::Delete(int index) {
    int x = 0;
    int i;
    
    if (index >= 0 && index < length) {
        x = A[index];
        for (i = index; i < length - 1; i++) {
            A[i] = A[i + 1];
        }
        length--;
        printf("Deleted element is: %d\n", x);
        return x;
    }
    return 0;
}

void Array::swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int Array::LinearSearch(int key) {
    int i;
    for (i = 0; i < length; i++) {
        if (key == A[i]) {
            swap(&A[i], &A[0]);
            return i;
        }
    }
    return -1;
}

int Array::BinarySearch(int key) {
    int l, mid, h;
    l = 0;
    h = length - 1;
    
    while (l <= h) {
        mid = (l + h) / 2;
        if (key == A[mid]) {
            return mid;
        }
        else if (key < A[mid]) {
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return -1;
}

int Array::RBinarySearch(int a[], int l, int h, int key) {
    int mid;
    if (l <= h) {
        mid = (l + h) / 2;
        if (key == a[mid]) {
            return mid;
        }
        else if (key < a[mid]) {
            return RBinarySearch(a, l, mid - 1, key);
        }
        else {
            return RBinarySearch(a, mid + 1, h, key);
        }
    }
    return -1;
}

int Array::get(int index) {
    if (index >= 0 && index < length) {
        return A[index];
    }
    return -1;
}

int Array::set(int index, int x) {
    if (index >= 0 && index < length) {
        A[index] = x;
        return 1;
    }
    return -1;
}

int Array::max() {
    int max_val = A[0];
    for (int i = 0; i < length; i++) {
        if (A[i] > max_val) {
            max_val = A[i];
        }
    }
    return max_val;
}

int Array::min() {
    int min_val = A[0];
    for (int i = 0; i < length; i++) {
        if (A[i] < min_val) {
            min_val = A[i];
        }
    }
    return min_val;
}

int Array::sum() {
    int s = 0;
    for (int i = 0; i < length; i++) {
        s += A[i];
    }
    return s;
}

float Array::avg() {
    return (float)sum() / length;
}

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

void Array::reverse2() {
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        swap(&A[i], &A[j]);
    }
}

void Array::InsertSoft(int x) {
    int i = length - 1;
    if (i >= 0 && length == size) {
        return;
    }
    while (i >= 0 && A[i] > x) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

int Array::isSoft() {
    int i;
    for (i = 0; i < length - 1; i++) {
        if (A[i] > A[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void Array::Rearrange() {
    int i, j;
    i = 0;
    j = length - 1;
    while (i < j) {
        while (A[i] < 0) i++;
        while (A[j] >= 0) j--;
        if (i < j) swap(&A[i], &A[j]);
    }
}

Array* Array::Merge(Array *arr1) {
    int i, j, k;
    i = j = k = 0;
    Array *arr2 = new Array(length + arr1->length);
    
    while (i < length && j < arr1->length) {
        if (A[i] < arr1->A[j]) {
            arr2->A[k++] = A[i++];
        } else {
            arr2->A[k++] = arr1->A[j++];
        }
    }
    for (; i < length; i++) {
        arr2->A[k++] = A[i];
    }
    for (; j < arr1->length; j++) {
        arr2->A[k++] = arr1->A[j];
    }
    arr2->length = length + arr1->length;
    return arr2;
}

Array* Array::Union(Array *arr1) {
    int i, j, k;
    i = j = k = 0;

    Array *arr2 = new Array(length + arr1->length);

    while (i < length && j < arr1->length) {
        if (A[i] < arr1->A[j]) {
            arr2->A[k++] = A[i++];
        } else if (A[i] > arr1->A[j]) {
            arr2->A[k++] = arr1->A[j++];
        } else {
            arr2->A[k++] = A[i++];
            j++;
        }
    }

    while (i < length) {
        arr2->A[k++] = A[i++];
    }

    while (j < arr1->length) {
        arr2->A[k++] = arr1->A[j++];
    }

    arr2->length = k;
    return arr2;
}

Array* Array::Intersection(Array *arr1) {
    int i, j, k;
    i = j = k = 0;

    Array *arr2 = new Array(length + arr1->length);

    while (i < length && j < arr1->length) {
        if (A[i] < arr1->A[j]) {
            i++;
        } else if (A[i] > arr1->A[j]) {
            j++;
        } else {
            arr2->A[k++] = A[i];
            i++;
            j++;
        }
    }

    arr2->length = k;
    return arr2;
}

Array* Array::Difference(Array *arr1) {
    int i, j, k;
    i = j = k = 0;
    Array *arr2 = new Array(length + arr1->length);
    
    while (i < length && j < arr1->length) {
        if (A[i] < arr1->A[j]) {
            arr2->A[k++] = A[i++];
        } else if (A[i] > arr1->A[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    for (; i < length; i++) {
        arr2->A[k++] = A[i];
    }

    arr2->length = k;
    return arr2;
}

int main() {
    Array *arr;
    int sz;
    int ch;
    int x, index;
    
    printf("Enter size of Array: ");
    scanf("%d", &sz);
    arr = new Array(sz);
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1: 
                printf("Enter an element and index: ");
                scanf("%d%d", &x, &index);
                arr->Insert(index, x);
                break;
            case 2: 
                printf("Enter index: ");
                scanf("%d", &index);
                arr->Delete(index);
                break;
            case 3: 
                printf("Enter element to search: ");
                scanf("%d", &x);
                index = arr->LinearSearch(x);
                if (index != -1)
                    printf("Element found at index: %d\n", index);
                else
                    printf("Element not found!\n");
                break;
            case 4: 
                printf("Sum is %d\n", arr->sum());
                break;
            case 5: 
                arr->Display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (ch < 6);

    delete arr;
    return 0;
}