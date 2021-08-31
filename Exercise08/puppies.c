#include "miniz.h"
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 512

char* GetFileName(char* filePath)
{
    size_t length = strlen(filePath);
    size_t index = length - 1;
    for (;; --index)
    {
        if (filePath[index] == '/')
        {
            return filePath + index + 1;
        }
        if (index == 0)
        {
            return filePath;
        }
    }
    return filePath;
}

int UnzipPuppies(char *archiveName)
{
    mz_zip_archive pZip;
    memset(&pZip, 0, sizeof(pZip));
    if (!mz_zip_reader_init_file(&pZip, archiveName, 0))
    {
        printf("Unable to unzip this file\n");
        return 0;
    }
    mz_uint numFiles =  mz_zip_reader_get_num_files(&pZip);
    mz_zip_archive_file_stat pStat;
    for (size_t i = 0; i < numFiles; ++i)
    {
        FILE *fp;
        if (!mz_zip_reader_is_file_a_directory(&pZip, i))
        {
            char filename[BUF_SIZE];
            mz_zip_reader_get_filename(&pZip, i, filename, BUF_SIZE);
            char* justFilename = GetFileName(filename);
            mz_zip_reader_extract_to_file(&pZip, i, justFilename, 0);
        }
    }
    mz_zip_end(&pZip);
    return 1;
}
