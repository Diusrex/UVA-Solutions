#include <iostream>

using namespace std;

// Note that the segment tree is built from the sequences, not individual indicies
    // So no need to merge sizes of the two children

int numSequences;
int indexToSequence[100005];
int startOfSequence[100005];

// Bit bigger than necessary
// Indexed from 1 (makes tree node calculation slightly easier)
int treeNodeSize[1000005];

// Note that the tree may NOT be correct for the sequences included on ends,
    // because tree will assume they are completely included
    // So those need to be handled specially
// Exclusive on end, inclusive on start
void MakeTree(int node, int sequenceStart, int sequenceEnd)
{
    if (sequenceStart + 1 == sequenceEnd)
    {
        treeNodeSize[node] = startOfSequence[sequenceStart + 1] - startOfSequence[sequenceStart];
        return;
    }
    
    int node1 = node * 2, node2 = node1 + 1;
    int middle = (sequenceStart + sequenceEnd) / 2;
    
    MakeTree(node1, sequenceStart, middle);
    MakeTree(node2, middle, sequenceEnd);
    
    treeNodeSize[node] = max(treeNodeSize[node1], treeNodeSize[node2]);
}

// Exclusive on end, inclusive on start (for both
int QueryTree(int node, int nodeSequenceStart, int nodeSequenceEnd, int wantedStart, int wantedEnd)
{
    // No intersection at all
    if (nodeSequenceStart >= wantedEnd || nodeSequenceEnd <= wantedStart)
    {
        return 0;
    }
    
    // Completely contained
    if (nodeSequenceStart >= wantedStart && nodeSequenceEnd <= wantedEnd)
    {
        return treeNodeSize[node];
    }
    
    // Partially contained, query subtree
    int node1 = node * 2, node2 = node1 + 1;
    int middle = (nodeSequenceStart + nodeSequenceEnd) / 2;
    
    return max(QueryTree(node1, nodeSequenceStart, middle, wantedStart, wantedEnd),
               QueryTree(node2, middle, nodeSequenceEnd, wantedStart, wantedEnd));
}


void ReadInput(int n)
{
    int numberOfFinishedSequences = 0, previousNum;
    
    indexToSequence[1] = 0;
    startOfSequence[0] = 1;
    cin >> previousNum;
    
    // Since they want [1, n]
    for (int i = 2; i <= n; ++i)
    {
        int current;
        cin >> current;
        if (current != previousNum)
        {
            ++numberOfFinishedSequences;
            startOfSequence[numberOfFinishedSequences] = i;
            previousNum = current;
        }
        indexToSequence[i] = numberOfFinishedSequences;
    }
    ++numberOfFinishedSequences;
    
    // Ensure that final one is finished properly, would be start of n + 1th element
    startOfSequence[numberOfFinishedSequences] = n + 1;
    
    numSequences = numberOfFinishedSequences;
}

int main()
{
    int n, q;
    while (cin >> n >> q, n)
    {
        ReadInput(n);
        MakeTree(1, 0, numSequences);
        
        while (q--)
        {
            int startIndex, endIndex;
            cin >> startIndex >> endIndex;
            
            // Should go to the first that includes it. Upperbound will always give the second sequence
            int firstSequence = indexToSequence[startIndex];
            int lastSequence = indexToSequence[endIndex];
            
            int best = min(startOfSequence[firstSequence + 1], endIndex + 1) - max(startOfSequence[firstSequence], startIndex);
            
            // Larger than just one
            if (firstSequence != lastSequence)
            {
                best = max(best,
                        min(startOfSequence[lastSequence + 1], endIndex + 1) - startOfSequence[lastSequence]);
                
                // Instead of iterate through middle, query sequences
                best = max(best, QueryTree(1, 0, numSequences, firstSequence + 1, lastSequence));
            }
            
            cout << best << '\n';
        }
        
    }
}