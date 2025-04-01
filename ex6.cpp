#include <iostream>
#include <vector>
using namespace std;

bool isEqualTarget(vector<int>& nums, int target) {
	int l = 0; int r = nums.size() - 1;

	while (l < r) {
		int sum = nums[l] + nums[r]; // xet tong cua hai phan tu o dau va cuoi mang
		if (sum == target) { // neu bang target thi return true
			return true;
		}
		if (sum > target) {// Neu sum > target, ta phai giam gia tri ben phai xuong
			r--;
		}
		else {
			l++; // Neu sum < target, ta tang gia tri ben trai len de cong
		}
	}
	return false; // Neu khong co tong = target thi return false
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
	if (isEqualTarget(nums, target)) {
		cout << "YES"; // In  ra YES neu co dap an
	}
	else {
		cout << "NO"; // In ra NO neu khong co dap an
	}
}