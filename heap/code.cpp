#include<iostream>
using namespace std;

class Maxheap {
    int *arr;
    int size;        
    int total_size;  

public:
    Maxheap(int n) {
        arr = new int[n];
        size = 0;
        total_size = n;
    }
    void insert(int value) {
        if (size >= total_size) {
            cout << "Overflow" << endl;
            return;
        }
        arr[size] = value;
        int index = size;
        size++;
        while (index > 0 && arr[(index - 1) / 2] < arr[index]) {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    void deleteMax() {
        if (size == 0) {
            cout << "Underflow" << endl;
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
    }
    void heapify(int index) {
        int largest = index;
        int leftchild = 2 * index + 1;
        int rightchild = 2 * index + 2;

        if (leftchild < size && arr[leftchild] > arr[largest]) {
            largest = leftchild;
        }
        if (rightchild < size && arr[rightchild] > arr[largest]) {
            largest = rightchild;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }
    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Maxheap() {
        delete[] arr;
    }
};

int main() {
    Maxheap m(5);
    m.insert(2);
    m.insert(5);
    m.insert(1);
    m.insert(10);
    m.insert(20);

    cout << "Heap after inserts: ";
    m.display();

    m.deleteMax();
    cout << "Heap after first delete: ";
    m.display();

    m.deleteMax();
    cout << "Heap after second delete: ";
    m.display();

    return 0;
}
