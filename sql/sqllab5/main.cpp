#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include "extmem.c"

#define BUFSIZE 520 //520 = (64+1)*8
#define BLKSIZE 64  //64 = 8 * 8 = 8 * 7 + 4 + 4
#define R_COUNT 112
#define S_COUNT 224
#define GROUPSIZE 8

int BLKNUM = 1;         //磁盘上块地址
Buffer buf;             //缓冲区
unsigned char *blk;     //块地址
int R_START, S_START;   //R,S的起始块地址
int group_in_blk = (BLKSIZE - 4)/GROUPSIZE;


//生成[minnum, maxnum]的随机数
unsigned int getRandom(int minnum, int maxnum) {
    return rand()%(maxnum-minnum+1)+minnum;
}

int initGroup(int group_count, int a_min, int a_max, int b_min, int b_max) {
    //blk = getNewBlockInBuffer(&buf);
    int startnum = BLKNUM;
    for(int i = 0; i < group_count / group_in_blk; i++) {
        blk = getNewBlockInBuffer(&buf);
        for(int j = 0; j < group_in_blk; j++) {
            unsigned int a = getRandom(a_min, a_max);
            unsigned int b = getRandom(b_min, b_max);
            *(blk+j*8+0) = a;
            *(blk+j*8+4) = b;
        }
        if(i == (group_count / group_in_blk - 1))
            *(blk+BLKSIZE-4) = (unsigned int)0;
        else
            *(blk+BLKSIZE-4) = (unsigned int)(BLKNUM+1);
        //printf("addr  ==  %d\n", *(blk+BLKSIZE-4));
        writeBlockToDisk(blk, BLKNUM, &buf);
        BLKNUM++;
    }
    return startnum;
}

void initData() {
    R_START = initGroup(R_COUNT, 1, 40, 1, 1000);
    S_START = initGroup(S_COUNT, 20, 60, 1, 1000);
}

void printData(int start) {
    int addr = start;

    printf("Data of %d:\n", addr);
    while(addr != 0) {

        blk = readBlockFromDisk(addr, &buf);
        for(int j = 0; j < group_in_blk; j++) {
            int a = *(blk+j*8+0);
            int b = *(blk+j*8+4);
            if(a != 0)
                printf("%d",a);
            if(b != 0)
                printf("\t%d",b);
            printf("\n");
        }
        addr = *(blk+BLKSIZE-4);
        freeBlockInBuffer(blk, &buf);
    }
    printf("\n");
}

int findfirst(int start, int value) {
    int ans = BLKNUM;
    int addr = start;
    unsigned char *tarblk;
    tarblk = getNewBlockInBuffer(&buf);
    int i = 0;
    while(addr != 0) {
        blk = readBlockFromDisk(addr, &buf);
        for(int j = 0; j < group_in_blk; j++) {
            int a = *(blk+j*8+0);
            int b = *(blk+j*8+4);
            if(value == a) {
                *(tarblk+i*8+0)=a;
                *(tarblk+i*8+4)=b;
                i++;
                if(i >= 7) {
                    *(tarblk+BLKSIZE-4) = BLKNUM+1;
                    writeBlockToDisk(tarblk, BLKNUM, &buf);
                    tarblk = getNewBlockInBuffer(&buf);
                    BLKNUM++;
                    i = 0;
                }
            }
        }
        addr = *(blk+BLKSIZE-4);
        freeBlockInBuffer(blk, &buf);
    }
    if(i != 0) {
        for(; i<=7; i++) {
            *(tarblk+i*8+0)=0;
            *(tarblk+i*8+4)=0;
        }
        writeBlockToDisk(tarblk, BLKNUM, &buf);
        BLKNUM++;
    } else {
        blk = readBlockFromDisk(BLKNUM-1, &buf);
        *(blk+BLKSIZE-4) = 0;
        writeBlockToDisk(blk, BLKNUM, &buf);
    }
    return ans;
}


