#include <string>

using namespace std;

class SimilarityChecker
{
public:
	int getLengthScore(string str1, string str2)
	{
		int score = 0;

		int shortLength = getGapShortLength(str1, str2);
		int gap = getGap(str1, str2);
		score = (100 - (gap * 100) / shortLength) * 60 / 100;

		return (int)score;
	}

	int getAlphaScore(string str1, string str2)
	{
		return getSameCount(str1, str2) * 100 / getTotalCount(str1, str2) * 40 / 100;
	}

private:
	int getGapShortLength(string str1, string str2)
	{
		int str1Size = str1.size();
		int str2Size = str2.size();
		if (str1Size >= str2Size)
		{
			return str2Size;
		}
		return str1Size;
	}

	int getTotalCount(string str1, string str2)
	{
		int totalCnt = 0;
		for (char alphabet : ALPHABET_PATTERN)
		{
			if (isInStr(str1, alphabet) || isInStr(str2, alphabet)) {
				totalCnt++;
			}
		}
		return totalCnt;
	}

	int getSameCount(string str1, string str2)
	{
		int sameCnt = 0;
		for (char alphabet : ALPHABET_PATTERN)
		{
			if (isInStr(str1, alphabet) && isInStr(str2, alphabet)) {
				sameCnt++;
			}
		}
		return sameCnt;
	}

	int getGap(string str1, string str2)
	{
		int str1Size = str1.size();
		int str2Size = str2.size();
		if (str1Size >= str2Size)
		{
			return str1Size - str2Size;
		}
		return str2Size - str1Size;
	}

	bool isInStr(string str, char ch)
	{
		if (str.find(ch) != -1)	return true;
		return false;
	}

	const string ALPHABET_PATTERN = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
};
