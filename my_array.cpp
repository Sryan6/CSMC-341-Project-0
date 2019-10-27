#include <iostream>
#include <stdexcept>
#include "my_array.h"

using namespace std;

// Default constructor (size has default value of 1; see .h file)
my_array::my_array( unsigned int size ) {
  if (size < 1) {
    throw range_error("my_array(): array must have at least one element");
  }
  m_data = new int[size];
  m_size = size;
}

my_array::my_array(int* data, int len) {

  // if data array is empty, throw range_error exception
  if ( len < 1 ) {
    throw range_error("my_array(): input data must have at least one element");
  }

  m_data = new int[len];
  m_size = len;
  
  // copy data to m_data
  for (int i = 0; i < len; i++) {
    m_data[i] = data[i];
  }
}

int my_array::size() const { return m_size; }

int& my_array::at(unsigned int indx) {
  if (indx >= m_size) {
    throw range_error("at(): index is out-of-range");
  }
  return m_data[indx];
}

my_array::my_array( const my_array& arr){

  // if data array is empty, throw range_error exception
  if (arr.size() < 1 ) {
    throw range_error("my_array(): input data must have at least one element");
  }

  m_size = arr.size();
  m_data = new int[m_size];
  for(int i = 0; i < arr.size(); i++){
    m_data[i] = arr.m_data[i];
  }
}

my_array::~my_array(){
  delete[] m_data;
}

my_array& my_array::operator=( const my_array& arr ){
  if(arr.size() < 1){
    throw range_error("my_array(): array must have at least one element to copy");
  }
  //Protects against self-assignment
  else if(this != &arr){
    delete[] m_data;
    
    this->m_size = arr.m_size;
    this->m_data = new int[m_size];
    
    for(int i = 0; i < arr.size(); i++){
      m_data[i] = arr.m_data[i];
    }
  }
  
  return *this;
}
