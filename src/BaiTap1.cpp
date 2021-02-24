#include <stdio.h>
#include <math.h>
void nhap(int &a, int &b);
int Tong(int a, int b);
int Hieu(int a, int b);
int Tich(int a, int b);
float Thuong(int a, int b);
int timBoiChungNhoNhat(int a, int b);
int UocChungMax(int a, int b);
int LuyThua(int a, int b);
void xuatTong(int a, int b);
void xuatHieu(int a, int b);
void xuatTich(int a, int b);
void xuatThuong(int a, int b);
void xuatBoiChungNhoNhat(int a, int b);
void xuatUocChungMax(int a, int b);
void hoanvi(int &a, int &b);
void xuatLuyThua(int a, int b);

int main()
{
	int a, b;
	nhap(a, b);
	xuatTong(a, b);
	xuatHieu(a, b);
	xuatTich(a, b);
	xuatThuong(a, b);
	xuatUocChungMax(a, b);
	xuatBoiChungNhoNhat(a, b);
	hoanvi(a, b);
	printf("\ntrong so hoan vi la a =%d\t b =%d\t ", a, b);
	xuatLuyThua(a, b);
}
void nhap(int &a, int &b)
{
	printf("Nhap a:");
	scanf("%d", &a);
	printf("Nhap b:");
	scanf("%d", &b);
}
int Tong(int a, int b)
{
	return a + b;
}
void xuatTong(int a, int b)
{
	int tong = Tong(a, b);
	printf("\n%d +%d =%d", a, b, tong);
}
int Hieu(int a, int b)
{
	return a - b;
}
void xuatHieu(int a, int b)
{
	int hieu = Hieu(a, b);
	printf("\n%d -%d =%d", a, b, hieu);
}
int Tich(int a, int b)
{
	return a * b;
}
void xuatTich(int a, int b)
{
	int tich = Tich(a, b);
	printf("\n%d *% d =%d", a, b, tich);
}
float Thuong(int a, int b)
{
	float thuong = 0;
	if (b == 0)
	{
		printf("\n maxerror!");
	}

	else
	{
		thuong = (float)a / b;
	}

	return thuong;
}
void xuatThuong(int a, int b)
{

	printf("\n%d /%d =%.2f", a, b, Thuong(a, b));
}
int UocChungMax(int a, int b)
{
	if (a == 0 || b == 0)
		return a + b;
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
void xuatUocChungMax(int a, int b)
{
	int ucln = UocChungMax(a, b);
	printf("\nuoc chung lon nhat la% d", ucln);
}
int timBoiChungNhoNhat(int a, int b)
{
	int bcnn;
	bcnn = (a * b) / UocChungMax(a, b);
	return bcnn;
}
void xuatBoiChungNhoNhat(int a, int b)
{
	int boi = timBoiChungNhoNhat(a, b);
	printf("\nboi chung nho nhat la:% d", boi);
}
void hoanvi(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int LuyThua(int a, int b)
{
	int LT;
	LT = pow(a, b);
	return LT;
}
void xuatLuyThua(int a, int b)
{
	int MU = LuyThua(a, b);
	printf("\nluy thua% d *% d ==% d", a, b, MU);
}
