#include "bubble_sort.h"
#include <iostream>

void bubble_sort(std::vector<int>& v) {
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        std::cout << "\nPass " << i + 1 << ":\n";

        for (int j = 0; j < n - i - 1; j++) {
            std::cout << "Comparing " << v[j] << " and " << v[j + 1];

            if (v[j] > v[j + 1]) {
                std::cout << " => swap\n";
                std::swap(v[j], v[j + 1]);
                swapped = true;
            } else {
                std::cout << " => no swap\n";
            }

            // Print the array after each comparison
            std::cout << "Current array: ";
            for (int k = 0; k < n; ++k) {
                std::cout << v[k] << " ";
            }
            std::cout << "\n";
        }

        if (!swapped) {
            std::cout << "No swaps in this pass, array is sorted early.\n";
            break;
        }
    }

    std::cout << "\nSorted array: ";
    for (int num : v) std::cout << num << " ";
    std::cout << "\n";
}
