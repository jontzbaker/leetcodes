/* #define directives */
#define TRUE    0x01
#define FALSE   0x00

/* Function definition */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    _Bool   sum_not_found   = TRUE; /* Indicates whether the sum has NOT been found */
    int*    ans             = NULL; /* Pointer used to return the answer */
    int     current_sum     = 0;    /* Value of the current sum */    
    int     index_0         = 0;    /* Index of the first number */
    int     index_1         = 1;    /* Index of the second number */
    int     status          = 0;    /* Indicates the status of the function. 0x00 means OK */

    while (sum_not_found)
    {
        /* First, calculate the current value of the sum */
        current_sum = nums[index_0] + nums[index_1];

        /* Then, check if the sum is correct */
        if (current_sum == target)
        {
            sum_not_found = FALSE;
        }
        /* If it is not, shift the index by one */
        else
        {
            index_1 ++;

            /* Guard against index_0 and index_1 being the same */
            if (index_0 == index_1)
            {
                index_1 ++;
            }

            /* Guard against index_1 going out of bounds */
            if (index_1 > (numsSize - 1))
            {
                index_0 ++;
                index_1 = 0;
            }

            /* Guard against index_0 going out of bounds */
            if (index_0 > (numsSize - 1))
            {
                status = 6;
            }
        }
    }

    /* After a sum has been found, malloc the return array into the pointer */
    if (status == 0)
    {
        ans = (int*) malloc(2 * sizeof(int));
        *returnSize = 2;
        ans[0] = index_0;
        ans[1] = index_1;
    }
    /* NOTE: a single value returned means an error code */
    else
    {
        ans = (int*) malloc(1 * sizeof(int));
        *returnSize = 1;
        ans[0] = status;
    }

    return ans;
}
