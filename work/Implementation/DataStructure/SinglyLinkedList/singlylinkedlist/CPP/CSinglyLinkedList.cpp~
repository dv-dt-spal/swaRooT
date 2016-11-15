//------------------------------------------------------------------------------
//  File        :   CSinglyLinkedList.cpp
//  Author      :   Swaroop Pal
//  Description :   Singly Linked List Implementation
//------------------------------------------------------------------------------

//Headers
#include "CSinglyLinkedList.h"

//------------------------------------------------------------------------------
//PrintList
void CSinglyLinkedList :: PrintList()
{   
    //Local variable to keep track of the loop
    CNode * l_pobjCurrentNode = m_pobjHead;

    //Check for the last link
    while(NULL != l_pobjCurrentNode)
    {
        //Print the Data
        std::cout<<"The Data in the Node is "<<l_pobjCurrentNode->m_iData
                                                                    <<std::endl;

        //Change the Node
        l_pobjCurrentNode = l_pobjCurrentNode->m_pobjNextNode;
    }
}

//------------------------------------------------------------------------------
//CreateNode
void CSinglyLinkedList :: PushBack(int p_iData)
{
    //Create the New Node and assign data
    CNode * l_pobjNewNode = new CNode;
    l_pobjNewNode->m_iData = p_iData;
    l_pobjNewNode->m_pobjNextNode = NULL;

    //Check if head is null
    if(NULL == m_pobjHead)
    {
        //Assign the new node as head and current node
        m_pobjHead = l_pobjNewNode;
        m_pobjTail = l_pobjNewNode;
    }
    else
    {
        //Point the current Node to the new node
        m_pobjTail->m_pobjNextNode = l_pobjNewNode;

        //Make this node the current node
        m_pobjTail = l_pobjNewNode;
    }
    
    //Increase the Count of the Nodes
    m_iCount++;
}

//------------------------------------------------------------------------------
//PushFront
void CSinglyLinkedList :: PushFront(int p_iData)
{
    //Create the New Node and assign data
    CNode * l_pobjNewNode = new CNode;
    l_pobjNewNode->m_iData = p_iData;

    //Check if head is null
    if(NULL == m_pobjHead)
    {
        //Assign the new node as head and current node
        m_pobjHead = l_pobjNewNode;
        m_pobjTail = l_pobjNewNode;
    }
    else
    {        
        //Point the current Node to the new node
        l_pobjNewNode->m_pobjNextNode = m_pobjHead;
    
        //Make this node the current node
        m_pobjHead = l_pobjNewNode;
    }   

    //Increase the Count of the Nodes
    m_iCount++;
}

//------------------------------------------------------------------------------
//GetFrom<1-N>
CNode* CSinglyLinkedList :: GetFrom(unsigned int p_uiIndex)
{
    //Validate the index
    if(p_uiIndex > m_iCount-1)
    {
        std::cout<<"Invalid Index"<<std::endl;
        return NULL;
    }

    //Local Index
    unsigned int l_uiIndex = 0;
    
    //Local Node Pointer
    CNode* l_pobjCurrentNode = m_pobjHead;
    
    while(p_uiIndex != l_uiIndex)
    {
        //Change the Node
        l_pobjCurrentNode = l_pobjCurrentNode->m_pobjNextNode;
        
        //Increment the index
        l_uiIndex++;
    }

    //Return the desired node
    return l_pobjCurrentNode;
}

//------------------------------------------------------------------------------
//PushFront<1-N>
void CSinglyLinkedList :: PushAt(unsigned int p_uiIndex, int p_iData)
{
    //Validate the index
    if(p_uiIndex > m_iCount)
    {
        std::cout<<"Invalid Index"<<std::endl;
        return;
    }

    //Check if the Index is 1
    if(0 == p_uiIndex)
    {
        //Push it in the front
        this->PushFront(p_iData);
        return;
    }

    //Check if the Index is Last
    if(m_iCount == p_uiIndex)
    {
        //Push it in the back
        this->PushBack(p_iData);
        return;
    }  

    //Get the Data At the previous index
    CNode * l_objPrevNode = this->GetFrom(p_uiIndex-1); 
    
    //Create the New Node and assign data
    CNode * l_pobjNewNode = new CNode;
    l_pobjNewNode->m_iData = p_iData;

    //Point the New Node's Next to previous index node's next
    l_pobjNewNode->m_pobjNextNode = l_objPrevNode->m_pobjNextNode;

    //Point the previous index next to the new node
    l_objPrevNode->m_pobjNextNode = l_pobjNewNode;

    //Increase the Count of the Nodes
    m_iCount++;
}

