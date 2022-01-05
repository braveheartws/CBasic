//
// Created by admin on 2021/10/28.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "util.h"
typedef struct {
    char name[20];
    int age;
} Person;

struct Student {
    char name[20];
    int age;
};

typedef struct Buffer{
    char *order[255];
}Buf;


int standard_to_stamp(char *str_time)
{
    struct tm stm;
    int iY, iM, iD, iH, iMin, iS;

    memset(&stm,0,sizeof(stm));
    iY = atoi(str_time);
    iM = atoi(str_time+5);
    iD = atoi(str_time+8);
    iH = atoi(str_time+11);
    iMin = atoi(str_time+14);
    iS = atoi(str_time+17);

    stm.tm_year=iY-1900;
    stm.tm_mon=iM-1;
    stm.tm_mday=iD;
    stm.tm_hour=iH;
    stm.tm_min=iMin;
    stm.tm_sec=iS;

    printf("%d-%0d-%0d %0d:%0d:%0d\n", iY, iM, iD, iH, iMin, iS);   //标准时间格式例如：2016:08:02 12:12:30
    return (int)mktime(&stm);
}

int main(int argc, char *argv[]) {
    //Hello();
    char *tszTmp = malloc(sizeof(char ) * 50);
    memset(tszTmp, 0, 50);
    time_t  ss = time(NULL) - 60*60*24;
    struct tm *t = localtime(&ss);
    sprintf_s(tszTmp, 50 ,("%d-%02d-%02d %02d:%02d:%02d"), 1900 + t->tm_year, 1 + t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    printf("格式化后的时间:%s", tszTmp);

    char *format = malloc(sizeof(char ) * 50);
    memset(format, 0, 50);
    sprintf_s(format, 50,"%d-%02d-%02d 00:00:00",1900 + t->tm_year, 1 + t->tm_mon, t->tm_mday);
    printf("times: %llu\n", standard_to_stamp(format));
    return 0;
}

void xxx() {

    Buf buf;
    buf.order[0] = "AAAAA";
    buf.order[0] = "bbbb";
    buf.order[0] = "ccc";

    printf("%s\n",buf.order[0]);
    printf("%s\n",buf.order[0]);
    printf("%s\n",buf.order[0]);
    /*printf("%s\n",buf.order[1]);
    printf("%s\n",buf.order[2]);

    printf("%s\n",*(buf.order + 0));
    printf("%s\n",*(buf.order + 1));
    printf("%s\n",*(buf.order + 2));*/

    Person p;
    p.age = 50;
    strcpy(p.name, "bravewinters");
    printf("p -> size: %llu  Person size: %llu\n", sizeof(p), sizeof(Person));

    char *shmem = malloc(sizeof(char) * 50);
    memcpy(shmem,&p, sizeof(Person));
    printf("shmem size: %llu \n", sizeof(shmem));

    int arr[5];
    printf("arr size: %llu \n", sizeof(arr));

    struct Student *stu = (struct Student*) shmem;
    Person *p_person  = (Person*) shmem;
    printf("p name: %s, age: %d\n",p.name,p.age);
    printf("student name: %s, age: %d\n",stu->name,stu->age);
    printf("pppppp name: %s, age: %d\n",p_person->name,p_person->age);


}