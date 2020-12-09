#include"Sort.h"
void bubbleSort(int a[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		bool swapped = false;
		//day max ve cuoi mang
		for (int j = 0; j < i; j++)
			if (a[j] > a[j + 1])
			{
				swapped = true;
				HoanVi(a[j], a[j + 1]);
			}
		if (!swapped)
			return;
	}
}

void shakerSort(int a[], int n)
{
	int left = 0;
	int right = n - 1;
	int k = 0;
	for (int i = left; i <= right; i++)
	{
		bool swapped = false;
		//day max ve cuoi mang
		for (int j = left; j < right; j++)
			if (a[j] > a[j + 1])
			{
				swapped = true;
				HoanVi(a[j], a[j + 1]);
				k = j;
			}
		if (!swapped)
			return;
		right = k;
		//day min ve dau mang
		swapped = false;
		for (int j = right; j > left; j--)
			if (a[j] < a[j - 1])
			{
				swapped = true;
				HoanVi(a[j], a[j - 1]);
				k = j;
			}
		if (!swapped)
			return;
		left = k;
	}
}

void selectionSort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = a[i];
		int minIndex = i;
		for (int j = i; j < n; j++)
			if (a[j] < a[i])
			{
				min = a[j];
				minIndex = j;
			}
		HoanVi(a[i], a[minIndex]);
	}
}
void insertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (a[k] > key && k >= 0)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}

int partition(int a[], int first, int last)
{
	int pivot = a[(first + last) / 2];
	int i = first;
	int j = last;
	int tmp;
	while (i <= j)
	{
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
	}
	return i;
}
void quickSort(int a[], int first, int last)
{
	int index = partition(a, first, last);
	if (first < index - 1)
		quickSort(a, first, index - 1);
	if (index < last)
		quickSort(a, index, last);
}

void heapRebuild(int a[], int pos, int n)
{

	while (2 * pos + 1 < n)
	{
		int j = 2 * pos + 1;
		if (j < n - 1)
			if (a[j] < a[j + 1])
				j = j + 1;
		if (a[pos] >= a[j])
			return;
		HoanVi(a[pos], a[j]);
		pos = j;
	}
}
void heapConstruct(int a[], int n)
{
	for (int i = (n - 1) / 2; i >= 0; i--)
		heapRebuild(a, i, n);
}
void heapSort(int a[], int n)
{
	heapConstruct(a, n);
	int r = n - 1;
	while (r > 0)
	{
		HoanVi(a[0], a[r]);
		heapRebuild(a, 0, r);
		r--;
	}
}

void merge(int a[], int first, int mid, int last)
{
	int n1 = mid - first + 1;
	int n2 = last - mid;
	int *L = new int[n1];
	int *R = new int[n2];
	for (int i = 0; i < n1; i++)
		L[i] = a[first + i];
	for (int j = 0; j < n2; j++)
		R[j] = a[mid + j + 1];
	int i = 0;
	int j = 0;
	int k = first;
	while (i < n1 && j < n2)
		a[k++] = (L[i] < R[j]) ? L[i++] : R[j++];

	while (j < n2)
		a[k++] = R[j++];
	while (i < n1)
		a[k++] = L[i++];
	delete[] L;
	delete[] R;
}
void mergeSort(int a[], int first, int last)
{
	if (first < last)
	{
		int mid = first + (last - first) / 2;
		mergeSort(a, first, mid);
		mergeSort(a, mid + 1, last);
		merge(a, first, mid, last);
	}
}
void shellSort(int a[], int n)
{
	for (int interval = n / 2; interval > 0; interval /= 2)
	{
		for (int i = interval; i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
				a[j] = a[j - interval];
			a[j] = temp;
		}
	}
}
int binarySearch(int a[], int first, int item, int last)
{
	while (true)
	{
		if (first >= last)
			return (a[first] > item) ? first : first + 1;
		int mid = (first + last) / 2;
		if (a[mid] == item)
			return mid + 1;
		if (a[mid] < item)
			first = mid + 1;
		else
			last = mid - 1;
	}
}
void binaryInsertionSort(int a[], int n)
{
	int i, loc, j, k, selected;
	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = a[i];
		loc = binarySearch(a, selected, 0, j);
		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}
void countingSort(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];

	int *count = new int[max + 1];
	for (int i = 0; i <= max; i++)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[a[i]]++;

	for (int i = 1; i <= max; i++)
		count[i] += count[i - 1];

	int *temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; i < n; i++)
		a[i] = temp[i];
	delete[] count;
	delete[] temp;
}

void radixSort(int a[], int n)
{
	int *b = new int[n];
	int m = a[0], exp = 1;

	for (int i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];

	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (int i = n - 1; i >= 0; i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		for (int i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
	delete[] b;
}

void flashSort(int a[], int n)
{
	int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal)
			minVal = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == minVal)
		return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	HoanVi(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1*(flash - minVal));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort(a, n);
}