//------------------------------------------------------------------------------
//Delete
void CSinglyLinkedList :: Delete(unsigned int p_uiIndex)
{
    //Validate the index
    if(p_uiIndex > m_iCount-1)
    {
        std::cout<<"Invalid Index"<<std::endl;
        return;
    }

    //Get the Node at Index
    CNode * l_pobjCurrentNode = this->GetFrom(p_uiIndex);

    //Check if it is the Head
    if(0 == p_uiIndex)
    {
        //Assign Head the Node next to the Current Head
        m_pobjHead = m_pobjHead->m_pobjNextNode;

        //Delete the Current Node
        delete l_pobjCurrentNode;
        l_pobjCurrentNode = NULL;
        
        //Decrement the Count of the Nodes and break
        m_iCount--;                
    }
    //Check if it is the Tail
    else if (m_iCount - 1 == p_uiIndex)
    {
        //Get the Previous Node
        CNode * l_pobjPrevNode = this->GetFrom(m_iCount-2);
        
        //Assign the Previous Index Node to the Current Index Next
        l_pobjPrevNode->m_pobjNextNode = NULL;

        //Delete the Current Node
        delete l_pobjCurrentNode;
        l_pobjCurrentNode = NULL;

        //Decrement the Count of the Nodes
        m_iCount--;

        //Update the Tail to the New Last Node and break from the loop
        m_pobjTail = l_pobjPrevNode;
    }
    else
    {
        //Get the Previous Node
        CNode * l_pobjPrevNode = this->GetFrom(p_uiIndex-1);

        //Assign the Previous Index Node to the Current Index Next
        l_pobjPrevNode->m_pobjNextNode = l_pobjCurrentNode->m_pobjNextNode;

        //Delete the Current Node
        delete l_pobjCurrentNode;
        l_pobjCurrentNode = NULL;

        //Decrement the Count of the Nodes
        m_iCount--;
    }
}

//------------------------------------------------------------------------------
//DeleteKey
void CSinglyLinkedList :: DeleteKey(int p_iKey)
{
    //Local Node Class
    CNode * l_pobjCurrentNode = m_pobjHead;

    //Local Counter
    int l_iIndex = 0;

    //Check for the last link
    while(NULL != l_pobjCurrentNode)
    {
        //Check if the Data is same as the key and is present in the Head
        if(p_iKey == l_pobjCurrentNode->m_iData && 0 == l_iIndex)
        {
            //Assign Head the Node next to the Current Head
            m_pobjHead = l_pobjCurrentNode->m_pobjNextNode;

            //Delete the Current Node
            delete l_pobjCurrentNode;
            l_pobjCurrentNode = NULL;
            
            //Decrement the Count of the Nodes
            m_iCount--;
    
            //Assign the Current Node as Head and continue the loop
            l_pobjCurrentNode = m_pobjHead;
            continue;                
        }
        else if (p_iKey == l_pobjCurrentNode->m_iData && m_iCount - 1 == l_iIndex)
        {
            //Get the Previous Node
            CNode * l_pobjPrevNode = this->GetFrom(l_iIndex-1);
            
            //Assign the Previous Index Node to the Current Index Next
            l_pobjPrevNode->m_pobjNextNode = NULL;

            //Delete the Current Node
            delete l_pobjCurrentNode;
            l_pobjCurrentNode = NULL;

            //Decrement the Count of the Nodes
            m_iCount--;

            //Update the Tail to the New Last Node and break from the loop
            m_pobjTail = l_pobjPrevNode;
            break;
        }
        else if (p_iKey == l_pobjCurrentNode->m_iData && 0 != l_iIndex 
                                                    && m_iCount - 1 != l_iIndex)
        {
            //Get the Previous Node
            CNode * l_pobjPrevNode = this->GetFrom(l_iIndex-1);

            //Assign the Previous Index Node to the Current Index Next
            l_pobjPrevNode->m_pobjNextNode = l_pobjCurrentNode->m_pobjNextNode;

            //Delete the Current Node
            delete l_pobjCurrentNode;
            l_pobjCurrentNode = NULL;

            //Decrement the Count of the Nodes
            m_iCount--;

            //Assign the Current Node as the Previous Node
            l_pobjCurrentNode = l_pobjPrevNode;
            l_iIndex--;
        }

        //Change the Node
        l_pobjCurrentNode = l_pobjCurrentNode->m_pobjNextNode;

        //Increment the counter
        l_iIndex++;
    }    
}

