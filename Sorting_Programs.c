#include <stdio.h>
#include <stdlib.h>
#define max 5
// sorting functions

void BubbleSort(int[], int);
void InsertionSort(int[], int);
void SelectionSort(int[], int);
void QuickSort(int[], int, int);
void MergeSort(int[],int ,int);

// Other functions
void printArray(int[], int);
void swap(int *, int *);
int partition(int[], int, int);
void merge(int[],int,int,int);

int main()
{
    int a[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    // BubbleSort(a,max);
    InsertionSort(a,10);
    // SelectionSort(a,max);
    // QuickSort(a, 0, 9);
    // MergeSort(a,0,9);
    printArray(a, 10);
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void BubbleSort(int a[], int n)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void InsertionSort(int a[], int n)
{
    int j, x;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        x = a[i];
        while (j > -1 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}
void SelectionSort(int a[], int n)
{
    int i, k, j;
    for (int i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }
        swap(&a[i], &a[k]);
    }
}
// function to find the partition position
int partition(int a[], int low, int high)
{

    int i = low + 1, j = high, pivot = a[low];
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
            swap(&a[i], &a[j]);
    } while (i < j);

    swap(&a[low], &a[j]);
    return j;
}

void QuickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        QuickSort(array, low, pi - 1);
        QuickSort(array, pi + 1, high);
    }
}

void MergeSort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        merge(a,mid,low,high);
    }
}
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

