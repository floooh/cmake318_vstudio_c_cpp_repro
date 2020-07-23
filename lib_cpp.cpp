#include "lib_cpp.h"
#include <stdio.h>

namespace bla {

class bla_t {
public:
    static void call_me();
};

void bla_t::call_me() {
    printf("cpp lib called\n");
}

} // namespace bla

void call_me(void) {
    bla::bla_t::call_me();
}