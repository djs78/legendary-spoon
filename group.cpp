
#include <iostream>

int* doubleArray (int* arr, int SIZE);
double pizza (int people, int*pizzas, int*slices)
  {
    int totalSlices = people*3;
    *pizzas = totalSlices/8;
    *slices = totalSlices%8;
    return *pizzas*11.95 + *slices*1.75;
 }

int main(int argc, char** argv){

  return 0;

}
int* doubleArray(int* arr, int size)
{
   //Create a dynamic array of double the size of integer array,arr
   int* darr=new int[size*2];

   //copy the elements of arr to darr
   for (int i = 0; i < size;i++)
       darr[i]=arr[i];

   //set start=0
   int start=0;
   for   (int j = size;j < size * 2;j++,start++)
       darr[j]=arr[start];


   //return darr
   return darr;
}
