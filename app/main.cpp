#define DOCTEST_CONFIG_IMPLEMENT

#include <doctest/doctest.h>
#include "../lib/dft.h"
#include "../lib/cooleyTukey.h"
#include "../lib/radixFour.h"

int main(int argc, char **argv) {
    doctest::Context context;
    context.applyCommandLine(argc, argv);

    int res = context.run();





    if (context.shouldExit()) {
        return res;
    }
}
