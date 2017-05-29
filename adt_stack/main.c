#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adt_stack_
{
    unsigned char *buffer;
    size_t elem_count;
    size_t elem_size;
    size_t buffer_size;
} adt_stack_t;

adt_stack_t * adt_stack_init(size_t element_size)
{
    adt_stack_t *new_stack = malloc(sizeof(adt_stack_t));

    new_stack->elem_size = element_size;
    new_stack->buffer = malloc(sizeof(new_stack->elem_size));
    new_stack->buffer_size = new_stack->elem_size;

    return new_stack;

}

/*
 * adt_stack_push: push some void * of elem_size onto the stack:
 * - find the cursor where buffer + elem_count * elem_size
 * - if the cursor + elem_size is greater than buffer_size, double space with
 *   realloc
 */
void adt_stack_push(adt_stack_t *stack, void *element)
{
    size_t offset = stack->elem_count * stack->elem_size;

    // check for available memory
    if ((offset + stack->elem_size) > stack->buffer_size)
    {
        printf("ran out of space. current buffer_size = %lu\n", stack->buffer_size);
        stack->buffer = realloc(stack->buffer, stack->buffer_size * 2);
        stack->buffer_size *= 2;
    }

    unsigned char *cursor = stack->buffer + offset;

    memcpy(cursor, element, sizeof(stack->elem_size));

    stack->elem_count++;
}

void *adt_stack_pop(adt_stack_t *stack)
{
    if (stack->elem_count == 0)
    {
        printf("stack empty\n");
        return NULL;
    }

    size_t offset = stack->elem_count * stack->elem_size;
    unsigned char *cursor = stack->buffer + offset - stack->elem_size;

    stack->elem_count--;

    return cursor;
}

typedef struct blep_
{
    int d;
} blep_t;

int main(void)
{
    blep_t one, two, *pop = NULL;
    one.d = 1;
    two.d = 2;

    adt_stack_t *stack = adt_stack_init(sizeof(blep_t));

    adt_stack_push(stack, &one);
    adt_stack_push(stack, &two);
    adt_stack_push(stack, &two);
    adt_stack_push(stack, &two);
    adt_stack_push(stack, &two);
    pop = adt_stack_pop(stack); printf("pop.d = %d\n", pop->d);
    pop = adt_stack_pop(stack); printf("pop.d = %d\n", pop->d);
    pop = adt_stack_pop(stack); printf("pop.d = %d\n", pop->d);
    pop = adt_stack_pop(stack); printf("pop.d = %d\n", pop->d);
    pop = adt_stack_pop(stack); printf("pop.d = %d\n", pop->d);
    pop = adt_stack_pop(stack); printf("pop.d = %d\n", pop->d);

}
