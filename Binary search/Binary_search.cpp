#include <iostream>
using namespace std;


class Search {
    public:
        Search(int array[], int number) {
            arr = &array[0];
            num = number;
        }

        int B_search() {
            int left = 0;
            int right = arr.size() -1;
            int mid = arr.size() / 2;
            while ((right - left) > 2) {
                if (arr[mid] == num) {
                    return mid;
                } else if (arr[mid] < num) {
                    left = mid;
                    mid = (right + left) / 2;
                } else if (arr[mid] > num) {
                    right = mid;
                    mid = (right + left) / 2;
                }
            }
        }
    private:
        int* arr;               /* the pointer preventing allocate particular array in the memory */
        int num;
}