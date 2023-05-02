#include <stdio.h>
#include <limits.h>

typedef struct item
{
    int value;
    int priority;
} item;

item pr[100000];

// Pointer to the last index
int size = -1;

// Function to insert a new element
// into priority queue
void enqueue(int value, int priority)
{
    // Increase the size
    size++;

    // Insert the element
    pr[size].value = value;
    pr[size].priority = priority;
}

// Function to check the top element
int peek()
{
    int highestPriority = INT_MIN;
    int ind = -1;

    // Check for the element with
    // highest priority
    for (int i = 0; i <= size; i++)
    {

        // If priority is same choose
        // the element with the
        // highest value
        if (highestPriority == pr[i].priority && ind > -1 && pr[ind].value < pr[i].value)
        {
            highestPriority = pr[i].priority;
            ind = i;
        }
        else if (highestPriority < pr[i].priority)
        {
            highestPriority = pr[i].priority;
            ind = i;
        }
    }

    // Return position of the element
    return ind;
}

// Function to remove the element with
// the highest priority
void dequeue()
{
    // Find the position of the element
    // with highest priority
    int ind = peek();

    // Shift the element one index before
    // from the position of the element
    // with highest priority is found
    for (int i = ind; i < size; i++)
    {
        pr[i] = pr[i + 1];
    }

    // Decrease the size of the
    // priority queue by one
    size--;
}

int main()
{
    enqueue(10, 2);
    enqueue(20, 4);
    enqueue(30, 4);
    enqueue(40, 3);

    int p = peek();

    printf("%d\n", pr[p].value);

    dequeue();

    p = peek();

    printf("%d\n", pr[p].value);

    dequeue();

    p = peek();

    printf("%d", pr[p].value);
}