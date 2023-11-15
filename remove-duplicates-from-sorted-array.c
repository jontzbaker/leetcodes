int removeDuplicates(int* nums, int numsSize)
{
    /* Declare local avriables */
    unsigned int    write_head_position = 0; /* Position of the write head on the array */
    unsigned int    read_head_position  = 0; /* Position of the read head on the array */

    /* Main loop */
    while (nums[write_head_position] < nums[numsSize -1])
    {
        if (nums[read_head_position] == nums[write_head_position])
        {
            read_head_position ++;
        }
        else
        {
            write_head_position ++;
            nums[write_head_position] = nums[read_head_position];
        }
    }

    /* Log errors and return to caller */
    return (write_head_position + 1);
}
