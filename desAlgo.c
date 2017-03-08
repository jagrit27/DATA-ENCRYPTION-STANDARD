#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define ROUNDS 16

int *getExpandedMessage (char Initial_Message[9]);
int *getExpandedKey (char Initial_Key[9]);
int *getKeyPermutation (int Expanded_Key[64], int Key_Permutation[56]);
int *getPermutedMessage (int initial_Permutation[64], int *Expanded_Message);
void printArr (int *arr, int sz);
void printHexArr (int *arr, int sz);
void expansion_E_Table (int *Right_Message, int *Expanded_Right_message);
void substitution (int *Right_Message, int *temp_Msg_Right);
int getRow (int *temp_Msg_Right, int i);
int getColumn (int *temp_Msg_Right, int i);
void roundPermutation (int *Right_Message);
int* Final_Permutation (int *Rounded_Message);
int *getHexFromBits (int *message);
int isTwoShiftRound (int round);
<<<<<<< HEAD:desAlgo.c
void desAlgo(char Initial_Message[9] ,char Initial_Key[9]);
char *getStringFromBits (int *message);
void writeToFile (char *message);

int main ()
{
    FILE *fp = fopen("input.txt", "r");
    char plainTextBuffer[100] ,Initial_Key[9], messageStream[9], streamIdx;
    int i;

    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        return 0;
    }

    // EXTRACTING KEY
	printf("enter key \n");
	scanf(" %[^\n]s", Initial_Key);

    fgets(plainTextBuffer, 100, fp);

    plainTextBuffer [ strlen (plainTextBuffer) - 1 ] = '\0';

    streamIdx = 0;
    for(i = 0; plainTextBuffer[i] != '\0'; i++)
    {
        if((i % 8 == 7) || (plainTextBuffer[i+1] == '\0'))
        {
            messageStream[streamIdx ++] = plainTextBuffer [i];
            messageStream[streamIdx] = '\0';
            printf("String -%s-\n", messageStream);
            desAlgo (messageStream, Initial_Key);
            streamIdx = 0;
        }
        else
        {
            messageStream[streamIdx ++] = plainTextBuffer [i];
        }
    }

    fclose(fp);
    return 0;
}
=======
>>>>>>> edc1f36beeff20d6a5894a82ebd3ccfec9bbc95f:desAlgo.c

