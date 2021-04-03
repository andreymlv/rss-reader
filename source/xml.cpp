
#include "xml.h"

int XML::download_file(const curlpp::options::WriteFunctionCurlFunction &WriteCallback)
{
    try
    {
        /// Set the writer callback to enable cURL to write result in a memory area
        curlpp::options::WriteFunctionCurlFunction myFunction(WriteCallback);

        FILE *file = stdout;
        if (filename != NULL)
        {
            file = fopen(filename, "wb");
            if (file == NULL)
            {
                fprintf(stderr, "%s/n", strerror(errno));
                return EXIT_FAILURE;
            }
        }

        curlpp::OptionTrait<void *, CURLOPT_WRITEDATA>
            myData(file);

        request.setOpt(myFunction);
        request.setOpt(myData);

        /// Setting the URL to retrive.
        request.setOpt(new curlpp::options::Url(url));
        request.setOpt(new curlpp::options::Verbose(true));
        request.perform();
    }

    catch (curlpp::LogicError &e)
    {
        std::cout << e.what() << std::endl;
    }

    catch (curlpp::RuntimeError &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 1;
}

XML::XML(const char *url, const char *filename) : url(url),
                                                  filename(filename)
{
}

XML::~XML()
{
}