//------------------------------------------------------------------------------
//GetLengthItr
int CSinglyLinkedList :: GetLengthItr()
{
    //Local Variable to store the Length
    int l_iLength = 0;
    
    //Local Node Class
    CNode * l_pobjCurrentNode = m_pobjHead;

    while(NULL != l_pobjCurrentNode)
    {
        //Increment the length
        l_iLength++;
        
        //Change to the next node
        l_pobjCurrentNode = l_pobjCurrentNode->m_pobjNextNode;
    }   
    return l_iLength;    
}

//------------------------------------------------------------------------------
//GetLengthRec
int CSinglyLinkedList :: GetLengthRec(CNode* p_pobjCurrentNode)
{
    //For the next of last Node
    if(NULL == p_pobjCurrentNode) return 0;
    //For everywhere else
    else return 1 + GetLengthRec(p_pobjCurrentNode->m_pobjNextNode);
}

//------------------------------------------------------------------------------
//PrintListRec
void CSinglyLinkedList :: PrintListRec(CNode* p_pobjCurrentNode)
{
    //Recursive Printing of the Linked List
    if(NULL == p_pobjCurrentNode) return;        
    else
    {
        std::cout<<"Data is :: "<<p_pobjCurrentNode->m_iData<<std::endl;
        PrintListRec(p_pobjCurrentNode->m_pobjNextNode);
    }
}

//------------------------------------------------------------------------------
//DeleteNode
void CSinglyLinkedList :: DeleteNode(CNode* p_pobjNode)
{
    //Check for Node Validity
    if(NULL == p_pobjNode)
    {
        return;
    }

    //Store the Node's Next in Temp
    CNode* l_pobjNodeNext = p_pobjNode->m_pobjNextNode;

    //Change the Current Node 
    p_pobjNode->m_iData = l_pobjNodeNext->m_iData;
    p_pobjNode->m_pobjNextNode = l_pobjNodeNext->m_pobjNextNode;
    
    //Delete the Temp
    delete l_pobjNodeNext;   
    l_pobjNodeNext = NULL;
}

//------------------------------------------------------------------------------
//PrintMiddle
void CSinglyLinkedList :: PrintMiddle()
{
    //Check if the Linked list exists
    if(NULL == m_pobjHead)
    {
        return;
    }

    //Create the two pointers
    CNode * l_pobjSlowPointer = m_pobjHead;
    CNode * l_pobjFastPointer = m_pobjHead;   

    //Iterate over the Fast Pointer check for current as well as next of current
    while(NULL != l_pobjFastPointer && 
          NULL != l_pobjFastPointer->m_pobjNextNode)
    {
        //Fast Pointer Update
        l_pobjFastPointer = l_pobjFastPointer->m_pobjNextNode->m_pobjNextNode;
        
        //Slow Pointer Update
        l_pobjSlowPointer = l_pobjSlowPointer->m_pobjNextNode;
    }
    std::cout<<"The Middle Value is "<<l_pobjSlowPointer->m_iData<<std::endl;  
}

