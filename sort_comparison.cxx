#include<iostream>
#include<ctime>
#include<algorithm>
#include<tuple>
#include<random>
#include"AllSort.h"
#define ITEM_NUM 9
#define MAX_RAND_NUM 5000000
using std::cout;
using std::cin;
using std::endl;

/*
 * Show Information
 *
 */
void showInfo()
{
	cout<<"\n########################### Sort Comparison ############################\n\n";
	cout<<"Please select the algorithm of sort below you want to compare:\n\n";
	cout<<"   1. Bubble Sort\n";
	cout<<"   2. Quick Sort\n";
	cout<<"   3. Quick Sort Variation(for data have many duplicate element)\n";
	cout<<"   4. Insert Sort\n";
	cout<<"   5. Shell Sort\n";
	cout<<"   6. Select Sort\n";
	cout<<"   7. Heap Sort\n";
	cout<<"   8. Merge Sort\n";
	cout<<"   9. Select All Above\n\n";
	cout<<"Input you selection and separated by space [1-"<<ITEM_NUM<<"]: ";
}

/*
 * Get Input
 *
 */
std::tuple<int,bool> getInput(int input[ITEM_NUM],int &numberOfData,int &seed)
{
	int select;

	// Initial input[]
	for(int i = 0; i < ITEM_NUM-1; ++i)
		input[i] = 0;

	int selectItemNum = 0;
	bool selectAll = false;

	while(selectItemNum < ITEM_NUM && cin>>select)
	{
		// Check input whether is valid
		while(select < 1 || select > ITEM_NUM)
		{
			cout<<"Invalid input,please input again [1-"<<ITEM_NUM<<"}: ";
			cin>>select;
		}

		if(select == ITEM_NUM)
		{
			selectAll = true;
			break;
		}

		// Save the input
		for(int i = 0; i < ITEM_NUM; ++i)
		{
			if(input[i] == 0)
			{
				input[i] = select;
				break;
			}
		}

		++selectItemNum;

		// The input is terminate when you press the 'Entry' key
		if(cin.get() == '\n')
			break;
	}

	cout<<"\n*******************************************************************\n";
	cout<<"Input the number of data you want to sort(less than "<<MAX_RAND_NUM<<"):";
	cin>>numberOfData;

	// Check the input whether is valid
	while(numberOfData < 1 || numberOfData > MAX_RAND_NUM)
	{
		cout<<"Invalid input,please input again(less than "<<MAX_RAND_NUM<<"):";
		cin>>numberOfData;
	}

	cout<<"\n******************************************************************\n";
	cout<<"Now please input the seed for generate the random:";
	cin>>seed;
	cout<<"\n$$$$$$$$$$$$$$$$$$$$ Result $$$$$$$$$$$$$$$$$$$$$\n\n";
	return std::make_pair(selectItemNum,selectAll);
}

/*
 * Generate random data
 *
 */
void generateRandData(int *randArr,int size,int seed)
{
	std::uniform_int_distribution<unsigned> u(0,10000);
	std::default_random_engine e(seed);
	for(int i = 0; i < size; ++i)
		randArr[i] = u(e);
}

