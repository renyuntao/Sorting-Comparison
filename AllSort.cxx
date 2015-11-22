/*
 * Bubble Sort
 *
 */
void BubbleSort(int arr[],int length)
{
	// (length-1) is the maximum times of for loop
	for(int i = 0; i < length - 1; ++i)
	{
		bool sorted = true;

		for(int j = 0; j < length-1-i; ++j)
		{
			// Swap
			if(arr[j] > arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				sorted = false;
			}
		}

		// Check if array is already sorted
		if(sorted)
			break;
	}
}

/*
 * Quick Sort
 *
 */
void quicksort(int arr[],int low,int high)
{
	if(low < high)
	{
		int i = low , j = high;
		int pivot = arr[low];
		while(1)
		{
			// from left to right
			while(i < high && arr[i] <= pivot) ++i;

			// from right to left
			while(j > low && arr[j] > pivot) --j;

			// Swap
			if(i < j)
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			else
				break;
		}

		// Swap
		arr[low] = arr[j];
		arr[j] = pivot;

		// recursion
		if(low < j)
			quicksort(arr,low,j-1);
		if(i < high)
			quicksort(arr,j+1,high);
	}
}

/*
 * Quick Sort Variation(for data that are mostly sorted or 
 * have many duplicate element)
 */
void quicksort_variation(int a[],int lo,int hi)
{
	int i = lo, j = (lo + hi) / 2, k = hi;
	int pivot;
	if(a[k] < a[i])             // Median of 3
	{
		int tmp = a[k];
		a[k] = a[i];
		a[i] = tmp;
	}
	if(a[j] < a[i])
	{
		int tmp = a[j];
		a[j] = a[i];
		a[i] = tmp;
	}
	if(a[k] < a[j])
	{
		int tmp = a[k];
		a[k] = a[j];
		a[j] = tmp;
	}
	pivot = a[j];
	while(i <= k)               // Partition
	{
		while(a[i] < pivot)  ++i;    // Note: no '='
		while(a[k] > pivot) --k;     // Note: no '='
		if(i <= k)
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			++i;
			--k;
		}
	}
	if(lo < k)                 // recurse
		quicksort(a,lo,k);
	if(i < hi)
		quicksort(a,i,hi);
}

/*
 * Insert Sort
 *
 */
void insertsort(int arr[],int length)
{
	for(int i = 1; i < length; ++i)
	{
		int tmp = arr[i];
		int j = i - 1;
		while(j > -1 && arr[j] > tmp)
		{
			arr[j+1] = arr[j];
			--j;
		}
		arr[++j] = tmp;
	}
}

/*
 * Shell Sort
 *
 */
void shellsort(int arr[],int length)
{
	int span = length >> 1;
	while(span > 0)
	{
		for(int k = 0; k < span; ++k)
		{
			// Insert Sort
			for(int i = k; i < length - span; i += span)
			{
				int tmp = arr[i+span];
				int j = i;
				while(j > -1 && arr[j] > tmp)
				{
					arr[j+span] = arr[j];
					j -= span;
				}
				arr[j+span] = tmp;
			}
		}
		span >>= 1;
	}
}

/*
 * Select Sort
 *
 */
void selectsort(int arr[],int length)
{
	if(!arr || length < 2)
		return;
	for(int i = 0; i < length - 1; ++i)
	{
		int small = i;
		for(int j = i + 1; j < length; ++j)
		{
			if(arr[j] < arr[small])
				small = j;
		}
		if(small != i)
		{
			int tmp = arr[i];
			arr[i] = arr[small];
			arr[small] = tmp;
		}
	}
}

/*
 * Heap Sort
 *
 */
// Create Max Heap
void createMaxHeap(int arr[],int length,int root)
{
	int i = root;
	int j = 2 * i + 1;
	int tmp = arr[i];

	while(j < length)
	{
		int max = tmp;
		int p = i;
		if(arr[j] > max)
		{
			p = j;
			max = arr[j];
		}
		if(j+1 < length && arr[j + 1] > max)
		{
			p = j + 1;
		}

		// parent node's value is greater than child node's value
		if(p == i)
			break;
		else
		{
			arr[i] = arr[p];
			i = p;
			j = 2 * i + 1;
		}
	}

	arr[i] = tmp;
}

// Initial
void InitMaxHeap(int arr[],int length)
{
	for(int k = (length-1)/2; k >= 0; --k)
	{
		createMaxHeap(arr,length,k);
	}
}

// Heap Sort
void heapsort(int arr[],int length)
{
	InitMaxHeap(arr,length);

	for(int i = length-1; i > 0; --i)
	{
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;

		// adjust the root and keep the arr is a Max Heap
		createMaxHeap(arr,i,0);
	}
}
