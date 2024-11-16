#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    // ทดสอบการอ่านแต่ละบรรทัด
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // จำเป็นต้อง free หลังจากใช้แต่ละบรรทัด
    }

    close(fd); // ปิดไฟล์หลังจากเสร็จ
    return (0);
}
