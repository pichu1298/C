#include <stdio.h>
#include <stdlib.h>

//Linked list
struct MusicNode{
    char title[100];
    char artist[100];
    int year;
    struct MusicNode *next_ptr;
};

void addToPlaylist();
void removeFromPlaylist();
void chooseSelection();

void chooseSelection(){
    printf("Do you want to: \n"
           "1. add to playlist\n"
           "2. remove from playlist\n"
           "3. display playlist\n"
           "4. quit\n");
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case 1:
            // Add to playlist
            break;
        case 2:
            //Remove from playlist
            break;
        case 3:
            // Display playlist
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}

struct MusicNode *add_to_playlist(struct MusicNode *list, char title[], char artist[], int year){
    struct MusicNode *new_node;

    new_node = malloc(sizeof(struct MusicNode));
    if (new_node == NULL){
        printf("Error: malloc failed in add_to_list\n")
    }
}


int main(){
    chooseSelection();
    return 0;
}
