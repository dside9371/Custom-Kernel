// tools.c, 159

#include "spede.h"
#include "types.h"
#include "data.h"

// clear DRAM data blocks by filling zeroes
void MyBzero(char *p, int size) {
   while(size--) *p++ = (char)0;
}

// dequeue, return 1st element in array, and move all forward
// if queue empty, return -1
int DeQ(q_t *p) {         // return -1 if q[] contains no valid elements
   int i,  element = -1;
   if(p->size == 0) return element;

   element = p->q[0];
   p->size--;
   for(i=0;i < p->size;i++){
	    p->q[i] = p->q[i+1];
   }
   return element;
}

// enqueue element to next available position in array, 'size' is array index
void EnQ(int element, q_t *p) {
   if(p->size == Q_SIZE) {
      cons_printf( "Kernel Panic: queue is full, cannot EnQ!\n");
      return;       // alternative: breakpoint() into GDB
   }
   p->q[p -> size] = element;
   p->size++;
}
int MyStrcmp(char *str1, char *str2) { // both null delimited
  while( *str1 != '\0') {
    if(*str1 != *str2)  return 0;
      str1++;
      str2++;
  }
  if (*str1 == *str2) return 1;
  else return 0;
}
void MyMemcpy(char *destination, char *source, int byte_size) {
  while(byte_size > 0){
    *destination = *source;
    byte_size--;
  }
}
