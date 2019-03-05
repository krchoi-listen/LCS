#ifndef __LCS_FINDER_H__
#define __LCS_FINDER_H__

#define MAX_LENGTH	16

class LCSFinder
{
private:
	char mStringA[MAX_LENGTH];
	char mStringB[MAX_LENGTH];
	char mStringLCS[MAX_LENGTH];
	int  mLCS[MAX_LENGTH+1][MAX_LENGTH+1];

	int  mLengthA;
	int  mLengthB;
	int  mLengthLCS;

public:
	LCSFinder();
	~LCSFinder() {}

	void ClearStrings();
	void ClearTable();

	void SetStrings(int paramLen1, char * paramStr1, int paramLen2, char * paramStr2);
	void MakeLCSTable();
	void RecoverLCS();

	void PrintTable();
};

#endif // __LCS_FINDER_H__

