#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIORITY 256

struct heap {
    int *priority;
    int size;
    int capacity;
};

static struct heap runq;


void expand();
void heap_init();
void heap_insert(int item_priority);
int get_parent(int i);
void sift_up(int i);
void sift_down(int i);
void print();

void expand() {
    int *new_priority = (int *)malloc(sizeof(int) * runq.capacity * 2);
    for (int i = 0; i < runq.size; ++i) {
        new_priority[i] = runq.priority[i];
    }
    free(runq.priority);
    runq.priority = new_priority;
    runq.capacity *= 2;
}

void heap_init() {
    runq.priority = (int *)malloc(sizeof(int) * 4);
    runq.size = 0;
    runq.capacity = 4;
}

void heap_insert(int item_priority) {
    if (runq.size + 1 > runq.capacity) {
        expand();
    }
    runq.priority[runq.size] = item_priority;
    sift_up(runq.size);
    ++runq.size;
}

int get_parent(int i) {
    return ((i - 1) / 2);
}

void sift_up(int i) {
    int parent = get_parent(i);
    while (i > 0 && runq.priority[parent] < runq.priority[i]) {
        int buf = runq.priority[i];
        runq.priority[i] = runq.priority[parent];
        runq.priority[parent] = buf;

        i = parent;
        parent = get_parent(i);
    }
}

void sift_down(int i) {
    while (1) {
        int max_index = i;

        int l = 2 * i + 1;
        if (l < runq.size && runq.priority[l] > runq.priority[max_index]) {
            max_index = l;
        }

        int r = 2 * i + 2;
        if (r < runq.size && runq.priority[r] > runq.priority[max_index]) {
            max_index = r;
        }

        if (i != max_index) {
            int buf = runq.priority[i];
            runq.priority[i] = runq.priority[max_index];
            runq.priority[max_index] = buf;

            i = max_index;
        } else {
            break;
        }
    }
}

void print() {
    for (int i = 0; i < runq.size; ++i) {
        printf("index: %i priorinty: %i\n", i, runq.priority[i]);
    }
}

int extract_max() {
    int result = runq.priority[0];
    runq.priority[0] = runq.priority[runq.size - 1];
    sift_down(0);
    --runq.size;
    return result;
}

int remove(int i) {
    runq.priority[i] = MAX_PRIORITY;
    sift_up(i);
    return extract_max();
}

int main(int argc, char **argv) {
    heap_init();
    heap_insert(4);
    heap_insert(1);
    heap_insert(10);
    heap_insert(3);
    heap_insert(5);
    heap_insert(13);
    heap_insert(11);

    remove(1);
    extract_max();

    print();

    return EXIT_SUCCESS;
}