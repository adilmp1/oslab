#include <stdio.h>
int main()
{
    int no_of_frames, no_of_pages;
    int page_faults=0;
    int rows, cols;
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    int a[no_of_pages];
    printf("Enter pages: ");
    for (int i = 0; i < no_of_pages; i++)
    {
        scanf("%d", a + i);
    }
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    rows = no_of_pages;
    cols = no_of_frames;
    int result[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = 0;
        }
    }
    int completed = 0;
    int flag;
    int flag_2;
    int flag_3;
    // here:
    while (completed < no_of_pages)
    {
        for (int i = 0; i < no_of_frames; i++)
        {
            // flag_3=0;
            flag = 0;
            flag_2 = 0;
            if (completed >= 1)
            {
                for (int s = 0; s < no_of_frames; s++)
                {
                    if (a[completed] == result[completed - 1][s])
                    {
                        flag = 1;
                        if(a[completed]==3 && completed>1)
                        {
                            // display();
                            // printf("rear = %d = rear",rear);
                        }
                        completed++;
                        break;  
                    }
                }
            }
            if (result[completed][i] == 0 && flag == 0)
            {
                flag_2 = 1;
                for (int j = completed; j < no_of_pages; j++)
                {
                    result[j][i] = a[completed];
                }
                completed++;
                page_faults++;
                break;
            }
        }
        if (!flag_2)
        {
            int fifo = a[completed-no_of_frames];
            page_faults++;
            for (int i = 0; i < no_of_frames; i++)
            {
                if (result[completed][i] == fifo)
                {
                    flag_2 = 1;
                    for (int j = completed; j < no_of_pages; j++)
                    {
                        result[j][i] = a[completed];
                    }
                    completed++;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        printf("\n");
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", result[i][j]);
        }
    }

    printf("\n\nPage Faults = %d",page_faults);
}
