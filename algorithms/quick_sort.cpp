#include "quick_sort.h"
#include <iostream>

int partition(std::vector<int>& v, int low, int high) {
    int pivot = v[high];
    int i = low - 1;

    std::cout << "\n--- Partitioning with pivot " << pivot << " ---\n";

    for (int j = low; j < high; j++) {
        std::cout << "Comparing " << v[j] << " with pivot " << pivot << "\n";
        if (v[j] <= pivot) {
            i++;
            std::cout << "Swap " << v[i] << " with " << v[j] << "\n";
            std::swap(v[i], v[j]);
        } else {
            std::cout << "No swap\n";
        }

        std::cout << "Current array: ";
        for (int k = 0; k < v.size(); ++k) {
            std::cout << v[k] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Final swap pivot " << v[high] << " with " << v[i + 1] << "\n";
    std::swap(v[i + 1], v[high]);

    return i + 1;
}

void quick_sort(std::vector<int>& v, int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);
        std::cout << "\nPartition index: " << pi << "\n";

        std::cout << "\nQuick sort left part [" << low << ", " << pi - 1 << "]\n";
        quick_sort(v, low, pi - 1);  

        std::cout << "\nQuick sort right part [" << pi + 1 << ", " << high << "]\n";
        quick_sort(v, pi + 1, high); 
    }
}
