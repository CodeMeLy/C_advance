#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int enter(int **array);
void print(int *array, int size);
int findMax(int *array, int size);
void printMax(int *array, int size);
int findMin(int *array, int size);
void printMin(int *array, int size);
void evenNumber(int *array, int size);
void oddNumber(int *array, int size);
bool isPrime(int n);
void primeCount(int *array, int size);
void squareNumber(int *array, int size);
bool findSymmetricalNumbers(int n);
void printSymmetricalNumbers(int *array, int size);
void enterValue(int &value);
int countNumbersOfValue(int *array, int size, int value);
int* findIndexOfValue(int *array, int size, int value);
int main(){
    int *array, value;
    int size;
    size = enter(&array);
    print(array,size);
    printMax(array,size);
    printMin(array,size);
    evenNumber(array,size);
    oddNumber(array,size);
    primeCount(array,size);
    squareNumber(array,size);
    printSymmetricalNumbers(array,size);
    enterValue(value);
    print(findIndexOfValue(array,size,value),countNumbersOfValue(array,size,value));
    return 0;
}
int enter(int **array){
    int size;
    int temp;
    printf("size of array: ");
    scanf("%d",&size);
    *array = (int*)malloc(size*sizeof(int));
    for(int index=0;index<size;index++){
        printf("array[%d]: ",index);
        scanf("%d",&temp);
        *(*array+index) = temp;
    }
    return size;
}
void print(int *array, int size){
    if(size ==0){
        printf("empty!");
    }
    else{
        for(int index = 0; index < size; index++){
            printf("%d ",array[index]);
        }
    }
}
int findMax(int *array, int size){
    int max=*(array+0);
    for(int i=1;i<size;i++){
        if(max<*(array+i)){
            max=*(array+i);
        }
    }
    return max;
}
void printMax(int *array, int size){
    printf("\nMax number of array is: %d",findMax(array,size));
}
int findMin(int *array, int size){
     int min=*(array+0);
    for(int i=1;i<size;i++){
        if(min>*(array+i)){
            min=*(array+i);
        }
    }
    return min;
}
void printMin(int *array, int size){
    printf("\nMin number of array is: %d",findMin(array,size));
}
void evenNumber(int *array, int size){
    printf("\nEven numbers of array is: ");
    for(int i=0;i<size;i++){
        if(*(array+i)%2==0){
            printf("\t%d", *(array+i));
        }
    }
}
void oddNumber(int *array, int size){
    printf("\nOdd numbers of array is: ");
    for(int i=0;i<size;i++){
        if(*(array+i)%2!=0){
            printf("\t%d", *(array+i));
        }
    }
}
bool isPrime(int n)
{ //kiểm tra số nguyên tố trong mảng
    bool prime = true;
    if (n < 2)
        prime = false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            prime = false;
        }
    }
    return prime;
}
void primeCount(int *array, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (isPrime(*(array+i)))
        {
            count++;
        }
    }
    printf("\nPrime numbers in array is: %d", count);
}
void squareNumber(int *array, int size){
    int count=0;
    for(int i=0;i<size;i++){
        if(sqrt(*(array+i))*sqrt(*(array+i))==*(array+i)){
            count++;
        }
    }
    printf("\nSquare numbers in array is: %d", count);
}
bool findSymmetricalNumbers(int n){
    //tìm số gánh(số đối xứng)
    int a[100];
	int value=(int)log10((float)n)+1;
	for(int i=0;i<value;i++){
		a[value-i-1]=n%10;
		n/=10;
	}
	for(int i=0;i<value;i++){
		if(a[i]!=a[value-i-1]){
            return a[i];
            break;
        }
	}
}
void printSymmetricalNumbers(int *array, int size){
    printf("\nSymmetrical numbers in array is: ");
    for(int i=0;i<size;i++){
        if(!findSymmetricalNumbers(*(array+i))){
            printf("\t%d",*(array+i));
        }else{
            printf("Don't have :P");
            break;
        }
    }
}
void enterValue(int &value){
    //nhập 1 giá trị bất kì
     printf("\nEnter a value: ");
    scanf("%d", &value);
}
int countNumbersOfValue(int *array, int size, int value){
    // đếm số lần xuất hiện của giá trị đó
    int count = 0;
    for(int index = 0; index < size; index++){
        if(array[index] == value){
            count++;
        }
    }
    return count;
}
int* findIndexOfValue(int *array, int size, int value){
    // tìm vị trí của giá trị đó
    int *result;
    int temp = 0;
    int size_result = countNumbersOfValue(array, size,value);
    result = (int*)calloc(size_result,sizeof(int));// cấp phát bộ nhớ
    for(int index = 0; index < size; index++){
        if(value == array[index]){
            result[temp] =  index;
            temp++;
        }
    }
    return result;
}