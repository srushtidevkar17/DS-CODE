#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node *prev, *next;
};

int main() {
    Node *song1 = new Node{"Song A", NULL, NULL};
    Node *song2 = new Node{"Song B", NULL, NULL};
    Node *song3 = new Node{"Song C", NULL, NULL};

    song1->next = song2;
    song2->prev = song1;

    song2->next = song3;
    song3->prev = song2;

    cout << "Forward Playlist:\n";
    Node *temp = song1;

    while (temp != NULL) {
        cout << temp->song << endl;
        temp = temp->next;
    }

    cout << "\nBackward Playlist:\n";
    temp = song3;

    while (temp != NULL) {
        cout << temp->song << endl;
        temp = temp->prev;
    }

    // Clean up memory
    delete song1;
    delete song2;
    delete song3;

    return 0;
}
