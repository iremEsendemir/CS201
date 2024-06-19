/*
 Name: Emine İrem Esendemir
 Student ID: 22202103
 Date: 08/04/2024
 */

#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

int* deepCopy(int* original, int size){
    if(size == 0){
        return nullptr;
    }
    int* toReturn = new int[size];
    for (int i = 0; i < size; i++) {
        toReturn[i] = original[i];
    }
    return toReturn;
}

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void insertionSort(int* arr, int n, int& second) {
    second = 0;
    for (int unsorted = 1; unsorted < n; ++unsorted) {
        int nextItem = arr[unsorted];
        second += 5; //new
        int loc = unsorted;
        for ( ;(loc > 0) && (arr[loc-1] > nextItem); --loc, second++){
            arr[loc] = arr[loc-1];
            second += 5;
        }
        arr[loc] = nextItem;
        second += 5;
      }
}

int indexOfLargest(const int* arr, int size, int&second) {
    int indexSoFar = 0;
    for (int currentIndex=1; currentIndex<size;++currentIndex){
        if (arr[currentIndex] > arr[indexSoFar])
            indexSoFar = currentIndex;
        second++;
    }
    return indexSoFar;
}

void selectionSort(int* arr, int n, int& second) {
    second = 0;
    for (int last = n-1; last >= 1 ; --last) {
        int largest = indexOfLargest(arr, last+1, second);
        swap(arr[largest], arr[last]);
        second += 15;
    }
}

void bubbleSort(int* arr, int n, int& second){
    second = 0;
    bool sorted = false;
    for (int pass = 1; (pass < n) && !sorted; ++pass) {
        sorted = true;
        for (int index = 0; index < n-pass; ++index) {
            int nextIndex = index + 1;
            if (arr[index] > arr[nextIndex]) {
                swap(arr[index], arr[nextIndex]);
                sorted = false;
                second += 15;
            }
            second++;
        }
    }
}

void partition(int* arr, int first, int last, int &pivotIndex, int& second){
    int pivot = arr[first];
    second += 5;
    int lastS1 = first;
    int firstUnknown = first + 1;
    for ( ; firstUnknown <= last; ++firstUnknown) {
        if (arr[firstUnknown] < pivot) {
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1]);
            second += 15;
        }
        second++;//for the if's comparison
    }
    swap(arr[first], arr[lastS1]);
    second += 15;
    pivotIndex = lastS1;
}

void quickSortRecursive(int* arr, int first, int last, int& second) {
    int pivotIndex;
    if (first < last) {
        partition(arr, first, last, pivotIndex, second);
        quickSortRecursive(arr, first, pivotIndex-1, second);
        quickSortRecursive(arr, pivotIndex+1, last, second);
    }
}

void quickSort(int* arr, int n, int& second){
    second = 0;
    quickSortRecursive(arr, 0, n-1, second);
}

void quickSortForTwoWorker(int* arr, int n, int& second1, int&second2){
    second1 = 0;
    second2 = 0;
    int pivotIndex = n;
    partition(arr, 0, n-1, pivotIndex, second1);
    quickSortRecursive(arr, 0, pivotIndex-1, second1);
    quickSortRecursive(arr, pivotIndex+1, n-1, second2);
}

int *generate_random_array(int size){
    if(size==0){
        return nullptr;
    }
    int* arr = new int[size];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand();
    }
    return arr;
}

int *generate_almost_sorted_array(int size){
    srand((unsigned int)time(NULL));
    int* random_array = generate_random_array(size);
    //sort
    int second = 0;
    quickSort(random_array, size, second);
    int swap_count = size * 0.03;
    if(swap_count < 1){
        swap_count = 1;
    }
    for (int i = 0; i < swap_count; i++) {
        int first_index = std::rand()%size;
        int second_index = size - first_index;
        int temp = random_array[first_index];
        random_array[first_index] = random_array[second_index];
        random_array[second_index] = temp;
    }
    return random_array;
}

