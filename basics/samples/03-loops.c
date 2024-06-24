#include <stdio.h>
#include <stdbool.h>

int main() {
    bool cherry[5] = {false, false, false, false, true};

    for (int i = 0; i < 5; i++) {
        if (cherry[i] == true) {
            printf("%d - червива!", i + 1);
        }
    }
}
