/*
I. Given an unsorted array of integers , design an algorithm and implement it using a program to sort an array of elements
by dividing the array into two subarrays and combining these subarrays after sorting each one of them .
 Your program should also find the number of comparisons and inversions during sorting of the array.

 ----->MERGE SORT .
*/

#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int left, int mid, int right, long long *comparisons)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }
    long long swaps = 0;
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
            swaps += n1 - i; // Count swaps
        }
        (*comparisons)++; // Count comparisons
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
    return swaps;
}

long long mergeSort(int arr[], int left, int right, long long *comparisons)
{
    long long swaps = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2; // for avoiding the overflow for large left  and right
        swaps += mergeSort(arr, left, mid, comparisons);
        swaps += mergeSort(arr, mid + 1, right, comparisons);
        swaps += merge(arr, left, mid, right, comparisons);
    }
    return swaps;
}

int inversion_count(int a[], int n)
{
    int icount = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
                icount++; // counts inversions
        }
    }
    return icount;
}

int main()
{
    int n, T;
    printf("ENTER THE TEST CASES:\n");
    scanf("%d", &T);

    while (T--)
    {
        printf("ENTER THE SIZE OF THE ARRAY:\n");
        scanf("%d", &n);

        int arr[n];

        printf("ENTER THE ARRAY ELEMENTS:\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        long long comparisons = 0;

        long long swaps = mergeSort(arr, 0, n - 1, &comparisons);

        printf("Sorted array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        int ic = inversion_count(arr, n);
        printf("\ninversion count is %d\n", ic);

        printf("Number of swaps: %lld\n", swaps);
        printf("Number of comparisons: %lld\n", comparisons);
    }
    return 0;
}

/*
II. Given an unsorted array of integeers , design and implement it using a program to sort an array of elements
by partitioning the array into two sub arrays based on a pivot element such that one of the sub array holds the values smaller than the
pivot element while another sub array holds values greater than the pivot element .
Pivot element should be selected at random from the array . Your program should also find the number of comparisons and swaps
required for sorting the array .

----->QUICK SORT .
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int *swapCount, int *comparisonCount)
{
    int pivot = arr[high];// taking the last element as pivot.
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        (*comparisonCount)++; // Increments comparison count
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
            (*swapCount)++; // Increments swap count
        }
    }
    swap(&arr[i + 1], &arr[high]);
    (*swapCount)++; // Increments swap count
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int *swapCount, int *comparisonCount)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, swapCount, comparisonCount);
        quickSort(arr, low, pi - 1, swapCount, comparisonCount);
        quickSort(arr, pi + 1, high, swapCount, comparisonCount);
    }
}

int main()
{
    int n, T;
    printf("ENTER THE TEST CASES:\n");
    scanf("%d", &T);

    while (T--)
    {
        printf("ENTER THE SIZE OF THE ARRAY:\n");
        scanf("%d", &n);

        int arr[n];

        printf("ENTER THE ARRAY ELEMENTS:\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int swapCount = 0;
        int comparisonCount = 0;

        quickSort(arr, 0, n - 1, &swapCount, &comparisonCount);
        printf("Sorted array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        printf("Number of swaps: %d\n", swapCount);
        printf("Number of comparisons: %d\n", comparisonCount);
    }
    return 0;
}

/*
III.Given an unsorted array of integers , design an algorithm and implement it using a program to find Kth smallest or largest
element in the array .
Worst case Time Complexity =O(n).

------> use HEAP SORT .
*/

#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

int findKthLargest(int arr[], int n, int k)
{
    buildHeap(arr, n);

    for (int i = 0; i < k - 1; i++)
    {
        int temp = arr[0];
        arr[0] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
        heapify(arr, n - 1 - i, 0);
    }

    return arr[0];
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int k;
    printf("Enter the value of K\n");
    scanf("%d", &k);

    printf("The %dth largest element is: %d\n", k, findKthLargest(arr, n, k));

    return 0;
}