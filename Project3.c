#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Player { // struct representing a pirate/ninja
  int type; // 0 = pirate, 1 = ninja
  pthread_t* data; // corresponding thread
  double costumingTime; // the time spent in the costuming department
  int costumeTeam; // the team the thread is using
};

struct QNode {
  struct Player* p;
  struct QNode* next; // pointer to next queue element
};

struct QNode* createNode (struct Player* p) {
  struct QNode* temp = (struct Qnode*) malloc(sizeof(struct QNode));
  temp->p = p;
  temp->next = NULL;
}

struct Queue {
  struct QNode* front; // pointers to front and back of Queue
  struct QNode* back;
};

struct Queue* createQueue() {
  struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
  q->front = q->back = NULL;
  return q;
}

// lock will be needed in this function
void add(struct Queue* q, struct Player* p) {
  struct QNode* temp = createNode(p);
  if (q->front == NULL) { // if the queue is empty
    q->front = q->back = NULL;
    return;
  }
  q->back->next = temp;
  q->back = temp;
  free(temp);
}

// simple function that returns true if a given int is in a range, false otherwise
int inRange(int num, int min, int max) {
  return num >= min && num <= max;
}

int main (int argc, char** argv) {
  if (argc != 8) {
    printf("Error: seven arguments are required\n");
    return 1;
  }
    int costumingTeams, pirates, ninjas;
    double avgPirate, avgNinja, pirateArrvl, ninjaArrvl;
    if (!inRange(costumingTeams = atoi(argv[1]), 2, 4)) {
      printf("Error: The number of teams must be between 2 and 4\n");
      return 1;
    }
    if (!inRange(pirates = atoi(argv[2]), 10, 50)) {
       printf("Error: The number of pirates must be between 10 and 50\n");
       return 1;
    }
    if (!inRange(ninjas = atoi(argv[3]), 10, 50)) {
       printf("Error: The number of ninjas must be between 10 and 50\n");
       return 1;
    }
    avgPirate = strtod(argv[4], NULL);
    avgNinja = strtod(argv[5], NULL);
    pirateArrvl = strtod(argv[6], NULL);
    ninjaArrvl = strtod(argv[7], NULL);
}

// waiting-room style mutex
// use structs to hold threads
// thread aquires the lock, gets in the queue, then the lock is released
