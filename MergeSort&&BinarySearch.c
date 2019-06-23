
#include <stdio.h>

void merge(int a[], int start, int end)
{
    int middle = (start + end) / 2;

    int i = start; //pointer for the first half of the array
    int k = start; //pointer for the second half of the array
    int j = middle + 1; //pointer for the temporary array
    int temp[end+1]; //temporarry array's is similar to the size of the original array

    while(i <= middle && j <= end) //as much as we have anything to compare
    {
       if (a[i] < a[j]) //we compare elements from the left with the elements form the right
       {
           temp[k++] = a[i++]; //elements that are smaller are added to the temporary array
       } 
       else
       {
           temp[k++] = a[j++];
       } 
    }

    while (i <= middle) //elements that remain are also copied downto temporary array 
    {
        temp[k++] = a[i++];
    }
    while (j <= end)
    {
        temp[k++] = a[j++];
    }

    for(int c = start; c <=end; c++) //copying every element from the temporary element to the original one
    {
        a[c] = temp[c];
    }
}


void mergeSort(int a[], int start, int end)
{
    if (start >= end) //we cannot sort 0 elements
    {
        return;
    }

    int middle = (start + end) / 2; //approx middle of the array

    mergeSort(a, start, middle); //division of the array into halves, from starting point to the middle of the array
    mergeSort(a, middle+1, end); //from the middle+1(since the middle is used for the first part of the array) of the array to the end of the array
    merge(a, start, end); //

}

void binarySearch(int a[], int number, int size)
{
    int start = 0; //start can be also called as the right part of the array
    int end = size-1; //end equals to the last element of the array
    int middle;
    int find = 0; //0 equals to false in c langauge, find will be false untill we find the element

    while(start<=end) 
    {
        middle = (start + end) / 2;

        if (number == a[middle]) //if number somehow is in the middle of the array while loop will brake and stop
        {
            find = 1; //true
            break;
        }
        else if(number <= a[middle]) //otherwise it will continue to find for our element
        { 
            end = middle - 1; //shortens our searching by making it smaller
        }
        else
        {
            start = middle + 1; //shortens our searching by making it smaller
        }
    }

    if (find == 1) //in case we found our element we print the message bellow
    {
        printf("your number %d in position %d", number, middle+1);
    }
    else //otherwise we inform that the element wasn't found
    {
        printf("no number found =()");
    }
}

void printArray(int a[], int size) //basic function that prints our array
{
    for(int i = 0; i < size; i++)
    {
        printf("[%d] ", a[i]);
    }
    printf("\n");
}

int main(void)
{
    int i;
    int size;
    int number;

    printf("enter array size: ");
    scanf("%d", &size);

    int a[size];

    for (i=0;i<size;i++)
    {
       printf("%d ", i); 
       scanf("%d", &a[i]); 
    }

    printf("unsorted array: ");
    printf("\n");

    printArray(a, size);

    printf("sorted array :");
    printf("\n");

    printArray(a,size);

    merge(a, 0, size-1); 


    printf("enter the number you are looking for in a sorted array : ");
    scanf("%d", &number);

    binarySearch(a, number, size);

    
	return 0;
}
