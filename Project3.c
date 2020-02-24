#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <time.h>



#define M_PI 3.141592653588979323846

//using namespace std;

// struct Player { // struct representing a pirate/ninja
//   int type; // 0 = pirate, 1 = ninja
//   pthread_t* data; // corresponding thread
//   double costumingTime; // the time spent in the costuming department
//   int costumeTeam; // the team the thread is using
// };

struct threadStats { // struct holding stats for threads

};

struct threadStats* pirateStats;
struct threadStats* ninjaStats;



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

typedef struct {
  int avgchangetime;
  int arrivetime;
  int pirateorninja;//0 if ninja, 1 if pirate
  }myarg_t;

typedef struct {
  int visitnum;
  int waittime;
  double cost;
  }  myret_t;

  struct myarg_t * pargs;
  struct myarg_t * nargs;
//takes in a thread and prints the statistics
void changingroom(pthread_t thread){
 // sleep(); //average changing time for thread goes into sleep


}



void *mythread(void * arg){

}

int main (int argc, char** argv) {

    double a = drand48();
    double b = drand48();
    double z= sqrt(-2 * log(a)) * cos(2 * M_PI * b);

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
    avgPirate = strtod(argv[4]+z, NULL);
    avgNinja = strtod(argv[5]+z, NULL);
    pirateArrvl = strtod(argv[6], NULL);
    ninjaArrvl = strtod(argv[7], NULL);
    myret_t *pvals;
    myret_t *nvals;
    struct queue pqueue;

    int i;
    int j;
    int n=0;
    pthread_t piratearr[pirates];
    pthread_t ninjaarr[ninjas];
    pargs = (struct myarg_t*) malloc(sizeof(struct myarg_t) * pirates);
    nargs = (struct myarg_t*) malloc(sizeof(struct myarg_t) * ninjas);

    pirateStats = (struct threadStats*) malloc(sizeof(struct threadStats * pirates));
    ninjaStats = (struct threadStats*) malloc(sizeof(struct threadStats * ninjas));
    //pthread_t *piratevals = malloc(sizeof(pthread_t)*pirates);

    for(i=0;i<pirates;i++){
      piratearr[i];
      pargs[i].avgchangetime=avgPirate;
      pargs[i].arrivetime=pirateArrvl;
      pargs[i].pirateorninja=1;
      lock_t mutex;
      lock(&mutex);
      add
    }
    for(j=0;j<ninjas;j++){

      //piratearr[i];
      pthread_create(&ninjaarr[i], NULL, mythread , &nargs);
      pthread_join(ninjaarr[i], (void**)&nvals);

    }
}

// waiting-room style mutex
// use structs to hold threads
// thread aquires the lock, gets in the queue, then the lock is released
// waiting-room style mutex
