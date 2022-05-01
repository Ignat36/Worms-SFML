#include "Layout.h"

int ** Layout::getLayoutInIntArray()
{
	return LayoutDescription;
}

Layout * Layout::getNextLayout()
{
	Layout *result = next;
	next = nullptr;
	return result;
}

Layout::Layout()
{
	next = nullptr;
}
