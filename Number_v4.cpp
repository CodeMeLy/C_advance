/* I.	Integer.cpp
1.	Nhập 2 số truyền vào tham chiếu
2.	Nhập 2 số truyền vào con trỏ
3.	Cộng, trừ, nhân, chia hai số
4.	Tìm max của 2 số
5.	Tìm tính tương quan của 2 số. 
-	Định nghĩa kiểu enum là kết quả của việc so sánh 2 số
-	Nếu đúng số thứ nhất > số thứ 2: trả về LARGER
-	Nếu bằng trả về: EQUAL
-	Nếu bé hơn trả về: SMALLER
6.	Viết hàm xuất ra 2 số
7.	Viết hàm xuất các kết quả tính
8.	Viết hàm xuất vào file
9.	Viết hàm nhập liệu từ file */
#include<stdio.h>
#include<stdlib.h>
//nhập 2 số truyền tham chiếu
void enter(int &first, int &second);
int main(){
    int first,second;
    enter(first,second);
    return EXIT_SUCCESS;
}
void enter(int &first, int &second){
    printf("\nPut in the first number: ");
    scanf("%d",&first);
    printf("\nPut in the second number: ");
    scanf("%d",&second);
}