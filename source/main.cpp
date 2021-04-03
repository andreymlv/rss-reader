

#include "xml.h"

/// Callback must be declared static, otherwise it won't link...
size_t WriteCallback(char *ptr, size_t size, size_t nmemb, void *f)
{
    FILE *file = (FILE *)f;
    return fwrite(ptr, size, nmemb, file);
};

int main(int argc, char *argv[])
{
    const char *url = "https://meduza.io/rss2/all";
    // CMake execute file from `build' directory
    const char *filename = "../resources/rss/meduza.rss";

    auto meduza = new XML(url, filename);

    printf("Downloading RSS-Feed from: %s\n", url);

    if (!meduza->download_file(WriteCallback))
    {
        printf("Error!\n");
    }

    return 0;
}
