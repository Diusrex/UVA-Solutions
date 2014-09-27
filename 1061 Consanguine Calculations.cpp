#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int A_POSSIBLE = 1, B_POSSIBLE = 2, AB_POSSIBLE = 4, O_POSSIBLE = 8;
const int ALL_POSSIBLE = A_POSSIBLE | B_POSSIBLE | AB_POSSIBLE | O_POSSIBLE;
const int NONE_POSSIBLE = 0;

int GetParentUnknownABO(const string & otherParent, const string & child)
{
    if (child == "O")
    {
        if (otherParent == "AB")
            return NONE_POSSIBLE;
            
        else
            return A_POSSIBLE | B_POSSIBLE | O_POSSIBLE;
    }
    
    else if (child == "A")
    {
        if (otherParent == "A" || otherParent == "AB") // Only two which guarantee an A
            return ALL_POSSIBLE;
        else
            return A_POSSIBLE | AB_POSSIBLE;
    }
    
    else if (child == "B")
    {
        if (otherParent == "B" || otherParent == "AB") // Onlytwo which guarantee a B
            return ALL_POSSIBLE;
        else
            return B_POSSIBLE | AB_POSSIBLE;
    }
    
    else // AB
    {
        if (otherParent == "O")
            return NONE_POSSIBLE;
        else if (otherParent == "AB")
            return A_POSSIBLE | B_POSSIBLE | AB_POSSIBLE;
        else if (otherParent == "A")
            return B_POSSIBLE | AB_POSSIBLE;
        else
            return A_POSSIBLE | AB_POSSIBLE;
    }
}

bool OneIsValue(const string & parentOne, const string & parentTwo, const string & value)
{
    return parentOne == value || parentTwo == value;
}

int GetChildUnknownABO(const string & parentOne, const string & parentTwo)
{
    // No other ones can have 'O'
    if (OneIsValue(parentOne , parentTwo, "O"))
    {
        if (OneIsValue(parentOne, parentTwo, "AB"))
            return A_POSSIBLE | B_POSSIBLE;
        
        else if (OneIsValue(parentOne, parentTwo, "A"))
            return A_POSSIBLE | O_POSSIBLE;
    
        else if (OneIsValue(parentOne, parentTwo, "B"))
            return B_POSSIBLE | O_POSSIBLE;
        
        else
            return O_POSSIBLE;
    }
    
    else if (OneIsValue(parentOne, parentTwo, "AB"))
    {
        // A and B are guarenteed, O is impossible
        return A_POSSIBLE | B_POSSIBLE | AB_POSSIBLE;
    }
    
    else if (OneIsValue(parentOne, parentTwo, "A"))
    {
        if (OneIsValue(parentOne, parentTwo, "B"))
            return ALL_POSSIBLE;
            
        else
            return A_POSSIBLE | O_POSSIBLE;
    }
    
    else // Both B
        return B_POSSIBLE | O_POSSIBLE;
}


bool ParentCanBeNegative(const char & otherParent, const char & child)
{
    return (child == '-' || otherParent == '+');
}


bool ChildCanHavePositive(const char & parentOne, const char & parentTwo)
{
    return parentOne == '+' || parentTwo == '+';
}

string Separate(const string & fullType, char & rhFactor)
{
    int size = fullType.size();
    rhFactor = fullType[size - 1];
    
    return fullType.substr(0, size - 1);
}

vector<string> GenerateValuesPossible(const int & value)
{
    vector<string> allValues;
    
    const int A_POSSIBLE = 1, B_POSSIBLE = 2, AB_POSSIBLE = 4, O_POSSIBLE = 8;
    
    if (value & A_POSSIBLE)
        allValues.push_back("A");
    
    if (value & AB_POSSIBLE)
        allValues.push_back("AB");
    
    if (value & B_POSSIBLE)
        allValues.push_back("B");
        
    if (value & O_POSSIBLE)
        allValues.push_back("O");

    return allValues;
}

vector<string> ParentIsUnknown(const string & otherParent, const string & child, bool & canBePositive, bool & canBeNegative)
{
    char otherParentRh;
    string otherParentABO = Separate(otherParent, otherParentRh);
    
    char childRh;
    string childABO = Separate(child, childRh);
    
    canBePositive = true;
    canBeNegative = ParentCanBeNegative(otherParentRh, childRh);
    
    return GenerateValuesPossible(GetParentUnknownABO(otherParentABO, childABO));
}

vector<string> ChildIsUnknown(const string & p1, const string & p2, bool & canBePositive, bool & canBeNegative)
{
    char p1Rh;
    string p1ABO = Separate(p1, p1Rh);
    
    char p2Rh;
    string p2ABO = Separate(p2, p2Rh);
    
    canBePositive = ChildCanHavePositive(p1Rh, p2Rh);
    canBeNegative = true;
    
    return GenerateValuesPossible(GetChildUnknownABO(p1ABO, p2ABO));
}

void PrintOutUnknown(const vector<string> & valuesPossible, const bool & canBePositive, const bool & canBeNegative)
{
    if (valuesPossible.size() == 0)
        cout << "IMPOSSIBLE";
    else if (valuesPossible.size() == 1 && (canBePositive ^ canBeNegative))
        cout << valuesPossible[0] << (canBePositive ? '+' : '-');
        
    else
    {
        cout << '{';
        bool first = true;
        
        for (int i = 0; i < valuesPossible.size(); ++i)
        {
            if (canBePositive)
            {
                if (!first)
                    cout << ", ";
                first = false;
                
                cout << valuesPossible[i] << '+';
            }
            
            if (canBeNegative)
            {
                if (!first)
                    cout << ", ";
                first = false;
                cout << valuesPossible[i] << '-';
            }
        }
        
        cout << "}";
    }
}

int main()
{
    string p1, p2, child;
    
    int T = 1;
    
    while (cin >> p1 >> p2 >> child, p1 != "E")
    {
        bool canBePositive = false, canBeNegative = false;
        
        cout << "Case " << T++ << ": ";
        
        if (p1 == "?")
        {
            vector<string> valuesPossible = ParentIsUnknown(p2, child, canBePositive, canBeNegative);
            PrintOutUnknown(valuesPossible, canBePositive, canBeNegative);
        }
        
        else
            cout << p1;
        
        cout << ' ';
        
        if (p2 == "?")
        {
            vector<string> valuesPossible = ParentIsUnknown(p1, child, canBePositive, canBeNegative);
            PrintOutUnknown(valuesPossible, canBePositive, canBeNegative);
        }
        
        else
            cout << p2;
        
        cout << ' ';
        
        if (child == "?")
        {
            vector<string> valuesPossible = ChildIsUnknown(p1, p2, canBePositive, canBeNegative);
            PrintOutUnknown(valuesPossible, canBePositive, canBeNegative);
        }
        
        else
            cout << child;
        
        cout << '\n';
    }
}