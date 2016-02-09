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


struct node {
   struct node* left;
   struct node* right;
   int data;
};

struct heap {
   Node* data;
   int count;
};

typedef struct node Node;

void swap(struct heap* Heap, int index1, int index2) {
   Node* temp1 = Heap -> data[index1];
   Heap -> data[index1] = Heap -> data[index2];
   Heap -> data[index2] = temp1;
};

void reHeapDown (struct heap* Heap) {
   int index = 0;
   while()
};

void reHeapUp(struct heap* Heap) {
   int index = Heap -> count;
   Node* curr = Heap -> data[index];
   while(index !=0 || Heap -> data[parent(index)] -> data > curr -> data) {
      swap(Heap, parent(index), index);
   }
};

Node* pop(struct heap* Heap) {
   assert(Heap != NULL && Heap -> count != 0);
   int size = Heap -> count;
   Node* tmp = Heap -> data[0];
   Heap -> data[0] = Heap -> data[size];
   Heap -> count--;
   reHeapDown(Heap);
   return tmp;
};

int insert(struct heap* Heap, Node* insertion) {
   assert(Heap != NULL && Heap -> count != 256);
   Heap -> data[Heap -> count] = insertion;
   int size = Heap -> count;
   Heap -> data[size] = insertion;
   Heap -> count ++;
   reHeapUp(Heap);
   return 0;
};

Node* combine(Node* node1, Node* node2) {
   Node* tmp;
   tmp -> data = node1 -> data + node2 -> data;
   tmp -> left = node1;
   tmp -> right = node2;
   return tmp;
};

int main(int argc, const char * argv[]) {
   struct heap* huffman;
   huffman -> data = (Node*)calloc(sizeof(Node*)*256);
   while (huffman -> count != 1) {
      Node* tmp1 = pop(huffman);
      Node* tmp2 = pop(huffman);
      tmp2 = combine(tmp1, tmp2);
      insert(huffman, tmp2);
   }
   printf("Hello, World!\n");
   return 0;
}
