/*
 * apAllocator.h
 *
 *  Created on: Dec 15, 2014
 *      Author: asishbiswas
 */

#ifndef INC_APALLOCATOR_H_
#define INC_APALLOCATOR_H_

#include "apAllocatorBase.h"

template<typename T>
class apAllocator_ : public apAllocatorBase_<T>
{
public:
	explicit apAllocator_(unsigned int n, unsigned int align = 0) : apAllocatorBase_<T> (n, align)
	{
		allocate();
		addRef();
	}

	virtual ~apAllocator_()
	{
		deallocate();
	}

private:
	// Allocate our memory for size_ elements of type T with the alignment specified by align_.
	virtual void allocate ();
	virtual void deallocate ();

	// Disallow copy-constructor and assignment operator
	apAllocator_ (const apAllocator_& src);
	apAllocator_& operator= (const apAllocator_& src);
	
};

#endif /* INC_APALLOCATOR_H_ */
