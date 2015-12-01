#include "danylib.hh"

#include <stdint.h>
#include <stdio.h>


#define BYTE 8
#define BYTE_MASK 0xFF


template<typename T> void danylib_valueToBytes(T in,uint8_t * out)
{
  for (int i = 0;i < sizeof(T);i++)
  {
    out[i] = in & BYTE_MASK;
    in >> BYTE;
  }
}


template<typename T> T * danylib_bytesToValue(uint8_t * in)
{
  T out = 0;

  for (int i = 0;i < sizeof(T);i++)
  {
    out |= in[i] << BYTE * i;
  }
  return out;
}


template<typename T> void danylib_readFromBytes(uint8_t * output,int nItems,FILE * input)
{
  for (int item = 0;item < nItems;item++)
  {
    T block;
    fread(&block,sizeof(T),1,input);
    for (int i = 0;i < sizeof(T);i++)
    {
      output[item * sizeof(T) + i] = block & BYTE_MASK;
      block >> BYTE;
    }
  }
}
