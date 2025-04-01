#include <iostream>
using namespace std;
// Ham tim kiem tuyen tinh
int LinearSearch(int a[], int n, int k) {
	for (int i = 0; i < n; i++) {// Duyet tung phan tu trong mang
		if (a[i] == k) { // Neu thay phan tu can tim
			return i; //Tra ve chi so
		}
	}
	return -1; // Neu khong tim thay tra ve -1
}

int main() {
	const int N = 100;
	int a[N]; int n;
	int k;
	
	cout << "Nhap so luong phan tu cua mang: ";
	cin >> n;
	
	cout << "Nhap phan tu cua mang: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	};

	cout << "Mang vua nhap la: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Nhap phan tu can tim: ";
	cin >> k;
	int kq = LinearSearch(a, n, k);

	cout << "Vi tri cua phan tu la: "<< kq << endl;
	return 0;
}