#include<stdio.h>
enum LuaChon{
    COMCHIEN = 1, BOKHO = 2, CHACA = 3
};
void menu();
int main(){
    menu();
    return 0;
}
void menu(){
    int luachon;
    printf("------------Danh sach mon an ban co the chon -----------\n");
    printf("1. com chien\n");
    printf("2. bo kho\n");
    printf("3. cha ca\n");
    // NOTE: nhập vào lựa chọn
    printf("nhap vao lua chon:");
    scanf("%d",&luachon);
    // NOTE: kiểm tra lựa chọn
    switch(luachon){
        case COMCHIEN: 
            printf("Bạn đã chọn cơm chiên");
            break;
        case BOKHO:
            printf("Bạn đã chọn bò kho");
            break;
        case CHACA:
            printf("Bạn đã chọn chả cá");
            break;
        default:
            printf("Món đó cửa hàng chúng tôi không có");
    }

}