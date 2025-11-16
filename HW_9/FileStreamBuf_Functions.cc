#include "FileStreamBuf.h"
#include <cstdio>

FileStreamBuf::FileStreamBuf(FILE* fp, int bufsize)
    : file(fp), size(bufsize)
{
    buffer = new char[size];

    setp(buffer, buffer + size);  
    setg(buffer, buffer, buffer);  
}

FileStreamBuf::~FileStreamBuf() {
    sync();

    if (file != stdin && file != stdout && file != stderr)
        fclose(file);

    delete[] buffer;
}

int FileStreamBuf::overflow(int c) {
    int count = pptr() - pbase();  
    if (count > 0)
        fwrite(pbase(), 1, count, file);

    setp(buffer, buffer + size);

    if (c != EOF) {
        *pptr() = static_cast<char>(c);
        pbump(1);
    }

    return c;
}

int FileStreamBuf::sync() {
    int count = pptr() - pbase();
    if (count > 0)
        fwrite(pbase(), 1, count, file);

    setp(buffer, buffer + size);
    return 0;
}

int FileStreamBuf::underflow() {
    if (gptr() < egptr())
        return static_cast<unsigned char>(*gptr());

    int count = fread(buffer, 1, size, file);

    setg(buffer, buffer, buffer + count);

    if (count == 0)
        return EOF;

    return static_cast<unsigned char>(*gptr());
}

int FileStreamBuf::uflow() {
    int c = underflow();
    if (c != EOF)
        gbump(1);
    return c;
}