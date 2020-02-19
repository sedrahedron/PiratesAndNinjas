#include <stdio.h>
#include <stdlib.h>

// simple function that returns true if a given int is in a range, false otherwise
int inRange(int num, int min, int max) {
  return num >= min && num <= max;
}

int main (int argc, char** argv) {
  if (argc != 8) printf("Error: seven arguments are required\n");
  else {
    int costumingTeams, pirates, ninjas;
    double avgPirate, avgNinja, pirateArrvl, ninjaArrvl;
    if (!inRange(costumingTeams = atoi(argv[1]), 2, 4)) printf("Error: The number of teams must be between 2 and 4\n");
    if (!inRange(pirates = atoi(argv[2]), 10, 50)) printf("Error: The number of pirates must be between 10 and 50\n");
    if (!inRange(ninjas = atoi(argv[3]), 10, 50)) printf("Error: The number of ninjas must be between 10 and 50\n");
    avgPirate = strtod(argv[4], NULL);
    avgNinja = strtod(argv[5], NULL);
    pirateArrvl = strtod(argv[6], NULL);
    ninjaArrvl = strtod(argv[7], NULL);
  }
}

// waiting-room style mutex
