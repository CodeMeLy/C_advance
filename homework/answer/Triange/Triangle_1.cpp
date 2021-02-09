/* // TODO: viết chương trình xây dựng và gọi hàm. được sử dụng google,được copy(không copy bài bạn) và phải hiểu
1. viết chương trình nhập vào 3 cạnh tam giác và tính chu vi, diện tích
2. viết hàm kiểm tra 3 cạnh có lập thành tam giác không?
3. viết hàm kiểm tra 3 cạnh lập thành tam giác gì?
- TH1: nếu có lập thành tam giác, kiểm tra xem nó là tam giác gì?
- TH2: nếu nó không lập thành tam giác, in ra màn hình không lập thành tam giác
 */
#include<stdio.h>
#include<assert.h>
#include<math.h>
int isValid(const float egde);// kiểm tra một cạnh hợp lệ hay không?
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
    enter(first, second, third);
    printTriangePerimeter(*first, *second, *third);
    printTriangeArea(*first, *second, *third);
    checkTriagleType(*first, *second, *third);
    return 0;
}

int isValid(const float egde){
    return egde > 0;
}

void enter(float *first, float *second, float *third){
    printf("Enter first egde: ");
    scanf("%f", first);
    printf("Enter second egde: ");
    scanf("%f", second);
    printf("Enter third egde: ");
    scanf("%f", third);
}

bool isEgdeOfTriAngle(const float first, const float second, const float third){
    bool egde = false;
    do{
        if((first + second) > third && (first + third) > second && (second + third) > first){
        egde = true;
        }
    } while(isValid(egde));
    return egde;
}

bool isEquilateralTriangle(const float first, const float second, const float third){
    bool egde = false;
    do{
    if((first == second) && (second == third) && ( third == first)){
        egde = true;
        }
    } while(isValid(egde));
    return egde;
}

bool isIsoscelesTriangle(const float first, const float second, const float third){
    bool egde = false;
    if(first == second || second == third || third == first){
        egde = true;
    }
    return egde;
}

bool isRightTriangle(const float first, const float second, const float third){
    bool egde = false;
    if(first*first == second*second + third*third || second*second == third*third + first*first || third*third == first*first + second*second){
        egde = true;
    }
    return egde;
}

bool isRightIsoscelesTriangle(const float first, const float second, const float third){
    bool egde = false;
    if((first == second || second == third || third == first) && (first*first == second*second + third*third || second*second == third*third + first*first || third*third == first*first + second*second)){
        egde = true;
    }
    return egde;
}

float findTrianglePerimeter(const float first, const float second, const float third){
    float P;
    P = first + second + third;
    return 0;
}

float findTriangleArea(const float first, const float second, const float third){
    float S, p;
    p = (first + second + third)/2;
    S = sqrt(p*(p-first)*(p-second)*(p-third));
    return 0;
}

void printTriangePerimeter(const float first, const float second, const float third){
    printf("Perimeter of triangle is: %.3f\n", findTrianglePerimeter(first, second, third));
}

void printTriangeArea(const float first, const float second, const float third){
    printf("Area of triangle is: %.3f\n", findTriangleArea(first, second, third));
}

void checkTriagleType(const float first, const float second, const float third){
    if(isEquilateralTriangle(first, second, third)){
        printf("This is Equilateral Triangle\n");
    } else if(isIsoscelesTriangle(first, second, third)){
        printf("This is Isosceles Triangle\n");
    } else if(isRightTriangle(first, second, third)){
        printf("This is Right Triangle\n");
    } else if(isRightIsoscelesTriangle(first, second, third)){
        printf("This is Right Isosceles Trangle\n");
    } else{
        printf("This is normal Triangle");
    }
}


