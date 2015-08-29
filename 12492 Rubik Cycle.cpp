#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// What this program does, is first simulate one full sequence.
// Then, it will compress that sequence into a single array using:
    // goesTo[current] = newPos
// And will keep applying that array to positions until they are all in the correct spot.

// Code for simulating the movement
///////////////////////////////////////////////////////
const int NUM_FACES = 6;
const int NUM_BOX_PER_FACE = 9;
const int TOTAL_BOXES = NUM_FACES * NUM_BOX_PER_FACE;
const int NUM_IN_SQUARE_ROTATIONS = 8;
const int IN_SQUARE_ROTATION_SHIFT = 2;
const int inSquareRotation[NUM_IN_SQUARE_ROTATIONS] = {0, 1, 2, 5, 8, 7, 6, 3}; // These are orderd in clockwise direction

int F = 0, U = 1, R = 2, D = 3, L = 4, B = 5;

int charToFace[128];

void SetUpCharToSquare()
{
    charToFace['F'] = charToFace['f'] = F;
    charToFace['U'] = charToFace['u'] = U;
    charToFace['R'] = charToFace['r'] = R;
    charToFace['D'] = charToFace['d'] = D;
    charToFace['L'] = charToFace['l'] = L;
    charToFace['B'] = charToFace['b'] = B;
}

// This is for changing the positions around
// Designed based on:
//       U
//    L  F  R
//       D
//   (L) B (R)
//       U
//    ...

const int NUM_SIDES = 4;
const int NUM_BOXES_PER_SIDE = 3;

enum Side { BOTTOM, LEFT, TOP, RIGHT};

#define MKPAIR(face, side) make_pair<int, Side>(face, side)

// Is pair<faceChanged, which side, as laid out above
pair<int, Side> facesAroundAndSide[NUM_FACES][NUM_SIDES]; // These are orderd in clockwise direction
                                                          // Also ordered {top, right, bottom, left}

// This complements facesAroundAndSide. Is in the order that they will need to be swapped
int faceSideOrdering[NUM_FACES][NUM_BOXES_PER_SIDE] = {{6, 7, 8}, // BOTTOM
                                                       {0, 3, 6}, // LEFT
                                                       {2, 1, 0}, // TOP
                                                       {8, 5, 2}}; // RIGHT
void SetUpFacesAround()
{
    facesAroundAndSide[F][0] = MKPAIR(U, BOTTOM); facesAroundAndSide[F][1] = MKPAIR(R, LEFT);
    facesAroundAndSide[F][2] = MKPAIR(D, TOP); facesAroundAndSide[F][3] = MKPAIR(L, RIGHT);
    
    facesAroundAndSide[U][0] = MKPAIR(B, BOTTOM); facesAroundAndSide[U][1] = MKPAIR(R, TOP);
    facesAroundAndSide[U][2] = MKPAIR(F, TOP); facesAroundAndSide[U][3] = MKPAIR(L, TOP);
    
    facesAroundAndSide[B][0] = MKPAIR(D, BOTTOM); facesAroundAndSide[B][1] = MKPAIR(R, RIGHT);
    facesAroundAndSide[B][2] = MKPAIR(U, TOP); facesAroundAndSide[B][3] = MKPAIR(L, LEFT);
    
    facesAroundAndSide[D][0] = MKPAIR(F, BOTTOM); facesAroundAndSide[D][1] = MKPAIR(R, BOTTOM);
    facesAroundAndSide[D][2] = MKPAIR(B, TOP); facesAroundAndSide[D][3] = MKPAIR(L, BOTTOM);
    
    facesAroundAndSide[L][0] = MKPAIR(U, LEFT); facesAroundAndSide[L][1] = MKPAIR(F, LEFT);
    facesAroundAndSide[L][2] = MKPAIR(D, LEFT); facesAroundAndSide[L][3] = MKPAIR(B, LEFT);
    
    facesAroundAndSide[R][0] = MKPAIR(U, RIGHT); facesAroundAndSide[R][1] = MKPAIR(B, RIGHT);
    facesAroundAndSide[R][2] = MKPAIR(D, RIGHT); facesAroundAndSide[R][3] = MKPAIR(F, RIGHT);
}

void SetUpSimulation()
{
    SetUpCharToSquare();
    SetUpFacesAround();
}

int GetNextIndexInSquareRotation(int position, bool clockwise)
{
    return (position + (clockwise ? IN_SQUARE_ROTATION_SHIFT : -IN_SQUARE_ROTATION_SHIFT) + NUM_IN_SQUARE_ROTATIONS) % NUM_IN_SQUARE_ROTATIONS;
}

