/* // TODO: viết chương trình xây dựng và gọi hàm. được sử dụng google,được copy(không copy bài bạn) và phải hiểu
1. viết chương trình nhập vào 3 cạnh tam giác và tính chu vi, diện tích
2. viết hàm kiểm tra 3 cạnh có lập thành tam giác không?
3. viết hàm kiểm tra 3 cạnh lập thành tam giác gì?
- TH1: nếu có lập thành tam giác, kiểm tra xem nó là tam giác gì?
- TH2: nếu nó không lập thành tam giác, in ra màn hình không lập thành tam giác
 */
#include<stdio.h>
#include<math.h>
#include<assert.h>
bool isValid(const float egde);// kiểm tra một cạnh hợp lệ hay không?
void enter(float *first, float *second, float *third);// nhập 3 cạnh tam giác
bool isEgdeOfTriAngle(const float first, const float second, const float third);// 3 cạnh có tạo thành tam giác hay không?
bool isEquilateralTriangle(const float first, const float second, const float third);// là tam giác đều
bool isIsoscelesTriangle(const float first, const float second, const float third);// là tam giác cân
bool isRightTriangle(const float first, const float second, const float third);// là tam giác vuông
bool isRightIsoscelesTriangle(const float first, const float second, const float third);// là tam giác vuông cân 
float findTrianglePerimeter(const float first, const float second, const float third);// tìm chu vi tam giác
float findTriangleArea(const float first, const float second, const float third); // tìm diện tích tam giác
void printTriangePerimeter(const float first, const float second, const float third);// in chu vi
void printTriangeArea(const float first, const float second, const float third);// in ra diện tích tam giác
void checkTriagleType(const float first, const float second, const float third);// kiểm tra đó là tam giác gì?
int main(){
    float *first, *second, *third;
    first=(float*)calloc(10,sizeof(float));
    second=(float*)calloc(10,sizeof(float));
    third=(float*)calloc(10,sizeof(float));
    enter(first,second,third);
    return 0;
}
bool isValid(const float egde){
    return egde!=0;
}
void enter(float *first, float *second, float *third){
    do{
        printf("Enter first egde: ");
        scanf("%f", first);
    }while(!isValid(*first));
    do{
        printf("Enter second egde: ");
        scanf("%f", second);
    }while(!isValid(*second));
    do{
        printf("Enter third egde: ");
        scanf("%f", third);
    }while(!isValid(*third));
}
bool isEgdeOfTriAngle(const float first, const float second, const float third){
    return first+second>third && first+third>second && second+third>first;
}
bool isEquilateralTriangle(const float first, const float second, const float third){
    return first==second&&first==third&&second==third;
}
bool isIsoscelesTriangle(const float first, const float second, const float third){
    return first==second||first==third||second==third;
}
bool isRightTriangle(const float first, const float second, const float third){
    return pow(first,2)==pow(second,2)+pow(third,2)||pow(second,2)==pow(first,2)+pow(third,2)||pow(third,2)==pow(first,2)+pow(second,2);
}
bool isRightIsoscelesTriangle(const float first, const float second, const float third){
    return isRightIsoscelesTriangle(first,second,third)&&isRightTriangle(first,second,third);
}
float findTrianglePerimeter(const float first, const float second, const float third){
    return first+second+third;
}