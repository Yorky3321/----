#include <iostream>
using namespace std;

struct SearchResult {
    int index;
    int iterations;
};

class Search {
    public:
        Search(int array[], int sizeofarr, int target) {
            arr = &array[0];
            tar = target;
            size = sizeofarr;
            count = 0;
        }

        SearchResult B_search() {
            int left = 0;
            int right = size - 1;
            int mid = size / 2 - 1;
            while (1) {
                count++;
                if (left == right) {
                    if (arr[left] != tar) return {-1, 0}; 
                    return {left, count};
                }else if (arr[mid] < tar) {
                    left = mid + 1;
                    mid = (right + left)  / 2;
                } else if (arr[mid] > tar) {
                    right = mid - 1;
                    mid = (right + left) / 2;
                }
            }
        }
    private:
        int* arr;               /* the pointer preventing allocate particular array in the memory */
        int tar;
        int size;
        int count;
};



int main() {
    int arr[] = {3, 6, 10, 11, 12, 13, 14, 15, 17, 19, 20, 22, 25, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 30;

    SearchResult res = Search(arr, size, target).B_search(); 
    int result = res.index;
    int count = res.iterations;

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
        cout << "Number of iterations: " << count << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    cout << size << endl;

    return 0;
}