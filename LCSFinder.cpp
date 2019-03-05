#include <stdio.h>

#include "LCSFinder.hpp"

LCSFinder::LCSFinder()
{
	mLengthA = 0;
	mLengthB = 0;
	mLengthLCS = 0;
	ClearStrings();
	ClearTable();
}

void LCSFinder::ClearStrings()
{
	int i;

	for (i = 0; i < MAX_LENGTH; i++)
	{
		mStringA[i] = '\0';
		mStringB[i] = '\0';
		mStringLCS[i] = '\0';
	}
}

void LCSFinder::ClearTable()
{
	int i, j;

	for (i = 0; i < MAX_LENGTH+1; i++)
	{
		for (j = 0; j < MAX_LENGTH+1; j++)
		{
			mLCS[i][j] = 0;
		}
	}
}

void LCSFinder::SetStrings(int paramLen1, char * paramStr1, int paramLen2, char * paramStr2)
{
	int i;

	if ((paramLen1 > MAX_LENGTH) || (paramLen2 > MAX_LENGTH))
		return;

	for (i = 0; i < paramLen1; i++)
		mStringA[i] = paramStr1[i];

	for (i = 0; i < paramLen2; i++)
		mStringB[i] = paramStr2[i];

	mLengthA = paramLen1;
	mLengthB = paramLen2;

	printf("Input Strings are: \n");
	printf("A(Length, String) --> (%d, %s)\n", mLengthA, paramStr1);
	printf("B(Length, String) --> (%d, %s)\n", mLengthB, paramStr2);
}

void LCSFinder::MakeLCSTable()
{
	int row, col;

	if ( (mLengthA == 0) || (mLengthB == 0) ) return;

	for (col = 0; col < mLengthB+1; col++) mLCS[0][col] = 0;

	for (row = 1; row < mLengthA+1; row++)
	{
		mLCS[row][0] = 0;
		for (col = 1; col < mLengthB+1; col++)
		{
			if (mStringA[row-1] != mStringB[col-1])
			{
				if (mLCS[row - 1][col] >= mLCS[row][col - 1])
					mLCS[row][col] = mLCS[row - 1][col];
				else
					mLCS[row][col] = mLCS[row][col - 1];
			}
			else
			{
				mLCS[row][col] = 1 + mLCS[row - 1][col -1];
			}
		}
	}
}

void LCSFinder::RecoverLCS()
{
	int row, col;
	int pos = 0;

	row = mLengthA;
	col = mLengthB;

	while ( (row > 0) || (col > 0) )
	{
		if (mStringA[row-1] != mStringB[col-1])
		{
			if (mLCS[row-1][col] == mLCS[row][col])
				row--;
			else 
				col--;
		}
		else
		{
			mStringLCS[pos++] = mStringA[row-1];
			row--;
			col--;
		}
	}

	printf("================================================\n");
	printf("LCS Found\n");
	printf("------------------------------------------------\n");

	for (col = pos-1; col >= 0; col--)
		printf("%c\t", mStringLCS[col]);
	printf("\n------------------------------------------------\n");
}

void LCSFinder::PrintTable()
{
	int row, col;

	printf("================================================\n");
	printf("LCS Table\n");
	printf("------------------------------------------------\n");

	if ( (mLengthA == 0) || (mLengthB == 0) )
		printf("Table is Empty\n");
	else
	{
		for (row = mLengthA; row >= 0; row--)
		{
			for (col = 0; col < mLengthB+1; col++)
			{
				printf("%d\t", mLCS[row][col]);
			}
			printf("\n");
		}
	}

	printf("------------------------------------------------\n");
}

