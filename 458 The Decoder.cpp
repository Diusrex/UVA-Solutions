#include <cstdio>

// 94 numbers. 87 forward
// 7 back, or 87 forward
int main()
{
    char letter;
    while (scanf("%c", &letter) == 1)
    {
        if (letter != 13 && letter != 10)
            letter = (char) letter - 7;
        
        printf("%c", letter);
  }

}
