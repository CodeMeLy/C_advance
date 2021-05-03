#include<iostream>
using namespace std;
typedef struct NhanVien{
    string ma;
    string ten;
    string chucvu;
    int songaycong;
    float tienluong;
};
void nhap(NhanVien &nhanvien); // tham chiếu
void nhap(NhanVien danhsach[], int &soluong);
void xuat(const NhanVien nhanvien);
void xuat(NhanVien danhsach[], int soluong);
string xepLoai(const NhanVien nhanvien);
float thuongPhat(const NhanVien nhanvien);
int main(){
    NhanVien danhsach[30];
    int soluong;
    nhap(danhsach,soluong);
    xuat(danhsach,soluong);
    return 0;
}
void nhap(NhanVien &nhanvien){
    cout<<"\tMa nhan vien:";
    cin>>nhanvien.ma;
    cout<<"\tten nhan vien:";
    cin>>nhanvien.ten;
    cout<<"\tChuc vu:";
    cin>>nhanvien.chucvu;
    cout<<"\tSo ngay cong:";
    cin>>nhanvien.songaycong;
    cout<<"\ttien luong 1 ngay cong:";
    cin>>nhanvien.tienluong;
}
void nhap(NhanVien danhsach[], int &soluong){
    cout<<"so luong nhan vien:";
    cin>>soluong;
    for(int i=0; i<soluong; i++){
        cout<<"Nhan vien thu:"<<i<<":"<<endl;
        nhap(danhsach[i]);
    }
}
void xuat(const NhanVien nhanvien){
    cout<<"\tma nhan vien:"<<nhanvien.ma<<endl;
    cout<<"\tten nhan vien:"<<nhanvien.ten<<endl;
    cout<<"\tchuc vu nhan vien:"<<nhanvien.chucvu<<endl;
    cout<<"\tso ngay cong nhan vien:"<<nhanvien.songaycong<<endl;
    cout<<"\ttien luong nhan vien:"<<nhanvien.tienluong<<endl;
    cout<<"\txep loai:"<<xepLoai(nhanvien)<<endl;
    cout<<"\tthuong/phat:"<<thuongPhat(nhanvien)<<"%"<<endl;
}
void xuat(NhanVien danhsach[], int soluong){
    cout<<"xuat danh sach nhan vien:"<<endl;
    for(int i=0; i<soluong; i++){
        cout<<"Nhan vien thu:"<<i<<":"<<endl;
        xuat(danhsach[i]);
    }
}
string xepLoai(const NhanVien nhanvien){
    string xeploai = "Y";
    if(nhanvien.songaycong >=27){
        xeploai = "XS";
    }
    else if(nhanvien.songaycong >= 25){
        xeploai = "G";
    } else if(nhanvien.songaycong >= 22){
        xeploai = "TB";
    }
    return xeploai;
}
float thuongPhat(const NhanVien nhanvien){
    float ketqua = 0;// giả sử nhân viên trung bình
    string xeploai = xepLoai(nhanvien);
    if(xeploai=="XS"){
        ketqua = 20;
    } else if(xeploai=="G"){
        ketqua = 15;
    } else if(xeploai=="Y"){
        ketqua = -10;
    }
    return ketqua;
}