void ApplyInSquareCurrentRotation(vector<int> &changedFace, int startInSquareRotation, bool clockwise)
{
    int positionInSquareRotation = startInSquareRotation;
    int nextPosInSquareRotation = -1;
    int nextVal = changedFace[inSquareRotation[startInSquareRotation]];
    
    while (nextPosInSquareRotation != startInSquareRotation)
    {
        nextPosInSquareRotation = GetNextIndexInSquareRotation(positionInSquareRotation, clockwise);
        int indexAccessing = inSquareRotation[nextPosInSquareRotation];
        int temp = changedFace[indexAccessing];
        
        changedFace[indexAccessing] = nextVal;
        
        nextVal = temp;
        
        positionInSquareRotation = nextPosInSquareRotation;
    }
}

void ApplyInSquareRotation(vector<int> &changedFace, bool clockwise)
{
    // Iterates twice, due to them jumping by 2
    ApplyInSquareCurrentRotation(changedFace, 0, clockwise);
    ApplyInSquareCurrentRotation(changedFace, 1, clockwise);
}

void BackupIntoArray(const vector<vector<int> > &faces, const pair<int, Side> &currentFace, int array[NUM_BOXES_PER_SIDE])
{
    int face = currentFace.first;
    Side side = currentFace.second;
    
    for (int i = 0; i < NUM_BOXES_PER_SIDE; ++i)
    {
        array[i] = faces[face][faceSideOrdering[side][i]];
    }
}

void UpdateFaceValue(vector<vector<int> > &faces, const pair<int, Side> &currentFace, const int array[NUM_BOXES_PER_SIDE])
{
    int face = currentFace.first;
    Side side = currentFace.second;
    
    for (int i = 0; i < NUM_BOXES_PER_SIDE; ++i)
    {
        faces[face][faceSideOrdering[side][i]] = array[i];
    }
}


void ApplyChangeToBesideFaces(vector<vector<int> > &faces, int faceShifted, bool clockwise)
{
    pair<int, Side> currentFace = facesAroundAndSide[faceShifted][0];
    int nextVal[NUM_BOXES_PER_SIDE];
    BackupIntoArray(faces, currentFace, nextVal);

    int increment = (clockwise ? 1 : NUM_SIDES - 1);
    for (int pos = increment; pos != 0; pos = (pos + increment) % NUM_SIDES)
    {
        currentFace = facesAroundAndSide[faceShifted][pos];
        int tempArray[NUM_BOXES_PER_SIDE];
        BackupIntoArray(faces, currentFace, tempArray);
        
        UpdateFaceValue(faces, currentFace, nextVal);
        for (int i = 0; i < NUM_BOXES_PER_SIDE; ++i)
            nextVal[i] = tempArray[i];
    }
    
    currentFace = facesAroundAndSide[faceShifted][0];
    UpdateFaceValue(faces, currentFace, nextVal);
}

void ApplyChange(vector<vector<int> > &faces, char change)
{
    int faceShifted = charToFace[change];
    bool clockwise = (change == toupper(change));
    
    ApplyInSquareRotation(faces[faceShifted], clockwise);
    ApplyChangeToBesideFaces(faces, faceShifted, clockwise);
}




///////////////////////////////////////////////////////


vector<vector<int> > CreatebaseFaces()
{
    vector<vector<int> > faces(NUM_FACES, vector<int>(NUM_BOX_PER_FACE));
    
    for (int face = 0, boxNum = 0; face < NUM_FACES; ++face)
    {
        for (int box = 0; box < NUM_BOX_PER_FACE; ++box, ++boxNum)
            faces[face][box] = boxNum;
    }
    
    return faces;
}

void ApplySequence(const vector<int> &nextPositionPerSequence, vector<int> &allPositions)
{
    static vector<int> temp(TOTAL_BOXES);
    for (int i = 0; i < TOTAL_BOXES; ++i)
        temp[nextPositionPerSequence[i]] = allPositions[i];
    
    allPositions.swap(temp);
}

vector<int> GetBasePositions()
{
    vector<int> basePositions(TOTAL_BOXES);
    for (int i = 0; i < TOTAL_BOXES; ++i)
        basePositions[i] = i;
    return basePositions;
}



int main()
{
    SetUpSimulation();
    
    string sequence;
    
    const vector<int> basePositions = GetBasePositions();(NUM_FACES);
    
    
    while (cin >> sequence)
    {
        vector<vector<int> > faces = CreatebaseFaces();
        for (int i = 0; i < sequence.size(); ++i)
            ApplyChange(faces, sequence[i]);
        
        // Set up the positions
        vector<int> nextPositionPerSequence(TOTAL_BOXES);
        
        for (int face = 0, boxNum = 0; face < NUM_FACES; ++face)
        {
            for (int box = 0; box < NUM_BOX_PER_FACE; ++box, ++boxNum)
            {
                nextPositionPerSequence[faces[face][box]] = boxNum;
            }
        }
        
        // After all, this shift would be applied at least once
        vector<int> allPositions = basePositions;
        
        int count = 1;
        ApplySequence(nextPositionPerSequence, allPositions);
        
        while (allPositions != basePositions)
        {
            ApplySequence(nextPositionPerSequence, allPositions);
            ++count;
        }
        
        cout << count << '\n';
    }
    
}




