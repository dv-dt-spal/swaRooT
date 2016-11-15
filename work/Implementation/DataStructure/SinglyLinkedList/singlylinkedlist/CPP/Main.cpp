//------------------------------------------------------------------------------
//  File        :   Main.cpp
//  Author      :   Swaroop Pal
//  Description :   Main Function
//------------------------------------------------------------------------------

//Headers
#include "CSinglyLinkedList.h"

int main()
{
    #if 1
    //New SinglyLinkedList
    CSinglyLinkedList l_objSinglyLinkedList;
    for(int l_iPos = 0 ; l_iPos < 10 ; l_iPos++)
    {
        l_objSinglyLinkedList.PushFront(l_iPos);
    }    
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;

    for(int l_iPos = 0 ; l_iPos < 2 ; l_iPos++)
    {
        l_objSinglyLinkedList.PushBack(-l_iPos);
    }
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;

    for(int l_iPos = 0 ; l_iPos < 3 ; l_iPos++)
    {
        l_objSinglyLinkedList.PushFront(-l_iPos);
    }    
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;

    std::cout<<"At Index 0::"<<l_objSinglyLinkedList.GetFrom(0)->m_iData
                                                                    <<std::endl;
    std::cout<<"At Index 1::"<<l_objSinglyLinkedList.GetFrom(1)->m_iData
                                                                    <<std::endl;
    std::cout<<"At Index 2::"<<l_objSinglyLinkedList.GetFrom(2)->m_iData
                                                                    <<std::endl;
    
    #if 1    
    l_objSinglyLinkedList.PushAt(0,100);
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;
    l_objSinglyLinkedList.PushAt(2,-1500);
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;
    l_objSinglyLinkedList.PushAt(0,100);
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;

    #endif

    #if 0

    l_objSinglyLinkedList.DeleteKey(-1500);
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;

    #endif

    l_objSinglyLinkedList.DeleteKey(0);
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;

    l_objSinglyLinkedList.DeleteKey(-1);
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;

    l_objSinglyLinkedList.PushBack(290);
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;

    l_objSinglyLinkedList.DeleteKey(100);
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;

    l_objSinglyLinkedList.PushFront(290);
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;

    l_objSinglyLinkedList.DeleteKey(290);
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;

    l_objSinglyLinkedList.Delete();
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;

    l_objSinglyLinkedList.Delete(2);
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;

    l_objSinglyLinkedList.Delete(8);
    l_objSinglyLinkedList.PrintList();
    std::cout<<std::endl;

    std::cout<<"The Length of Linked List by Itr "
            <<l_objSinglyLinkedList.GetLengthItr()<<std::endl;

    std::cout<<"The Length of Linked List by Rec "
        <<l_objSinglyLinkedList.GetLengthRec(l_objSinglyLinkedList.m_pobjHead)
                                                                    <<std::endl;
    l_objSinglyLinkedList.PrintListRec(l_objSinglyLinkedList.m_pobjHead);

    l_objSinglyLinkedList.PrintMiddle();

    CNode * l_pbjNodetoDelte = l_objSinglyLinkedList.GetFrom(2);
    l_objSinglyLinkedList.DeleteNode(l_pbjNodetoDelte);
    l_objSinglyLinkedList.PrintList();

    l_objSinglyLinkedList.PrintMiddle();

    l_objSinglyLinkedList.PrintNthFromLast(1);  
    l_objSinglyLinkedList.PrintNthFromLast(0);  
    l_objSinglyLinkedList.PrintNthFromLast(-1);  
    l_objSinglyLinkedList.PrintNthFromLast(19);
    l_objSinglyLinkedList.PrintNthFromLast(7);
    l_objSinglyLinkedList.PrintNthFromLast(8);

    std::cout<<"The Reverse Linked List is Itr "<<std::endl;
    l_objSinglyLinkedList.ReverseItr();
    l_objSinglyLinkedList.PrintList();

    std::cout<<"The Reverse Linked List is Recr "<<std::endl;
    l_objSinglyLinkedList.ReverseRecr(l_objSinglyLinkedList.m_pobjHead,NULL);
    l_objSinglyLinkedList.PrintList();

    std::cout<<"Loop Present Status "
                <<l_objSinglyLinkedList.DetectLoop()<<std::endl;   
    #endif
    #if 0
    CSinglyLinkedList l_objSinglyLinkedList1;
    l_objSinglyLinkedList1.PushBack(1);
    l_objSinglyLinkedList1.PushBack(2);
    l_objSinglyLinkedList1.PushBack(5);
    l_objSinglyLinkedList1.PushBack(2);
    l_objSinglyLinkedList1.PushBack(1);
    std::cout<<"Is Plaindrome Status "
                <<l_objSinglyLinkedList1.IsPalindrome()<<std::endl;    
    l_objSinglyLinkedList1.PrintList();
    #endif
}
