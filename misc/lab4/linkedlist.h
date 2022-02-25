#ifndef MYLIST_H
#define MYLIST_H

   struct listNode {
        int data;
        struct listNode* prev;
        struct listNode* next;
   };

   typedef struct listNode Node;
   typedef Node* NodePtr;

   extern NodePtr head;
   extern NodePtr tail;   
   

   //static int nodeCount = 0;

   bool isEmpty();
   NodePtr makeNewNode(int); 

   void insertAtFront(const NodePtr);
   void insertAtEnd(const NodePtr);
   void insertStrategic(const NodePtr);

   void deleteFromFront( );
   void deleteFromEnd( );

   void printList();


#endif
