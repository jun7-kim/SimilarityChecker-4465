#include "pch.h"
#include "../SimilarityChecker/similarity_checker.cpp"

TEST(SimilarityChecker, Length) {
	SimilarityChecker sc;
	EXPECT_EQ(60, sc.getLengthScore("ASD", "DSA"));
	EXPECT_EQ(0, sc.getLengthScore("A", "BB"));
	EXPECT_EQ(20, sc.getLengthScore("AAABB", "BAA"));
	EXPECT_EQ(30, sc.getLengthScore("AA", "AAA"));
}