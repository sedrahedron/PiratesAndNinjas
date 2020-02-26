#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <time.h>

#define M_PI 3.141592653588979323846

struct QNode {
  pthread_t* p;
  struct QNode* next; // pointer to next queue element
};

struct QNode* createNode (pthread_t* p) {
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
void add(struct Queue* q, pthread_t* p) {
  struct QNode* temp = createNode(p);
  if (q->front == NULL) { // if the queue is empty
    q->front = q->back = temp;
    return;
  }
  q->back->next = temp;
  q->back = temp;
  free(temp);
}

pthread_t pop(struct Queue* q) { // fix this later
  if(q->front == NULL) return NULL;
  struct QNode* front = q->front;
  pthread_t* p = front->p;
  q->front = front->next;
  if (q->front == NULL) q->back = NULL;
  free(front);
  return p;
}

// simple function that returns true if a given int is in a range, false otherwise
int inRange(int num, int min, int max) {
  return num >= min && num <= max;
}

 struct myarg_t {
  int avgchangetime;
  int arrivetime;//time spent organizing before it changes
  int waittime;//time spent waiting in queue
  int pirateorninja;//0 if ninja, 1 if pirate
  };

 struct myret_t {
  int visitnum;
  int* waitarr;
  double cost;
  }  myret_t;

  struct myarg_t * pargs;
  struct myarg_t * nargs;


  //gets the random number using the distribution
  double randomdistribution(int n){
  double a = drand48();
  double b = drand48();
  //double z= sqrt(-2 * log(a)) * cos(2 * M_PI * b);
  double num = (double)n + z;
  return fabs(num);
  }


//takes in the args and the ret and prints the statistics
void changingroom(struct myarg_t arg, struct myret_t ret){
double changetime;
changetime = randomdistribution(arg.avgchangetime);
sleep(changetime); //average changing time for thread goes into sleep
ret.cost=(int) changetime;//sets the amount of time spent changing to goldowed
ret.visitnum++;
}

void *mythread(void * arg){

}

struct myret_t* pirateStats;
struct myret_t* ninjaStats;

int main (int argc, char** argv) {

    //double a = drand48();
    //double b = drand48();
    //double z= sqrt(-2 * log(a)) * cos(2 * M_PI * b);

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

    struct Queue* pirateQueue = createQueue();
    struct Queue* ninjaQueue = createQueue();

    pirateStats = (struct myret_t*) malloc (sizeof(struct myret_t) * pirates);
    ninjaStats = (struct myret_t*) malloc (sizeof(struct myret_t) * ninjas);

    for (int i = 0; i < pirates; i++) {
      pthread_t thread;
      add(pirateQueue, &thread);
    }

    for (int i = 0; i < ninjas; i++) {
      pthread_t thread;
      add(ninjaQueue, &thread);
    }

    /*
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
    */
}

// waiting-room style mutex
// use structs to hold threads
// thread aquires the lock, gets in the queue, then the lock is released
// waiting-room style mutex
