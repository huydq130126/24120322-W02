#include <iostream>
using namespace std;
//Ham tim kiem tuyen tinh co su dung linh canh
int sentinalLinearSearch(int arr[], int n, int k) {
	int last = arr[n - 1]; // dung bien last chua gia tri cuoi cua mang
	arr[n - 1] = k;  // thiet lap linh canh

	int i = 0;
	while (arr[i] != k) {  // Dung vong lap de duyet cho den khi arr[i] == k
		i++;
	}
	arr[n - 1] = last;   // tra lai gia tri cuoi cua mang


	// neu tim thay gia tri thi tra ve chi so i, con khong thi tra ve -1
	if (i < (n - 1) || arr[n - 1] == k) {
		return i;
	}

	return -1;
}

int main() {
	const int N = 100;
	int arr[N];
	int n; int k;

	cout << "Nhap so luong phan tu: ";
	cin >> n;

	cout << "Nhap cac phan tu: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Mang vua nhap: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Nhap gia tri can tim: ";
	cin >> k;

	int kq = sentinalLinearSearch(arr, n, k);
	cout << "Chi so la: " << kq << endl;
	return 0;
}