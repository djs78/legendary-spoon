
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



/***************************************************************************/
/* The isReverese function tests the values inside two arrays***************/
/* This function checks over the first array and compares the values to the*/
/* second array to see if the values in the second array are the same but***/
/* lined up in a reverse order. ********************************************/
/***************************************************************************/


bool isReverse(int *array1, int *array2, int size1, int size2)
{
  
	bool status = false;
	int counter = 0;
	int i = size2-1;
	
  //If the given array doesn't have the same size then
  //the arrays wouldn't have the same values because
  
	if(size1 != size2)
	{
		cout << "The given array doesn't have the same size." << endl;
		return status;
	}
	
	for(int index = 0; index < size1; index++, i--)
	{
		if(*(array1+index) == *(array2+i))
		{
			counter++;
		}
	}
	
	
	if(counter == size1)
	{
		status = true;
	}
	
	return status;
}
