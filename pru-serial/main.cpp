#include <iostream>
#include <sys/mman.h>
#include <stdint.h>

#include <prussdrv.h>
#include <pruss_intc_mapping.h>

#define PRU_NUM 1

uint8_t *getAddr();

int main () {
    /* Initialize structure used by prussdrv_pruintc_intc   */
    /* PRUSS_INTC_INITDATA is found in pruss_intc_mapping.h */
    tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;

    /* Allocate and initialize memory */
    prussdrv_init ();
    prussdrv_open(PRU_EVTOUT_1);
    /* Map PRU's INTC */
    prussdrv_pruintc_init(&pruss_intc_initdata);

    // Get address and flush part of memory
    uint8_t *pruData = getAddr();
    pruData[0] = 0;
    pruData[1] = 0;

    /* Load and execute binary on PRU */
    prussdrv_exec_program(PRU_NUM, "./prucode.bin");

    while (true) {
        prussdrv_pru_wait_event(PRU_EVTOUT_1);
        prussdrv_pru_clear_event(PRU_EVTOUT_1, PRU1_ARM_INTERRUPT);
        prussdrv_pru_wait_event(PRU_EVTOUT_1);
        prussdrv_pru_clear_event(PRU_EVTOUT_1, PRU1_ARM_INTERRUPT);

        for (int i = 3; i >= 0; i--) {
            std::cout << (int)pruData[i] << ' ';
        }
        std::cout << '\n';
    }

    /* Disable PRU and close memory mappings */
    prussdrv_pru_disable(PRU_NUM);
    prussdrv_exit ();

    return 0;
}

uint8_t *getAddr() {
    void *addr;
    prussdrv_map_prumem(PRUSS0_PRU1_DATARAM, &addr);
    return (uint8_t *)addr;
}
