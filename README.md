# Simple Song Playlist

In this homework you are supposed to write a C program in which you can create a simple song
list. You must use given data structures and implement given methods properly. The user of the
program must be able to
  - add a song to the list by providing its name and duration
  - delete a song from the list by providing its name
  - list all songs

Your implementation must satisfy these constraints below
  - You must use the **_dynamic_array_** data structure for storing songs. The initial **_capacity_** of
    the **_dynamic_array_** must be 2, and you must allocate 2 **_void*_** in the heap by using
    **_malloc()_** and assign **_NULL_** value to them. elements pointer must store the returned
    address from **_malloc()_**. Implement these operations in the **_init_array_** function.
  - When the user chooses to add a new song you must create that song in the heap by
    using **_malloc()_**. You must put this song address into the songs by using the **_put_element_**
    function. In the **_put_element_** function you must increase the size of the **_elements_** array
    and put the newly added element’s address into the **_elements_** array. Emplace it to the
    first available position.
  - When the user chooses to delete the song, you must find it by using **_get_element_**
    function, and use **_free()_** function to deallocate them from the heap. And use
    **_remove_element_** to remove its address from the songs.
  - Everytime the size of the **_dynamic_array_** reaches capacity you must increase the
    capacity to 2 times the old one, and copy the elements of the **_elements_** array into the
    new allocated _elements_ array. You must assign _NULL_ value for **_elements_** array elements
    that haven’t pointed to any valid songs yet. All these operations must be implemented in
    the **_put_element_** function.
  - Everytime the size of the **_dynamic_array_** drops down to **_capacity/2_**, reduce **_capacity_** by
    factor of 2 and allocate space for that **_capacity_**, copy the values of the **_elements_** array to
    the newly allocated **_elements_** array and deallocate the old **_elements_** array by using **_free()_**
    function. All these operations must be implemented in the **_remove_element_** function.
  - While you list the songs you must use the **_get_element_** function to get the song address
    at that position. Note that **_get_element_** returns **_void*_**, so you can cast the type of **_void*_** to
    **_song*_**, and then access the song fields.

Notes:
  - The elements field of dynamic_array is a pointer that stores the address of elements
    rather than elements as values. You can regard elements as an array of **_void*_**.
  - The heap mentioned above is not a data structure, it is the memory region. You can
    create or manipulate an object on the heap by using dynamic memory allocation
    functions(e.g. **_malloc(), free()_** etc.) declared in **_stdlib.h_**
  - **_NULL_** is also declared in stdlib.h, it is used as an address that points to **_0_** which means
    there is no valid data at that address, or the data hasn't been allocated yet. To indicate
    the pointer hasn't been initialized yet or the pointed value deallocated, you can use
    **_NULL_**.
    
    ```C
    char* myptr = NULL;
    ```
  - void* is a general purpose pointer that helps you to store an object without knowing the
    actual pointed data type. You can cast it to the actual pointed data type. E.g.
    
    ```C
    void* myptr = malloc(sizeof(int)); //Allocates 4 bytes space on the heap
    int* my_num_ptr = (int*) myptr; //Cast it to int*, we are allowed to do since we allocate 4 bytes
    *my_num_ptr = 25; // Change the value at that address through our int*
    printf("%d", *my_num_ptr);  //Prints 25
    printf("%d", *((int*)myptr));  //Prints 25
    ```

