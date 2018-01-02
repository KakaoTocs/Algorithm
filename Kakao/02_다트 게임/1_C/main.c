#include <stdio.h>

int main()
{
    int i=0, j=0, sum=0, step[3]={0,}, state=0;
    char scoreTable[9];

    scanf("%s", scoreTable);

    for(i=0; scoreTable[i]!='\0'; i++)
    {
        // �����϶�(=����)
        if(scoreTable[i]>47 && scoreTable[i]<58)
        {
            // ������ 2�ڸ��϶�
            step[j]+=(scoreTable[i]-48);
            if(scoreTable[i+1]>47 && scoreTable[i+1]<58)
            {
                step[j]*=10;
                step[j]+=(scoreTable[i+1]-48);
                i++;
            }
        }
        // �����϶�(=���ʽ�)
        else if(scoreTable[i]>64 && scoreTable[i]<91)
        {
            state=1;
            switch(scoreTable[i])
            {
                // S
                case 83:
                    // ���ʽ� ����� ������ ����
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
            // ù��° ������ ������
            if(j>1)
            {
                sum -= step[j-1];
                sum -= step[j-2];
                sum += (step[j-1] * 2 + step[j-2] * 2);
            }
            // ������ �̹� 2�� �̻� ���� ������
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
