#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

// Code for suffix array from Competitive Programming 3
#define ii pair<int, int>

// At most 100000 characters in dict, and 20000 words with ending character.
const int MaxN = 125010;
char T[MaxN];
int N;
// SA: Index from sorted suffix i to position in string
// RA: At i, is rank of SA in all 
int SA[MaxN], tempSA[MaxN];
int RA[MaxN], tempRA[MaxN];

// Tested for non-circular!
int c[MaxN];
void radixSort(int k) { // O(n), numbers up to N, any chars
	int i, maxi = max(300, N);
	memset(c, 0, sizeof c);
	for (i = 0; i < N; ++i) {// Integer rank freq
		int index = i + k < N ? RA[i + k] : 0;
		c[index]++;
	}
	int sum = 0;
	for (i = 0; i < maxi; ++i) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for (i = 0; i < N; ++i) { // Shuffle sufix array.
		int indexToRA = SA[i] + k;
		int indexToC = indexToRA < N ? RA[indexToRA] : 0;
		int indexToTempSA = c[indexToC]++;
		tempSA[indexToTempSA] = SA[i];
	}
	for (i = 0; i < N; ++i)
		SA[i] = tempSA[i];
}

// Tested for non-circular!
void constructSA() {
	int i;
	for (i = 0; i < N; ++i)
		RA[i] = T[i];
	for (i = 0; i < N; ++i)
		SA[i] = i;
	for (int k = 1; k < N; k <<= 1) {
		radixSort(k); // Sort based on value k indicies after
		radixSort(0); // Sort based on current value of self (stable)
		int r = 0; // Rank, starting from 0.
		tempRA[SA[0]] = r;
		for (i = 1; i < N; ++i) {
			tempRA[SA[i]] =
				// Note that second condition will only be hit if SAs + k < N. Otherwise they
				// would already be different, due to sorting to there
				(RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] +k] == RA[SA[i - 1] + k]) ? r : ++r;
		}
		for (i = 0; i < N; ++i)
			RA[i] = tempRA[i];
		if (RA[SA[N - 1]] == N - 1)
			break; // All have unique ranks.
	}
}


// Tested for non-circular. What would circular do?
// For world finals, will just give a description for what to do!
// Returns inclusive set of all matches of P[0-pLen] in the SA of N, O(|P|log|N|).
// pLen is exclusive.
char P[MaxN];
ii stringMatching(int pLen) {
	// Find lower bound on suffixes that match.
	int low = 0, high = N-1;
	while (low < high) {
		int mid = (low + high) / 2;
		int result = strncmp(T + SA[mid], P, pLen);
		if (result >= 0) high = mid; // At most this guy
		else low = mid + 1; // Can't include this guy
	}
	if (strncmp(T + SA[low], P, pLen) != 0)
		return ii(-1, -1); // Doesn't match.
	ii ans; ans.first = low;
	
	low = 0; high = N - 1;
	// Find upper bound on suffixes that match.
	while (low < high) {
		int mid = (low + high) / 2;
		int result = strncmp(T + SA[mid], P, pLen);
		if (result > 0) high = mid; // Too far into the array.
		else low = mid + 1; // Try only including above this guy.
	}
	if (strncmp(T + SA[high], P, pLen) != 0) // Went one past the end.
		--high;
	ans.second = high;
	return ans;
}

const int MaxNumWords = 20005;
int wordPriorityInSA[MaxN];
// Can do a lowerbound search on this!
int wordStart[MaxNumWords];
int wordLength[MaxNumWords];

struct FindWordsOrder
{
    bool operator()(const int i, const int j) const
    {
        if (wordLength[i] != wordLength[j])
            return wordLength[i] < wordLength[j];
        
		int cmp = strcmp(T + wordStart[i], T + wordStart[j]);
		if (cmp != 0)
			return cmp < 0;
		
		return i < j;
    }
};

int orderToWord[20005];
int wordToOrder[20005];

bool encounteredPriority[20005];

char loadedWord[MaxN];

int main() {
	int NumWords;
	cin >> NumWords;
	wordStart[0] = 0;
	for (int i = 0; i < NumWords; ++i) {
		scanf("%s", loadedWord);
		wordLength[i] = strlen(loadedWord);
		
		for (int j = 0; j < wordLength[i]; ++j) {
			T[j + wordStart[i]] = loadedWord[j];
		}
		T[wordStart[i] + wordLength[i]] = '\0';
		
		// Skip past the '\0'
		wordStart[i + 1] = wordStart[i] + wordLength[i] + 1;
	}
	
	// Determine ordering for words.
	for (int i = 0; i < NumWords; ++i)
		orderToWord[i] = i;
	
	sort(orderToWord, orderToWord + NumWords, FindWordsOrder());
	for (int i = 0; i < NumWords; ++i)
		wordToOrder[orderToWord[i]] = i;
	N = wordStart[NumWords];
	constructSA();
	
	// Create i in T -> wordNum
	for (int i = 0; i < N; ++i) {
		// Always overestimate by 1, then reduce down
		int word = upper_bound(wordStart, wordStart + NumWords, SA[i]) - wordStart - 1;
		wordPriorityInSA[i] = wordToOrder[word];
	}
	
    int Q;
    cin >> Q;
    while (Q--) {
		scanf("%s", P);
		int pLen = strlen(P);
		
		ii lower_upper = stringMatching(pLen);
		// No matches found!
		if (lower_upper.first == -1) {
			cout << "-1\n";
			continue;
		}
		memset(encounteredPriority, 0, sizeof(encounteredPriority));
		for (int i = lower_upper.first; i <= lower_upper.second; ++i) {
			encounteredPriority[wordPriorityInSA[i]] = true;
		}
		int printedOut = 0;
		for (int i = 0; i < NumWords; ++i) {
			if (encounteredPriority[i]) {
				if (printedOut)
					cout << ' ';
				cout << (orderToWord[i] + 1);
				++printedOut;
				if (printedOut == 10)
					break;
			}
		}
		if (printedOut == 0) {
			cout << "-1";
		}
		cout << '\n';
	}
}
