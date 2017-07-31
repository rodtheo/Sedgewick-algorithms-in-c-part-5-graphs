# Templates and Generic Programming

In C++ there're three ways to employ generic coding (code that can work with different types) practices:

- `void*` pointers
- templates
- inheritance

Example:

Assigning the contents of one array to a second array. The following code works for any array type since `void*` is a universal pointer type, any array can be passed as parameter.

```c++

int transfer(void* from, void* to, int elementSize, int size)
{
  // the number of bytes to be transfered is the amount of
  // bytes required to store the element (an int fits in 4
  // bytes on many machines) times the number of elements
  // in array
  int nBytes = size * elementSize;

  // loop to transfer byte to byte
  for (int i=0; i < nBytes); i++)
    static_cast<char*>(to)[i] = static_cast<char*>(from)[i];

  return size;
}

```
