#include <iostream>
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

    int key;
    cout << "\nEnter the element to search: ";
    cin >> key;

    // Start execution time
    auto start = high_resolution_clock::now();

    // Linear Search
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        cout << "\nElement " << key
             << " found at index " << index << "." << endl;
    }
    else
    {
        cout << "\nElement " << key << " not found." << endl;
    }

    // End execution time
    auto end = high_resolution_clock::now();

    duration<double> executionTime = end - start;

    cout << "\nExecution Time: "
         << executionTime.count()
         << " seconds" << endl;

    cout << "\nTime Complexity:" << endl;
    cout << "Best Case      : O(1)" << endl;
    cout << "Average Case   : O(n)" << endl;
    cout << "Worst Case     : O(n)" << endl;
    cout << "Space Complexity: O(1)" << endl;

    return 0;
}
