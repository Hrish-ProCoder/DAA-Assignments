#include <iostream>
#include <chrono>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef struct {
   int v;
   int w;
   float d;
} Item;
void input(Item items[],int sizeOfItems) {
   cout << "Enter total "<< sizeOfItems <<" item's values and weight" <<
   endl;
   for(int i = 0; i < sizeOfItems; i++) {
      cout << "Enter "<< i+1 << " V ";
      cin >> items[i].v;
      cout << "Enter "<< i+1 << " W";
      cin >> items[i].w;
   }
}
void display(Item items[], int sizeOfItems) {
   int i;
   cout << "values: ";
   for(i = 0; i < sizeOfItems; i++) {
      cout << items[i].v << "\t";
   }
   cout << endl << "weight: ";
   for (i = 0; i < sizeOfItems; i++) {
      cout << items[i].w << "\t";
   }
   cout << endl;
}
bool compare(Item i1, Item i2) {
   return (i1.d > i2.d);
}
float knapsack(Item items[], int sizeOfItems, int W) {
   int i, j, pos;
   Item mx, temp;
   float totalValue = 0, totalWeight = 0;
   for (i = 0; i < sizeOfItems; i++) {
      items[i].d = items[i].v / items[i].w;
   }
   sort(items, items+sizeOfItems, compare);
   for(i=0; i<sizeOfItems; i++) {
      if(totalWeight + items[i].w<= W) {
         totalValue += items[i].v ;
         totalWeight += items[i].w;
      } else {
         int wt = W-totalWeight;
         totalValue += (wt * items[i].d);
         totalWeight += wt;
         break;
      }
   }
   cout << "total weight in bag " << totalWeight<<endl;
   return totalValue;
}
int main() {
   int W;
   Item items[5];
   input(items, 5);
   cout << "Entered data \n";
   display(items,5);
   cout<< "Enter Knapsack weight \n";
   cin >> W;
   
   // Get starting timepoint
   auto start = high_resolution_clock::now();
   
   float mxVal = knapsack(items, 5, W);
   
   // Get ending timepoint
   auto stop = high_resolution_clock::now();
   
   auto duration = duration_cast<microseconds>(stop - start);

   cout << "Max value for "<< W <<" weight is "<< mxVal;

   cout << "\nTime taken by function: "
         << duration.count()<< " microseconds" << endl;
}

/* Algo
Begin
   Take an array of structure Item
   Declare value, weight, knapsack weight and density
   Calculate density=value/weight for each item
   Sorting the items array on the order of decreasing density
   We add values from the top of the array to total value until the bag is full, i.e; total
   value <= W
End
*/