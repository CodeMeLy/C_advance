// TODO: hoàn thiện những nội dung có trong todo
#include <stdio.h>
#include <assert.h>
void swap(int &first, int &second);                                           // hoán vị 2 số
int findMax(int *array, int size);                                            // tìm max của mảng
bool hasSameValues(int *first, int first_size, int *second, int second_size); // kiểm tra giá trị của 2 mảng có tương tự nhau hay không?
void ascSort(int *array, int size);                                           // sắp xếp tăng dần một mảng
// test function
void test_findMax(); // viết hàm test để kiểm tra giá trị max
void test_hasSameValues();
void test_ascSort();
int main()
{
    test_findMax();
    test_hasSameValues();
    test_ascSort();
    return 0;
}
<<<<<<< HEAD
void enter(int &size)
{
    // TODO: hoàn thiện hàm nhập vào số lượng phần tử
    printf("Enter n: ");
    scanf("%d", &size);
}
void swap(int &first, int &second)
{
=======
void swap(int &first, int &second){
>>>>>>> answer
    // TODO: hoàn thiện hàm swap
    int temp = first;
    first = second;
    second = temp;
}
// bị th
int findMax(int *array, int size)
{
    // TODO: hoàn thiện hàm tìm max
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}
bool hasSameValues(int *first, int first_size, int *second, int second_size)
{
    //NOTE: kĩ thuật đặt cờ hiệu
    //NOTE: cho một biến flag là nhận định ban đầu
    bool flag = true;// nhạn định 2 mảng có cùng giá trị là đúng
    //TODO: tìm cách phủ định nhạn định trên
    //NOTE: 1. không cùng giá trị khi không cùng size
    if(first_size!=second_size){// khác size
        flag = false;
    }
    //NOTE: 2. không cùng giá trị khi cùng size, nhưng từng cặp giá trị không trùng 
    else{// cùng size
        // ví dụ: first: 1 2 3 4 5
        //       second: 1 2 4 4 5
        //        index: 0 1 2 3 4, size = 5 = first_size = second_size
        for(int index = 0;index < first_size;index++){
            //if(first[index]!= second[index]){ first[index] có thể viết lại *(first+index)
             if(*(first+index)!=*(second+index)){// có thể viết lại
                flag = false;
                break;//thấy có 1 cặp khác nhau rồi thì không cần tìm lại nữa
             }     
            }
        }
    return flag;// trả về nhận định đó đúng hay sai
}
void ascSort(int *array, int size)
{
    // TODO: hoàn thiện hàm sắp xếp một mảng
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
// test
void test_findMax()
{
    printf("tìm max:");
    int array[13] = {3, 3, 4, 2, 5, 6, 6, 43, 7, 5, 3, 6, 4};
    assert(findMax(array, 13) == 43);
    printf("chính xác!\n");
}
void test_hasSameValues()
{
    printf("kiểm tra 2 mảng có cùng phần tử: ");
    int first[13] = {3, 3, 4, 2, 5, 6, 6, 43, 7, 5, 3, 6, 4};
    int second[13] = {3, 3, 4, 2, 5, 6, 6, 43, 7, 5, 3, 6, 4};
    assert(hasSameValues(first, 13, second, 13));
    printf("chính xác!\n");
}
void test_ascSort()
{
    printf("sắp xếp tăng dần: <\n");
    printf("\t -hoán vị: ");
    int first = 3, second = 2;
    bool swap_success = false;
    swap(first, second);
    assert(first == 2 && second == 3);
    printf("chính xác!\n");
    // sap xep
    int array[5] = {3, 2, 4, 4, 1};
    int sorted[5] = {1, 2, 3, 4, 4};
    printf("\t - sắp xếp tăng dần:");
    ascSort(array, 5);
    assert(hasSameValues(array, 5, sorted, 5));
    printf("chính xác!\n");
}