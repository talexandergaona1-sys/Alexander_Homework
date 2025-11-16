#ifndef FILESTREAMBUF_H
#define FILESTREAMBUF_H

#include <streambuf>
#include <cstdio>

class FileStreamBuf : public std::streambuf {
public:
    FileStreamBuf(FILE* fp, int bufsize);
    ~FileStreamBuf();

    FileStreamBuf(const FileStreamBuf&) = delete;
    FileStreamBuf& operator=(const FileStreamBuf&) = delete;

protected:
    virtual int overflow(int c) override;
    virtual int sync() override;

    virtual int underflow() override;
    virtual int uflow() override;

private:
    FILE* file;    
    char* buffer;
    int size;
};

#endif