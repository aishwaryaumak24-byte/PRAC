#include <iostream>
using namespace std;

int main() {
    int page_table[10], n, logical_address, page_size;

    cout << "Enter number of pages: ";
    cin >> n;

    cout << "Enter page table (frame numbers):\n";
    for (int i = 0; i < n; i++) {
        cout << "Page " << i << " -> Frame: ";
        cin >> page_table[i];
    }

    cout << "Enter page size: ";
    cin >> page_size;

    cout << "Enter logical address: ";
    cin >> logical_address;

    int page_number = logical_address / page_size;
    int offset = logical_address % page_size;

    if (page_number >= n) {
        cout << "Invalid logical address!\n";
        return 0;
    }

    int frame_number = page_table[page_number];
    int physical_address = frame_number * page_size + offset;

    cout << "Page Number: " << page_number << endl;
    cout << "Offset: " << offset << endl;
    cout << "Frame Number: " << frame_number << endl;
    cout << "Physical Address: " << physical_address << endl;

    return 0;
}
