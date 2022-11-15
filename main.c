#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dynamic_array
{
    int capacity;
    int size;
    void **elements;
} dynamic_array;

void init_array(dynamic_array *array)
{
    int length = 2;
    array->capacity = 2;
    array->size = 0;
    array->elements = (void *)malloc(length * sizeof(void));
    for (int i = 0; i < array->capacity; i++)
    {
        array->elements[i] = NULL;
    }
}

void put_element(dynamic_array *array, void *element)
{
    if (array->size == array->capacity)
    {
        array->capacity = array->capacity * 2;
        void **tempArray = (void *)malloc(array->capacity * sizeof(void *));
        for (int index = 0; index < array->capacity; index++)
        {
            if (index != array->size)
            {
                tempArray[index] = array->elements[index];
            }
            else
                tempArray[index] = NULL;
        }
        free(array->elements);
        array->elements = tempArray;
    }

    array->elements[array->size] = element;
    array->size = array->size + 1;
}

void remove_element(dynamic_array *array, int position)
{
    if (array->size == array->capacity / 2)
    {
        array->capacity = array->capacity / 2;
        void **tempArray = (void *)malloc(array->capacity * sizeof(void *));
        for (int index = 0; index < array->size; index++)
        {
            tempArray[index] = array->elements[index];
        }
        free(array->elements);
        array->elements = tempArray;
    }

    int lastPosition = array->size;
    for (int index = position; index <= lastPosition - 1; index++)
    {
        array->elements[index] = array->elements[index + 1];
    }
    array->elements[lastPosition] = NULL;
    array->size = array->size - 1;
}

void *get_element(dynamic_array *array, int position)
{
    return array->elements[position];
}

typedef struct song
{
    char *name;
    float duration;
} song;

int main()
{
    struct dynamic_array musicArray;
    init_array(&musicArray);

    while (1)
    {

        int choice;

        printf("[1] -> List all songs\n");
        printf("[2] -> Add a song to the list\n");
        printf("[3] -> Delete a song from the list\n");
        printf("[4] -> Exit\n");
        printf("Enter your option: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 1)
        {
            if (musicArray.size == 0)
            {
                printf("There is no any song in the list\n\n");
            }
            else
            {
                for (int i = 0; i < musicArray.size; i++)
                {
                    song *music = get_element(&musicArray, i);
                    printf("%s -> %f minutes\n", music->name, music->duration);
                }
                printf("\n");
            }
        }
        else if (choice == 2)
        {

            song *music = (song *)malloc(sizeof(song));
            music->name = (char *)malloc(1024 * sizeof(char));

            printf("Enter the name: ");
            scanf("%s", music->name);
            printf("Enter the duration: ");
            scanf("%f", &music->duration);
            printf("\n\n");

            put_element(&musicArray, music);
            printf("The song has been added\n");
        }
        else if (choice == 3)
        {
            if (musicArray.size == 0)
            {
                printf("There is no any song in the list\n\n");
            }
            else
            {
                char *name = (char *)malloc(1024 * sizeof(char));

                printf("Enter the name: ");
                scanf("%s", name);

                for (int index = 0; index < musicArray.size; index++)
                {
                    song *getMusic = get_element(&musicArray, index);
                    int res = strcmp(name, getMusic->name);
                    if (res == 0)
                    {
                        remove_element(&musicArray, index);
                        printf("The song has been deleted\n");
                        free(getMusic);
                        free(getMusic->name);
                        break;
                    }
                    else
                    {
                        printf("The song is not found\n");
                    }
                }
            }
        }
        else if (choice == 4)
        {
            exit(0);
        }
        else
        {
            printf("Please enter a valid option\n\n");
        }
    }

    return 0;
}