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
    checkTriagleType(*first,*second,*third);
    printTriangePerimeter(*first,*second,*third);
    printTriangeArea(*first,*second,*third);
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
float findTriangleArea(const float first, const float second, const float third){
    float halfOfPerimeter=findTrianglePerimeter(first,second,third)/2.0;
    return sqrt(halfOfPerimeter*(halfOfPerimeter-first)*(halfOfPerimeter-second)*(halfOfPerimeter-third));
}
void printTriangePerimeter(const float first, const float second, const float third){
    if(isEgdeOfTriAngle(first,second,third)){
        printf("\nPerimeter of triangle: %.3f",findTrianglePerimeter(first,second,third));
    }
}
void printTriangeArea(const float first, const float second, const float third){
    if(isEgdeOfTriAngle(first,second,third)){
        printf("\nArea of triangle: %.3f",findTriangleArea(first,second,third));
    }
}
void checkTriagleType(const float first, const float second, const float third){
    if(isEgdeOfTriAngle(first,second,third)){
        if(isEquilateralTriangle(first,second,third)){
            printf("This is equilateral triangle");
        }else if(isIsoscelesTriangle(first,second,third)){
            printf("This is isosceles triangle");
        }else if(isRightTriangle(first,second,third)){
            printf("This is right triangle");
        }else if(isRightIsoscelesTriangle(first,second,third)){
            printf("This is right isosceles triangle");
        }else{
            printf("This is normal triangle");
        }
    }else{
        printf("This is not a triangle!");
    }
}