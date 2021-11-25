#include<iostream>
#include<time.h>
#include<algorithm>
using namespace std;

void print(int boardFunc[][9]) { // printing 81 numbers in a 3x3x3 pattern
   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         cout << boardFunc[i][j] << " ";
         if (j == 2 || j == 5) {
            cout << " ";
         }
      }
      cout << endl;
      if (i == 2 || i == 5) {
         cout << endl;
      }
   }

}

void shuffle(int place[]) { // shuffleing numbers around in the array
   int temp = 0;  // temporary number
   int random = 0;   // random number

   for (int i = 0; i < 9; i++){
      random = rand() % 9; // getting unique random number every loop
      temp = place[i]; 
      place[i] = place[random];  // swaping current selected array value with chosen random array value
      place[random] = temp;      
   }
}

int main() {
   srand(time(NULL));
   int row, col, digit;
   int place [9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // initializing numbers from 1 - 9

   shuffle(place); // getting a random order those numbers

   // Declaring placeholder letters and their values
   int a = place[0],b = place[1],c = place[2],d = place[3],e = place[4],f = place[5],g = place[6],h = place[7],k = place[8]; 
   int board [9][9] = { // setting up board shape
      {d, c, e, b, f, k, g, h, a},
      {f, h, b, e, g, a, d, k, c},
      {a, k, g, h, c, d, e, f, b},
      {h, b, f, a, k, e, c, d, g},
      {c, g, d, f, h, b, k, a, e},
      {k, e, a, g, d, c, f, b, h},
      {e, a, k, c, b, f, h, g, d},
      {b, d, h, k, e, g, a, c, f},
      {g, f, c, d, a, h, b, e, k},
   };
   for (int i = 0; i < 45 ; i++){
      for (; ;) {
         int randomX = rand() % 9;
         int randomY = rand() % 9;
         if (board [randomX][randomY] != 0) {
            board [randomX][randomY] = 0;
            break;
         }
      }
   }

   print(board); // print start board

   for (int j = 0; j < 5; j++){ // 5 times to change the numbers
   cout << "Enter the column of the digit you wish to change:";
   cin >> col;
   cout << "Enter the row of the digit you wish to change:";
   cin >> row;
   cout << "Enter the digit you wish to change to:";
   cin >> digit;

   board [row - 1][col - 1] = digit; // print the adjusted board
   print(board);
   }

   return 0;
}