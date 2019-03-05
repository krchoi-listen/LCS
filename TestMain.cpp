#include "LCSFinder.hpp"

int main(int argc, char ** argv)
{
//	char * strA = "cbabac";
//	char * strB = "abcabba";
//	char * strA = "banana";
//	char * strB = "cabana";
	char * strA = "abaacbacab";
	char * strB = "bacabbcaba";

	LCSFinder lcsFinder;

	lcsFinder.SetStrings(10, strA, 10, strB);
	lcsFinder.MakeLCSTable();
	lcsFinder.PrintTable();
	lcsFinder.RecoverLCS();
	return 0;
}

