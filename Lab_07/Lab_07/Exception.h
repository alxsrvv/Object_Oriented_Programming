#pragma once
#include <exception>
#include <string>

class Exception : public std::exception
{
private:
    std::string _error;
public:
    Exception(const std::string& temp_error);
    virtual const char* Excp_massage() const;
};