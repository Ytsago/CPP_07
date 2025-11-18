
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& firstVal, T& secondVal) {T temp = firstVal; firstVal = secondVal; secondVal = temp;}
template <typename T>
T&		min(T& firstVal, T& secondVal) {return (firstVal > secondVal) ? secondVal : firstVal;}
template <typename T>
T&		max(T& firstVal, T& secondVal) {return (firstVal < secondVal) ? secondVal : firstVal;}

#endif
