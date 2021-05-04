#include <stdio.h>
int tinhTong(int n);
int tinhTich(int n);
bool laSoNguyenTo(int x);// x la so nguyen to hay khong?
int demSoLuongSoNguyenTo(int n);// tim so luong so nguyen to
void lietKeSoNguyenTo(int n);// Liet ke so nguyen to trong day
int main(){
    int n;// 1 2 3 4 5 6 7 8, n = 8
    printf("Nhap n:");
    scanf("%d",&n);
    // TODO: tinh tong day so: 1+2+3+4+ ...+n
    printf("Tong = %d\n",tinhTong(n));
    printf("Tich = %d\n",tinhTich(n));
    printf("So luong so nguyen to: %d\n",demSoLuongSoNguyenTo(n));
    printf("Danh sach so nguyen to:");
    lietKeSoNguyenTo(n);    
    return 0;
}
int tinhTong(int n){
    int tong = 0;// chưa tính tổng nên tổng bằng 0
    for(int i=0; i<n; i++){
        tong+=i;
    }
    return tong;// hàm trả về kiểu void không return tong được
}
int tinhTich(int n){
    int tich;
    if(n==0){
        tich = 0;
    }
    else{
        tich = 1;
        for(int i=1; i<n; i++){
            tich*=i;
        }
    }
    return tich;
}
bool laSoNguyenTo(int x){
    // dùng khái niệm: số nguyên tố chia hết cho 1 và chính nó
    bool flag = true;// đặt giả thuyết rằng: x là số nguyeen tố
    // TODO: tìm cách phản biện giả thiết
    for(int i=2;i<x;i++){// Nếu x chia hết cho bất kì 1 số khác 1 và x thì nó không phải số nguyên tố
        if(x%i==0){
            flag = false;
            break;
        }
    }
    return flag;// đưa ra kết luận cuối cùng
}
void lietKeSoNguyenTo(int n){
    for(int i=1;i<n;i++){
        if(laSoNguyenTo(i)){
            printf("%d ",i);
        }
    }
}
int demSoLuongSoNguyenTo(int n){
    int dem = 0;
    for(int i=1;i<n;i++){
        if(laSoNguyenTo(i)){
            dem++;
        }
    }
    return dem;   
}