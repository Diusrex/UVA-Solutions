#include <iostream>
#include <vector>
#include <set>

using namespace std;


int shoesInPlace[20010]; // There are at most two, for this
int leftShoePos[10010], rightShoePos[10010];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        
        set<int> numbersEncountered;

        for (int i = 0; i < N; ++i)
        {
            int left, right;
            cin >> left >> right;
            int leftPos = i * 2, rightPos = leftPos + 1;
            shoesInPlace[leftPos] = left;
            shoesInPlace[rightPos] = right;
            
            leftShoePos[left] = leftPos;
            rightShoePos[right] = rightPos;
            
            numbersEncountered.insert(left);
            numbersEncountered.insert(right);
        }
        
        int count = 0;
        
        // Idea is that, can just swap any pair of shoes, as long as competing at least one pair.
        // Since the exact order will not change the number of swaps
        for (int shoe : numbersEncountered)
        {
            // If not already matched
            if (leftShoePos[shoe] + 1 != rightShoePos[shoe])
            {
                // Swap the right shoe to the left
                int wantedPos = leftShoePos[shoe] + 1, oldPos = rightShoePos[shoe];
                
                int rightShoeChanged = shoesInPlace[wantedPos];
                
                // Update other move shoe
                shoesInPlace[oldPos] = rightShoeChanged;
                rightShoePos[rightShoeChanged] = oldPos;
                
                // Update wanted shoe
                shoesInPlace[wantedPos] = shoe;
                rightShoePos[shoe] = wantedPos;
                ++count;
            }
        }
        
        cout << count << '\n';
    }
}