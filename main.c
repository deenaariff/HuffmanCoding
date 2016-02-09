//
//  main.c
//  Huffman
//
//  Created by Deen Aariff on 2/8/16.
//  Copyright (c) 2016 Deen Aariff. All rights reserved.
//

#include <stdio.h>
#include "assert.h"

#define lchild(X) (2(X)+1)
#define rchild(X) (2(X)+2)
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
   Node* temp1 = Heap -> data[index1];
   Heap -> data[index1] = Heap -> data[index2];
   Heap -> data[index2] = temp1;
};

// Re-Order Heap from Top
void reHeapDown (struct heap* Heap) {
   int index = 0;
   while()
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
   Node* tmp = Heap -> data[0];
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
   struct heap* huffman;
   while (huffman -> count != 1) {
      Node* tmp1 = pop(huffman);
      Node* tmp2 = pop(huffman);
      tmp2 = combine(tmp1, tmp2);
      insert(huffman, tmp2);
   }
   printf("Hello, World!\n");
   return 0;
}
