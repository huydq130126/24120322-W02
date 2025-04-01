#include <iostream>
#include <vector>
using namespace std;
// Ham kiem tra co the van chuyen hang trong so ngay cho truoc khong
bool isShipped(vector<int>& weights, int capacity, int days) {
	int w = 0; // Trong luong hang luc dau
	int d = 1;// So ngay van chuyen, bat dau tu ngay 1
	for (int i = 0; i < weights.size(); i++) {
		if (w + weights[i] > capacity) { // Neu cong them kien hang ma vuot qua capacity
			d++;// Bat dau ngay moi
			w = weights[i];// Dat hang vao ngay moi
		}
		else {
			w += weights[i];// Neu chua vuot qua muc, thi them kien hang vao ngay hien tai
		}
		
	}
	if (d <= days) { // Neu tong so ngay d khong vuot qua so ngay cho truoc
		return true; // Tra ve true
	}
	return false; // Neu khong thi tra ve false
	
}
// Ham tim tai trong nho nhat de tau co the van chuyen tat ca hang trong so ngay days
int leastWeightShip(vector<int>& weights, int days) {
	// l la trong luong lon nhat cua mot kien hang
	int l = weights[0];
	int r = 0;// r la tong trong luong cua tat ca kien hang
	for (int i = 0; i < weights.size(); i++) {
		if (weights[i] > l) {
			l = weights[i];
		}
		r += weights[i];
	}
	while (l < r) {
		int mid = l + (r - l) / 2; // Tai trong trung binh
		// Kiem tra neu trong tai mid phu hop
		if (!isShipped(weights, mid, days)) {
			l = mid + 1; // Neu khong the thi tang gioi han duoi
		}
		else {
			r = mid; // Neu co the thi giam gioi han tren de tim gia tri nho hon
		}
		
	}
	return l; // tra ve tai trong toi uu
}

int main() {
	int n; cin >> n;// Nhap so kien hang
	vector<int>weights(n);
	for (int i = 0; i < n; i++) {
		cin >> weights[i]; // Nhap trong luong tung kien hang
	}
	int days; 
	cin >> days;
	int kq = leastWeightShip(weights, days);
	cout << kq << endl;
	return 0;
}