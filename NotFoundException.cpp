#include "NotFoundException.h"

NotFoundException::NotFoundException(const string& message)
          : logic_error("Precondition Violated Excpetion: " + message)
{
} // end constructor
