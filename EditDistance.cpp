#include<iostream>
#include<string>
using namespace std;


//Edit Distance using Dynamic Programming
int minDistance (string word1, string word2) {
	int len1 = word1.length();
	int len2 = word2.length();
	
	int** dp = new int*[len1+1];
	for (int i=0; i<len1+1 ; i++) 
		dp[i] = new int[len2+1];
	
	for (int i=0; i<= len1; i++) {
		dp[i][0] = i;
		}
		for (int j=0; j<= len2; j++) {
		dp[0][j] = j;
		}
		for( int i=0; i < len1; i++) {
			char c1 = word1[i];
			for (int j=0; j< len2; j++) {
				char c2= word2[j];
				if (c1 == c2) {
				dp[i+1][j+1] = dp [i][j];
				}
			else {
				int replace = dp[i][j] + 1;
				int insert = dp[i][j+1] +1;
				int delet = dp[i+1][j] + 1;

				int minimum = replace > insert ? insert : replace;
				minimum = delet > minimum? minimum : delet;
				dp [i+1][j+1] = minimum;
				}
		}
	}
		return dp[len1][len2];
}






int main() {
	string word1 = "hot";
	string word2 = "hotter";
	cout << minDistance(word1, word2);

	return 0;
}