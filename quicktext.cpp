#include<iostream>
void swap(int& a,int& b)
{
	int t = a;
	a=b;
	b=t;
}
int partition(int a[], int left, int right, int pivotIndex)
{
    int pivot = a[pivotIndex];
    do
    {
        while (a[left] < pivot) left++;
        while (a[right] > pivot) right--;
        if (left < right && a[left] != a[right])
        {
            swap(a[left], a[right]);
        }
        else
        {
            return right;
        }
    }
    while (left < right);
    return right;
}
void quicksort(int a[], int left, int right)
{
    if (left < right)
    {
        int pivot = (left + right) / 2; // middle
        int pivotNew = partition(a, left, right, pivot);
        quicksort(a, left, pivotNew - 1);
        quicksort(a, pivotNew + 1, right);
    }
}

using namespace std;

void printArray(int thearray[], int count)
{
    for (int i=0; i<count; ++i)
    {
        cout << thearray[i] << " ";
    }
    cout << endl;
}
void arraySortingTests()
{
// unique unsorted
int numbers1[] = {14, 17, 11, 13, 19, 16, 12, 15, 18, 10};
int numbers2[] = {19, 16, 10, 12, 14, 17, 13, 18, 15, 11};
// already sorted
int numbers3[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
// reverse sorted
int numbers4[] = {19, 18, 17, 16, 15, 14, 13, 12, 11, 10};
// all duplicates
int numbers5[] = {7, 7, 7, 7, 7};
// 1 pair
int numbers6[] = {14, 17, 11, 13, 19, 16, 12, 15, 18, 14};
// 1 pair at start
int numbers7[] = {14, 14, 17, 11, 13, 19, 16, 12, 15, 18};
// multiple duplicates
int numbers8[] = {14, 14, 14, 13, 13, 13, 13, 12, 12, 12};
int numbers9[] = {12};
int numbers10[] = {12,10};
quicksort(numbers1, 0, 9);
printArray(numbers1, 10);
quicksort(numbers2, 0, 9);
printArray(numbers2, 10);
quicksort(numbers3, 0, 9);
printArray(numbers3, 10);
quicksort(numbers4, 0, 9);
printArray(numbers4, 10);
quicksort(numbers5, 0, 4);
printArray(numbers5, 5);
quicksort(numbers6, 0, 9);
printArray(numbers6, 10);
quicksort(numbers7, 0, 9);
printArray(numbers7, 10);
quicksort(numbers8, 0, 9);
printArray(numbers8, 10);
quicksort(numbers9, 0, 0);
printArray(numbers9, 1);
quicksort(numbers10, 0, 1);
printArray(numbers10, 2);
}
int main()
{
    arraySortingTests();
    return 0;
}
