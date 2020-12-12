#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <iterator>
# include <vector>
# include <algorithm>

class Span;

class Span
{
    private:
        Span();
        unsigned int _length;
        std::vector<int> _numbers;
    public:
        Span(unsigned int n);
        Span(const Span& copy);
        virtual ~Span();

        //exceptions
        class ShortSpanException: public std::exception {
            virtual const char* what() const throw();
        };
        class LongSpanException: public std::exception {
            virtual const char* what() const throw();
        };
        class VectorIsFull: public std::exception {
            virtual const char* what() const throw();
        };

        Span &operator=(Span const &op);
        void addNumber(int n);
        template < class Iterator >
        void        addNumber(Iterator begin, Iterator end)
        {
            if (this->_numbers.size() + std::distance(begin, end) > this->_length)
                throw(VectorIsFull());
            else
                std::copy(begin, end, std::back_inserter(this->_numbers));
            std::sort(this->_numbers.begin(), this->_numbers.end());
        }
        size_t shortestSpan();
        long longestSpan();
};

#endif