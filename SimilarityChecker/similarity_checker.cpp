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
};
