//main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>
#include "sequence.h"
#include "shell_array.h"
#include "shell_list.h"

int main (int argc, char *argv[]){
    if (argc != 4){
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-a") && strcmp(argv[1], "-l")){
        return EXIT_FAILURE;
    }

    if (!(strcmp(argv[1], "-a"))){ //shell sort array
        int size; 
        long *arr; 
        double n_comp = 0;

        //Array_Load_From_File(argv[2], &size);
        arr = Array_Load_From_File(argv[2], &size);
        Array_Shellsort(arr, size, &n_comp);
        int num = Array_Save_To_File(argv[3], arr, size);
	if (num!=size){
	    printf("ERROR in fwrite");
	    return EXIT_FAILURE;
	}
	printf("number of compression: %le\n", n_comp);
        free(arr);
    }
    else if (!(strcmp(argv[1], "-l"))){ //shell sort linked list
        Node * head;
        double n_comp = 0;

        head = List_Load_From_File(argv[2]);
        head = List_Shellsort(head, &n_comp);
	    printf("number of compression: %le\n", n_comp);
        List_Save_To_File(argv[3], head);
        
        //free memory
        while (head != NULL){
            Node * freelist = head->next;
            free(head);
            head = freelist;
        }
    }
    else{
        printf("error method of shell sort to use\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}