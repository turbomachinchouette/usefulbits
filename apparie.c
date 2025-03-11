#include <stdio.h>
#include <stdlib.h>
/* apparie.c - un algorithme simple pour donner les appariements pour tournoi
   à rondes complètes, tiré de mes notes de cours d'arbitre NA */
int
black(int board, int round, int participants) {
  if ((round & 1) == 0) {
    return ((round + participants) / 2 - board + 1);
  } else {
    if (board == 1) {
      return (participants);
    } else if ( 2 * board -1 <= round) {
      return ((round + 1) / 2 - board + 1);
    } else {
      return ((round + 1) / 2 - board + participants);
    }
  }
}

int
white(int board, int round, int participants) {
  if ((round & 1) == 0) {
      if (board == 1) {
	return (participants);
      } else if (board + round / 2 <= participants / 2) {
	return ((round + participants) / 2 + board -1);
      } else {
	return ((round - participants) /2 + board);
      }
  } else {
    return ((round - 1) / 2 + board);
  }
}

int
main(int argc, const char *argv[])
{
  if ((argc !=2)) {
    printf("Usage: %s <participant count>\n", argv[0]);
  } else {
    int participants = (atoi(argv[1])+1)/2*2;
    for (int round = 1; round <= participants-1; round ++) {
      printf("Round %2d:", round);
      for (int board = 1; board <= participants/2; board++) {
	printf ("\t%2d-%2d ", white(board, round, participants), black(board, round, participants));
      }
      printf("\n");
    }
  }
  return 0;
}
