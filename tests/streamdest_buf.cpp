/*! \file streamdest_buf.cpp
    \brief Class for Assembly Stream destination buffer.
*/
#include <string>
#include <streamdest.h>
#include "streamdest_buf.h"

streamdest_buf::streamdest_buf()
{
}

streamdest_buf::~streamdest_buf()
{
}

void streamdest_buf::clear()
{
    m_buf.clear();
}

std::string streamdest_buf::get() const
{
    return m_buf;
}

void streamdest_buf::space()
{
    m_buf.push_back(' ');
}

void streamdest_buf::indent()
{
}

void streamdest_buf::write(const std::string &str)
{
    m_buf += str;
}

void streamdest_buf::writeln(const std::string &str)
{
    m_buf += str;
}
