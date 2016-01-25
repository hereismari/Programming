#include <stdio.h>
#include<string.h>
int main()
{
char c;
int i;
while(scanf("%c",&c)!=EOF){
   if(isdigit(c)|| c == '-' || c == '\n')
    printf("%c",c);
   else
    {
        switch(c)
        {

        case 'A':
        case 'B':
        case 'C':
            printf("2");
            break;
        case 'D':
        case 'E':
        case 'F':
            printf("3");
            break;
        case 'G':
        case 'H':
        case 'I':
            printf("4");
            break;
        case 'J':
        case 'K':
        case 'L':
            printf("5");
            break;
        case 'M':
        case 'N':
        case 'O':
            printf("6");
            break;
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
            printf("7");
            break;

        case 'T':
        case 'U':
        case 'V':
            printf("8");
            break;
        case 'Z':
        case 'W':
        case 'X':
        case 'Y':
            printf("9");
            break;

        }

    }
}
return 0;
}