void desAlgo(char Initial_Message[9] ,char Initial_Key[9])
{
<<<<<<< HEAD:desAlgo.c
=======
	char Initial_Message[9] , Initial_Key[9];
>>>>>>> edc1f36beeff20d6a5894a82ebd3ccfec9bbc95f:desAlgo.c
	int i, j, k, round;

    /*
	// EXTRACTING MESSAGE
	printf("enter your message \n " );
	scanf (" %[^\n]s", Initial_Message);
    */
	int* Expanded_Message = getExpandedMessage (Initial_Message);

/*
<<<<<<< HEAD:desAlgo.c
	int Expanded_Message [64] = { 0,0,0,0
	,0,0,0,1, 0,0,1,0 ,0,0,1,1 ,0,1,0,0
	,0,1,0,1 ,0,1,1,0, 0,1,1,1 ,1,0,0,0,
	1,0,0,1 ,1,0,1,0, 1,0,1,1, 1,1,0,0, 1,1,0,1 ,1,1,1,0, 1,1,1,1};

*/
	// ("Expanded Message\n");
	//printArr (Expanded_Message, 56);

=======
	int Expanded_Message [64] = { 0,0,0,0 
	,0,0,0,1, 0,0,1,0 ,0,0,1,1 ,0,1,0,0 
	,0,1,0,1 ,0,1,1,0, 0,1,1,1 ,1,0,0,0, 
	1,0,0,1 ,1,0,1,0, 1,0,1,1, 1,1,0,0, 1,1,0,1 ,1,1,1,0, 1,1,1,1};

*/
	printf ("Expanded Message\n");
	printArr (Expanded_Message, 56);
		
	// EXTRACTING KEY
	printf("enter key \n ");
	scanf(" %[^\n]s", Initial_Key);
	
>>>>>>> edc1f36beeff20d6a5894a82ebd3ccfec9bbc95f:desAlgo.c
	int* Expanded_Key = getExpandedKey (Initial_Key);
	/*
	int Expanded_Key [64] = {0,0,0,1,0,0,1,1,
							 0,0,1,1,0,1,0,0,
<<<<<<< HEAD:desAlgo.c
							 0,1,0,1,0,1,1,1,
							 0,1,1,1,1,0,0,1,
							 1,0,0,1,1,0,1,1,
							 1,0,1,1,1,1,0,0,
							 1,1,0,1,1,1,1,1,
=======
							 0,1,0,1,0,1,1,1, 
							 0,1,1,1,1,0,0,1, 
							 1,0,0,1,1,0,1,1, 
							 1,0,1,1,1,1,0,0, 
							 1,1,0,1,1,1,1,1, 
>>>>>>> edc1f36beeff20d6a5894a82ebd3ccfec9bbc95f:desAlgo.c
							 1,1,1,1,0,0,0,1};
	*/
	// 	Creating Key Permutation
	int Key_Permutation[56] =
	{
		57,   49,    41,   33,    25,    17,    9,
		 1,   58,    50,   42,    34,    26,   18,
		10,    2,    59,   51,    43,    35,   27,
		19,   11,     3,   60,    52,    44,   36,
		63,   55,    47,   39,    31,    23,   15,
		 7,   62,    54,   46,    38,    30,   22,
		14,    6,    61,   53,    45,    37,   29,
		21,   13,     5,   28,    20,    12,    4
	};

	int* Permuted_Key = getKeyPermutation (Expanded_Key, Key_Permutation);
	//printf ("Permuted key\n");
	//printArr (Permuted_Key, 56);
<<<<<<< HEAD:desAlgo.c


=======
	
	
>>>>>>> edc1f36beeff20d6a5894a82ebd3ccfec9bbc95f:desAlgo.c
	// Divide the permuted key into 2 blocks of 28-bits each
	int Left_Key[28], Right_Key[28];

	for (i = 0; i < 56; i++)
	{
		if (i < 28)
			Left_Key[i] = Permuted_Key[i];
		else
			Right_Key[i - 28] = Permuted_Key[i];
	}
	//printArr (Left_Key, 28);
	//printArr (Right_Key, 28);
<<<<<<< HEAD:desAlgo.c

	int final_key_permutation [48] =
=======
		
	int final_key_permutation [48] = 
>>>>>>> edc1f36beeff20d6a5894a82ebd3ccfec9bbc95f:desAlgo.c
	{
		14,    17,   11,    24,     1,    5,
		3,     28,   15,     6,    21,   10,
		23,    19,   12,     4,    26,    8,
		16,     7,   27,    20,    13,    2,
		41,    52,   31,    37,    47,   55,
		30,    40,   51,    45,    33,   48,
		44,    49,   39,    56,    34,   53,
        46,    42,   50,    36,    29,   32
	};

	//printf("left arr\n");
	//printArr (Left_Key, 28);
	//printf("right arr\n");
	//printArr (Right_Key, 28);
	//printf("Block keys\n");
<<<<<<< HEAD:desAlgo.c

	// Create Ci and Di for 1 <= i <= 8
	int Block_Key_Left[ROUNDS][28], Block_Key_Right[ROUNDS][28], temp_left, temp_right;
	int final_Keys[ROUNDS][48];

=======
		
	// Create Ci and Di for 1 <= i <= 8
	int Block_Key_Left[ROUNDS][28], Block_Key_Right[ROUNDS][28], temp_left, temp_right;
	int final_Keys[ROUNDS][48];
	
>>>>>>> edc1f36beeff20d6a5894a82ebd3ccfec9bbc95f:desAlgo.c
	//Initializing Block_Key_Left & Block_Key_Right
	for(i = 0; i < 1; i++)
	{
		for(j = 0; j < 28; j++)
		{
			Block_Key_Left [i][j] = Left_Key [j];
			Block_Key_Right [i][j] = Right_Key [j];
		}
	}

	for (i = 0; i < ROUNDS; i++)
	{
		if (isTwoShiftRound (i))
		{
			temp_left = Block_Key_Left[i][0];
			temp_right = Block_Key_Right[i][0];

			for (j = 0; j < 27; j++)
			{
				Block_Key_Left[i][j] = Block_Key_Left[i][j + 1];
				Block_Key_Right[i][j] = Block_Key_Right[i][j + 1];
			}

			Block_Key_Left[i][j] = temp_left;
			Block_Key_Right[i][j] = temp_right;

		}

		// Two left shift

		temp_left = Block_Key_Left[i][0];
		temp_right = Block_Key_Right[i][0];

		for (j = 0; j < 27; j++)
		{
			Block_Key_Left[i][j] = Block_Key_Left[i][j + 1];
			Block_Key_Right[i][j] = Block_Key_Right[i][j + 1];
		}

		Block_Key_Left[i][j] = temp_left;
		Block_Key_Right[i][j] = temp_right;

		if((i+1) != ROUNDS)
		{
			for(j = 0; j < 28; j++)
			{
				Block_Key_Left [i+1][j] = Block_Key_Left[i][j];
				Block_Key_Right [i+1][j] = Block_Key_Right[i][j];
			}
		}
<<<<<<< HEAD:desAlgo.c

=======
			
>>>>>>> edc1f36beeff20d6a5894a82ebd3ccfec9bbc95f:desAlgo.c
		//printArr (Block_Key_Left[i], 28);
		//printArr (Block_Key_Right[i], 28);

		for(k = 0; k < 48; k++)
		{
			if( final_key_permutation[k] <= 28 )
				final_Keys [i][k] = Block_Key_Left [i][final_key_permutation[k] - 1];
			else
				final_Keys [i][k] = Block_Key_Right [i][final_key_permutation[k] - 28 - 1];
		}
	}

	for(i = 0; i < ROUNDS; i++)
	{
		//printf("%d\n", i);
		//printArr (final_Keys[i], 48);
	}

	//Initial Permutaion
	int Initial_Permutation [64] =
	{
		58,    50,   42,    34,    26,   18,    10,    2,
		60,    52,   44,    36,    28,   20,    12,    4,
		62,    54,   46,    38,    30,   22,    14,    6,
		64,    56,   48,    40,    32,   24,    16,    8,
		57,    49,   41,    33,    25,   17,     9,    1,
		59,    51,   43,    35,    27,   19,    11,    3,
		61,    53,   45,    37,    29,   21,    13,    5,
		63,    55,   47,    39,    31,   23,    15,    7
	};

	int *Permuted_Message = getPermutedMessage (Initial_Permutation, Expanded_Message);
	//printf ("Permuted msg\n");
<<<<<<< HEAD:desAlgo.c
	//printArr(Permuted_Message, 64);
=======
	//printArr(Permuted_Message, 64); 
>>>>>>> edc1f36beeff20d6a5894a82ebd3ccfec9bbc95f:desAlgo.c
	//printf("\n--\n");

	// Divide the permuted message into 2 blocks of 32-bits each
	int Left_Message[32], Right_Message[32], temp_Msg_Left[32], temp_Msg_Right[48];


	for (i = 0; i < 64; i++)
	{
		if (i < 32)
			Left_Message[i] = Permuted_Message[i];
		else
			Right_Message[i - 32] = Permuted_Message[i];
	}

	for(round = 0; round < ROUNDS; round ++)
	{
		//printf("\nS - left\n");
		//printArr (Left_Message, 32);
		//printf("S - Right\n");
		//printArr (Right_Message, 32);
		//Sture Left [i-1] & Right [i-1]
		for (i = 0; i < 32; i++)
		{
			temp_Msg_Left[i] = Left_Message[i];
		}

		// Left[i] = Right[i-1]
		for (i = 0; i < 32; i++)
		{
			Left_Message[i] = Right_Message[i];
		}

		//Right[i] = Left[i-1] + F (Rigth[i-1], k[i])
		//E Table
		//printf("%d\n", round);
		//printArr (temp_Msg_Right, 48);
		expansion_E_Table (Right_Message, temp_Msg_Right);
		//printf("Expanded Right\n");
		//printArr (temp_Msg_Right, 48);

		//printf("Final key \n");
		//printArr (final_Keys[round], 48);
		//XOR
		for(i = 0; i < 48; i++)
		{
			temp_Msg_Right[i] = temp_Msg_Right[i] ^ final_Keys[round][i];
		}
		//printf("Xored Right\n");
		//printArr (temp_Msg_Right, 48);

		//s boxes
		substitution (Right_Message, temp_Msg_Right);
		//printf("S boxed Right\n");
		//printArr (Right_Message, 32);

		//permutation
		roundPermutation (Right_Message);
		//printf("perrmuted Right\n");
		//printArr (Right_Message, 32);

		//XOR
		for(i = 0; i < 32; i++)
		{
			Right_Message[i] = Right_Message[i] ^ temp_Msg_Left[i];
		}

		//printf("left\n");
		//printArr (Left_Message, 32);
		//printf("Right\n");
		//printArr (Right_Message, 32);
	}
<<<<<<< HEAD:desAlgo.c
	//printf("\n");
=======
	printf("\n");
>>>>>>> edc1f36beeff20d6a5894a82ebd3ccfec9bbc95f:desAlgo.c

	int After_Round_Message [64];

	//combine left & right

	for(i=0 ; i<64 ; i++)
	{
		if(i<32)
			After_Round_Message[i] = Right_Message[i];
		else
			After_Round_Message[i] = Left_Message[i-32];
	}

<<<<<<< HEAD:desAlgo.c
	//printf("After round\n");
	//printArr (After_Round_Message, 64);


	int *Encrypted_Message_in_Bits = Final_Permutation (After_Round_Message);

	//printf("final permuted \n");
	//printArr (Encrypted_Message_in_Bits, 64);


	//int *Encrypted_Message = getHexFromBits (Encrypted_Message_in_Bits);
	char *Encrypted_Message = getStringFromBits (Encrypted_Message_in_Bits);

	printf ("-%s-\n", Encrypted_Message);

	writeToFile (Encrypted_Message);
	//printHexArr (Encrypted_Message, 16);

	//printf ("Answer - %s\n", Encrypted_Message);


=======
	printf("After round\n");
	printArr (After_Round_Message, 64);
	

	int *Encrypted_Message_in_Bits = Final_Permutation (After_Round_Message);

	printf("final permuted \n");
	printArr (Encrypted_Message_in_Bits, 64);


	int *Encrypted_Message = getHexFromBits (Encrypted_Message_in_Bits);

	printf ("\nMsg\n");
	printHexArr (Encrypted_Message, 16);

	//printf ("Answer - %s\n", Encrypted_Message);
	

>>>>>>> edc1f36beeff20d6a5894a82ebd3ccfec9bbc95f:desAlgo.c
	free (Encrypted_Message);
	free (Encrypted_Message_in_Bits);
	free (Expanded_Message);
	free (Expanded_Key);
	free (Permuted_Key);
	free (Permuted_Message);
}

