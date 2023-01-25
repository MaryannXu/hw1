
#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
  if (empty()){
    Item* newp = new Item();
    newp->prev = NULL;
    newp->next = NULL;
    head_ = newp;
    tail_ = newp;
    tail_->val[0] = val;
    tail_->last=(tail_->last)+1;
  }
  else if (tail_->last >= (ARRSIZE)){
    Item* newp = new Item();
    tail_->next = newp;
    newp->prev = tail_;
    newp->next = NULL;
    tail_ = newp;
    tail_->val[0] = val;
    tail_->last=(tail_->last)+1;
  }
  else if (tail_->last < (ARRSIZE)){
    tail_->val[(tail_->last)] = val;
    tail_->last=(tail_->last)+1;
  }
  size_++;
}

void ULListStr::pop_back(){
  if (empty()==false){
    if ((tail_->last) == 0){
      tail_ = tail_->prev;
      tail_->next = NULL;
    }
    else{
      tail_->val[(tail_->last)-1] = "";
      tail_->last = (tail_->last)-1;
    }
  }
  size_--;
}

void ULListStr::push_front(const std::string& val){
  if (empty()){
    Item* newp = new Item();
    newp->prev = NULL;
    newp->next = NULL;
    head_ = newp;
    tail_ = newp;
    head_->val[ARRSIZE-1] = val;
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
  }
  else if (head_->first == 0){
    Item* newp = new Item();
    newp -> next = head_;
    head_ -> prev = newp;
    head_ = newp;
    head_->val[ARRSIZE-1] = val;
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
  }
  else if (head_->first>0){
    head_->val[(head_->first)-1] = val;
    head_->first=(head_->first)-1;
  }
  size_++;
}

void ULListStr::pop_front(){
  if (empty()==false){
    if ((head_->first) == (ARRSIZE-1)){
      head_ = head_->next;
      head_->prev = NULL;
    }
    else{
      head_->val[(head_->first)] = "";
      head_->first = (head_->first)+1;
    }
  }
  size_--;
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* curr = head_;
  int temp;
  int itemsPassed = 0;
  int counter = 0;
  for(size_t i = 0; i < size_; i++){
    temp = (curr->first) + (loc-itemsPassed);
    if (i==loc){
      return &(curr->val[temp]);
    }

    counter++;
    if ((curr->first) + counter >= ARRSIZE){
      curr = curr->next;
      itemsPassed += counter;
      counter = 0;
    }
  }
  return NULL;
  }

std::string const & ULListStr::back() const{
  return tail_->val[(tail_->last)-1];

}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];

}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
