#include <stdio.h>
#include <malloc.h>

typedef int keytype;
typedef float othertype;

typedef struct
{
    keytype key;
    othertype otherfields;
} recordtype;

void Swap(recordtype *x, recordtype *y)
{
    recordtype temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int FindPivot(recordtype a[], int i, int j)
{
    keytype firstkey;
    int k;
    k = i + 1;
    firstkey = a[i].key;
    while ((k <= j) && (firstkey == a[k].key))
        k++;
    if (k > j)
        return -1;
    else
    {
        if (firstkey < a[k].key)
            return k;
        else
            return i;
    }
}
int Partition(recordtype a[], int i, int j, keytype pivot)
{

    int L = i;
    int R = j;
    while (L <= R)
    {
        while (a[L].key < pivot)
            L++;
        while (a[R].key >= pivot)
            R--;
        if (L < R)
            Swap(&a[L], &a[R]);
    }
    return L;
}
void QuickSort(recordtype a[], int i, int j)
{
    keytype pivot;
    int pivotindex, k;
    pivotindex = FindPivot(a, i, j);
    if (pivotindex != -1)
    {
        pivot = a[pivotindex].key;
        k = Partition(a, i, j, pivot);
        QuickSort(a, i, k - 1);
        QuickSort(a, k, j);
    }
}
void Read_Data(recordtype a[], int *n)
{
    FILE *f;
    f = fopen("data.txt", "r");
    int i = 0;
    if (f != NULL)
        while (!feof(f))
        {
            fscanf(f, "%d%f", &a[i].key, &a[i].otherfields);
            i++;
        }
    else
        printf("Loi mo file\n");
    fclose(f);
    *n = i;
}
void Print_Data(recordtype a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%3d%5d%8.2f\n", i + 1, a[i].key, a[i].otherfields);
    }
}
int main()
{
    recordtype a[100];
    int n;
    printf("Thuat toan QuickSort\n\n");
    Read_Data(a, &n);
    printf("Du lieu ban dau:\n");
    Print_Data(a, n);

    QuickSort(a, 0, n - 1);

    printf("Du lieu sau khi sap xep\n");
    Print_Data(a, n);
    return 0;
}