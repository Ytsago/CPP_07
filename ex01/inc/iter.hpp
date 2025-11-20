#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename F>
void	iter(T* ptr, const unsigned long long length, F f ) {
	if (!f || !ptr)
		return ;
	for (unsigned long long i = 0; i < length; i++) {
		f(ptr[i]);
	}
}

#endif
