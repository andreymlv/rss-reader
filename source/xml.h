
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cerrno>

#ifndef XML_H
#define XML_H

class XML
{
private:
    const char *url;
    const char *filename;

private:
    curlpp::Cleanup cleaner;
    curlpp::Easy request;

private:
    FILE *file = stdout;

public:
    int download_file(const curlpp::options::WriteFunctionCurlFunction &WriteCallback);
    XML(const char *url, const char *filename);
    ~XML();
};

#endif
