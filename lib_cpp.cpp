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
