/*
Given an unsorted array of alphabets containing duplicate elements. Design an algorithm
and implement it using a program to find which alphabet has maximum number of
occurrences and print it.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h> // Character classification and conversion functions are included in this header file .

#define MAX_SIZE 256 // for ASCII characters

void findMaxOccurrence(const char *str)
{
    // Initialize frequency array to store count of each alphabet
    int freq[26] = {0};

    // Traverse the input string and update frequency array
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = tolower(str[i]); // Convert character to lowercase
        if (isalpha(ch))           // Check if character is alphabet
            freq[ch - 'a']++;      // Increment count for current alphabet
    }

    // Find the alphabet with maximum occurrence
    int maxCount = 0;
    char maxChar;
    int hasDuplicates = 0;

    for (int i = 0; i < 26; ++i)
    {
        if (freq[i] > maxCount)
        {
            maxCount = freq[i];
            maxChar = 'a' + i;
            hasDuplicates = 1;
        }
    }

    // Output the result
    if (hasDuplicates)
    {
        if (maxCount == 1)
            printf("No Duplicates Present\n");
        else
            printf("%c - %d\n", maxChar, maxCount);
    }
    else
        printf("No Duplicates Present\n");
}

int main()
{
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T); // Number of test cases

    while (T--)
    {
        int n;
        printf("Enter the size of the string: ");
        scanf("%d", &n); // Size of string

        char str[1000];
        printf("Enter the string: ");
        scanf(" %[^\n]", str); // Input string

        findMaxOccurrence(str);
    }
    return 0;
}

/*
Given an unsorted array of integers, design an algorithm and implement it using a
program to find whether two elements exist such that their sum is equal to the given
key element. (Time Complexity = O(n log n))
*/

#include <stdio.h>
#include <stdlib.h>

// Merge function for merge sort
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Creating two arrays for storing
    int L[n1], R[n2];

    // Copying data to the arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merging the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copying the remaining elements of L[] if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copying the remaining elements of R[]  if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2; // for avoiding the overflow for large l and r
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to check if two elements with sum equal to key exist
int hasPairWithSum(int arr[], int n, int key, int *index1, int *index2)
{
    // Sorting the array
    mergeSort(arr, 0, n - 1);

    // Initializing the left and the right pointers
    int left = 0, right = n - 1;

    // Traversing the array using two pointers
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == key)
        {
            *index1 = left;
            *index2 = right;
            return 1; // found
        }
        else if (sum < key)
            left++;
        else
            right--;
    }
    return 0;
}

int main()
{
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);
    while (T--)
    {
        int n, key, index1, index2;
        printf("Enter the size of the array: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter the elements of the array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("Enter the key element: ");
        scanf("%d", &key);

        if (hasPairWithSum(arr, n, key, &index1, &index2))
        {
            printf(" %d =  %d %d.\n", key, arr[index1], arr[index2]);
        }
        else
        {
            printf("No such elements exist \n");
        }
    }
    return 0;
}

/*
You have been given two sorted integer arrays of size m and n. Design an algorithm
and implement it using a program to find list of elements which are common to
both. (Time Complexity = O(m+n))
*/
#include <stdio.h>
#include <stdlib.h>

// Function to find common elements in two sorted arrays
void findCommonElements(int arr1[], int m, int arr2[], int n)
{
    int i = 0, j = 0;
    printf("Common elements: ");
    while (i < m && j < n)
    {
        if (arr1[i] == arr2[j])
        {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
            i++;

        else
            j++;
    }
    printf("\n");
}

int main()
{
    int m, n;
    printf("Enter the size of the first array: ");
    scanf("%d", &m);

    int arr1[m];
    printf("Enter the elements of the first array (in sorted order): ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &n);

    int arr2[n];
    printf("Enter the elements of the second array (in sorted order): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }
    findCommonElements(arr1, m, arr2, n);
    return 0;
}
