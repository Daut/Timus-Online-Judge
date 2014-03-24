#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

struct node {
        char c;
        node *next;
        node *pre;
};

int main() {
        node *message = new node();
        message->c = getchar();
        char c;
        int size = 1;
        node *curr = message;
        while(cin.get(c)) {
                if (c == '\n' || c == ' ')
                        break;
                node *n = new node();
                n->c = c;
                curr->next = n;
                n->pre = curr;
                curr = n;
                size++;
        }
        
        for(node *curr = message; curr->next != NULL; ) {
                if (curr->c == curr->next->c) {
                        node *old_1 = curr;
                        node *old_2 = curr->next;
                        size -= 2;
                        if (curr->pre == NULL) {
                                message = curr = curr->next->next;
                                if (message != NULL) {
                                        curr->pre = NULL;
                                }
                                else 
                                        break;
                        }
                        else if (curr->pre != NULL) {
                                if (curr->next->next != NULL) {
                                        curr->next->next->pre = curr->pre;
                                        curr = curr->pre;
                                        curr->next = curr->next->next->next;
                                }
                                else {
                                        curr = curr->pre;
                                        curr->next = NULL;
                                }
                        }
                        delete old_1;
                        delete old_2;
                }
                else {
                        curr = curr->next;
                }
        }
        
        curr = message;
        while(curr != NULL) {
                cout << curr->c;
                node *old = curr;
                curr = curr->next;
                delete old;
        }

        return 0;
}

