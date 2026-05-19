#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    int allocation[n][m], max[n][m], need[n][m], available[m];

    cout << "\nEnter Allocation Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> allocation[i][j];

    cout << "\nEnter Max Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> max[i][j];

    cout << "\nEnter Available Resources:\n";
    for(int i = 0; i < m; i++)
        cin >> available[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    cout << "\nInitial Table:\n";
    cout << "Process\tAllocation\tMax\tNeed\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t";
        for(int j = 0; j < m; j++) cout << allocation[i][j] << " ";
        cout << "\t\t";
        for(int j = 0; j < m; j++) cout << max[i][j] << " ";
        cout << "\t";
        for(int j = 0; j < m; j++) cout << need[i][j] << " ";
        cout << endl;
    }

    bool finish[n] = {false};
    int safeSeq[n];
    int work[m];

    for(int i = 0; i < m; i++)
        work[i] = available[i];

    int count = 0;

    cout << "\nExecution Steps:\n";6

    while(count < n) {
        bool found = false;

        for(int i = 0; i < n; i++) {
            if(!finish[i]) {

                cout << "\nChecking P" << i+1 << ": ";

                bool canExecute = true;
                for(int j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        cout << "Need > Available : Cannot Execute";
                        canExecute = false;
                        break;
                    }
                }

                if(canExecute) {
                    cout << "Need <= Available : Executing";

                    cout << "\nAvailable before: ";
                    for(int x = 0; x < m; x++) cout << work[x] << " ";

                    for(int k = 0; k < m; k++)
                        work[k] += allocation[i][k];

                    cout << "\nAvailable after: ";
                    for(int x = 0; x < m; x++) cout << work[x] << " ";
                    cout << endl;

                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if(!found) {
            cout << "\nSystem is NOT in SAFE state\n";
            return 0;
        }
    }

    cout << "\nSystem is in SAFE state\nSafe sequence: ";
    for(int i = 0; i < n; i++)
        cout << "P" << safeSeq[i] + 1 << " ";

    return 0;
}