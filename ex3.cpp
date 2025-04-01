#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>nums) {
	int l = 0; int r = nums.size() - 1; // Khoi tao gia tri left va right
	// Do phan tu chac chan co ton tai trong mang nen ta khong can kiem tra l == r
	while (l < r) {
		int mid = l + (r - l) / 2; // khoi tao gia tri mid
		if (nums.size() == 1) {
			return nums[0];  // Neu mang chi co mot phan tu, ta tra ve phan tu do 
		}
		if (nums[mid] > nums[r]) {  // dap an can tim o ben phai mid, => ta bo mid va phan cac phan tu ben trai mid
			l = mid + 1;
		}
		else if (nums[mid] < nums[r]) {
			r = mid;       // dap an co the la mid => ta bo cac phan tu ben phai mid, xet ben trai
		}
	}
	return nums[l];  // ta co the tra ve nums[r], nhung r == mid chua chac da la dap an nen tot nhat return nums[l]

}
int main() {
	int n; cin >> n; // Kich thuoc mang
	vector<int>nums(n);  
	for (int i = 0; i < n; i++) { // Nhap mang
		cin >> nums[i];
	}
	int kq = findMin(nums); // Goi ham
	cout << kq << endl;
	return 0;


}