#include <iostream>
#include <vector>
using namespace std;

// Tao ham kiem tra xem day co do dai mid co do dai thoa man >= target khong
bool checkMid(const vector<int>& nums, int target, int mid) {
	int currentSum = 0; 
	// Tinh tong day dau tien co dai mid
	for (int i = 0; i < mid; i++) {
		currentSum += nums[i];
	}
	// Neu tong >= target thi tra ve true
	if (currentSum >= target) {
		return true;
	}
	// Ta dung ki thuat cua so truot de kiem tra cac day con lai cung co do dai mid
	for (int i = mid; i < nums.size(); i++) {
		currentSum += nums[i] - nums[i - mid];
		// Neu tong >= target thi tra ve true
		if (currentSum >= target) {
			return true;
		}
	}
	return false; // Neu khong tim thay day con hop le thoa tong >= target thi ta return false
}

// Ham tim do dai nho nhat cua day co tong cac phan tu >= target
int minimalLengthSum(const vector<int>& nums, int target) {
	// Khoi tao cac bien left , right va bien minimalLength
	int l = 1; int r = nums.size();
	int minimalLength = 0;
	// Do ta khong xac dinh duoc lieu co dap an hay khong nen phai xet dau "="
	while (l <= r) {
		int mid = l + (r - l) / 2;
		// Neu ton tai day thoa tong >= target
		if (checkMid(nums, target, mid)) {
			minimalLength = mid; // cap nhat lai do dai nho nhat 
			r = mid - 1; 
		}
		else {
			l = mid + 1; 
		}
	}
	return minimalLength;
}

int main() {
	int n; int target;
	cout << "Nhap so luong phan tu cua mang: ";
	cin >> n;
	vector<int> nums(n);
	cout << "Nhap cac phan tu cua mang: ";
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << "Nhap gia tri target: ";
	cin >> target;
	int kq = minimalLengthSum(nums, target);
	cout << kq << endl;
	return 0;
}