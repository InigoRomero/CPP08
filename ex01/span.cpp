# include "Span.hpp"

Span::Span()
:
_length(0),
_numbers(0)
{}

Span::Span(unsigned int n)
:
_length(n),
_numbers(std::vector<int>())
{}

Span::Span(Span const &copy)
:
	_length(copy._length)
{
	this->_numbers.clear();
	this->_numbers = copy._numbers;
}

Span::~Span(){}

Span &Span::operator=(const Span& op)
{
    this->_length = op._length;
    this->_numbers = op._numbers;
    return (*this);
}

void Span::addNumber(int n)
{
    if (this->_numbers.size() < this->_length)
        this->_numbers.push_back(n);
    else
        throw VectorIsFull();
}

size_t Span::shortestSpan()
{
    size_t size = this->_numbers.size();
	if (size <= 1)
		throw Span::ShortSpanException();
    std::sort(this->_numbers.begin(), this->_numbers.end());
    size_t x = (size_t)this->_numbers[1] - (size_t)this->_numbers[0];
    for (size_t n = 0; n < size; n++)
        if (x > ((size_t)this->_numbers[n + 1] - (size_t)this->_numbers[n]))
            x = (size_t)this->_numbers[n + 1] - (size_t)this->_numbers[n];
    return (x);
}

long Span::longestSpan()
{
    long x;
    std::vector<int>::iterator min;
	std::vector<int>::iterator max;
    size_t size = this->_numbers.size();

	if (size <= 1)
		throw Span::LongSpanException();
	min = std::min_element(this->_numbers.begin(), this->_numbers.end());
	max = std::max_element(this->_numbers.begin(), this->_numbers.end());
	x = (long)(*min) - (long)(*max);
    x = x < 0 ? (x * -1) : x;
    return (x);
}


//exceptions
const char* Span::VectorIsFull::what() const throw()
{
	return "Exception: Vector is FULL";
}

const char* Span::ShortSpanException::what() const throw()
{
    return "Exception: ShortSpanException";
}

const char* Span::LongSpanException::what() const throw()
{
    return "Exception: LongSpanException";
}
