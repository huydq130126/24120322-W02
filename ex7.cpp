#include <iostream>

using namespace std;
// Xay dung ham Sap xep chen
void InsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

void ThreeSumZero(int nums[], int n) {

	InsertionSort(nums, n); // Ta sap xep mang tang dan bang thuat toan Insertion Sort
	// Vong lap tu phan tu dau den phan tu ke cuoi vi can ba phan tu de cong
	for (int i = 0; i < n - 2; i++) {
		// Neu phan tu hien tai = phan tu truoc do thi ta bo qua de tranh trung lap
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		// Khoi tao hai con tro
		int l = i + 1;
		int r = n - 1;
		while (l < r) {
			int threesum = nums[i] + nums[l] + nums[r]; // Tinh tong ba phan tu
			if (threesum == 0) { // thoa yeu cau 
				// In ra bo ba hop le
				cout << "[" << nums[i] << "," << nums[l] << "," << nums[r] << "]\n";
				while (l < r && nums[l] == nums[l + 1]) {
					l++; // Tang left de bo qua cac phan tu trung lap tu trai sang phai
				};
				while (l < r && nums[r] == nums[r - 1]) {
					r--; // Tang right de bo qua cac phan tu trung lap tu phai sang trai
				};
				l++; // Tien den phan tu tiep theo
				r--; // Lui ve phan tu phia truoc
			}
			else if (threesum < 0) {
				l++; // Neu tong nho hon 0, ta tang left len 
			}
			else {
				r--; // Neu tong lon hon 0, ta giam right xuong
			}
		}

	}
	
}
int main() {
	int nums[] = { -1,0,1,2,-1,-4 };
	int n = sizeof(nums) / sizeof(nums[0]); // tinh n
	ThreeSumZero(nums, n);
	return 0;
}