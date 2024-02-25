include "bstree.h"
#include <iostream>

using namespace std;


template <typename SomeType>


void BSTree<SomeType>::Delete(BSTreeNode<SomeType>*& treePtr, SomeType& item)
{
    if (treePtr == NULL)
        throw NotFoundBSTree();

    if (item < treePtr->data)
        Delete(treePtr->leftPtr, item);
    else if (item > treePtr->data)
        Delete(treePtr->rightPtr, item);
    else
        DeleteNode(treePtr);
}

template <typename SomeType>
void BSTree<SomeType>::DeleteNode(BSTreeNode<SomeType>*& treePtr)
{
    BSTreeNode<SomeType>* tempPtr;

    if (treePtr->leftPtr == NULL && treePtr->rightPtr == NULL)
    {
        delete treePtr;
        treePtr = NULL;
    }
    else if (treePtr->leftPtr == NULL)
    {
        tempPtr = treePtr;
        treePtr = treePtr->rightPtr;
        delete tempPtr;
    }
    else if (treePtr->rightPtr == NULL)
    {
        tempPtr = treePtr;
        treePtr = treePtr->leftPtr;
        delete tempPtr;
    }
    else
    {
        treePtr->data = GetPredecessor(treePtr->leftPtr);
        Delete(treePtr->leftPtr, treePtr->data);
    }
}

template <typename SomeType>

void BSTree<SomeType>::Insert(BSTreeNode<SomeType>*& ptr, SomeType item)
{
    if (ptr == NULL)
    {
        try
        {
            ptr = new BSTreeNode<SomeType>;
            ptr->data = item;
            ptr->leftPtr = ptr->rightPtr = NULL;
        }
        catch (std::bad_alloc)
        {
            throw FullBSTree();
        }
    }
    else if (item < ptr->data)
        Insert(ptr->leftPtr, item);
    else if (item > ptr->data)
        Insert(ptr->rightPtr, item);
    else
        throw FoundInBSTree();
}

template <typename SomeType>
void BSTree<SomeType>::Destroy(BSTreeNode<SomeType>*& ptr)
{
    if (ptr != NULL)
    {
        Destroy(ptr->leftPtr);
        Destroy(ptr->rightPtr);
        delete ptr;
        ptr = NULL;
    }
}

template <typename SomeType>
void BSTree<SomeType>::CopyTree(BSTreeNode<SomeType>*& copy, const BSTreeNode<SomeType>* originalTree)
{
    if (originalTree == NULL)
        copy = NULL;
    else
    {
        copy = new BSTreeNode<SomeType>;
        copy->data = originalTree->data;
        CopyTree(copy->leftPtr, originalTree->leftPtr);
        CopyTree(copy->rightPtr, originalTree->rightPtr);
    }
}

template <typename SomeType>
SomeType BSTree<SomeType>::GetPredecessor(BSTreeNode<SomeType>* treePtr) const
{
    while (treePtr->rightPtr != NULL)
        treePtr = treePtr->rightPtr;

    return treePtr->data;
}

template <typename SomeType>
int BSTree<SomeType>::CountNodes(BSTreeNode<SomeType>* treePtr) const
{
    if (treePtr == NULL)
        return 0;
    else
        return 1 + CountNodes(treePtr->leftPtr) + CountNodes(treePtr->rightPtr);
}

template <typename SomeType>
int BSTree<SomeType>::LevelCount(BSTreeNode<SomeType>* treePtr) const
{
    if (treePtr == NULL)
        return 0;
    else
        return 1 + std::max(LevelCount(treePtr->leftPtr), LevelCount(treePtr->rightPtr));
}

template <typename SomeType>
int BSTree<SomeType>::FindLevel(BSTreeNode<SomeType>* treePtr, SomeType item) const
{
    if (treePtr == NULL)
        throw NotFoundBSTree();

    if (item == treePtr->data)
        return 0;
    else if (item < treePtr->data)
        return 1 + FindLevel(treePtr->leftPtr, item);
    else
        return 1 + FindLevel(treePtr->rightPtr, item);
}



template <typename SomeType>
BSTree<SomeType>::BSTree() : rootPtr(NULL)
{
   
}

template <typename SomeType>
BSTree<SomeType>::BSTree(const BSTree<SomeType>& someTree)
{
    CopyTree(rootPtr, someTree.rootPtr);
}

template <typename SomeType>
void BSTree<SomeType>::operator=(const BSTree<SomeType>& originalTree)
{
    if (this != &originalTree)
    {
        Destroy(rootPtr);
        CopyTree(rootPtr, originalTree.rootPtr);
    }
}

template <typename SomeType>
BSTree<SomeType>::~BSTree()
{
    Destroy(rootPtr);
}

template <typename SomeType>
void BSTree<SomeType>::InsertItem(SomeType item)
{
    Insert(rootPtr, item);
}

template <typename SomeType>
SomeType BSTree<SomeType>::DeleteItem(SomeType item)
{
    SomeType temp;
    Delete(rootPtr, item);
    temp = item;
    return temp;
}

template <typename SomeType>
void BSTree<SomeType>::MakeEmpty()
{
    Destroy(rootPtr);
}

template <typename SomeType>
int BSTree<SomeType>::Size() const
{
    return CountNodes(rootPtr);
}

template <typename SomeType>
bool BSTree<SomeType>::IsFull() const
{
    try
    {
        BSTreeNode<SomeType>* temp = new BSTreeNode<SomeType>;
        delete temp;
        return false;
    }
    catch (std::bad_alloc)
    {
        return true;
    }
}

template <typename SomeType>
bool BSTree<SomeType>::IsEmpty() const
{
    return rootPtr == NULL;
}

template <typename SomeType>
SomeType BSTree<SomeType>::Min() const
{
    if (IsEmpty())
        throw EmptyBSTree();

    BSTreeNode<SomeType>* current = rootPtr;
    while (current->leftPtr != NULL)
        current = current->leftPtr;

    return current->data;
}

template <typename SomeType>
SomeType BSTree<SomeType>::Max() const
{
    if (IsEmpty())
        throw EmptyBSTree();

    BSTreeNode<SomeType>* current = rootPtr;
    while (current->rightPtr != NULL)
        current = current->rightPtr;

    return current->data;
}

template <typename SomeType>
int BSTree<SomeType>::TotalLevels() const
{
    if (IsEmpty())
        throw EmptyBSTree();

    return LevelCount(rootPtr);
}

template <typename SomeType>
int BSTree<SomeType>::Level(SomeType item) const
{
    return FindLevel(rootPtr, item);
}

