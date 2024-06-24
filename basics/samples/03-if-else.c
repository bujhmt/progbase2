#include <stdio.h>
#include <stdbool.h>

int main() {
    bool isNight = false;
    bool isMorning = false;

    if (isNight) {
        printf("Йдем спати\n");
    } else if (isMorning) {
        printf("Йдем на роботу\n");
    } else {
      printf("Йдем з роботи\n");
    }

    return 0;
}
