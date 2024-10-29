#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdlib.h>
#include <stdio.h>

typedef struct DynamicArray
{
	void* data; // You must always cast the data to the correct pointer type before use.
	unsigned int size; // This is the actual number of elements.
	unsigned int length; // This just keeps track of how much memory is in use.
} DynamicArray;

// Yes, these are macros. Welcome to generic typing in C
#define dynamicInit(arr, first, type) \
	do { \
		arr.size = 1; \
		arr.length = 10; \
		arr.data = (type*)malloc(arr.length * sizeof(type)); \
		if (arr.data == NULL) { \
			printf("Fatal Error\n"); \
			return; \
		} \
		((type*)arr.data)[arr.size - 1] = first; \
	} while (0)

#define dynamicAdd(arr, add, type) \
	do { \
		arr.size++; \
		if (arr.size > arr.length) { \
			arr.length *= 2; \
			void* a = (type*)malloc(arr.length * sizeof(type)); \
			if (a == NULL) { \
				printf("Fatal Error\n"); \
				return; \
			} \
			for (unsigned int i = 0; i < arr.size; i++) \
				((type*)a)[i] = ((type*)arr.data)[i]; \
			free(arr.data); \
			arr.data = a; \
		} \
		((type*)arr.data)[arr.size - 1] = add; \
	} while (0)

#define dynamicRemove(arr, index, type) \
	do { \
		if (index < 0 || index >= arr.size) return; \
		arr.size--; \
		if (index == arr.size) return; \
		for (unsigned int i = index; i < arr.size; i++) \
			((type*)arr.data)[i] = ((type*)arr.data)[i + 1]; \
	} while (0)

#endif
