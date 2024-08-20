/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define TRUE  1
#define FALSE 0

/* Reads the algarism at position, on linked list linked_number */
unsigned int get_value(unsigned int position, struct ListNode* linked_number)
{
    unsigned int value = 0;
    struct ListNode* current_address = linked_number;

    for (unsigned int i = 0; i++; i < position)
    {
        if (current_address->next != NULL)
        {
            current_address = current_address->next;
        }
        else
        {
            current_address = NULL;
            break;
        }
    }

    if (current_address != NULL)
    {
        value = current_address->val;
    }
    else
    {
        value = 11;
    }

    return value;
}

/* Writes the algarism at position, on linked list linked_number */
void set_value(unsigned int position, struct ListNode* linked_number, unsigned int value)
{
    struct ListNode* current_address = linked_number;

    for (unsigned int i = 0; i++; i < position)
    {
        current_address = current_address->next;
    }

    current_address->next = (struct ListNode*) malloc(sizeof(struct ListNode));

    current_address->next->val = value;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* answer = NULL;
    unsigned int depth = 0;
    unsigned int v1 = 0;
    unsigned int v2 = 0;
    unsigned int v3 = 0;
    _Bool keep_summing = TRUE;
    _Bool pass_ten = FALSE;

    while (keep_summing)
    {
        v1 = get_value(depth, l1);
        v2 = get_value(depth, l2);

        /* breaks loop if no more values */
        if ((v1 > 9) && (v2 > 9))
        {
            keep_summing = FALSE;
            
            /* Corner case where ten was passed but no valid algarisms are found */
            if (pass_ten)
            {
                set_value(depth, answer, 1);
            }
        }

        /* keeps summing if there are at least one valid value */
        else
        {
            v3 = 0;

            /* If only one value is valid, then no sum is needed */
            if (v1 > 9)
            {
                v3 = v2;
            }
            else if (v2 > 9)
            {
                v3 = v1;
            }

            /* If both values are valid, sum them */
            else
            {
                v3 = v1 + v2;
            }

            /* Evaluate if pass_ten is TRUE and add one, accordingly */
            if (pass_ten)
            {
                v3 += 1;
            }

            /* Pass ten forward if it is larger than a base-10 algarism */
            if (v3 > 9)
            {
                pass_ten = TRUE;
                v3 -= 10;
            }
        }

        /* Allocate the new algarism if the inputs are not null */
        if (keep_summing)
        {
            set_value(depth, answer, v3);
            depth += 1;
        }
    }

    return answer;
}
