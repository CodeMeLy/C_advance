#include <stdio.h>
int main(){
    // giải phương trình bậc 1
    int a,b;// phương trình bậc 1: ax + b =0--> mục tiêu: tìm x. 3/4 = 0.75 (số thực:float)
    float x;
    // NOTE: nhập a,b
    printf("Nhap vao a,b:");
    scanf("%d%d",&a,&b);
    // NOTE: chạy thử nhé
    // nếu a= 0 thì phương trình không phải bậc nhất
    if(a==0){
        printf("Phương trình không là phương trình bậc nhất!\n");
    } else{// ngược lại mới tìm nghiệm và in ra
        x = -(float)b/a;
        printf("x = %.2f",x);
    }
    return 0;
}