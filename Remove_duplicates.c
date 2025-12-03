#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int removeDuplicates(int nums[]);

void BubbleSort(int nums[]);

int length;

int main()
{

    int nums[] = {1, 2, 3, 3, 3, 4};
    int expectednums[] = {1, 2, 3, 4};
    length = sizeof(nums) / sizeof(nums[0]);

    if (length < 1 || length > (3 * 10000))
    {
        printf("Invalid array. Length must be between 1 and 3x10^4");
        return 1;
    }

    for (int i = 0; i < length; i++)
    {
        if (nums[i] < -100 || nums[i] > 100)
        {
            printf("Invalid array. All values must be between [-100,100]");

            return 2;
        }
    }

    int *ptr = &nums[0];

    printf("original: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d", nums[i]);
    }

    int k = removeDuplicates(ptr);

        if (k != (sizeof(expectednums) / sizeof(expectednums[0])))
    {

        printf("\n\nFailed. K = expectednums.length");
        return 3;
    }

    for (int i = 0; i < k; i++)
    {
        if (nums[i] != expectednums[i])
        {

            printf("\n\nFailed. nums does not match expected nums withing range k.");
            return 4;
        }
    }

    printf("\n\nUnique array: ");
    for (int i = 0; i < k; i++)
    {
        printf("%d", nums[i]);
    }

    printf("\n\nPASSED.");

    return 0;
}

int removeDuplicates(int *nums)
{
    BubbleSort(nums);
    int uniqueIndex = 0;

    for (int i = 1; i < length; i++)
    {

        if (nums[i] != nums[uniqueIndex])
        {
            uniqueIndex++;
            nums[uniqueIndex] = nums[i];
        }
    }

    return uniqueIndex + 1;
}

void BubbleSort(int nums[])
{
    bool swapped;
    for (int i = 0; i < length - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}