int main() {
    int** originalOnes = new int*[10];
    for(int i = 0; i < 10; i++){
        originalOnes[i] = generate_random_array(pow(2, i+3));
    }
    
    //for insertion
    int** forInsertion = new int*[10];
    for(int i = 0; i < 10; i++){
        forInsertion[i] = deepCopy(originalOnes[i], pow(2, i+3));
    }
    
    //for selection
    int** forSelection = new int*[10];
    for(int i = 0; i < 10; i++){
        forSelection[i] = deepCopy(originalOnes[i], pow(2, i+3));
    }
    
    //for bubble
    int** forBubble = new int*[10];
    for(int i = 0; i < 10; i++){
        forBubble[i] = deepCopy(originalOnes[i], pow(2, i+3));
    }
    
    //for quick
    int** forQuick = new int*[10];
    for(int i = 0; i < 10; i++){
        forQuick[i] = deepCopy(originalOnes[i], pow(2, i+3));
    }
    
    //random and insertion sort
    for (int i = 3; i < 13; i++) {
        int size = pow(2, i);
        int second = 0;
        int* arr = forInsertion[i-3];
        insertionSort(arr, size, second);
        cout << "Size: " << size << ", sorting random array with insertion sort: " << second << " second"<<  endl;
        delete[] arr;
    }
    
    delete[] forInsertion;
    
    cout << endl << endl;
    
    //random and selection sort
    for (int i = 3; i < 13; i++) {
        int size = pow(2, i);
        int second = 0;
        int* arr = forSelection[i-3];
        selectionSort(arr, size, second);
        cout << "Size: " << size << ", sorting random array with selection sort: " << second<< " second" << endl;
        delete[] arr;

    }
    
    delete[] forSelection;
    
    cout << endl << endl;
    
    //random and bubble sort
    for (int i = 3; i < 13; i++) {
        int size = pow(2, i);
        int second = 0;
        int* arr = forBubble[i-3];
        bubbleSort(arr, size, second);
        cout << "Size: " << size << ", sorting random array with bubble sort: " << second << " second"<< endl;
        delete[] arr;
    }
    
    delete[] forBubble;
    cout << endl << endl;
    
    
    //random and quick sort
    for (int i = 3; i < 13; i++) {
        int size = pow(2, i);
        int second = 0;
        int* arr = forQuick[i-3];
        quickSort(arr, size, second);
        cout << "Size: " << size << ", sorting random array with quick sort: " << second << " second"<< endl;
        delete[] arr;
    }
    delete[] forQuick;
    cout << endl << endl;
    
    for (int i = 0; i < 10; i++) {
        delete[] originalOnes[i];
    }
    
    delete[] originalOnes;
    
    
    originalOnes = new int*[10];
    for(int i = 0; i < 10; i++){
        originalOnes[i] = generate_almost_sorted_array(pow(2, i+3));
    }
    
    //for insertion
    forInsertion = new int*[10];
    for(int i = 0; i < 10; i++){
        forInsertion[i] = deepCopy(originalOnes[i], pow(2, i+3));
    }
    
    //for selection
    forSelection = new int*[10];
    for(int i = 0; i < 10; i++){
        forSelection[i] = deepCopy(originalOnes[i], pow(2, i+3));
    }
    
    //for bubble
    forBubble = new int*[10];
    for(int i = 0; i < 10; i++){
        forBubble[i] = deepCopy(originalOnes[i], pow(2, i+3));
    }
    
    //for quick
    forQuick = new int*[10];
    for(int i = 0; i < 10; i++){
        forQuick[i] = deepCopy(originalOnes[i], pow(2, i+3));
    }
    
    //%6 and insertion sort
    for (int i = 3; i < 13; i++) {
        int size = pow(2, i);
        int second = 0;
        int* arr = forInsertion[i-3];
        insertionSort(arr, size, second);
        cout << "Size: " << size << ", sorting almost sorted array with insertion sort: " << second << " second"<< endl;
        delete[] arr;

    }
    
    delete[] forInsertion;
    
    cout << endl << endl;
    
    //%6 and selection sort
    for (int i = 3; i < 13; i++) {
        int size = pow(2, i);
        int second = 0;
        int* arr = forSelection[i-3];
        selectionSort(arr, size, second);
        cout << "Size: " << size <<", sorting almost sorted array with selection sort: " << second << " second"<< endl;
        delete[] arr;

    }
    delete[] forSelection;

    cout << endl << endl;
    
    //%6 and bubble sort
    for (int i = 3; i < 13; i++) {
        int size = pow(2, i);
        int second = 0;
        int* arr = forBubble[i-3];
        bubbleSort(arr, size, second);
        cout << "Size: " << size << ", sorting almost sorted array with bubble sort: " << second << " second"<< endl;
        delete[] arr;

    }
    delete[] forBubble;
    cout << endl << endl;
    
    //%6 and quick sort
    for (int i = 3; i < 13; i++) {
        int size = pow(2, i);
        int second = 0;
        int* arr = forQuick[i-3];
        quickSort(arr, size, second);
        cout << "Size: " << size << ", sorting almost sorted array with quick sort: " << second << " second"<< endl;
        delete[] arr;
    }
    
    delete[] forQuick;
    
    for(int i = 0; i < 10; i++){
        delete[] originalOnes[i];
    }
    
    delete[] originalOnes;
    originalOnes = new int*[10];
    for(int i = 0; i < 10; i++){
        originalOnes[i] = generate_random_array(pow(2, i+3));
    }
    for (int i = 3; i < 13; i++) {
        int size = pow(2, i);
        int second1 = 0;
        int second2 = 0;
        int* arr = originalOnes[i-3];
        quickSortForTwoWorker(arr, size, second1, second2);
        cout << "Size: " << size << ", sorting random array with 2 people, Their seconds: First: " << second1 << ", Second: "<< second2 << endl;
        cout << "Maximum time: " << max(second1, second2)<<endl;
        cout << "Total Time: " << second1 + second2 << endl;
        delete[] arr;
    }
    
    delete[] originalOnes;
    return 0;
}