//Print Nth From Last
void CSinglyLinkedList :: PrintNthFromLast(int p_iIndex)
{
    //Check if the Linked list exists
    if(NULL == m_pobjHead)
    {
        return;
    }

    //Validate Index
    if(1 > p_iIndex)
    {
        return;
    }

    //Create the two pointers
    CNode * l_pobjMainPointer = m_pobjHead;
    CNode * l_pobjRefPointer = m_pobjHead;   

    //Local Counter
    int l_iCounter = 0;

    //Iterate the Reference pointer to the Nth Node from the beginning
    while(l_iCounter < p_iIndex)
    {
        //Check for invalid index
        if(NULL == l_pobjRefPointer)return;

        //Reference Pointer Update
        l_pobjRefPointer = l_pobjRefPointer->m_pobjNextNode;

        //Increment the counter
        l_iCounter++;
    }

    //Iterate the Reference pointer till the end and update the main pointer
    while(NULL != l_pobjRefPointer)
    {
        //Reference Pointer Update
        l_pobjRefPointer = l_pobjRefPointer->m_pobjNextNode;

        //Main Pointer Update
        l_pobjMainPointer = l_pobjMainPointer->m_pobjNextNode;
    }
    std::cout<<"The "<<p_iIndex<<" Value from end is "
                                    <<l_pobjMainPointer->m_iData<<std::endl;   
}

//------------------------------------------------------------------------------
//Iterative Reversal Linked List
void CSinglyLinkedList :: ReverseItr()
{
    //Check for linked list head
    if(NULL == m_pobjHead)
    {
        return;
    }

    //Local Pointers
    CNode* l_pobjPrevNode = NULL;
    CNode* l_pobjNextNode = NULL;
    CNode* l_pobjCurrentNode = m_pobjHead;

    //Iterate the linked list to reverse the link list
    while(NULL != l_pobjCurrentNode)
    {
        //Reverse the Nodes
        l_pobjNextNode = l_pobjCurrentNode->m_pobjNextNode;
        l_pobjCurrentNode->m_pobjNextNode = l_pobjPrevNode;
        l_pobjPrevNode = l_pobjCurrentNode;
        l_pobjCurrentNode = l_pobjNextNode;
    }
    
    //Update the Head
    m_pobjHead = l_pobjPrevNode;
}

//------------------------------------------------------------------------------
//Recursive Reversal Linked List
void CSinglyLinkedList :: ReverseRecr(CNode* p_pobjCurrentNode,
                                      CNode* p_pbojPrevNode)
{
    //Check if current Node is NULL
    if(NULL == p_pobjCurrentNode)
    { 
        //Update the Head
        m_pobjHead = p_pbojPrevNode;
        return; 
    }

    //Reverse Algorithm
    CNode * l_pobjNextNode = p_pobjCurrentNode->m_pobjNextNode;
    p_pobjCurrentNode->m_pobjNextNode = p_pbojPrevNode;
    p_pbojPrevNode = p_pobjCurrentNode;
    p_pobjCurrentNode = l_pobjNextNode;
    ReverseRecr(p_pobjCurrentNode,p_pbojPrevNode);
}

//------------------------------------------------------------------------------
//Detect Loop -- Floyd’s Cycle-Finding Algorithm
bool CSinglyLinkedList :: DetectLoop()
{
  //Local Node Pointers Slow and Fast
  CNode * l_pobjNodeSlowPointer = m_pobjHead; 
  CNode * l_pobjNodeFastPointer = m_pobjHead;
 
  while(l_pobjNodeSlowPointer && 
        l_pobjNodeFastPointer &&
        l_pobjNodeFastPointer->m_pobjNextNode)
  {
    l_pobjNodeSlowPointer = l_pobjNodeSlowPointer->m_pobjNextNode;
    l_pobjNodeFastPointer = l_pobjNodeFastPointer->m_pobjNextNode->m_pobjNextNode;
    if (l_pobjNodeSlowPointer == l_pobjNodeFastPointer)
    {
       std::cout<<"Found Loop"<<std::endl;
       return true;
    }
  }
  return false;
}

