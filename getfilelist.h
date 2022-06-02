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
            printf("���� ����\n");
            exit(ENOENT);
            break;
        case EINVAL:
            fprintf(stderr, "��θ� ����.\n");
            exit(EINVAL);
            break;
        case ENOMEM:
            fprintf(stderr, "�޸� ���� �Ǵ� �ʹ� �� ���ϸ� ����.\n");
            exit(ENOMEM);
            break;
        default:
            fprintf(stderr, "��Ÿ ����.\n");
            exit(1);
            break;
        }
    }
    else {
        printf("------�ۼ��� ���ϸ��------\n");
        do {
            if (c_file.name[0] != '.')
                printf("%s\n", c_file.name);
        } while (_findnexti64(hFile, &c_file) == 0);
        printf("---------------------------\n");
        _findclose(hFile); // �޸𸮸� ��ȯ
    }
    return 0;
}