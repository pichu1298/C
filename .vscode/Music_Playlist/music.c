#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Linked list
struct MusicNode{
    char title[20];
    char artist[20];
    int year;
    struct MusicNode *next_ptr;
};

struct MusicNode *add_to_playlist(struct MusicNode *list, char title[], char artist[], int year){
    struct MusicNode *new_node;

    new_node = malloc(sizeof(struct MusicNode));
    if (new_node == NULL){
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->artist, artist);
    strcpy(new_node->title, title);
    new_node->year = year;
    new_node->next_ptr = list;
    return new_node;
}

struct MusicNode *display_playlist(struct MusicNode *list){
    printf("Playlist:\n");
    int count = 0;
    while (list != NULL){
        printf("%d. %s - %s (%d)\n", ++count, list->title, list->artist, list->year);
        list = list->next_ptr;
    }
    return list;
}



struct MusicNode *remove_from_playlist(struct MusicNode *list, char title[], char artist[], int year){
    struct MusicNode *current = list;
    struct MusicNode *prev = NULL;
    while (current != NULL){
        if (strcmp(current->title, title) == 0 &&
            strcmp(current->artist, artist) == 0 &&
            current->year == year){
            if (prev == NULL){
                list = current->next_ptr;
            } else {
                prev->next_ptr = current->next_ptr;
            }
            free(current);
            return list;
        }
        prev = current;
        current = current->next_ptr;
    }
    return list;
}


void chooseSelection(struct MusicNode **playlist){
    printf("\nDo you want to: \n"
           "1. add to playlist\n");
    //choice 2 should only be shown if the playlist has actual songs
    if (*playlist != NULL){
        printf("2. remove from playlist\n");
    }
    printf("3. display playlist\n"
           "4. quit\n");
        //choice 2 should only be shown if the playlist has actual songs

    int choice;
    scanf("%d", &choice);
    if (choice == 2 && *playlist == NULL){
        printf("Invalid choice.\n");
        return;
    }
    switch(choice){
        case 1:
            // Add to playlist
            char title[20];
            char artist[20];
            int year;
            printf("Enter title: ");
            scanf("%s", title);
            printf("Enter artist: ");
            scanf("%s", artist);
            printf("Enter year: ");
            scanf("%d", &year);
            //check if it there is an exact duplicate
            struct MusicNode *current = *playlist;
            while (current != NULL){
                if (strcmp(current->title, title) == 0 &&
                    strcmp(current->artist, artist) == 0 &&
                    current->year == year){
                    printf("Song already exists in playlist.\n");
                    break;
                }
                current = current->next_ptr;
            }
            if (current == NULL){
                printf("Adding to playlist...\n");
                *playlist = add_to_playlist(*playlist, title, artist, year);
            }
            break;
        case 2:
            //Remove from playlist
            printf("You are removing a song from the playlist.\n");
            char title_to_remove[20];
            char artist_to_remove[20];
            int year_to_remove;
            printf("Enter title: ");
            scanf("%s", title_to_remove);
            printf("Enter artist: ");
            scanf("%s", artist_to_remove);
            printf("Enter year: ");
            scanf("%d", &year_to_remove);

            //check if the song exists in the playlist
            struct MusicNode *current_for_removal = *playlist;
            while (current_for_removal != NULL){
                if (strcmp(current_for_removal->title, title_to_remove) == 0 &&
                    strcmp(current_for_removal->artist, artist_to_remove) == 0 &&
                    current_for_removal->year == year_to_remove){
                    break;
                }
                current_for_removal = current_for_removal->next_ptr;
            }

            if (current_for_removal == NULL){
                printf("Song not found in playlist.\n");
                break;
            }

            printf("Removing from playlist...\n");
            *playlist = remove_from_playlist(*playlist, title_to_remove, artist_to_remove, year_to_remove);
            break;
        case 3:
            // Display playlist
            display_playlist(*playlist);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}





int main(){
    struct MusicNode *playlist = NULL;
    while (1){
        chooseSelection(&playlist);
    }
}
