#include <iostream>
using namespace std;

int main() {
    int base[10], limit[10];
    int n, segment, offset;

    cout << "Enter number of segments: ";
    cin >> n;

    cout << "Enter base and limit for each segment:\n";
    for (int i = 0; i < n; i++) {
        cout << "Segment " << i << " Base: ";
        cin >> base[i];
        cout << "Segment " << i << " Limit: ";
        cin >> limit[i];
    }

    cout << "Enter segment number: ";
    cin >> segment;

    cout << "Enter offset: ";
    cin >> offset;

    if (segment >= n) {
        cout << "Invalid segment number!\n";
        return 0;
    }

    if (offset >= limit[segment]) {
        cout << "Segmentation Fault!\n";
    } else {
        int physical_address = base[segment] + offset;
        cout << "Physical Address: " << physical_address << endl;
    }

    return 0;
}