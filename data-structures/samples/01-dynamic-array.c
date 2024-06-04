#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct DynArray
{
    size_t capacity;
    size_t length;
    int *items;
};

void initDynamicArray(struct DynArray *arr, size_t capacity)
{
    arr->capacity = capacity;
    arr->length = 0;
    arr->items = malloc(arr->capacity * sizeof(int));
}

void destroyDynamicArray(struct DynArray *arr)
{
    if (arr->items != NULL)
    {
        free(arr->items);
    }

    arr->items = NULL;
    arr->capacity = 0;
    arr->length = 0;
}

void resizeDynamicArray(struct DynArray *arr, size_t newCapacity)
{
    if (newCapacity > arr->capacity)
    {
        int *newItems = realloc(arr->items, newCapacity * sizeof(int));

        if (newItems == NULL)
        {
            fprintf(stderr, "Dynamic array memory reallocation error for %s", __func__);
        }

        arr->capacity = newCapacity;
        arr->items = newItems;
    }
}

void printDynamicArray(struct DynArray *arr)
{
    printf("%zu / %zu\n", arr->length, arr->capacity);

    printf("[");
    for (int i = 0; i < arr->length; i++)
    {
        printf("%i", arr->items[i]);

        if (i < arr->length - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");
}

void pushToDynamicArray(struct DynArray *arr, int item)
{
    if (arr->capacity == 0)
        resizeDynamicArray(arr, 1);

    if (arr->length == arr->capacity)
        resizeDynamicArray(arr, arr->capacity * 2);

    arr->items[arr->length] = item;
    arr->length++;
}

void emptyDynamicArray(struct DynArray *arr)
{

    if (arr->items != NULL)
    {
        free(arr->items);
    }

    initDynamicArray(arr, 1);
}

void removeFromDynamicArray(struct DynArray *arr, size_t index)
{
    if (index < arr->length)
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->items[i] = arr->items[i + 1];
        }
        arr->length--;
    }
}

int main() {
    struct DynArray arr;

    initDynamicArray(&arr, 1);
    printDynamicArray(&arr);

    pushToDynamicArray(&arr, 1);
    printDynamicArray(&arr);

    pushToDynamicArray(&arr, 2);
    printDynamicArray(&arr);

    pushToDynamicArray(&arr, 3);
    printDynamicArray(&arr);

    pushToDynamicArray(&arr, 4);
    printDynamicArray(&arr);

    pushToDynamicArray(&arr, 5);
    printDynamicArray(&arr);

    removeFromDynamicArray(&arr, 2);
    printDynamicArray(&arr);

    removeFromDynamicArray(&arr, 2);
    printDynamicArray(&arr);

    emptyDynamicArray(&arr);
    printDynamicArray(&arr);

    destroyDynamicArray(&arr);

    return 0;
}
