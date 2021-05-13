#pragma once
#include<iostream>
using namespace std;


class selectionSort {
	public:
		selectionSort(std::vector<int> &arr, int N);
		void sort(std::vector<int> &arr, int N);
		void swap(std::vector<int> &arr, int i, int j);

};
selectionSort::selectionSort(std::vector<int> &arr, int N) {
	sort(arr, N);
}
void selectionSort::sort(std::vector<int> &arr, int N) {
	int i, j, min_idx;
	for (i = 0; i < N - 1; i++){ 
		min_idx = i;
		for (j = i + 1; j < N; j++) {
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		swap(arr,min_idx,i);
		/*for (auto i : arr) {
			cout << i << " ";
		}
		cout << endl;*/
		visual(arr);
	}
}
void selectionSort::swap(std::vector<int> &arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


class mergeSort {
	public:
		mergeSort(std::vector<int> &arr, int N);
		void sort(std::vector<int> &arr, std::vector<int> &aux, int low,int high);
		void merge(std::vector<int> &arr, std::vector<int> &aux, int low, int mid,int high);
};
mergeSort::mergeSort(std::vector<int> &arr, int N) {
	std::vector<int> aux(N,0);
	for (int i = 0; i < N; i++) {
		aux[i] = arr[i];
	}
	sort(arr, aux, 0, N - 1);
}
void mergeSort::sort(std::vector<int> &arr, std::vector<int> &aux, int low, int high) {
	if (low >= high)
		return;
	int mid = low + (high - low) / 2;
	sort(arr, aux, low, mid);
	visual(arr);
	sort(arr, aux, mid + 1, high);
	visual(arr);
	merge(arr, aux, low, mid, high);
	visual(arr);
}
void mergeSort::merge(std::vector<int> &arr, std::vector<int> &aux, int low, int mid, int high) {
	int i = low, j = mid + 1;
	for (int i = 0; i < N; i++) {
		aux[i] = arr[i];
	}
	for (int k = low; k <= high; k++) {
		if (i > mid) {
			arr[k] = aux[j++];
		}
		else if (j > high) {
			arr[k] = aux[i++];
		}
		else if (aux[i] > aux[j]) {
			arr[k] = aux[j++];
		}
		else {
			arr[k] = aux[i++];
		}
	}
}


class insertionSort {
	public:
		insertionSort(std::vector<int> &arr, int N);
		void sort(std::vector<int> &arr, int N);
		void swap(std::vector<int> &arr, int i, int j);
};
insertionSort::insertionSort(std::vector<int> &arr, int N) {
	sort(arr, N);
}
void insertionSort::sort(std::vector<int> &arr, int N) {
	for (int i = 1; i < N; i++){
		for (int j = i; j >= 1; j--){
			if (arr[j] < arr[j - 1]){
				swap(arr, j, j - 1);
				visual(arr);
			}
			else
				break;
		}
	}
}
void insertionSort::swap(std::vector<int> &arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


class quickSort {
public:
	quickSort(std::vector<int> &arr, int N);
	void sort(std::vector<int> &arr, int lo, int hi);
	int part(std::vector<int> &arr, int lo, int hi);
	void swap(std::vector<int> &arr, int i, int j);
};
quickSort::quickSort(std::vector<int> &arr, int N) {
	sort(arr, 0, N-1);
}
void  quickSort::sort(std::vector<int> &arr, int low, int high){
	if (low < high){
		int pi = part(arr, low, high);
		sort(arr, low, pi - 1);
		sort(arr, pi + 1, high);
	}
}
int quickSort::part(std::vector<int> &arr, int low, int high){
	int pivot = arr[high]; 
	int i = (low - 1); 
	for (int j = low; j <= high - 1; j++){
		if (arr[j] < pivot){
			i++;
			swap(arr, i, j);
			visual(arr);
		}
	}
	swap(arr,i+1,high);
	//visual(arr);
	return (i + 1);
}
void quickSort::swap(std::vector<int> &arr, int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


class shellSort {
	public:
		shellSort(std::vector<int> arr, int N);
		void sort(std::vector<int> arr, int N);
};
shellSort::shellSort(std::vector<int> arr, int N){
	sort(arr, N);
}
void shellSort::sort(std::vector<int> arr, int N){
	for (int gap = N / 2; gap > 0; gap /= 2){
		for (int i = gap; i < N; i += 1){
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
			visual(arr);
		}
	}

}


class binarySearch {
	public:
		binarySearch(std::vector<int> &arr, int N, int x);
		void search(std::vector<int> &arr, int l, int r, int x);
};
binarySearch::binarySearch(std::vector<int> &arr, int N, int x) {
	search(arr, 0, arr.size() - 1, x);
}
void binarySearch::search(std::vector<int> &arr, int l, int r, int x) {
	if(r >= l) {
		int mid = l + (r - l) / 2;
		visualSearch(arr, mid, arr[mid]);
		if (arr[mid] == x) {
			visualSearch(arr, mid, arr[mid]);
		}
		if (arr[mid] > x)
			search(arr, l, mid - 1, x);
		else
			search(arr, mid + 1, r, x);
	}
}
