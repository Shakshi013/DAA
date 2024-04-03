
/*
I. Given an unsorted array of integers, design an algorithm and a program to sort the anay using insertion sort. Your program should be able to find number of comparisons and shifts (shifts- total number of times the array elements are shifted from their place) required for sorting the атау.
Input Format:
The first line contains number of test cases, I
For each test case, there will be two input lines.
First line contains (the size of away).
Second line contains space-separated integers describing array.
Output Format:
The output will have T number of lines.
For each test case T, there will be three output lines.
First line will give the sorted array.
Second line will give total number of comparisons.
Third line will give total number of shift operations required.
*/

#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n, i, j, comparisons = 0, shifts = 0;
        scanf("%d", &n);
        int arr[n];
        for (i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        // Performs Insertion Sort
        for (i = 1; i < n; i++)
        {
            int key = arr[i];
            j = i - 1;

            shifts++;

            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
                shifts++;
                comparisons++;
            }
            arr[j + 1] = key;
        }

        // Output sorted array
        for (i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Output number of comparisons
        printf("%d\n", comparisons);

        // Output number of shifts
        printf("%d\n", shifts);
    }

    return 0;
}

/*
II. Given an unsorted array of integers, design an algorithm and implement a program to sort this amay using selection sort.
Your program should also find number of comparisons and number of swaps required.
Input Format:
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of away).
Second line contains space-separated integers describing array.
Output Format:
The output will have T number of lines.
For each test case T, there will be three output lines.
First line will give the sorted array.
Second line will give total number of comparisons,
Third line will give total number of swaps required.
*/

#include <stdio.h>

void main()
{
    int n, T;
    printf("ENTER THE TEST CASES:\n");
    scanf("%d", &T);

    while (T > 0)
    {
        printf("ENTER THE SIZE OF THE ARRAY:\n");
        scanf("%d", &n);

        int arr[n];

        printf("ENTER THE ARRAY ELEMENTS:\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int comparisons = 0, shifts = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int min_index = i;
            for (int j = i + 1; j < n; j++)
            {
                comparisons++;
                if (arr[j] < arr[min_index])
                {
                    min_index = j;
                }
            }
            int temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
            shifts++;
        }

        printf("THE SORTED ARRAY IS:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("THE NUMBER OF COMPARISONS ARE: %d\n", comparisons);
        printf("THE NUMBER OF SHIFTS ARE: %d\n", shifts);

        T--;
    }
}

/*
III. Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether there are any
duplicate elements in the array or not. (use sorting) (Time complexity 0(n log n) )
*/

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // temporary arrays
    int L[n1], R[n2];
    // data getting copied  to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    // merging back the temporary arrays to the original array , arr[]
    int i = 0, j = 0, k = left;
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
    // copying of rest of the elements of L[], if present
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // copying of rest of the elements of R[], if present
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        // first and second half is getting sorted
        mergeSort(arr, left, mid); // first it will sort the first half than the control goes to the second half of the array i.e;next line of code gets executed after the first half is sompletely executed .
        mergeSort(arr, mid + 1, right);
        // sorted halves are getting sorted
        merge(arr, left, mid, right);
    }
}

int hasDuplicates(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return 1; //  found
        }
    }
    return 0; // Not found
}

int main()
{
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--)
    {
        int n;
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        int arr[n];

        printf("Enter the array elements: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        // Sorts the array using Merge Sort
        mergeSort(arr, 0, n - 1);

        // Checks for duplicates in the sorted array
        if (hasDuplicates(arr, n))
            printf("Duplicate elements found.\n");
        else
            printf("No duplicate elements found.\n");
    }

    return 0;
}

/*
LEET CODE :     Find Minimum In Rotated Sub Array
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example,
the array nums = [0,1,2,4,5,6,7] might become:
[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a [0], a[1], [2], ..., a[n-1]] 1 time results in the
array [a[n-1], a[0], a[1], [2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.
*/

#include <stdio.h>

// Function to find  the minimum element in the rotated array nums[]
int findMin(int nums[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[right])
        {
            // if TRUE  then the minimum element must be on the left side
            right = mid;
        }
        else
        {
            // if FALSE the minimum element must be on the right side
            left = mid + 1;
        }
    }

    // left ppoints at the minimum element
    return nums[left];
}

int main()
{
    int n;
    printf("ENTER THE  SIZE OF ARRAY: nums[] \n ");
    scanf("%d", &n);

    int nums[n];
    printf("ENTER THE ELEMENTS OF THE ARAAY : nums[]\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int minElement = findMin(nums, n);
    printf("Minimum element in the rotated sorted array: %d\n", minElement);

    return 0;
}

/*
GEEKS FOR GEEKS :
Given an array of size 'n' , generate and print all possible combinations of 'r' elements in the array .
Input :
        arr=[1,2,3,4] ,r=2
Output:
        1 3
        1 4
        2 3
        2 4
        3 4
*/
#include <stdio.h>
#include <math.h>
void main()
{
    int n;
    printf("ENTER THE SIZE OF THE ARRAY \n");
    scanf("%d", &n);

    int arr[n];
    printf("ENTER THE ARRAY ELEMENTS :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }

    int r = 2;
    int combination[r];

    for (int i = 0; i <= n - r; i++)
    {
        combination[0] = arr[i];
        if (r > 1)
        {
            for (int j = i + 1; j <= n - (r - 1); j++)
            {
                combination[1] = arr[j];
                printf("%d %d\n", combination[0], combination[1]);
            }
        }
        else
        {
            printf("%d\n", combination[0]);
        }
    }
}

/*
LEET CODE : CONTAINER  WITH MOST WATER
You are given an integer array 'height' of length'n' .There are 'n' vertical lines drawn such that the two endpoints of the 'i-th'
line are '(i,0)' and '(i,height[i])'.
Find two lines that together with the x-axis from a container contains the most water.
Return the maximum amount of water a container can store .
Notice: that you may not slant the container
*/

#include <stdio.h>

int maxArea(int *height, int heightSize)
{
    int maxArea = 0;
    int left = 0, right = heightSize - 1;

    while (left < right)
    {
        int minHeight = height[left] < height[right] ? height[left] : height[right];
        int area = (right - left) * minHeight;
        if (area > maxArea)
        {
            maxArea = area;
        }
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return maxArea;
}
int main()
{
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);

    int result = maxArea(height, heightSize);
    printf("Max area: %d\n", result);

    return 0;
}
