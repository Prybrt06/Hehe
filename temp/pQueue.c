// Priority Queue implementation in C

#include <stdio.h>
int size = 0;
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

// Function to heapify the tree
void heapify(int array[], int size, int i)
{
    if (size == 1)
    {
        printf("Single element in the heap");
    }

    else
    {
        // Find the largest among root, left child and right child
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l] < array[smallest])
            smallest = l;
        if (r < size && array[r] < array[smallest])
            smallest = r;

        // Swap and continue heapifying if root is not largest
        if (smallest != i)
        {
            swap(&array[i], &array[smallest]);
            heapify(array, size, smallest);
        }
    }
}

// Function to insert an element into the tree
void insert(int array[], int newNum)
{
    if (size == 0)
    {
        array[0] = newNum;
        size += 1;
    }
    else
    {
        array[size] = newNum;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(array, size, i);
        }
    }
}

void delete(int *arr, int del)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == del)
        {
            break;
        }
    }
    swap(&arr[i], &arr[size - 1]);
    size--;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
}

// Function to delete an element from the tree
// void deleteRoot(int array[], int num)
// {
//     int i;
//     for (i = 0; i < size; i++)
//     {
//         if (num == array[i])
//             break;
//     }

//     swap(&array[i], &array[size - 1]);
//     size -= 1;
//     for (int i = size / 2 - 1; i >= 0; i--)
//     {
//         heapify(array, size, i);
//     }
// }

// Print the array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

// Driver code
int main()
{
    int array[20];

    insert(array, 3);
    printArray(array, size);
    insert(array, 4);
    printArray(array, size);
    insert(array, 9);
    printArray(array, size);
    insert(array, 5);
    printArray(array, size);
    insert(array, 2);
    printArray(array, size);
    insert(array, 10);
    printArray(array, size);
    insert(array, 8);
    printArray(array, size);

    printf("Max-Heap array: ");
    printArray(array, size);

    // deleteRoot(array, 4);

    // printf("After deleting an element: ");

    // printArray(array, size);
}