void writeToFile (char *message)
{
    FILE *fp = fopen("encrypted.txt", "a");

    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    fputs(message, fp);
    fclose(fp);
}

int *getHexFromBits (int *message)
{
	int *Encrypted_Message = (int *)malloc (sizeof(int) * 16);
	int radix_2 = 1, i, j = 0, hex, msgIdx = 0;

	//printf("\nHEX\n");

	for(i = 0; i < 64; i += 4)
	{
		j = 3;
		hex = 0;
		radix_2 = 1;
		while (j >= 0)
		{
			hex += message[i+j] * radix_2;
			radix_2 *= 2;
			j--;
		}

		//printf ("%d ", hex);
		Encrypted_Message[msgIdx++] = hex;
	}

	return Encrypted_Message;
}

char *getStringFromBits (int *message)
{
	char *Encrypted_Message = (char *)malloc (sizeof(char) * 9);
	int radix_2 = 1, i, j = 0, ch, msgIdx = 0;

	//printf("\nHEX\n");

	for(i = 0; i < 64; i += 8)
	{
		j = 7;
		ch = 0;
		radix_2 = 1;
		while (j >= 0)
		{
			ch += message[i+j] * radix_2;
			radix_2 *= 2;
			j--;
		}

		//printf ("%d ", hex);
		Encrypted_Message[msgIdx++] = ch;
	}
	Encrypted_Message[msgIdx] = '\0';

	return Encrypted_Message;
}

