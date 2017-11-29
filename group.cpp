
#include <iostream>

int* doubleArray (int* arr, int SIZE); //Prototype for doubleArray
bool isReverse(int *, int *,int , int); //Prototype for isReverse
double pizza(int, int *, int *); //Prototype for pizza
int *duplicateArray(int *, int); //Prototype for duplicateArry
int *subArray (int *, int , int ); //Prototype for subArray

int main(int argc, char** argv){

  int size = 10;
  int arr1[size];
  int arr2[size];
  for(int it = 0; it < size; it++){
    arr1[it] = it;
    arr2[it] = size - 1 - it;
  }

  // ---------------------------------------------------------------------------
  // isReverse() function test
  std::cout << "\n\ntesting isReverse:\ntest data array 1: ";
  for(int it = 0; it < size; it++)
    std::cout << arr1[it] << " ";
  std::cout << "\ntest data array 2: ";
  for(int it = 0; it < size; it++)
    std::cout << arr2[it] << " ";
  std::cout << "\nExpected result: 1\nActual result: " << isReverse(arr1, arr2, size, size) << std::endl;


  std::cout << "test data array 1: ";
  for(int it = 0; it < size; it++)
    std::cout << arr1[it] << " ";
  std::cout << "\ntest data array 3: ";
  for(int it = 0; it < size; it++)
    std::cout << arr1[it] << " ";
  std::cout << "\nExpected result: 0\nActual result: " << isReverse(arr1, arr1, size, size) << std::endl;

  // ---------------------------------------------------------------------------
  // pizza() function test
  std::cout << "\n\ntesting pizza for 25 people:\n";
  int pizzas = 9;
  int slices = 3;
  double value = pizza(25, &pizzas, &slices);
  std::cout << "Expected result: 112.8 p:9 s:3" << std::endl;
  std::cout << "Actual result: " << value << " p: " << pizzas << " s: " << slices << std::endl;

  // ---------------------------------------------------------------------------
  // DoubleArray() function test
  std::cout << "\n\ntesting doubleArray:\ntest data: ";
  for(int it = 0; it < size; it++)
    std::cout << arr1[it] << " ";
  std::cout << "\nExpected result: 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9\nActual result: ";
  int* doubled_arr = doubleArray(arr1, size);
  for(int it = 0; it < size*2; it++)
    std::cout << doubled_arr[it] << " ";
  delete[] doubled_arr;
  doubled_arr = NULL;

  // ---------------------------------------------------------------------------
  // subArray() function test
  std::cout << "\n\n\ntesting subArray:\ntest data: ";
  for(int it = 0; it < size; it++)
    std::cout << arr1[it] << " ";
  std::cout << "\nstart: 5 length: 4\nExpected result: 5 6 7 8\nActual result: ";
  int length = 4;
  int* sub_array = subArray(arr1, 5, length);
  for(int it = 0; it < length; it++)
    std::cout << sub_array[it] << " ";
  delete[] sub_array;
  sub_array = NULL;
  std::cout << "\n\n\n";

  return 0;
}

double pizza (int people, int* pizzas, int* slices){
  int totalSlices = people*3;
  *pizzas = totalSlices/8;
  *slices = totalSlices%8;
  return *pizzas*11.95 + *slices*1.75;
}

int* doubleArray(int* arr, int size)
{
  //Create a dynamic array of double the size of integer array,arr
  int* darr = new int[size*2];

   //copy the elements of arr to darr
  for (int i = 0; i < size;i++)
    darr[i]=arr[i];

  //set start=0
  int start=0;
  for (int j = size;j < size * 2;j++,start++)
    darr[j]=arr[start];

  //return darr
  return darr;
}

/**********************************Prompt***********************************/
/*isReverse: takes two int arrays and the arrays’ sizes as arguments *******/
/*(4 arguments). It should return true if the second array is equivalent to*/
/*the first array in reverse order. Do not use square brackets anywhere in */
/*the function, not even the parameter list (use pointers instead). ********/
/***************************************************************************/
bool isReverse(int *array1, int *array2, int size1, int size2)
{
  
  bool status = false;
  int counter = 0;
  int i = size2-1;
  
  //If the given array doesn't have the same size then
  //the arrays wouldn't have the same values. Since
  //the values would be counted outside of the subscript.
  if(size1 != size2)
  {
    std::cout << "The given array doesn't have the same size." << std::endl;
    return status;  //If array doesn't have the same size return status which is false.
  }
  
  //Iterate i-- so to traverse the array
  //starting from the end all the way to the start.
  //While i iterates backward, index iterates forwards
  //starting from start of the array all the way to the end.
  //This checks if the values in the 2nd array is in reverse order.
  for(int index = 0; index < size1; index++, i--) 
  {            
    if(*(array1+index) == *(array2+i))  
    {
      //Counter marks off the values that are similar.
      //If the values are similar then counter will increment
      //by one, if the value is not the same in the specified
      //location then the counter will not increment.
      counter++;
    }
  }
  
  //This checks to see if the values that are marked by counter
  //is consistent with the size of the array.
  //Meaning if the values for the 2nd array is organized in reverse order
  //and the counter variable counted for all the values in the right order
  //then the size of the array should be the same with counter.
  if(counter == size1)
  {
    status = true;
  }
  
  return status;
}

//*********************duplicateArray********************************
//duplicateArray: duplicates array given with size
//int *arr = points at the array in main
//int size = passes the size of the orginal array from main
//*******************************************************************
int *duplicateArray (int *arr, int size) {
  int *newArray;
  if (size <= 0)         //size must be positive
    return NULL;        //NULL is 0, an invalid address
  newArray = new int [size];  //allocate new array
  for (int index = 0; index < size; index++)
    newArray[index] = arr[index];  //copy to new array
  return newArray;
}


//*************************SubArray***********************************
//SubArray: takes an int array, a start index and a length as arguments.  It 
//creates a new array that is a copy of the elements from the original array 
//subArray: Takes an array, creates a new one with only desired
//part of the orginal array

//int *array = points at the array in main
//int start = starting postion in the array desired
//int length = the amount of desired to be displayed after start
//returns: address of new array
//********************************************************************
int *subArray (int *array, int start, int length) { 
  int *result = duplicateArray(array + start, length);
  return result;
}
