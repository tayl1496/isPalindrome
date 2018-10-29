
#include <string>

#include "isPalindrome.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

bool isPalindrome(const std::string& s){
  LinkedStack<char> stack;
  LinkedQueue<char> queue;

  bool palin = true;
  char ch1, ch2;
  
  for(int i(0); i<(int)s.length(); ++i){
    stack.push(s[i]);
    queue.enqueue(s[i]);
  }

  for(int i(0); i<(int)s.length(); ++i){
    ch1 = stack.peek();
    ch2 = queue.peekFront();
    stack.pop();
    queue.dequeue();
    if(ch1!=ch2)
      palin = false;
  }

  return palin;
}
