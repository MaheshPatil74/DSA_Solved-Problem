/*
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> secondLargestAndSmallest(int n, std::vector<int>& a) {
    if (n < 2) return {}; // Not enough elements

    std::sort(a.begin(), a.end());
    int second_smallest = a[1];
    int second_largest = a[n - 2];

    return {second_largest, second_smallest};
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    int n = a.size();

    std::vector<int> result = secondLargestAndSmallest(n, a);
    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl; // Output: [4, 2]

    return 0;
}

*/


/*
#include <iostream>
#include <vector>
#include <climits>

std::vector<int> secondLargestAndSmallest(int n, const std::vector<int>& a) {
    if (n < 2) return {};

    int largest = INT_MIN, second_largest = INT_MIN;
    int smallest = INT_MAX, second_smallest = INT_MAX;

    for (int num : a) {
        // Largest & Second Largest
        if (num > largest) {
            second_largest = largest;
            largest = num;
        } else if (num > second_largest) {
            second_largest = num;
        }

        // Smallest & Second Smallest
        if (num < smallest) {
            second_smallest = smallest;
            smallest = num;
        } else if (num < second_smallest) {
            second_smallest = num;
        }
    }

    return {second_largest, second_smallest};
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    int n = a.size();

    std::vector<int> result = secondLargestAndSmallest(n, a);
    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl; // Output: [4, 2]

    return 0;
}
*/