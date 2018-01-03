#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0, casheSize=0, cnt=0;
    char *cashe, value;

    scanf("%d", &casheSize);
    cashe = (char*)calloc(casheSize, sizeof(char));

    getchar();
    printf("입력하세요>>\n");
    scanf("%c", &value);
    printf("Input: %c | ", value);
    while(value != 10)
    {
        if(value>='A' && value<='Z')
            value+=32;
        insert(cashe, value, casheSize, &cnt);
        scanf("%c", &value);
        printf("Input: %c | ", value);
        printf("Cahse: %s | ", cashe);
    }
    printf("%d\n", cnt);
    return 0;
}

void update(char cashe[], int index)
{
    int i=0;
    char temp=cashe[index];

    for(i=index; i>0; i--)
    {
        cashe[i] = cashe[i-1];
    }
    cashe[0] = temp;
}

void insert(char cashe[], char value, int size, int *cnt)
{
    int i=0;

    for(i=0; i<size; i++)
    {
        if(cashe[i] == value)
        {
            *cnt=*cnt+1;
            update(cashe, i);
            printf("HIT\n");
            return;
        }
    }

    for(i=size-1; i>0; i--)
    {
        cashe[i] = cashe[i-1];
    }
    cashe[0] = value;
    printf("FULT\n");
    *cnt=*cnt+5;
}
