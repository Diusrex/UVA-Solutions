//
//  main.cpp
//  ants_on_stick
//
//  Created by Gary Dhillon on 2013-09-13.
//  Copyright (c) 2013 Gary Dhillon. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{

    int cases;
    cin >> cases;
    
    vector<int> allFarthestGoodEnd;
    vector<int> allFarthestBadEnd;
    
    for(int i = 0; i < cases; ++i)
    {
        int logSize, numAnts;
        
        cin >> logSize >> numAnts;
        
        int farthestGoodEnd(0), farthestBadEnd(0);
        
        for(int z = 0; z < numAnts; ++z)
        {
            int position;
            cin >> position;
            int closestEdge = min(position, logSize - position);
            
            if (farthestGoodEnd < closestEdge)
                farthestGoodEnd = closestEdge;
            
            int furthestEdge = logSize - closestEdge;
            
            if (farthestBadEnd < furthestEdge)
                farthestBadEnd = furthestEdge;
            
        }
        allFarthestGoodEnd.push_back(farthestGoodEnd);
        allFarthestBadEnd.push_back(farthestBadEnd);
    }
    
    for (int i = 0; i < cases; ++i)
        cout << allFarthestGoodEnd[i] << " " << allFarthestBadEnd[i] << endl;
    
    return 0;
}

