#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mapSize=0, i=0, j=0;
    int *arr1;
    int *arr2;
    char **map;

    // ���� ũ�� �Է�
    scanf("%d", &mapSize);
    printf("%d\n", mapSize);

    // ����1, ����2�� ������ �迭 ���� �Ҵ�
    arr1 = (int*)calloc(mapSize, sizeof(int));
    arr2 = (int*)calloc(mapSize, sizeof(int));
    map = (char**)calloc(mapSize, sizeof(char*));

    // �� ���� �Է�
    for(i=0; i<mapSize; i++)
    {
        scanf("%d", &arr1[i]);
        map[i] = (char*)calloc(mapSize, sizeof(char));
    }
    for(i=0; i<mapSize; i++)
    {
        scanf("%d", &arr2[i]);
        for(j=0; j<mapSize; j++)
        {
            // ������ 2������ ���
            //printf("%d", ((arr1[i]|arr2[i])>>j)&1);

            if(((arr1[i]|arr2[i])>>j)&1)
            {
                map[i][mapSize-j-1] = '#';
            }
            else
            {
                map[i][mapSize-j-1] = ' ';
            }

        }
        printf("\n");
    }

    // ���� ���
    for(i=0; i<mapSize; i++)
    {
        printf("%s\n", map[i]);
    }

    // malloc ����
    free(arr1);
    free(arr2);
    return 0;
}
