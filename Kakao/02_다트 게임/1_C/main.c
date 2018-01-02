#include <stdio.h>

int main()
{
    int i=0, j=0, sum=0, step[3]={0,}, state=0;
    char scoreTable[9];

    scanf("%s", scoreTable);

    for(i=0; scoreTable[i]!='\0'; i++)
    {
        // 숫자일때(=점수)
        if(scoreTable[i]>47 && scoreTable[i]<58)
        {
            // 점수가 2자리일때
            step[j]+=(scoreTable[i]-48);
            if(scoreTable[i+1]>47 && scoreTable[i+1]<58)
            {
                step[j]*=10;
                step[j]+=(scoreTable[i+1]-48);
                i++;
            }
        }
        // 영어일때(=보너스)
        else if(scoreTable[i]>64 && scoreTable[i]<91)
        {
            state=1;
            switch(scoreTable[i])
            {
                // S
                case 83:
                    // 보너스 계산후 총점에 합함
                    sum+=step[j];
                    j++;
                    break;
                // D
                case 68:
                    step[j] = step[j]*step[j];
                    sum+=step[j];
                    j++;
                    break;
                // T
                case 84:
                    step[j] = step[j]*step[j]*step[j];
                    sum+=step[j];
                    j++;
                    break;
            }
        }
        else if(scoreTable[i] == '#')
        {
            step[j-1] *= -1;
            sum += (step[j-1] * 2);
        }
        else if(scoreTable[i] == '*')
        {
            // 첫번째 점수만 있을때
            if(j>1)
            {
                sum -= step[j-1];
                sum -= step[j-2];
                sum += (step[j-1] * 2 + step[j-2] * 2);
            }
            // 점수가 이미 2개 이상 더해 졌을때
            else
            {
                sum -= step[j-1];
                step[j-1] = step[j-1] *2;
                sum += step[j-1];
            }
        }
    }
    printf("Score: %d\n", sum);

    return 0;
}
