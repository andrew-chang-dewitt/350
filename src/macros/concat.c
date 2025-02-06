#ifndef CONCAT
#define _concat_impl(x, y) x##y

#define CONCAT(x, y) _concat_impl(x, y)
#endif
