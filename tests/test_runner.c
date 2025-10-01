#include <stdio.h>

// Declare test functions
void test_linked_list(void);
void test_state_machine(void);
void test_led_controller(void);

int main(void) {
    printf("=== Running Unit Tests ===\n\n");

    test_linked_list();
    test_state_machine();
    test_led_controller();

    printf("=== All tests completed ===\n");
    return 0;
}
