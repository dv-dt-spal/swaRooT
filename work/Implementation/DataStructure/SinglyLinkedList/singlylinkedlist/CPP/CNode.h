//------------------------------------------------------------------------------
//  File        :   CNode.h
//  Author      :   Swaroop Pal
//  Description :   Node of the Linked List
//------------------------------------------------------------------------------

//Guard for multiple inclusion
#ifndef CNODE_H
#define CNODE_H
//Headers
#include <iostream>

//Class Description
class CNode
{    
    public:
        
        //Data
        int m_iData;
    
        //Next Node
        CNode * m_pobjNextNode;
 
        //Constructor
        CNode(){ m_pobjNextNode = NULL; }
        
        //Destructor
        ~CNode(){ m_pobjNextNode = NULL; }
};
#endif
//----------------------------End of File---------------------------------------
