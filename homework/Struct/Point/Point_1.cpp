/*TODO: viết chương trình:
- nhập vào 3 điểm
- kiểm tra xem 3 điểm đó lập thành tam giác hay không?
- kiểm tra xem 3 điểm đó lập thành tam giác gì?
 */
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
void canFormEgdeOfTriAngle(const Point first, const Point second);// 2 điểm có thể tạo thành một cạnh tam giác?
void isPointOfTriAngle(const Point first, const Point second, const Point third);// là 3 đỉnh của tam giác?
bool isEquilateralTriangle(const Point first, const Point second, const Point third);// là tam giác đều
bool isIsoscelesTriangle(const Point first, const Point second, const Point third);// là tam giác cân
bool isRightTriangle(const Point first, const Point second, const Point third);// là tam giác vuông
bool isRightIsoscelesTriangle(const Point first, const Point second, const Point third);// là tam giác vuông cân 
void print(const Point output);// in ra 1 điểm
void print(const Point first, const Point second, const Point third);// in ra 3 điểm tam giác
void printTrianglePerimeter(const Point first, const Point second, const Point third);// in ra chu vi tam giác
void printTriangleArea(const Point first, const Point second, const Point third);// in ra diện tích tam giác
int main(){
    Point first, second, third;
    enter(&first,&second,&third);
    printTrianglePerimeter(first, second, third);
    printTriangleArea(first,second,third);
    return 0;
}
// TODO: hoàn thiện các hàm
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
double findDistance(const Point first, const Point second){
    double distance = sqrt((double)(first.x-second.x)*(first.x-second.x)+(first.y-second.y)*(first.y-second.y));//NOTE: khởi gán luôn nhé
    return distance;
}
double findTrianglePerimeter(const Point first, const Point second, const Point third){// NOTE: có những chỗ a có thể sai nên sửa lại nhé
    // NOTE: đưa xuống cho dễ đọc nhé
    double AB = findDistance(first,second);
    double AC = findDistance(first,third);
    double BC = findDistance(second,third);
    return AB + AC + BC;
}
double findTriangleArea(const Point first, const Point second, const Point third){
    // sửa lại nhé
    double AB = findDistance(first,second);
    double AC = findDistance(first,third);
    double BC = findDistance(second,third);
    double triagle_perimeter = findTrianglePerimeter(first,second,third);
    return sqrt(triagle_perimeter*(triagle_perimeter-AB)*(triagle_perimeter-AC)*(triagle_perimeter-BC));
}
void printTrianglePerimeter(const Point first, const Point second, const Point third){
    double triagle_perimeter = findTrianglePerimeter(first,second,third);
    printf("triangle perimeter = %lf\n",triagle_perimeter);
}
void printTriangleArea(const Point first, const Point second, const Point third){
    double triagle_area = findTriangleArea(first,second,third);
    printf("triangle area = %lf\n",triagle_area);
}