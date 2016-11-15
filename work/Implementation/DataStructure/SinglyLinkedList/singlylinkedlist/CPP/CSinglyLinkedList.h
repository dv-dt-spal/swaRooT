//------------------------------------------------------------------------------
//  File        :   CSinglyLinkedList.h
//  Author      :   Swaroop Pal
//  Description :   Singly Linked List Header
//------------------------------------------------------------------------------

//Guard for multiple inclusion
#ifndef CSINGLY_LINKED_LIST_H
#define CSINGLY_LINKED_LIST_H

//Headers
#include "CNode.h"

//Class Description
class CSinglyLinkedList
{
    public:

        //Head
        CNode * m_pobjHead;               

        //Current Node
        CNode * m_pobjTail;

        //Index Count
        int m_iCount;

        //Constructor
        CSinglyLinkedList(){m_pobjHead = NULL; m_pobjTail = NULL;m_iCount = 0;}
        
        //Destructor
        ~CSinglyLinkedList(){m_pobjHead = NULL; m_pobjTail = NULL;m_iCount = 0;}

        //Print the List
        void PrintList();

        //Push an element to the top of the linked list
        void PushFront(int p_iData);

        //Push an element to the end of the linked list
        void PushBack(int p_iData);

        //Get Node from Index
        CNode* GetFrom(unsigned int p_uiIndex);

        //Push an element at a specified position of the linked list
        void PushAt(unsigned int p_uiIndex,int p_iData);

        //Delete a Node at particular position
        void Delete(unsigned int p_uiIndex = 0);

        //Delete a Node at particular position
        void DeleteKey(int p_iKey);

        //Get the Length of the Linked List Iterative
        int GetLengthItr();

        //Get the Length of the Linked List Recursive
        int GetLengthRec(CNode* p_pobjCurrentNode);

        //Print Linked list in recursive function
        void PrintListRec(CNode* p_pobjCurrentNode);

        //Delete Node with givent node pointer
        void DeleteNode(CNode* p_pobjNode);

        //Print the middle of the linked list
        void PrintMiddle();

        //Print Nth From Last
        void PrintNthFromLast(int p_iIndex);

        //Iterative Reversal Linked List
        void ReverseItr();

        //Iterative Reversal Linked List with Reference Node
        void ReverseItr(CNode **p_ppobjNode);

        //Recursive Reversal Linked List
        void ReverseRecr(CNode* p_pobjCurrentNode,CNode* p_pbojPrevNode);

        //Detect Loop -- Floyd’s Cycle-Finding Algorithm
        bool DetectLoop();

        //Check for Palindrome by Reversing a List
        bool IsPalindrome();

};
#endif
//------------------------------End of File-------------------------------------
