#include "Singleton.h"

Singleton* Singleton::singleton_ = nullptr;;

Singleton *Singleton::GetInstance()
{
	if (singleton_ == nullptr) {
		singleton_ = new Singleton();
	}
	return singleton_;
}
