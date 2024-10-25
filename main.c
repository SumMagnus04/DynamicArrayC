#include <stdio.h>
#include <stdlib.h>

#include "dynamicarray.h"

typedef struct Vector
{
	float x;
	float y;
} Vector;

int main()
{
	DynamicArray arr;
	dynamicInit(arr, 10, int); // Always initialize the array before use.

	printf("%d\n\n", ((int*)arr.data)[0]); // Note: the data is cast to an int* before use.

	dynamicAdd(arr, 20, int);
	for (unsigned int i = 0; i < arr.size; i++)
		printf("%d\n", ((int*)arr.data)[i]);

	printf("\n");
	dynamicRemove(arr, 0, int);
	printf("%d\n\n", ((int*)arr.data)[0]);

	DynamicArray vecs;
	Vector a;
	a.x = 0.0f;
	a.y = 0.0f;
	dynamicInit(vecs, a, Vector); // Same as above but with a custom Vector struct.
	Vector b;
	b.x = 1.0f;
	b.y = 1.0f;
	dynamicAdd(vecs, b, Vector);
	for (unsigned int i = 0; i < vecs.size; i++)
		printf("x: %f, y: %f\n",
			((Vector*)vecs.data)[i].x, // The data must still be cast to Vector*.
			((Vector*)vecs.data)[i].y
		);
	printf("\n");
	dynamicRemove(vecs, 0, Vector);
	for (unsigned int i = 0; i < vecs.size; i++)
		printf("x: %f, y: %f\n",
			((Vector*)vecs.data)[i].x,
			((Vector*)vecs.data)[i].y
		);

	free(arr.data); // Remember to free the data.
	free(vecs.data);

	return 0;
}
