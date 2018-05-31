#include <iostream>
#include <array>
using namespace std;

class Heap
{
    public:
        Heap(int[]);
        ~Heap();

        int size;

        void BuildMaxHeap();
        void MaxHeapify(int);
        int ExtractMax();
        void Show();
    private:
        int* _data;
};
Heap::Heap(int data[])
{
    this->size = 10;
    this->_data = new int[this->size + 1];

    for (int i = 0; i <= this->size; ++i)
    {
        this->_data[i] = data[i];
    }
}
Heap::~Heap()
{
    delete[] this->_data;
}
void Heap::MaxHeapify(int index)
{
    int max = index;
    int l = index * 2; // left
    int r = l + 1; // right

    if (l <= this->size && this->_data[l] > this->_data[max])
        max = l;

    if (r <= this->size && this->_data[r] > this->_data[max])
        max = r;

    if (max != index)
    {
        swap(this->_data[max], this->_data[index]);
        MaxHeapify(max);
    }
}
void Heap::BuildMaxHeap()
{
    for (int i = this->size / 2; i; --i)
    {
        MaxHeapify(i);
    }
}
void Heap::Show()
{
    for (int i = 1; i <= this->size; ++i)
    {
        cout << this->_data[i] << " ";
    }

    cout << endl;
}
int Heap::ExtractMax()
{
    if (this->size == 0)
        throw "Heap underflow.";

    int max = this->_data[1];
    this->_data[1] = this->_data[this->size];
    this->size--;
    MaxHeapify(1);
    return max;
}

int main()
{
    int data[] = { NULL, 1, 14, 10, 8, 7, 9, 3, 2, 4, 6 };
    Heap heap(data);
    heap.BuildMaxHeap(); // (NULL) 14 8 10 4 7 9 3 2 1 6
    heap.Show();

    while (heap.size)
    {
        cout << heap.ExtractMax();
    }

    system("pause");
}