/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Implementation file for a pointer-based implementation of the ADT
 *  stack.
 *
 *  Adapted from pages 246-248, 250 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 29 Sep 2017
 *
 *  @version 7.0 */

#include <new>
#include <string>

#include "PrecondViolatedExcep.h"

template <typename ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack) {

  if (aStack.topPtr == nullptr) {
    topPtr = nullptr;
  }
  else {
    auto origStackPtr(aStack.topPtr);

    try {
      topPtr = std::make_shared<Node<ItemType>>(origStackPtr->getItem() );

      auto newChainPtr(topPtr);

      origStackPtr = origStackPtr->getNext();

      while (origStackPtr != nullptr) {
	auto newChainPtr(std::make_shared<Node<ItemType>>(origStackPtr->getItem()));

	newChainPtr = newChainPtr->getNext();
	origStackPtr = origStackPtr->getNext();
      }
    }
    catch(const std::bad_alloc&) {
      while (!isEmpty() ) {
	pop();
      }
      throw;
    }
  }
}

template <typename ItemType>
LinkedStack<ItemType>::~LinkedStack() {

  while (!isEmpty() ) {
    pop();
  }
}

template <typename ItemType>
bool LinkedStack<ItemType>::isEmpty() const {

  return topPtr == nullptr;
}

template <typename ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem) {

  bool canPush(true);

  try {
    topPtr = std::make_shared<Node<ItemType>>(newItem, topPtr);
  }
  catch(const std::bad_alloc&) {
    canPush = false;
  }

  return canPush;
}

template <typename ItemType>
bool LinkedStack<ItemType>::pop() {

  bool canPop(!isEmpty() );

  if (canPop) {
    auto nodeToDeletePtr(topPtr);

    topPtr = topPtr->getNext();

    nodeToDeletePtr->setNext(nullptr);
    //delete nodeToDeletePtr;
  }

  return canPop;
}

template <typename ItemType>
ItemType LinkedStack<ItemType>::peek() const {
  //   throw(PrecondViolatedExcep) {

  if (isEmpty() ) {
    std::string message("LinkedStack::peek() ");
    message += "called on an empty stack.";

    throw PrecondViolatedExcep(message);
  }

  return topPtr->getItem();
}
