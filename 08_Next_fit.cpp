#include <iostream>
using namespace std;

int main() {
    int m, n;

    cout << "Enter number of memory blocks: ";
    cin >> m;

    int *blocks = new int[m];

    cout << "Enter sizes of blocks:\n";
    for (int i = 0; i < m; i++) {
        cin >> blocks[i];
    }

    cout << "Enter number of processes: ";
    cin >> n;

    int *process = new int[n];

    cout << "Enter sizes of processes:\n";
    for (int i = 0; i < n; i++) {
        cin >> process[i];
    }

    int last = 0;

    for (int i = 0; i < n; i++) {
        int j = last;
        int count = 0;
        bool allocated = false;

        while (count < m) {
            if (blocks[j] >= process[i]) {
                cout << "Process " << i 
                     << " allocated to block " << j << endl;

                blocks[j] -= process[i];
                last = j;
                allocated = true;
                break;
            }

            j = (j + 1) % m;
            count++;
        }

        if (!allocated) {
            cout << "Process " << i << " not allocated\n";
        }
    }

    delete[] blocks;
    delete[] process;

    return 0;
}