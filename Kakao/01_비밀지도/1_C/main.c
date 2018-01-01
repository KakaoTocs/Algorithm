#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mapSize=0, i=0, j=0;
    int *arr1;
    int *arr2;
    char **map;

    // 지도 크기 입력
    scanf("%d", &mapSize);
    printf("%d\n", mapSize);

    // 지도1, 지도2를 저장할 배열 동적 할당
    arr1 = (int*)calloc(mapSize, sizeof(int));
    arr2 = (int*)calloc(mapSize, sizeof(int));
    map = (char**)calloc(mapSize, sizeof(char*));

    // 각 지도 입력
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
            // 지도를 2진수로 출력
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

    // 지도 출력
    for(i=0; i<mapSize; i++)
    {
        printf("%s\n", map[i]);
    }

    // malloc 해제
    free(arr1);
    free(arr2);
    return 0;
}
