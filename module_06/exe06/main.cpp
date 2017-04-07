#include <iostream>
#include "../exe02/printtype.h"

int global = 10;

int getVal() { return global; }
int& getRef() { return global; }

auto getValWrap() -> decltype(getVal())
{
	return getVal();
}

auto getRefWrap() -> decltype(getRef())
{
	return getRef();
}

int main(){

}
