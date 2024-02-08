#ifndef UTILS_H
#define UTILS_H

typedef struct string {
    char* ptr;
    int size;
} string;

string to_string(int val);

#endif