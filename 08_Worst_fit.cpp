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

    for (int i = 0; i < n; i++) {
        int worstIdx = -1;

        for (int j = 0; j < m; j++) {
            if (blocks[j] >= process[i]) {
                if (worstIdx == -1 || blocks[j] > blocks[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1) {
            cout << "Process " << i 
                 << " allocated to block " << worstIdx << endl;

            blocks[worstIdx] -= process[i];
        } else {
            cout << "Process " << i << " not allocated\n";
        }
    }

    delete[] blocks;
    delete[] process;

    return 0;
}