#include <iostream>

using namespace std;

enum Status {Unchecked, Checking, IsHappy, NotHappy };

const int HIGHEST = 1000;
Status numbers[HIGHEST];

inline int nextNum(int num)
{
    int ret = 0;
    while (num)
    {
        ret += (num % 10) * (num % 10);
        num /= 10;
    }

    return ret;
}

bool isHappy(int num)
{
    num = nextNum(num);

    if (numbers[num] == Unchecked)
    {
        numbers[num] = Checking;
        bool is = isHappy(num);
        numbers[num] = (is ? IsHappy : NotHappy);
    }

    else if (numbers[num] == Checking)
        return false;

    return numbers[num] == IsHappy;
}

int main()
{
    for (int i = 0; i < HIGHEST; ++i)
        numbers[i] = Unchecked;

    numbers[1] = IsHappy;

    int T;
    cin >> T;
    

    for (int t = 1; t <= T; ++t)
    {
        int num;
        cin >> num;
        if (isHappy(num))
            cout << "Case #" << t << ": " << num << " is a Happy number.\n";
        else
            cout << "Case #" << t << ": " << num << " is an Unhappy number.\n";
    }
}
