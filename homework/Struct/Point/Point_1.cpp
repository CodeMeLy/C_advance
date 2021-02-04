#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct Point{
    int x;
    int y;
};
void enter(Point *input);// nhập vào 1 điểm
void enter(Point *first, Point *second, Point *third);// nhập vào 3 đỉnh của tam giác
double findDistance(const Point first, const Point second);// tính khoảng cách 2 điểm
double findTrianglePerimeter(const Point first, const Point second, const Point third);// tính chu vi tam giác
double findTriangleArea(const Point first, const Point second, const Point third);// tính diện tích tam giác
bool canFormEgdeOfTriAngle(const Point first, const Point second);// 2 điểm có thể tạo thành một cạnh tam giác?
bool isPointOfTriAngle(const Point first, const Point second, const Point third);// là 3 đỉnh của tam giác?
bool isEquilateralTriangle(const Point first, const Point second, const Point third);// là tam giác đều
bool isIsoscelesTriangle(const Point first, const Point second, const Point third);// là tam giác cân
bool isRightTriangle(const Point first, const Point second, const Point third);// là tam giác vuông
bool isRightIsoscelesTriangle(const Point first, const Point second, const Point third);// là tam giác vuông cân 
void print(const Point output);// in ra 1 điểm
void print(const Point first, const Point second, const Point third);// in ra 3 điểm tam giác
void typeOfTriangle(const Point first, const Point second, const Point third);//là tam giác gì
void printTrianglePerimeter(const Point first, const Point second, const Point third);// in ra chu vi tam giác
void printTriangleArea(const Point first, const Point second, const Point third);// in ra diện tích tam giác
int main(){
    Point first, second, third;
    enter(&first,&second,&third);
    print(first,second,third);
    typeOfTriangle(first,second,third);
    printTrianglePerimeter(first, second, third);
    printTriangleArea(first,second,third);
    return 0;
}
void enter(Point *input){
    printf("x: ");
    scanf("%d", &input->x);
    printf("y: ");
    scanf("%d", &input->y);
}
void enter(Point *first, Point *second, Point *third){
    printf("Enter point A:\n ");
    enter(first); // gọi lại hàm, không cần viết lại
    printf("Enter point B:\n ");
    enter(second);
    printf("Enter point C:\n ");
    enter(third);
}
void print(const Point output){
    printf("(%d, %d)\n", output.x, output.y);
}
void print(const Point first, const Point second, const Point third){
    printf("Point A: ");
    print(first);
    printf("Point B: ");
    print(second);
    printf("Point C: ");
    print(third);
}
double findDistance(const Point first, const Point second){
    double distance = sqrt((double)(first.x-second.x)*(first.x-second.x)+(first.y-second.y)*(first.y-second.y));//NOTE: khởi gán luôn nhé
    return distance;
}
double findTrianglePerimeter(const Point first, const Point second, const Point third){// NOTE: là tam giác mới có chu vi
    double AB = findDistance(first,second);
    double AC = findDistance(first,third);
    double BC = findDistance(second,third);
    return AB + AC + BC;
}
double findTriangleArea(const Point first, const Point second, const Point third){// NOTE: là tam giác mới có diện tích
    double AB = findDistance(first,second);
    double AC = findDistance(first,third);
    double BC = findDistance(second,third);
    double triagle_perimeter = findTrianglePerimeter(first,second,third)/2;//Nửa chu vi
    return sqrt(triagle_perimeter*(triagle_perimeter-AB)*(triagle_perimeter-AC)*(triagle_perimeter-BC));//công thức Heron
}
void printTrianglePerimeter(const Point first, const Point second, const Point third){
    double AB = findDistance(first,second);
    double AC = findDistance(first,third);
    double BC = findDistance(second,third);
    if(canFormEgdeOfTriAngle(first,second)&&canFormEgdeOfTriAngle(first,third)&&canFormEgdeOfTriAngle(second,third)&&isPointOfTriAngle(first,second,third)){
    printf("AB= %.3lf\tAC= %.3lf\tBC= %.3lf\n",AB,AC,BC);
    double triagle_perimeter = findTrianglePerimeter(first,second,third);
    printf("triangle perimeter = %.3lf\n",triagle_perimeter);
    }
}
void printTriangleArea(const Point first, const Point second, const Point third){
    if(canFormEgdeOfTriAngle(first,second)&&canFormEgdeOfTriAngle(first,third)&&canFormEgdeOfTriAngle(second,third)&&isPointOfTriAngle(first,second,third)){
    double triagle_area = findTriangleArea(first,second,third);
    printf("triangle area = %.3lf\n",triagle_area);
    }
}
bool canFormEgdeOfTriAngle(const Point first, const Point second){
    return findDistance(first,second)!=0;//độ dài 1 cạnh khác 0
}
bool isPointOfTriAngle(const Point first, const Point second, const Point third){
    double AB = findDistance(first,second);
    double AC = findDistance(first,third);
    double BC = findDistance(second,third);
    return AB+AC > BC && AB + BC> AC && AC + BC> AB;//tổng 2 cạnh lớn hơn cạnh còn lại
}
bool isEquilateralTriangle(const Point first, const Point second, const Point third){
    double AB = findDistance(first,second);
    double AC = findDistance(first,third);
    double BC = findDistance(second,third);
    return AB==AC&&AC==BC&&AB==BC;
}
bool isIsoscelesTriangle(const Point first, const Point second, const Point third){
    double AB = findDistance(first,second);
    double AC = findDistance(first,third);
    double BC = findDistance(second,third);
    return AB==AC||AC==BC||AB==BC;
}
bool isRightTriangle(const Point first, const Point second, const Point third){
    double AB = findDistance(first,second);
    double AC = findDistance(first,third);
    double BC = findDistance(second,third);
    return pow(AB,2)==pow(AC,2)+pow(BC,2)||pow(AC,2)==pow(AB,2)+pow(BC,2)||pow(BC,2)==pow(AB,2)+pow(AC,2);
}
bool isRightIsoscelesTriangle(const Point first, const Point second, const Point third){
    return isIsoscelesTriangle(first,second,third) && isRightTriangle(first,second,third);// là tam giác vuông, vừa là tam giác cân    
}
void typeOfTriangle(const Point first, const Point second, const Point third){
    if(canFormEgdeOfTriAngle(first,second)&&canFormEgdeOfTriAngle(first,third)&&canFormEgdeOfTriAngle(second,third)&&isPointOfTriAngle(first,second,third)){
        if(isEquilateralTriangle(first,second,third)){
            printf("This is equilateral triangle\n");
        }else if(isIsoscelesTriangle(first,second,third)){
            printf("This is isosceles triangle\n");
        }else if(isRightTriangle(first,second,third)){
            printf("This is right triangle\n");
        }else if(isRightIsoscelesTriangle(first,second,third)){
            printf("This is right isosceles triangle\n");
        }else{
            printf("This is normal triangle\n");
        }
    }else{
        printf("This is not a triangle!\n");
    }
}