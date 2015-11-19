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

