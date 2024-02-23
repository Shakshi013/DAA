/*
I. Given a sorted array of positive integers containing few duplicate elements, design an algorithm and implement it using a program to find
whether the given key element is present in the array or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
Input format:
The first line contains number of test cases, T.
For each test case, there will be three input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Third line contains the key element that need to be searched in the array.
Output format:
The output will have T number of lines.
For each test case T, output will be the key element and its number of copies in the array if the key element is present in the array
otherwise print " Key not present".
*/
#include <stdio.h>

int main()
{
    int T;
    printf("Enter number of test cases: ");
    scanf("%d", &T);

    while (T--)
    {
        int n;
        printf("Enter size of array: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter elements of array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int key;
        printf("Enter the key element: ");
        scanf("%d", &key);

        // Find the first occurrence of the key
        int low = 0, high = n - 1, firstIndex = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] == key)
            {
                firstIndex = mid;
                high = mid - 1; // Continuous searching in the left half
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

        if (firstIndex == -1)
        {
            printf("Key not present\n");
        }
        else
        {
            // Finding the last occurrence of the key entered
            low = 0, high = n - 1;
            int lastIndex = -1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (arr[mid] == key)
                {
                    lastIndex = mid;
                    low = mid + 1; // Continuous searching in the right half
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
            // Calculating the number of copies of the key
            int copies = lastIndex - firstIndex + 1;
            printf("Key: %d, Number of copies: %d\n", key, copies);
        }
    }

    return 0;
}


/*II. Given a sorted array of positive integers, design an algorithm and implement it using a program to find three indices i, j, k
such that arr[i] + an[j] = arr[k].
Input format:
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output:
The output will have T number of lines.
For each test case T, print the value of i, j and k, if found else print "No sequence found".
Sample I/O Problem II:
Input:
3
5
15 84 209 341
10
24 28 48 71 86 89 92 120 194 201
15
64 69 82 95 99 107 113 141 171 350 369 400 511 590 666
Output:
No sequence found. 2,7,8 1,6,9  */
#include <stdio.h>

void main()
{
    int T;
    printf("Enter number of test cases: ");
    scanf("%d", &T);

    while (T > 0)
    {
        int n;
        printf("Enter size of array: ");
        scanf("%d", &n);
        int a[n];
        printf("Enter elements of array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        int found = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (a[i] + a[j] == a[k])
                    {
                        printf("(%d, %d, %d)\n", i, j, k);
                        found = 1;
                        goto end;
                    }
                }
            }
        }

        end:
        if (!found)
        {
            printf("No sequence found.\n");
        }

        T--;
    }
}


/*III. Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K.
Input format:
The first line contains number of test cases, T.
For each test case, there will be three input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Third line contains the key element.   */

#include <stdio.h>

void main()
{
    int T;
    printf("Enter number of test cases: ");
    scanf("%d", &T);

    while (T > 0)
    {
        int n;
        printf("Enter size of array: ");
        scanf("%d", &n);
        int a[n];
        printf("Enter elements of array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        int key;
        printf("Enter the key element: ");
        scanf("%d", &key);

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] - a[j] == key || a[j] - a[i] == key)
                {
                    printf("(%d, %d)\n", a[i], a[j]);
                    count++;
                }
            }
        }
        if (count == 0)
        {
            printf("No such pairs found.\n");
        }

        T--;
    }
}

/*

EXTRA FROM LEET CODE :   Given an integer array find a sub array that has largest product
 */

#include <stdio.h>
int maxi(int a, int b)
{
    return (a > b) ? a : b;
}
int min(int a, int b)
{
    return (a < b) ? a : b;
}

void main()
{
    int arr[20], n;
    printf("ENTER THE SIZE OF THE ARRAY :\n");
    scanf("%d", &n);
    printf("ENTER THE ARRAY ELEMENTS:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int pro = arr[0];
    int max = arr[0];
    int max_prod = arr[0];
    int start = 0, end = 0, s = 0;
    int temp;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
        {
            temp = max;
            max = pro;
            pro = temp;
        }

        max = maxi(arr[i], max * arr[i]);
        pro = min(arr[i], pro * arr[i]);
        if (max > max_prod)
        {
            max_prod = max;
            start = s;
            end = i;
        }

        if (max == 0)
        {
            max = 1;
            s = i + 1;
        }
    }
    int product = 1;
    for (int i = start; i <= end; i++)
    {
        product = product * arr[i];
    }
    printf("MAXIMUM PRODUCT SUBARRAY IS :	\n");
    for (int i = start; i <= end; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    printf(" THE MAXIMUM PRODUCT IS :%d ", product);
}