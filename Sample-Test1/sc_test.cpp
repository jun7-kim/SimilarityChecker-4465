#include "pch.h"
#include "../SimilarityChecker/similarity_checker.cpp"

TEST(SimilarityChecker, Length) {
	SimilarityChecker sc;
	EXPECT_EQ(60, sc.getLengthScore("ASD", "DSA"));
	EXPECT_EQ(0, sc.getLengthScore("A", "BB"));
	EXPECT_EQ(20, sc.getLengthScore("AAABB", "BAA"));
	EXPECT_EQ(30, sc.getLengthScore("AA", "AAA"));
}

TEST(SimilarityChecker, Alpha) {
	SimilarityChecker sc;
	EXPECT_EQ(40, sc.getAlphaScore("ASD", "DSA"));
	EXPECT_EQ(0, sc.getAlphaScore("A", "BB"));
	EXPECT_EQ(40, sc.getAlphaScore("AAABB", "BA"));
	EXPECT_EQ(20, sc.getAlphaScore("AA", "AAE"));
}