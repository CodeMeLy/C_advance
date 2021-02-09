/*** Viết chương trình
 * - nhập
 * - tìm kiếm giá trị max của mảng
 * - tìm kiếm giá trị min của mảng
 * - tìm kiếm một phần tử có trong mảng
 * - tìm kiếm vị trí của max trong mảng
 * - tìm kiếm vị trí của min trong mảng
 * - xuất
 * */
void enter(int &size);// nhập số lượng phần tử
void enter(int *array, int size);// nhập vào mảng
int findMax(int *array, int size);// tìm giá trị max
int findMin(int *array, int size);// tìm giá trị min
int* findIndexOfValue(int *array, int size, int value);// tìm vị trí của một giá trị nhập vào
int* findIndexOfMin(int *array, int size);// tìm vị trí min
int* findIndexOfMax(int *array, int size);// tìm vị trí max
int main(){
    int *array, size;
    // TODO: gọi hàm
    return 0;    
}
// TODO: xây dựng các hàm