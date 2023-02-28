#include <iostream>
using namespace std;

class SortStrategy {
public:
    int* arr;
    int size;

    SortStrategy(int* arr, int size) : arr(arr), size(size) {}
    virtual void sort(int* arr, int size) = 0;
    virtual void print() = 0;
    virtual ~SortStrategy() { delete arr; }
};

class QuickSort : public SortStrategy {

public:
    QuickSort(int* arr, int size) : SortStrategy(arr, size) {}
    void sort(int* arr, int size) override {
        long left = 0, right = size - 1;
        int temp, middle;
        middle = arr[size / 2];
        do {
            while (arr[left] < middle) {
                left++;
            }
            while (arr[right] > middle) {
                right--;
            }
            if (left <= right) {
                temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        } while (left <= right);
        if (right > 0)
            sort(arr, right);
        if (size > left)
            sort(arr + left, size - left);
    }
    void print() override {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }
};

class BubbleSort : public SortStrategy {
public:
    BubbleSort(int* arr, int size) : SortStrategy(arr, size) {}
    void sort(int* arr, int size) override {
        bool swapped;
        for (int i = 0; i < size - 1; i++) {
            swapped = false;
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (swapped == false)
                break;
        }
    }
    void print() override {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }
};

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    SortStrategy* sort = nullptr;
    cout << "BubbleSort: " << endl;
    sort = new BubbleSort(arr, n);
    sort->sort(arr, n);
    sort->print();
    cout << endl;
    cout << "QuickSort: " << endl;
    sort = new QuickSort(arr, n);
    sort->sort(arr, n);
    sort->print();
    cout << endl;
}