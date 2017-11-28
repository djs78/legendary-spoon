
#include <iostream>

int* doubleArray (int* arr, int SIZE); //Prototype for doubleArray
bool isReverse(int *, int *,int , int); //Prototype for isReverse
double pizza(int, int *, int *); //Prototype for pizza
int main(int argc, char** argv){

  return 0;

}


double pizza (int people, int*pizzas, int*slices)
  {
    int totalSlices = people*3;
    *pizzas = totalSlices/8;
    *slices = totalSlices%8;
    return *pizzas*11.95 + *slices*1.75;
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
		cout << "The given array doesn't have the same size." << endl;
		return status;
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
			//by one, if the value are not the same in the specified
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
//*duplicateArray: Works with the subArray function to perform 
//what subarray does
//
//*array1- array
//
//returns: a duplicated array
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
//SubArray: created a new array that is a copy of the elements from the 
//original array starting at the index, and has length
//equal to the length arguement.
//*arrray- the array
//start - where the array starts or index of the array
//length - the length of array
//********************************************************************
int *subArray (int *array, int start, int length) { 
int *result = duplicateArray( array + start, length);
    return result;
}
