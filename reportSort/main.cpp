#include"dataGenerator.h"
#include"Sort.h"

int main()
{
	//quickSort(a, 0, n - 1);
	//bubbleSort(a, n);
	//shakerSort(a, n);
	//selectionSort(a, n);
	//inserttionSort(a, n);
	//heapSort(a, n);
	//mergeSort(a, 0, n - 1);
	//shellSort(a, n);
	//binaryInserttionSort(a, n);
	//countingSort(a, n);
	//radixSort(a, n);
	//flashSort(a, n);
	int size[5] = {3000, 10000, 30000, 100000, 300000 };
	int type = 0;
	ofstream ofs;
	ofs.open("result.txt", ios:: out);
	while (type < 4)
	{
		switch (type)
		{
		case 0:
			ofs << "RANDOM DATA" << endl;
			break;
		case 1:
			ofs << "SORTED DATA" << endl;
			break;
		case 2:
			ofs << "REVERSE DATA" << endl;
			break;
		case 3:
			ofs << "NEARLY SORTED DATA" << endl;
			break;
		};
		for (int j = 0; j < 5; j++)
		{
			int n = size[j];
			int *a = new int[n];
			int *b = new int[n];
			GenerateData(a, n, type);
			ofs << "==============" << n << "==============" << endl << endl;
			for (int i = 0; i < n; i++)
				b[i] = a[i];
			auto begin = clock();
			bubbleSort(b, n);
			double timeUsed = ((double)clock() - begin);
			ofs << "Bubble Sort: " << timeUsed << "ms" << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			shakerSort(b, n);
			timeUsed = ((double)clock() - begin);
			ofs << "Shaker Sort: " << timeUsed << "ms" << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			selectionSort(b, n);
			timeUsed = ((double)clock() - begin);
			ofs << "Selection Sort: " << timeUsed << "ms" << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			insertionSort(b, n);
			timeUsed = ((double)clock() - begin);
			ofs << "Insertion Sort: " << timeUsed << "ms" << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			binaryInsertionSort(b, n);
			timeUsed = ((double)clock() - begin);
			ofs << "Binary Insertion Sort: " << timeUsed << "ms" << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			auto begin = clock();
			shellSort(b, n);
			auto timeUsed = ((double)clock() - begin);
			ofs << "Shell Sort: " << timeUsed << "ms" << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			heapSort(b, n);
			timeUsed = ((double)clock() - begin);
			ofs << "Heap Sort: " << timeUsed << "ms" << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			mergeSort(b, 0, n - 1);
			timeUsed = ((double)clock() - begin);
			ofs << "Merge Sort: " << timeUsed << "ms" << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			quickSort(b, 0, n - 1);
			timeUsed = ((double)clock() - begin);
			ofs << "Quick Sort: " << timeUsed << "ms" << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			countingSort(b, n);
			timeUsed = ((double)clock() - begin);
			ofs << "Counting Sort: " << timeUsed << "ms" << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			radixSort(b, n);
			timeUsed = ((double)clock() - begin);
			ofs << "Radix Sort: " << timeUsed << "ms" << endl;

			for (int i = 0; i < n; i++)
				b[i] = a[i];
			begin = clock();
			flashSort(b, n);
			timeUsed = ((double)clock() - begin);
			ofs << "Flash Sort: " << timeUsed << "ms" << endl;

			ofs << endl;
			delete[]a;
			delete[]b;
		}
		type++;
		
	}
	ofs.close();
	system("pause");
	return 0;
}