int isTwoShiftRound (int round)
{
	if(round == 0 || round == 1 || round == 8 || round == 15)
		return 0;
	return 1;
}

int *getHexFromBits (int *message)
{
	int *Encrypted_Message = (int *)malloc (sizeof(int) * 16);
	int radix_2 = 1, i, j = 0, hex, msgIdx = 0;

	//printf("\nHEX\n");

	for(i = 0; i < 64; i += 4)
	{
		j = 3;
		hex = 0;
		radix_2 = 1;
		while (j >= 0)
		{
			hex += message[i+j] * radix_2;
			radix_2 *= 2;
			j--;
		}

		//printf ("%d ", hex);
		Encrypted_Message[msgIdx++] = hex;
	}

	return Encrypted_Message;
}

int isTwoShiftRound (int round)
{
	if(round == 0 || round == 1 || round == 8 || round == 15)
		return 0;
	return 1;
}

void expansion_E_Table (int *Right_Message, int *Expanded_Right_message)
{
	int i;

	int E_Permutation [48] =
	{
		32,     1,    2,     3,     4,    5,
		 4,     5,    6,     7,     8,    9,
		 8,     9,   10,    11,    12,   13,
		12,    13,   14,    15,    16,   17,
		16,    17,   18,    19,    20,   21,
		20,    21,   22,    23,    24,   25,
		24,    25,   26,    27,    28,   29,
		28,    29,   30,    31,    32,    1
	};

	for(i = 0; i < 48; i++)
		Expanded_Right_message[i] = Right_Message[ E_Permutation[i] - 1 ];
}

