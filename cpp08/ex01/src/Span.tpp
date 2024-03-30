#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

template<typename T>
void Span::fillSpan(const typename T::const_iterator start, const typename T::const_iterator end)
{
	for (typename T::const_iterator temp = start; temp != end; temp++)
		this->addNumber(*temp);
}

#endif