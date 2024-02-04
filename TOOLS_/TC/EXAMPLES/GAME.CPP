// GAME.CPP--Example from Chapter 3 "An Introduction to C++"

#include <stdlib.h>
#include <iostream.h>
#include <conio.h>

const DODGERS = 0;
const GIANTS = 1;

void main(void)
{
   int scoreboard [2][9];    // An array two rows by nine columns
   int team, inning;
   int score, total;

   randomize();              // Initialize random number generator

   // Generate the scores
   for (team = DODGERS; team <= GIANTS; team++) {
      for (inning = 0; inning < 9; inning++) {
         score = random(3);
         if (score == 2)             // 1/3 chance to score at least a run
            score = random(3) + 1;   // 1 to 3 runs
         if (score == 3)
            score = random(7) + 1;   // Simulates chance of a big
                                     // inning of 1 to 7 runs
         scoreboard[team][inning] = score;
      }
   }

   // Print the scores
   cout << "\nInning\t1   2   3   4   5   6   7   8   9  Total\n";
   cout << "Dodgers\t";
   total = 0;
   for (inning = 0; inning <= 8; inning++) {
      score = scoreboard[DODGERS][inning];
      total += score;
      cout << score << "   ";
   }
   cout << total << "\n";

   cout << "Giants\t";
   total = 0;
   for (inning = 0; inning < 9; inning++) {
      score = scoreboard[GIANTS][inning];
      total += score;
      cout << score << "   ";
   }
   cout << total << "\n" ;
}
