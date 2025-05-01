#include "binary_search.h"
#include<iostream>

bool binary_search(std::vector<int>& v, int val) {

	int left = 0, right = v.size() - 1, mid, step = 0;

	while(left <= right) {
		mid = left + (right - left) / 2;
		
		std::cout << "\nStep: " << ++step << "\n";

		for(int num : v) std::cout << num << " ";
		std::cout << "\n";
		for(int i=0; i<mid; i++) std::cout << "  ";
		std::cout << "^\n";
		std::cout << "Left: " << left << "   Right: " << right << "    Mid:" << mid << "\n";
		std::cout << "arr[" << mid << "] = " << v[mid] << "\n";
		if(v[mid] == val) {
			std::cout << "Found on position " << mid << "\n";
			return true;
		}else if(v[mid] < val) {
			left = mid + 1;
			std::cout<<"Searching the right half\n";
		}else {
			right = mid - 1;
			std::cout<<"Searching the left half\n";
		}
	}

	std::cout << "Element not found\n";
	return false;
}