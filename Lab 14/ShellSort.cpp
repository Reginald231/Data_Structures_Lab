#include <cstdlib>
#include <cassert>
#include <ctime>  // used in initialization of random number generator
#include <iostream>
#include<time.h>//useful for seeds in random number generators.

using namespace std;

template <typename T>
bool is_sorted (T* a, size_t size) {
    for (int i = 1; i < size; i++) {
        if (a[i-1] > a[i])
        return false;
    }
        return true;
// precondition: a is not NULL
// returns: whether array a is sorted
}
template <typename T>
void shell_sort (T* a, size_t size){
size_t gap = size / 2;

while(gap > 0){
    
int j = 0;
    
for(int i = gap; i < size; i++){

    int temp = a[i];
        for(j = i; j >= gap && a[j - gap] > temp; j-=gap){
             a[j] = a[j-gap];
            }
        a[j] = temp;
        }
        gap = gap / 2;
    }
}

int* create_array (size_t size){// returns an array with size random integers

    srand(time(NULL));//random number generator.

    int *a = new int[size];

    for(int i = 0; i < size; i++){

        a[i] = rand() % (size+1);
    }
    return a;
}

int main ()
{
    size_t size = 1000;
    int* a = create_array (size);
    shell_sort (a, size);
    assert (is_sorted (a, size));

    cout << "Below is the sorted array of 1000 elements:\n";

    for(int i = 0; i < size; i++){
        cout << a[i] << endl;
    }
    delete a;
    return EXIT_SUCCESS;
}
