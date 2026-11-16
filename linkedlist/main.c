#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char*    artist;
    char*    name;
    uint32_t year;
} song;

typedef struct node {
    song         data;
    struct node* next;
} node;

typedef struct {
    node* head;
} linked_list;

void add_to_playlist(linked_list* playlist, const char* artist, const char* name, uint32_t year) {

    node* new_node = malloc(sizeof(node));

    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->data.artist = malloc(strlen(artist) + 1);
    new_node->data.name   = malloc(strlen(name) + 1);

    if (new_node->data.artist == NULL || new_node->data.name == NULL) {
        free(new_node->data.artist);
        free(new_node->data.name);
        free(new_node);
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(new_node->data.artist, artist);
    strcpy(new_node->data.name, name);

    new_node->data.year = year;
    new_node->next      = NULL;

    if (playlist->head == NULL) {
        playlist->head = new_node;
        return;
    }

    node* current = playlist->head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void delete_from_playlist(linked_list* playlist, const char* name) {

    node* current  = playlist->head;
    node* previous = NULL;

    while (current != NULL) {

        if (strcmp(current->data.name, name) == 0) {
            if (previous == NULL) {
                playlist->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->data.artist);
            free(current->data.name);
            free(current);

            printf("Deleted: %s\n\n", name);
            return;
        }

        previous = current;
        current  = current->next;
    }

    printf("Song not found: %s\n\n", name);
}

void print_playlist(const linked_list* playlist) {

    node* current = playlist->head;

    if (current == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    while (current != NULL) {

        printf("Artist: %s\n", current->data.artist);
        printf("Song:   %s\n", current->data.name);
        printf("Year:   %u\n", current->data.year);

        current = current->next;
    }
}

void free_playlist(linked_list* playlist) {

    node* current = playlist->head;

    while (current != NULL) {

        node* next = current->next;

        free(current->data.artist);
        free(current->data.name);
        free(current);

        current = next;
    }

    playlist->head = NULL;
}

int main(void) {

    linked_list playlist = {NULL};

    add_to_playlist(&playlist, "Queen", "Bohemian Rhapsody", 1975);
    add_to_playlist(&playlist, "Michael Jackson", "Billie Jean", 1982);
    add_to_playlist(&playlist, "Nirvana", "Smells Like Teen Spirit", 1991);

    printf("\nOriginal Playlist:\n\n");
    print_playlist(&playlist);

    delete_from_playlist(&playlist, "Billie Jean");

    printf("Updated Playlist:\n\n");
    print_playlist(&playlist);

    free_playlist(&playlist);

    return 0;
}
