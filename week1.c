/*
QUESTION 1 : Given an array of nonnegative integers, design a linear algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input). */

#include <stdio.h>

int main()
{
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--)
    {
        int n, key;
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter the elements of the array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("Enter the key element to search: ");
        scanf("%d", &key);

        int comparisons = 0;
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            comparisons++;
            if (arr[i] == key)
            {
                found = 1; // Key found
                break;
            }
        }
        if (found)
            printf("Element %d found in the array with %d comparisons.\n", key, comparisons);
        else
            printf("Element %d not found in the array with %d comparisons.\n", key, comparisons);
    }
    return 0;
}

/*
QUESTION 2 : Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).  */

#include <stdio.h>

int main()
{
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--)
    {
        int n, key;
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter the sorted elements of the array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("Enter the key element to search: ");
        scanf("%d", &key);

        int comparisons = 0;
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            comparisons++;
            if (arr[mid] == key)
            {
                printf("Element %d found at index %d with %d comparisons.\n", key, mid, comparisons);
                break;
            }
            else if (arr[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (low > high)
        {
            printf("Element %d not found in the array with %d comparisons.\n", key, comparisons);
        }
    }
    return 0;
}

/*
QUESTION 3 : Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k
] and so on. Once the interval (arr[2k
]
< key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k
to find the element
key. (Complexity < O(n), where n is the number of elements need to be scanned for searching).
JUMP SEARCH  */

#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int n, int key)
{
    int step = sqrt(n);
    int prev = 0;

    while (arr[(step < n ? step : n) - 1] < key) // checks if the element at the current step (arr[fmin(step, n) - 1]) is less than the key.
    // If so, it updates the prev index and increases the step size by the square root of n.
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n) // If previous jump exceeds array size, key not present
            return -1;
    }
    // Linear search within the block starting from prev
    while (arr[prev] < key)
    {
        prev++;
        // If we reach the end of the current block or the end of the array, key not present
        if (prev == (step < n ? step : n))
            return -1;
    }
    // If the key is found at index prev, return its index
    if (arr[prev] == key)
        return prev;
    // key not found
    return -1;
}

int main()
{
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--)
    {
        int n, key;
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter the elements of the sorted array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("Enter the key element to search: ");
        scanf("%d", &key);

        int index = jumpSearch(arr, n, key);

        if (index != -1)
        {
            printf("Element %d found at index %d.\n", key, index);
        }
        else
        {
            printf("Element %d not found in the array.\n", key);
        }
    }
    return 0;
}
