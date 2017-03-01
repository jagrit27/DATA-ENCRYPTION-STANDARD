#include<stdio.h>

void initialPermutation (int *userArr);

/*
*input - Plaintext User string
*Output - Encrypted User string
*
*DES Algorithm
*/
int main ()
{
    int arr[64] , left[32] , right[32] , input , output ;
    	for(i= 0 ; i<64 ; i++ )
    	{
			scanf("%d" , &arr[i] ) ;
		}
		
		for(i = 0 ; i<64 ; i++ )
		{
			if(i<32)
			{
				left[i] = arr[i] ;
			}
			else
			{
				right[i] = arr[i] ;
			}
		}	
    
	    for(i = 0 ; i < 32 ; i++ )
	    {
			input[i] = right[i] ; 
		}
		
		for(i=0 ; i<16 ; i++ )
		{
			output = Round(i) ;
			input = 
    
    return 0;
}

/*
*Function to perform initial permutation on the 64-bit array. 
*
*@params
*  int *userArr (64-bit plaintext)
*/
void initialPermutation (int *userArr)
{
	int permutationHash[64] = {58, 50, 42, 34, 26, 18, 10, 2,
										60, 52, 44, 36, 28, 20, 12, 4,
										62, 54, 46, 38, 30, 22, 14, 6,
										64, 56, 48, 40, 32, 24, 16, 8,
										57, 49, 41, 33, 25, 17,  9, 1,
										59, 51, 43, 35, 27, 19, 11, 3,
										61, 53, 45, 37, 29, 21, 13, 5,
										63, 55, 47, 39, 31, 23, 15, 7};
	int tempArr[64];
	
	for(i=0 ; i<64 ; i++)
	{
		tempArr[i] = userArr[permutationHash[i]];
	
	}	
}
