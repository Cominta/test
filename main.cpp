#include <iostream>

class Stragegy
{
    public:
        virtual void sort(int* arr, int size) = 0;
};

class QuickSort : public Stragegy
{
    public:
        void sort(int* arr, int size) override
        {
            long left = 0, right = size - 1;
            int temp, middle;
            middle = arr[size / 2];

            do 
            {
                while (arr[left] < middle)
                {
                    left++;
                }

                while (arr[right] > middle)
                {
                    right--;
                }

                if (left <= right) 
                {
                    temp = arr[left];
                    arr[left] = arr[right];
                    arr[right] = temp;
                    left ++;
                    right--;
                }

            } while (left <= right);

            if (right > 0) sort(arr, right);
            if (size > left) sort(arr + left, size - left);
        };
};

class BubbleSort : public Stragegy
{
    public:
        void sort(int* arr, int size) override
        {
            for (int j = 0; j <= size; j++) 
            {      
                for (int i = 0; i <= size - j; i++) 
                {
                    if (arr[i] > arr[i + 1]) 
                    {
                        int temp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = temp;
                    }
                }
            }
        }
};

int main()
{
    const int size = 10;
    int* arr = new int[size] {2, 10, -1, 30, 100, -2, 7, 25, 83, -100};
    Stragegy* st;
    st = new QuickSort();
    st->sort(arr, size);

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}