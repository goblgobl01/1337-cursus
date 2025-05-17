#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* worker(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < 5; ++i) {
        printf("Thread %d: %d\n", id, i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t threads[2];
    int ids[2] = {1, 2};

    for (int i = 0; i < 2; ++i)
        pthread_create(&threads[i], NULL, worker, &ids[i]);

    for (int i = 0; i < 2; ++i)
        pthread_join(threads[i], NULL);

    return 0;
}
