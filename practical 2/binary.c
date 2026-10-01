#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Start execution time
    auto start = high_resolution_clock::now();

    // Sort the array
    sort(arr, arr + n);

    cout << "\nSorted Array: [";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    // Binary Search
    int low = 0;
    int high = n - 1;
    int index = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            index = mid;
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (index != -1)
        cout << "\nElement " << key << " found at index " << index << "." << endl;
    else
        cout << "\nElement " << key << " not found." << endl;

    // End execution time
    auto end = high_resolution_clock::now();

    duration<double> executionTime = end - start;

    cout << "\nExecution Time: " << executionTime.count()
         << " seconds" << endl;

    cout << "\nTime Complexity:" << endl;
    cout << "Best Case      : O(1)" << endl;
    cout << "Average Case   : O(log n)" << endl;
    cout << "Worst Case     : O(log n)" << endl;
    cout << "Space Complexity: O(1)" << endl;

    return 0;
}
