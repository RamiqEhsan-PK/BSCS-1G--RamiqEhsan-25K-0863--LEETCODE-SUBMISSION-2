#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{

    int nums[] = {0, 1, 0, 3, 12}; // Manually set array.

    int length = sizeof(nums) / sizeof(nums[0]), Zerocount = 0, Counter = 0, boundary = length - 1, temp;
    if (length > pow(10, 4) && length < 1)
    {
        printf("Invalid array. Length must be between 1 and 10^4");
        return 0;
    }

    for (int i = 0; i < length; i++)
    {
        if (nums[i] < -pow(2, 31) || nums[i] > (pow(2, 31) - 1))
        {
            printf("Invalid array. Each value must be between (-2^31 and 2^31-1)");
            return 0;
        }
    }

    printf("Original: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d", nums[i]);
    }
    printf("\n\n");

    printf("Adjusted: ");
    for (int i = 0; i < boundary; i++)
    {

        if (nums[i] == 0)
        {
            temp = nums[boundary];
            nums[boundary] = nums[i];
            nums[i] = temp;
            boundary--;
        }
    }

    for (int i = 0; i < length; i++)
    {
        printf("%d", nums[i]);
    }

    return 0;
}
