//P1177 【模板】快速排序
#include <cstdio>
#include <algorithm>

void quick_sort(int *array, int low, int high);
int partition(int *array, int low, int high);

int main()
{
    int n;
    int array[100000];
    scanf("%d", &n);
    for (int i = 0; i < n; scanf("%d", &array[i++]))
        ;

    quick_sort(array, 0, n - 1);

    for (int i = 0; i < n; printf("%d ", array[i++]))
        ;
}

void quick_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(array, low, high);
        quick_sort(array, low, pivot);
        quick_sort(array, pivot + 1, high);
    }
}

int partition(int *array, int low, int high)
{
    int mid = (low + high) / 2;
    std::swap(array[mid], array[low]);
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i = i + 1;
        } while (array[i] < pivot);

        do
        {
            j = j - 1;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        std::swap(array[i], array[j]);
    }
}
