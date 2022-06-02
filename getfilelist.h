#include "callendar.h"
#include "crud.h"
#include <stdio.h>
#include <io.h>
#include <conio.h>

int getfilelist(void)
{
    struct __finddata64_t c_file;
    intptr_t hFile;
    char path[] = "C:\\Users\\soon\\source\\repos\\C_TeamProject\\C_TeamProject\\*.txt";
    if ((hFile = _findfirsti64(path, &c_file)) == -1L) {
        switch (errno) {
        case ENOENT:
            printf("파일 없음\n");
            exit(ENOENT);
            break;
        case EINVAL:
            fprintf(stderr, "경로명 오류.\n");
            exit(EINVAL);
            break;
        case ENOMEM:
            fprintf(stderr, "메모리 부족 또는 너무 긴 파일명 오류.\n");
            exit(ENOMEM);
            break;
        default:
            fprintf(stderr, "기타 오류.\n");
            exit(1);
            break;
        }
    }
    else {
        printf("------작성된 파일목록------\n");
        do {
            if (c_file.name[0] != '.')
                printf("%s\n", c_file.name);
        } while (_findnexti64(hFile, &c_file) == 0);
        printf("---------------------------\n");
        _findclose(hFile); // 메모리를 반환
    }
    return 0;
}