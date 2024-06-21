#include "range.h"

double range(int y1, int y2, int x1, int x2) {
	return sqrt(pow((y1 - y2), 2) + pow((x1 - x2), 2));
}