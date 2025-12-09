/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:48:10 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/12/04 23:21:47 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxsize(0)
{}

Span::Span(unsigned int N) : _maxsize(N)
{}

Span::Span(const Span& obj) : _maxsize(obj._maxsize), _numbers(obj._numbers)
{}

Span& Span::operator=(const Span& obj)
{
	if (this != &obj)
	{
		_maxsize = obj._maxsize;
		_numbers = obj._numbers;
	}
	return *this;
}

Span::~Span()
{}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxsize)
		throw SpanFullException();
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
	{
		throw NoSpanException();
	}

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for(size_t i = 1; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < minSpan)
		{
			minSpan = diff;
		}
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
	{
		throw NoSpanException();
	}

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	int res = max - min;

	return res;
}

const char* Span::SpanFullException::what() const throw()
{
	return "Span is full, cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw()
{
	return "Not enough numbers to calculate span";
}
