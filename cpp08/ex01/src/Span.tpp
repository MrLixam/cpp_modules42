#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template<typename T>
void Span::fillSpan(const typename T::iterator start, const typename T::iterator end)
{
	for (typename T::iterator temp = start; temp != end; temp++)
		this->addNumber(*temp);
}

#endif