int main()
{
	int numberOfData = 0;
	int seed = 0;
	int arr[ITEM_NUM] = {0,};
	int selectItemNum;
	bool selectAll;

	showInfo();
	std::tie(selectItemNum,selectAll) = getInput(arr,numberOfData,seed);
	
	int *randArr = new int[numberOfData];
	generateRandData(randArr,numberOfData,seed);

	

	// Should call more than one sort function
	if(selectAll || selectItemNum > 1)
	{
		int *copy_arr = new int[numberOfData];	
		std::copy(randArr,randArr+numberOfData,copy_arr);


		// Should call all sort function
		if(selectAll)
		{
			// Bubble Sort
			clock_t start = clock();
			BubbleSort(copy_arr,numberOfData);
			clock_t end = clock();
			cout<<"Bubble Sort run time: "<<float(end-start)/CLOCKS_PER_SEC<<endl;

			std::copy(randArr,randArr+numberOfData,copy_arr);
			
			// Quick Sort
			start = clock();
			quicksort(copy_arr,0,numberOfData-1);
			end = clock();
			cout<<"QuickSort run time: "<<float(end-start)/CLOCKS_PER_SEC<<endl;

			std::copy(randArr,randArr+numberOfData,copy_arr);

			// Quick Sort Variation (for data that are mostly sorted or 
			// have many duplicate element)
			start = clock();
			quicksort_variation(copy_arr,0,numberOfData-1);
			end = clock();
			cout<<"Quick Sort Variation run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;

			std::copy(randArr,randArr+numberOfData,copy_arr);

			// Insert Sort
			start = clock();
			insertsort(copy_arr,numberOfData);
			end = clock();
			cout<<"Insert Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;

			std::copy(randArr,randArr+numberOfData,copy_arr);

			// Shell Sort
			start = clock();
			shellsort(copy_arr,numberOfData);
			end = clock();
			cout<<"Shell Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
			
			std::copy(randArr,randArr+numberOfData,copy_arr);

			// Select Sort
			start = clock();
			selectsort(copy_arr,numberOfData);
			end = clock();
			cout<<"Select Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;

			std::copy(randArr,randArr+numberOfData,copy_arr);

			// Heap Sort
			start = clock();
			heapsort(copy_arr,numberOfData);
			end = clock();
			cout<<"Heap Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;

			std::copy(randArr,randArr+numberOfData,copy_arr);

			// Merge Sort
			start = clock();
			mergesort(copy_arr,numberOfData);
			end = clock();
			cout<<"Merge Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
		}

		// Should call more than one sort function
		else
		{
			clock_t start,end;
			for(int i = 0; i < ITEM_NUM; ++i)
			{
				if(arr[1] == 0)
					break;

				std::copy(randArr,randArr+numberOfData,copy_arr);

				switch(arr[i])
				{
					// Bubble Sort
					case 1:
						start = clock();
						BubbleSort(copy_arr,numberOfData);
						end = clock();
						cout<<"Bubble Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
						break;

					// Quick Sort
					case 2:
						start = clock();
						quicksort(copy_arr,0,numberOfData-1);
						end = clock();
						cout<<"QuickSort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
						break;

					// Quick Sort Variation
					case 3:
						start = clock();
						quicksort_variation(copy_arr,0,numberOfData-1);
						end = clock();
						cout<<"Quick Sort Variation run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
						break;

					// Insert Sort
					case 4:
						start = clock();
						insertsort(copy_arr,numberOfData);
						end = clock();
						cout<<"Insert Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
						break;

					// Shell Sort
					case 5:
						start = clock();
						shellsort(copy_arr,numberOfData);
						end = clock();
						cout<<"Shell Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
						break;

					// Select Sort
					case 6:
						start = clock();
						selectsort(copy_arr,numberOfData);
						end = clock();
						cout<<"Select Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;

					// Heap Sort
					case 7:
						start = clock();
						heapsort(copy_arr,numberOfData);
						end = clock();
						cout<<"Heap Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;

					// Merge Sort
					case 8:
						start = clock();
						mergesort(copy_arr,numberOfData);
						end = clock();
						cout<<"Merge Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
				}
			}
		}

		delete [] copy_arr;
	}
	// Call only one sort function
	else
	{
		
		clock_t start,end;
		switch(arr[0])
		{
			// Bubble Sort
			case 1:
				start = clock();
				BubbleSort(randArr,numberOfData);
				end = clock();
				cout<<"Bubble Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
				break;

			// Quick Sort
			case 2:
				start = clock();
				quicksort(randArr,0,numberOfData-1);
				end = clock();
				cout<<"QuickSort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
				break;

			// Quick Sort variation
			case 3:
				start = clock();
				quicksort_variation(randArr,0,numberOfData-1);
				end = clock();
				cout<<"Quick Sort Variation run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
				break;
			
			// Insert Sort
			case 4:
				start = clock();
				insertsort(randArr,numberOfData);
				end = clock();
				cout<<"Insert Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
				break;

			// Shell Sort
			case 5:
				start = clock();
				shellsort(randArr,numberOfData);
				end = clock();
				cout<<"Shell Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
				break;

			// Select Sort
			case 6:
				start = clock();
				selectsort(randArr,numberOfData);
				end = clock();
				cout<<"Select Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;

			// Heap Sort
			case 7:
				start = clock();
				heapsort(randArr,numberOfData);
				end = clock();
				cout<<"Heap Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;

			// Merge Sort
			case 8:
				start = clock();
				mergesort(randArr,numberOfData);
				end = clock();
				cout<<"Merge Sort run time: "<<static_cast<double>(end-start)/CLOCKS_PER_SEC<<endl;
		}
	}

	cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";

	delete [] randArr;

	return 0;
}
