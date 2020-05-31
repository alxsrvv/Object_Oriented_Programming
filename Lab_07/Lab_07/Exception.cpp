#include "Exception.h"

Exception::Exception(const std::string& temp_error) : _error(temp_error)
{

}

const char* Exception::Excp_massage() const
{
    return _error.c_str();
}