void substitution (int *Right_Message, int *temp_Msg_Right)
{
	int i, row, col, j, int_16, extractMSB;

	int S_Boxes [8][64] =
	{
		{
			14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
			 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
			 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
			15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13
		},
		{
			15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
			 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
			 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
			13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9
		},
		{
			10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
			13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
			13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
			1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12
		},
		{
			7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
			13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
			10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
			3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14
		},
		{
			2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
			14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
			 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
			11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3
		},
		{
			12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
			10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
			 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
			4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13
		},
		{
			4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
			13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
			 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
			6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12
		},
		{
			13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
			 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
			 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
			2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11
		}
	};
	//printf("in s box\n");
	j = 0;
	for(i = 0; i < 48; i += 6)
	{
		row = getRow (temp_Msg_Right, i);
		col = getColumn (temp_Msg_Right, i);

		//printf ("r - %d\n", row);
		//printf ("c - %d\n", col);

		int_16 = S_Boxes [(i / 6)][row*16 + col];
		//printf("got - %d\n", int_16);

		extractMSB = 3;
		while (extractMSB >= 0)
		{
			if( int_16 & (1 << extractMSB) )
				Right_Message [j++] = 1;
			else
				Right_Message [j++] = 0;
			extractMSB --;
		}
	}

}

int getRow (int *temp_Msg_Right, int i)
{
	return ( 2*temp_Msg_Right[i] + temp_Msg_Right[i+5] );
}

int getColumn (int *temp_Msg_Right, int i)
{
	return ( 8*temp_Msg_Right[i+1] + 4*temp_Msg_Right[i+2] + 2*temp_Msg_Right[i+3] + temp_Msg_Right[i+4] );
}


void roundPermutation (int *Right_Message)
{
	int tempArr[32], i;

	for(i = 0; i < 32; i ++)
		tempArr [i] = Right_Message [i];

	int Round_Permutaion [32] =
	{
		16,   7,  20,  21,
		29,  12,  28,  17,
		 1,  15,  23,  26,
		 5,  18,  31,  10,
		 2,   8,  24,  14,
		32,  27,   3,   9,
		19,  13,  30,   6,
		22,  11,   4,  25
	};

	for(i = 0; i < 32; i ++)
		Right_Message [i] = tempArr [ Round_Permutaion[i] - 1 ];
}

