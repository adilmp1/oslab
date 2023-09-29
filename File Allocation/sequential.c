#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void main()
{
    int f[50], i, start, len, j, c, k, count = 0;

    for (i = 0; i < 50; i++)
        f[i] = 0;
    printf("Files Allocated are : \n");
    bool flag=true;
    while(flag)
    {

        count = 0;
        printf("Enter starting block and length of files:");
        scanf("%d%d", &start, &len);
        for (k = start; k < (start + len); k++)
            if (f[k] == 0)
                count++;
        if (len == count)
        {
            for (j = start; j < (start + len); j++)
                if (f[j] == 0)
                {
                    f[j] = 1;
                    printf("%d\t%d\n", j, f[j]);
                }
            if (j != (start + len - 1))
                printf(" The file is allocated to disk\n");
        }
        else
            printf("The file is not allocated \n");
        printf("Do you want to enter more file(Yes - 1/No - 0)");
        scanf("%d", &c);
        flag = (c==1)?true:false;
    }
}

/*OUTPUT
Files Allocated are :
Enter starting block and length of files:1
5
1	1
2	1
3	1
4	1
5	1
 The file is allocated to disk
Do you want to enter more file(Yes - 1/No - 0)1
Enter starting block and length of files:5
2
The file is not allocated
Do you want to enter more file(Yes - 1/No - 0)1
Enter starting block and length of files:7
4
7	1
8	1
9	1
10	1
 The file is allocated to disk
Do you want to enter more file(Yes - 1/No - 0)

*/