//------------------------------------------------------------------------------
//Iterative Reversal Linked List with Reference Node
void CSinglyLinkedList :: ReverseItr(CNode **p_ppobjNode)
{
    //Validate the head pointer
    if(NULL == *p_ppobjNode)
    {
        return;
    }
    
    //Reverse the Back Node
    CNode * l_pobjCurrentNode = *p_ppobjNode;
    CNode * l_pobjPrevNode = NULL;
    CNode * l_pobjNextNode = NULL;

    //Iterate over the current node to reverse
    while(NULL != l_pobjCurrentNode)
    {
        l_pobjNextNode = l_pobjCurrentNode->m_pobjNextNode;
        l_pobjCurrentNode->m_pobjNextNode = l_pobjPrevNode;
        l_pobjPrevNode = l_pobjCurrentNode;
        l_pobjCurrentNode = l_pobjNextNode;
    }

    //Update the Head of the Back Node
    *p_ppobjNode = l_pobjPrevNode;
}

//------------------------------------------------------------------------------
//Check for Palindrome by Reversing a List
bool CSinglyLinkedList :: IsPalindrome()
{
    //Validate the Linked List
    if(NULL == m_pobjHead)
    {
        return false;
    }
    
    //Bool Status
    bool l_bIsPalindrome = false;

    std::cout<<"The Original List"<<std::endl;
    PrintListRec(m_pobjHead);

    //Local Pointers
    CNode * l_pobjNodeFastPointer = m_pobjHead;
    CNode * l_pobjNodeSlowPointer = m_pobjHead;
    CNode * l_pobjNodeFront = m_pobjHead;
    CNode * l_pobjNodeBack = NULL;
    CNode * l_pobjNodeMiddle = NULL;

    //Iterate to reach the middle of the node
    while(NULL != l_pobjNodeFastPointer &&
          NULL != l_pobjNodeFastPointer->m_pobjNextNode)
    {
        //Update the Pointers
        l_pobjNodeFastPointer = l_pobjNodeFastPointer->
                                                m_pobjNextNode->m_pobjNextNode;
        l_pobjNodeFront = l_pobjNodeSlowPointer;
        l_pobjNodeSlowPointer = l_pobjNodeSlowPointer->m_pobjNextNode;
        
    }
    //Update the Back List
    l_pobjNodeBack = l_pobjNodeSlowPointer;

    //Store the middle pointer    
    l_pobjNodeMiddle = l_pobjNodeSlowPointer;

    //Make the last of the front list point to null
    l_pobjNodeFront->m_pobjNextNode = NULL;

    std::cout<<"The Original Back List"<<std::endl;
    PrintListRec(l_pobjNodeBack);

    //Reverse the Back List
    ReverseItr(&l_pobjNodeBack);

    //Local Pointer for comparision loop
    CNode * l_pobjNodeFrontItr = m_pobjHead;
    CNode * l_pobjNodeBackItr = l_pobjNodeBack;

    std::cout<<"The Front List"<<std::endl;
    PrintListRec(l_pobjNodeFrontItr);
    std::cout<<"The Reverse Back List"<<std::endl;
    PrintListRec(l_pobjNodeBackItr);

    //Compare the Lists
    while(NULL != l_pobjNodeFrontItr)
    {

        //Check if the data are the same
        if(l_pobjNodeFrontItr->m_iData != l_pobjNodeBackItr->m_iData)
        {
            l_bIsPalindrome = false;
            break;
        }                                

        //Update the Node
        l_pobjNodeFrontItr = l_pobjNodeFrontItr->m_pobjNextNode;
        l_pobjNodeBackItr = l_pobjNodeBackItr->m_pobjNextNode;

        //Update the bool
        l_bIsPalindrome = true;
    }

    //Reverse the Back List
    ReverseItr(&l_pobjNodeBack);

    std::cout<<"The Restored Back List"<<std::endl;
    PrintListRec(l_pobjNodeBack);

    //Reconnect the linked list
    l_pobjNodeFront->m_pobjNextNode = l_pobjNodeMiddle;

    std::cout<<"The Restored List"<<std::endl;
    PrintListRec(m_pobjHead);

    //return the status
    return l_bIsPalindrome;
}
//------------------------------End of File-------------------------------------