int* Final_Permutation (int *Rounded_Message)
{
	int i, *Encrypted_MEssage;

	Encrypted_MEssage = (int *)malloc ((sizeof(int) * 64));


	int Final_Permutaion [64] =
	{		40,  8, 48, 16, 56, 24, 64, 32,
			39,  7, 47, 15, 55, 23, 63, 31,
			38,  6, 46, 14, 54, 22, 62, 30,
			37,  5, 45, 13, 53, 21, 61, 29,
			36,  4, 44, 12, 52, 20, 60, 28,
			35,  3, 43, 11, 51, 19, 59, 27,
			34,  2, 42, 10, 50, 18, 58, 26,
		33, 1, 41, 9, 49, 17, 57, 25
	};


	for(i = 0; i < 64; i ++)
		Encrypted_MEssage [i] = Rounded_Message [ Final_Permutaion[i] - 1 ];
	return Encrypted_MEssage;
}

/*
*Function to perform initial permutation on the 64-bit array.
*
*@params
*  int Initial_Permutation[64] (Permutaion Hash Table)
*  int *Expanded_Message (64-bit plaintext)
*/
int *getPermutedMessage (int Initial_Permutation[64], int *Expanded_Message)
{
	int i;

	int *Permuted_message = (int *)malloc (sizeof(int) * 64);

	for(i = 0; i < 64; i++)
	{
		Permuted_message [i] = Expanded_Message [Initial_Permutation [i] - 1];
	}

	return Permuted_message;
}

void printArr (int *arr, int sz)
{
	int i;
	for(i = 0; i < sz; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	printf("\n");
}

void printHexArr (int *arr, int sz)
{
	int i;
	for(i = 0; i < sz; i++)
	{
		if(arr[i] == 10)
			printf("A ");
		else if(arr[i] == 11)
			printf("B ");
		else if(arr[i] == 12)
			printf("C ");
		else if(arr[i] == 13)
			printf("D ");
		else if(arr[i] == 14)
			printf("E ");
		else if(arr[i] == 15)
			printf("F ");
		else
			printf("%d ", arr[i]);
	}
<<<<<<< HEAD:desAlgo.c
    printf("\n");
=======
	printf("\n");
	printf("\n");
>>>>>>> edc1f36beeff20d6a5894a82ebd3ccfec9bbc95f:desAlgo.c
}

int* getExpandedMessage (char Initial_Message[9])
{
	int k = 0, j = 0, i;

	int *Expanded_Message = malloc (sizeof (int) * 64);

	for (i = 0; i < 8; i++)
	{
		j = 7;
		while (j >= 0)
		{
			if (Initial_Message[i] & (1 << j))
				Expanded_Message[k++] = 1;
			else
				Expanded_Message[k++] = 0;

			j--;
		}
	}
	/*
	printf ("k = %d\n", k);
	for (i = 0; i < 64; i++)
	{
		if (i % 8 == 0)
			printf ("\n");
		printf ("%d ", Expanded_Message[i]);
	}
	printf ("\n");
*/
	return Expanded_Message;
}

int *getExpandedKey (char Initial_Key[9])
{
	int i, j, k = 0;

	int *Expanded_Key = malloc (sizeof (int) * 64);

	for (i = 0; i < 8; i++)
	{
		j = 7;
		while (j >= 0)
		{
			if (Initial_Key[i] & (1 << j))
				Expanded_Key[k++] = 1;
			else
				Expanded_Key[k++] = 0;

			j--;
		}
	}
	/*
	printf ("k = %d\n", k);
	for (i = 0; i < 64; i++)
	{
		if (i % 8 == 0)
			printf ("\n");
		printf ("%d ", Expanded_Key[i]);
	}
	printf ("\n");
*/
<<<<<<< HEAD:desAlgo.c
	return Expanded_Key;
=======
	return Expanded_Key;	
>>>>>>> edc1f36beeff20d6a5894a82ebd3ccfec9bbc95f:desAlgo.c
}

int *getKeyPermutation (int Expanded_Key[64], int Key_Permutation[56])
{
	int i;
	int* Permuted_Key = malloc (sizeof (int) * 56);

	for (i = 0; i < 56; i++)
		Permuted_Key[i] = Expanded_Key[Key_Permutation[i] - 1];
	/*
	for (i = 0; i < 56; i++)
	{
		if (i % 7 == 0)
			printf ("\n");
		printf ("%d ", Permuted_Key[i]);
	}
	printf ("\n");
*/
	return Permuted_Key;
}