Buffer initBuf(size_t bufsize, size_t blksize) {
    Buffer buffer;
    if (!initBuffer(bufsize, blksize, &buffer)) {
        perror("Buffer Initialization Failed!\n");
    }
    return buffer;
}

bool issaved(int value, unsigned char* blks) {
    for(int i = 0; i < 7; i++) {
        int ans = *(blks+i*8+0);
        if(ans == 0)
            return false;
        else if(ans == value)
            return true;
    }
    return false;
}

int projection(int start) {
    int ans = BLKNUM;
    int i = 0;
    unsigned char *blks[6];
    for(int k = 0; k < 6; k++) {
        blks[k] = getNewBlockInBuffer(&buf);;
        for(int j = 0; j < 64; j++)
            *(blks[k]+j) = 0;
    }
    int addr = start;
    while(addr != 0) {
        blk = readBlockFromDisk(addr, &buf);
        for(int j = 0; j < group_in_blk; j++) {
            int a = *(blk+j*8+0);
            bool flag = false;
            for(int k = 0; k < 6; k++) {
                if(issaved(a, blks[k]))
                    flag = true;
            }
            if(!flag) {
                int ii = i%7;
                int jj = i/7;
                *(blks[jj]+ii*8+0) = a;
                i++;
            }
        }
        addr = *(blk+BLKSIZE-4);
        freeBlockInBuffer(blk, &buf);
    }
    int jj = i/7;
    for(int k = 0; k <= jj; k++) {
        if(k == jj)
            *(blks[k]+BLKSIZE-4) = 0;
        else
            *(blks[k]+BLKSIZE-4) = BLKNUM+1;
        writeBlockToDisk(blks[k],BLKNUM,&buf);
        BLKNUM++;
    }
    for(int k = jj+1; k < 6; k++) {
        freeBlockInBuffer(blks[k], &buf);
    }
    return ans;
}

int join(int r, int s) {
    int addr_r = r, addr_s = s;
    int ret = BLKNUM;
    unsigned char * blkr, *blks;
    while(addr_r != 0) {
        blkr = readBlockFromDisk(addr_r, &buf);
        for(int ii = 0; ii < 7; ii++) {
            int a = *(blkr+ii*8+0);
            addr_s = s;
            while(addr_s != 0) {
                blks = readBlockFromDisk(addr_s, &buf);
                blk = getNewBlockInBuffer(&buf);
                for(int jj = 0; jj < 7; jj++) {
                    int c = *(blks+jj*8+0);
                    *(blk+jj*8+0) = a;
                    *(blk+jj*8+4) = c;
                }
                addr_s = *(blks+BLKSIZE-4);
                //printf(" addr = %d\n", addr_s);
                *(blk+BLKSIZE-4) = BLKNUM+1;
                writeBlockToDisk(blk,BLKNUM,&buf);
                BLKNUM++;
                freeBlockInBuffer(blks, &buf);
            }
        }
        addr_r = *(blkr+BLKSIZE-4);

        freeBlockInBuffer(blkr,&buf);
    }
    blk = readBlockFromDisk(BLKNUM-1, &buf);
    *(blk+BLKSIZE-4) = 0;
    writeBlockToDisk(blk, BLKNUM-1,&buf);
    return ret;
}


int main() {
    srand((unsigned) time(NULL));

    buf = initBuf(BUFSIZE, BLKSIZE);

    initData();

    //输出R的内容
    //printData(R_START);
    //输出S的内容
    //printData(S_START);

    //找到R.A = 40
    int addr_find_R_A = findfirst(R_START, 40);
    printData(addr_find_R_A);

    //找到S.C = 60
    int addr_find_S_C = findfirst(S_START, 60);
    printData(addr_find_S_C);


    //R.A投影
    int projection_R_A = projection(R_START);
    printData(projection_R_A);
    printf("NUM = %d\n", BLKNUM);
    //R.A连接S.C
    int r_join_s = join(R_START, S_START);
    //printData(r_join_s);

    //printf("%d\n", BLKNUM);
    return 0;
}
