#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir = opendir("./tmp");
    struct dirent* dp;
    struct dirent *inode[100];
    int n = 0;
    while((dp = readdir(dir)) != NULL) {
        inode[n] = dp;
        n++;
    }

    for (int i = 0; i < n; i++) {
        int num = 0;
        int indexes[100];
        for (int j = i; j < n; j++) {
            if (inode[i]->d_ino == inode[j]->d_ino) {
                indexes[num] = j;
                num++;
            }
        }
        if (num > 1) {
            printf("Inode: %lu\n", inode[i]->d_ino);
            for(int k = 0; k < num; k++)
                printf("%s ", inode[indexes[k]]->d_name);
            printf("\n");
        }
    }
}
