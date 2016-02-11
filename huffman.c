//
//  main.c
//  Huffman
//
//  Created by Deen Aariff on 2/8/16.
//  Copyright (c) 2016 Deen Aariff. All rights reserved.
//

#include <stdio.h>
#include "assert.h"
#include <stdlib.h>

#define LCHILD(X) (2(X)+1)
#define RCHILD(X) (2(X)+2)
#define parent(X) ((X-1)/2)

// structure for node
struct node {
   struct node* left;
   struct node* right;
   int val;
};

typedef struct node Node;

// structure for heap
struct heap {
   Node* data[256];
   int count;
};

// Swap values in indexes of Heap
void swap(struct heap* Heap, int index1, int index2) {
   Node* temp1 = malloc(sizeof(Node*));
   temp1 = Heap -> data[index1];
   Heap -> data[index1] = Heap -> data[index2];
   Heap -> data[index2] = temp1;

};

// Re-Order Heap from Top
void reHeapDown (struct heap* Heap) {
   int index = 0;
   int size = Heap -> count;
   while((2*(index)+1) < size && (2*(index)+2) < size) {
      int minChild = index;
      int right = (2*(index)+2);
      int left = (2*(index)+1);
      if(Heap -> data[left])
         minChild = Heap -> data[left] -> val;
      if(Heap -> data[right]) {
         if((Heap -> data[right] -> val) > minChild)
            minChild = Heap -> data[right] -> val;
      }
      if(Heap -> data[index] -> val > Heap -> data[minChild] -> val) {
         swap(Heap, index, minChild);
         index = minChild;
      }
   }
};

// Re-Order Heap from Bottom
void reHeapUp(struct heap* Heap) {
   int index = Heap -> count;
   Node* curr = Heap -> data[index];
   while(index !=0 || Heap -> data[parent(index)] -> val > curr -> val) {
      swap(Heap, parent(index), index);
   }
};

// Return min value from Heap and Resort
Node* pop(struct heap* Heap) {
   assert(Heap != NULL && Heap -> count != 0);
   int size = Heap -> count;
   Node* tmp = malloc(sizeof(Node*));
   tmp = Heap -> data[0];
   Heap -> data[0] = Heap -> data[size];
   Heap -> count--;
   reHeapDown(Heap);
   return tmp;
};

// Insert into Heap and Sort
int insert(struct heap* Heap, Node* insertion) {
   assert(Heap != NULL && Heap -> count != 256);
   Heap -> data[Heap -> count] = insertion;
   int size = Heap -> count;
   Heap -> data[size] = insertion;
   Heap -> count ++;
   reHeapUp(Heap);
   return 0;
};

// combine two nodes into one tree
Node* combine(Node* node1, Node* node2) {
   Node* tmp;
   tmp -> val = node1 -> val + node2 -> val;
   tmp -> left = node1;
   tmp -> right = node2;
   return tmp;
};

int main(int argc, const char * argv[]) {
   FILE *fp;
   int *freq = calloc(256, sizeof(int));
   struct heap* huffman = malloc(sizeof(struct heap*));
   int val = 0;

   // Open and Read File
   fp = fopen("test.rtf", "r");
   if (fp == NULL) {
      printf("File not Found\n");
      return 0;
   }
   while ((val = fgetc(fp)) != EOF)
      freq[val]++;
   printf("Read file");

   // Put frequencies into freq array
   int i = 0;
   for(i = 0; i < 254; i++) {
      Node* tmp = malloc(sizeof(Node*));
      tmp -> val = freq[i];
      insert(huffman, tmp);
   }

   // Set constant min-heap min
   Node* eof;
   eof -> val = -1;
   insert(huffman, eof);

   while (huffman -> count != 1) {
      Node* tmp1 = pop(huffman);
      Node* tmp2 = pop(huffman);
      tmp2 = combine(tmp1, tmp2);
      insert(huffman, tmp2);
   }

   printf("Complete!");
   return 0;
}
