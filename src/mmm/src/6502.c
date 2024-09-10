#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "6502.h"

// Helper functions
void    add_value_to_accumulator(MACHINE *m, uint8_t value);
void    compare_bytes(MACHINE *m, uint8_t lhs, uint8_t rhs);
uint8_t pull(MACHINE *m);
void    push(MACHINE *m, uint8_t value);
uint8_t read_from_memory(MACHINE *m, uint16_t address);
void    write_to_memory(MACHINE *m, uint16_t address, uint8_t value);
void    set_register_to_value(MACHINE *m, uint8_t *reg, uint8_t value);
void    subtract_value_from_accumulator(MACHINE *m, uint8_t value);

// Stage instructions
void    ah_from_stack(MACHINE *m);
void    ah_read_a16_sl2al(MACHINE *m);
void    ah_read_pc(MACHINE *m);
void    al_from_stack(MACHINE *m);
void    al_read_pc(MACHINE *m);
void    branch(MACHINE *m);
void    brk_pc(MACHINE *m);
void    empty_cycle(MACHINE *m);
void    p_from_stack(MACHINE *m);
void    p_to_stack(MACHINE *m);
void    oc_read_pc(MACHINE *m);
void    pc_hi_to_stack(MACHINE *m);
void    pc_lo_to_stack(MACHINE *m);
void    read_a16_ind_x(MACHINE *m);
void    read_a16_ind_y(MACHINE *m);
void    read_pc(MACHINE *m);
void    read_sp(MACHINE *m);
void    sl_read_a16(MACHINE *m);
void    sl_read_xpf_a16(MACHINE *m);
void    sl_read_ypf_a16(MACHINE *m);
void    sl_read_x_a16(MACHINE *m);
void    sl_write_a16(MACHINE *m);

// 6502 Instructions
void    adc_a16(MACHINE *m);    /* 65 */
// void adc_a16_x(MACHINE *m);  /* 75 */ same as adc_a16
// void adc_abs(MACHINE *m);    /* 6D */ same as adc_a16
void    adc_abs_x(MACHINE *m);  /* 7D */
void    adc_abs_y(MACHINE *m);  /* 79 */
void    adc_imm(MACHINE *m);    /* 69 */
// void adc_ind_x(MACHINE *m);  /* 61 */ same as adc_a16
//void adc_ind_y(MACHINE *m);   /* 71 */ same as adc_abs_y

void    and_imm(MACHINE *m);    /* 29 */
void    and_a16(MACHINE *m);    /* 25 */
// void and_a16_x(MACHINE *m);  /* 35 */ same as and_a16
void    and_abs(MACHINE *m);    /* 2D */
void    and_abs_x(MACHINE *m);  /* 3D */
void    and_abs_y(MACHINE *m);  /* 39 */
void    and_ind_x(MACHINE *m);  /* 21 */
// void and_ind_y(MACHINE *m);  /* 31 */ same as and_abs_y

void    asl_a(MACHINE *m);      /* 0A */
void    asl_a16(MACHINE *m);    /* 06 */
// void asl_a16_x(MACHINE *m);  /* 16 */ same as asl_a16
// void asl_abs(MACHINE *m);    /* 0E */ same as asl_a16
// void asl_abs_x(MACHINE *m);  /* 1E */ same as asl_a16

void    bcc(MACHINE *m);        /* 90 */
void    bcs(MACHINE *m);        /* B0 */
void    beq(MACHINE *m);        /* F0 */
void    bit_a16(MACHINE *m);    /* 24 */
// void bit_abs(MACHINE *m);    /* 2C */ same as bit_a16
void    bmi(MACHINE *m);        /* 30 */
void    bne(MACHINE *m);        /* D0 */
void    bpl(MACHINE *m);        /* 10 */
void    brk(MACHINE *m);        /* 00 */
void    bvc(MACHINE *m);        /* 50 */
void    bvs(MACHINE *m);        /* 70 */

void    clc(MACHINE *m);        /* 18 */
void    cld(MACHINE *m);        /* D8 */
void    cli(MACHINE *m);        /* 58 */
void    clv(MACHINE *m);        /* B8 */

void    cmp_imm(MACHINE *m);    /* C9 */
void    cmp_a16(MACHINE *m);    /* C5 */
// void cmp_a16_x(MACHINE *m);  /* D5 */ same as cmp_a16
// void cmp_abs(MACHINE *m);    /* CD */ same as cmp_a16
void    cmp_abs_x(MACHINE *m);  /* DD */
void    cmp_abs_y(MACHINE *m);  /* D9 */
// void cmp_ind_x(MACHINE *m);  /* C1 */ same as cmp_a16
// void cmp_ind_y(MACHINE *m);  /* D1 */ same as cmp_abs_y

void    cpx_imm(MACHINE *m);    /* E0 */
void    cpx_a16(MACHINE *m);    /* E4 */
// void cpx_abs(MACHINE *m);    /* EC */ same as cpx_a16

void    cpy_imm(MACHINE *m);    /* C0 */
void    cpy_a16(MACHINE *m);    /* C4 */
// void cpy_abs(MACHINE *m);    /* CC */ same as cpy_a16

void    dec_a16(MACHINE *m);    /* C6 */
// void dec_a16_x(MACHINE *m);  /* D6 */ same as dec_a16
// void dec_abs(MACHINE *m);    /* CE */ same as dec_a16
// void dec_abs_x(MACHINE *m);  /* DE */ same as dec_a16

void    dex(MACHINE *m);        /* CA */
void    dey(MACHINE *m);        /* 88 */

void    eor_imm(MACHINE *m);    /* 49 */
void    eor_a16(MACHINE *m);    /* 45 */
// void eor_a16_x(MACHINE *m);  /* 55 */ same as eor_a16
// void eor_abs(MACHINE *m);    /* 4D */ same as eor_a16
void    eor_abs_x(MACHINE *m);  /* 5D */
void    eor_abs_y(MACHINE *m);  /* 59 */
// void eor_ind_x(MACHINE *m);  /* 41 */ same as eor_a16
// void eor_ind_y(MACHINE *m);  /* 51 */ same as eor_abs_y

void    inc_a16(MACHINE *m);    /* E6 */
// void inc_a16_x(MACHINE *m);  /* F6 */ same as inc_a16
// void inc_abs(MACHINE *m);    /* EE */ same as inc_a16
// void inc_abs_x(MACHINE *m);  /* FE */ same as inc_a16

void    inx(MACHINE *m);        /* E8 */
void    iny(MACHINE *m);        /* C8 */

void    jmp_abs(MACHINE *m);    /* 4C */
void    jmp_ind(MACHINE *m);    /* 6C */
void    jsr_abs(MACHINE *m);    /* 20 */

void    lda_imm(MACHINE *m);    /* A9 */
void    lda_a16(MACHINE *m);    /* A5 */
// void lda_a16_x(MACHINE *m);  /* B5 */ same as lda_a16
// void lda_abs(MACHINE *m);    /* AD */ same as lda_a16
void    lda_abs_x(MACHINE *m);  /* BD */
void    lda_abs_y(MACHINE *m);  /* B9 */
// void lda_ind_x(MACHINE *m);  /* A1 */ same as lda_a16
// void lda_ind_y(MACHINE *m);  /* B1 */ same as lda_abs_y

void    ldx_imm(MACHINE *m);    /* A2 */
void    ldx_a16(MACHINE *m);    /* A6 */
// void ldx_a16_y(MACHINE *m);  /* B6 */ same as ldx_a16
// void ldx_abs(MACHINE *m);    /* AE */ same as ldx_a16
void    ldx_abs_y(MACHINE *m);  /* BE */

void    ldy_imm(MACHINE *m);    /* A0 */
void    ldy_a16(MACHINE *m);    /* A4 */
// void ldy_a16_x(MACHINE *m);  /* B4 */ same as ldy_a16
// void ldy_abs(MACHINE *m);    /* AC */ same as ldy_a16
void    ldy_abs_x(MACHINE *m);  /* BC */

void    lsr_a(MACHINE *m);      /* 4A */
void    lsr_a16(MACHINE *m);    /* 46 */
// void lsr_a16_x(MACHINE *m);  /* 56 */ same as lsr_a16
// void lsr_abs(MACHINE *m);    /* 4E */ same as lsr_a16
// void lsr_abs_x(MACHINE *m);  /* 5E */ same as lsr_a16

void    nop(MACHINE *m);        /* EA */

void    ora_imm(MACHINE *m);    /* 09 */
void    ora_a16(MACHINE *m);    /* 05 */
// void ora_a16_x(MACHINE *m);  /* 15 */ same as ora_a16
// void ora_abs(MACHINE *m);    /* 0D */ same as ora_a16
void    ora_abs_x(MACHINE *m);  /* 1D */
void    ora_abs_y(MACHINE *m);  /* 19 */
// void ora_ind_x(MACHINE *m);  /* 01 */ same as ora_a16
// void ora_ind_y(MACHINE *m);  /* 11 */ same as ora_abs_y

void    pha(MACHINE *m);        /* 48 */
void    php(MACHINE *m);        /* 08 */
void    pla(MACHINE *m);        /* 68 */
void    plp(MACHINE *m);        /* 28 */

void    rol_a(MACHINE *m);      /* 2A */
void    rol_a16(MACHINE *m);    /* 26 */
// void rol_a16_x(MACHINE *m);  /* 36 */ same as rol_a16
// void rol_abs(MACHINE *m);    /* 2E */ same as rol_a16
// void rol_abs_x(MACHINE *m);  /* 3E */ same as rol_a16

void    ror_a(MACHINE *m);      /* 6A */
void    ror_a16(MACHINE *m);    /* 66 */
// void ror_a16_x(MACHINE *m);  /* 76 */ same as ror_a16
// void ror_abs(MACHINE *m);    /* 6E */ same as ror_a16
// void ror_abs_x(MACHINE *m);  /* 7E */ same as ror_a16

void    rti(MACHINE *m);        /* 40 */
void    rts(MACHINE *m);        /* 60 */

void    sbc_imm(MACHINE *m);    /* E9 */
void    sbc_a16(MACHINE *m);    /* E5 */
// void sbc_a16_x(MACHINE *m);  /* F5 */ same as sbc_a16
// void sbc_abs(MACHINE *m);    /* ED */ same as sbc_a16
void    sbc_abs_x(MACHINE *m);  /* FD */
void    sbc_abs_y(MACHINE *m);  /* F9 */
// void sbc_ind_x(MACHINE *m);  /* E1 */ same as sbc_a16
// void sbc_ind_y(MACHINE *m);  /* F1 */ same as sbc_abs_y

void    sec(MACHINE *m);        /* 38 */
void    sed(MACHINE *m);        /* F8 */
void    sei(MACHINE *m);        /* 78 */

void    sta_a16(MACHINE *m);    /* 85 */
// void sta_a16_x(MACHINE *m);  /* 95 */ same as sta_a16
// void sta_abs(MACHINE *m);    /* 8D */ same as sta_a16
void    sta_abs_x(MACHINE *m);  /* 9D */
void    sta_abs_y(MACHINE *m);  /* 99 */
// void sta_ind_x(MACHINE *m);  /* 81 */ same as sta_a16
// void sta_ind_y(MACHINE *m);  /* 91 */ same as sta_abs_y

void    stx_a16(MACHINE *m);    /* 86 */
// void stx_a16_y(MACHINE *m);  /* 96 */ same as stx_a16
// void stx_abs(MACHINE *m);    /* 8E */ same as stx_a16

void    sty_a16(MACHINE *m);    /* 84 */
// void sty_a16_x(MACHINE *m);  /* 94 */ same as sty_a16
// void sty_abs(MACHINE *m);    /* 8C */ same as sty_a16

void    tax(MACHINE *m);        /* AA */
void    tay(MACHINE *m);        /* A8 */
void    tsx(MACHINE *m);        /* BA */
void    txa(MACHINE *m);        /* 8A */
void    txs(MACHINE *m);        /* 9A */
void    tya(MACHINE *m);        /* 98 */

// All cycle stages for all instructions
opcode_steps ADC_IMM[]   = {adc_imm};                               // 2
opcode_steps ADC_ZP[]    = {al_read_pc, adc_a16};                   // 3
opcode_steps ADC_ZP_X[]  = {al_read_pc, read_a16_ind_x, adc_a16};   // 4
opcode_steps ADC_ABS[]   = {al_read_pc, ah_read_pc, adc_a16};       // 4
opcode_steps ADC_ABS_X[] = {al_read_pc, ah_read_pc, adc_abs_x};     // 4*
opcode_steps ADC_ABS_Y[] = {al_read_pc, ah_read_pc, adc_abs_y};     // 4*
opcode_steps ADC_IND_X[] = {al_read_pc, read_a16_ind_x, sl_read_a16, ah_read_a16_sl2al, adc_a16}; // 6
opcode_steps ADC_IND_Y[] = {al_read_pc, sl_read_a16, ah_read_a16_sl2al, adc_abs_y}; // 5*

opcode_steps AND_IMM[]   = {and_imm};                               // 2
opcode_steps AND_ZP[]    = {al_read_pc, and_a16};                   // 3
opcode_steps AND_ZP_X[]  = {al_read_pc, read_a16_ind_x, and_a16};   // 4
opcode_steps AND_ABS[]   = {al_read_pc, ah_read_pc, and_abs};       // 4
opcode_steps AND_ABS_X[] = {al_read_pc, ah_read_pc, and_abs_x};     // 4*
opcode_steps AND_ABS_Y[] = {al_read_pc, ah_read_pc, and_abs_y};     // 4*
opcode_steps AND_IND_X[] = {al_read_pc, read_a16_ind_x, sl_read_a16, ah_read_a16_sl2al, and_ind_x}; // 6
opcode_steps AND_IND_Y[] = {al_read_pc, sl_read_a16, ah_read_a16_sl2al, and_abs_y}; // 5*

opcode_steps ASL_A[]     = {asl_a};                                 // 2
opcode_steps ASL_ZP[]    = {al_read_pc, sl_read_a16, sl_write_a16, asl_a16}; // 5
opcode_steps ASL_ZP_X[]  = {al_read_pc, read_a16_ind_x, sl_read_a16, sl_write_a16, asl_a16}; // 6
opcode_steps ASL_ABS[]   = {al_read_pc, ah_read_pc, sl_read_a16, sl_write_a16, asl_a16}; // 6
opcode_steps ASL_ABS_X[] = {al_read_pc, ah_read_pc, sl_read_xpf_a16, sl_read_x_a16, sl_write_a16, asl_a16}; // 7

opcode_steps BCC[]       = {bcc, branch};                           // 2**
opcode_steps BCS[]       = {bcs, branch};                           // 2**
opcode_steps BEQ[]       = {beq, branch};                           // 2**

opcode_steps BIT_ZP[]    = {al_read_pc, bit_a16};                   // 3
opcode_steps BIT_ABS[]   = {al_read_pc, ah_read_pc, bit_a16};       // 4

opcode_steps BMI[]       = {bmi, branch};                           // 2**
opcode_steps BNE[]       = {bne, branch};                           // 2**
opcode_steps BPL[]       = {bpl, branch};                           // 2**
opcode_steps BRK[]       = {al_read_pc, pc_hi_to_stack, pc_lo_to_stack, p_to_stack, brk_pc, brk}; // 7
opcode_steps BVC[]       = {bvc, branch};                           // 2**
opcode_steps BVS[]       = {bvs, branch};                           // 2**

opcode_steps CLC[]       = {clc};                                   // 2
opcode_steps CLD[]       = {cld};                                   // 2
opcode_steps CLI[]       = {cli};                                   // 2
opcode_steps CLV[]       = {clv};                                   // 2

opcode_steps CMP_IMM[]   = {cmp_imm};                               // 2
opcode_steps CMP_ZP[]    = {al_read_pc, cmp_a16};                   // 3
opcode_steps CMP_ZP_X[]  = {al_read_pc, read_a16_ind_x, cmp_a16};   // 4
opcode_steps CMP_ABS[]   = {al_read_pc, ah_read_pc, cmp_a16};       // 4
opcode_steps CMP_ABS_X[] = {al_read_pc, ah_read_pc, cmp_abs_x};     // 4*
opcode_steps CMP_ABS_Y[] = {al_read_pc, ah_read_pc, cmp_abs_y};     // 4*
opcode_steps CMP_IND_X[] = {al_read_pc, read_a16_ind_x, sl_read_a16, ah_read_a16_sl2al, cmp_a16}; // 6
opcode_steps CMP_IND_Y[] = {al_read_pc, sl_read_a16, ah_read_a16_sl2al, cmp_abs_y}; // 5*

opcode_steps CPX_IMM[]   = {cpx_imm};                               // 2
opcode_steps CPX_ZP[]    = {al_read_pc, cpx_a16};                   // 3
opcode_steps CPX_ABS[]   = {al_read_pc, ah_read_pc, cpx_a16};       // 4

opcode_steps CPY_IMM[]   = {cpy_imm};                               // 2
opcode_steps CPY_ZP[]    = {al_read_pc, cpy_a16};                   // 3
opcode_steps CPY_ABS[]   = {al_read_pc, ah_read_pc, cpy_a16};       // 4

opcode_steps DEC_ZP[]    = {al_read_pc, sl_read_a16, sl_write_a16, dec_a16}; // 5
opcode_steps DEC_ZP_X[]  = {al_read_pc, read_a16_ind_x, sl_read_a16, sl_write_a16, dec_a16}; // 6
opcode_steps DEC_ABS[]   = {al_read_pc, ah_read_pc, sl_read_a16, sl_write_a16, dec_a16}; // 6
opcode_steps DEC_ABS_X[] = {al_read_pc, ah_read_pc, sl_read_xpf_a16, sl_read_x_a16, sl_write_a16, dec_a16}; // 7

opcode_steps DEX[]       = {dex};                                   // 2
opcode_steps DEY[]       = {dey};                                   // 2

opcode_steps EOR_IMM[]   = {eor_imm};                               // 2
opcode_steps EOR_ZP[]    = {al_read_pc, eor_a16};                   // 3
opcode_steps EOR_ZP_X[]  = {al_read_pc, read_a16_ind_x, eor_a16};   // 4
opcode_steps EOR_ABS[]   = {al_read_pc, ah_read_pc, eor_a16};       // 4
opcode_steps EOR_ABS_X[] = {al_read_pc, ah_read_pc, eor_abs_x};     // 4*
opcode_steps EOR_ABS_Y[] = {al_read_pc, ah_read_pc, eor_abs_y};     // 4*
opcode_steps EOR_IND_X[] = {al_read_pc, read_a16_ind_x, sl_read_a16, ah_read_a16_sl2al, eor_a16}; // 6
opcode_steps EOR_IND_Y[] = {al_read_pc, sl_read_a16, ah_read_a16_sl2al, eor_abs_y}; // 5*

opcode_steps INC_ZP[]    = {al_read_pc, sl_read_a16, sl_write_a16, inc_a16}; // 5
opcode_steps INC_ZP_X[]  = {al_read_pc, read_a16_ind_x, sl_read_a16, sl_write_a16, inc_a16}; // 6
opcode_steps INC_ABS[]   = {al_read_pc, ah_read_pc, sl_read_a16, sl_write_a16, inc_a16}; // 6
opcode_steps INC_ABS_X[] = {al_read_pc, ah_read_pc, sl_read_xpf_a16, sl_read_x_a16, sl_write_a16, inc_a16}; // 7

opcode_steps INX[]       = {inx};                                   // 2
opcode_steps INY[]       = {iny};                                   // 2

opcode_steps JMP_ABS[]   = {al_read_pc, jmp_abs};                   // 3
opcode_steps JMP_IND[]   = {al_read_pc, ah_read_pc, sl_read_a16, jmp_ind}; // 5
opcode_steps JSR_ABS[]   = {al_read_pc, read_sp, pc_hi_to_stack, pc_lo_to_stack, jsr_abs}; // 6

opcode_steps LDA_IMM[]   = {lda_imm};                               // 2
opcode_steps LDA_ZP[]    = {al_read_pc, lda_a16};                   // 3
opcode_steps LDA_ZP_X[]  = {al_read_pc, read_a16_ind_x, lda_a16};   // 4
opcode_steps LDA_ABS[]   = {al_read_pc, ah_read_pc, lda_a16};       // 4
opcode_steps LDA_ABS_X[] = {al_read_pc, ah_read_pc, lda_abs_x};     // 4*
opcode_steps LDA_ABS_Y[] = {al_read_pc, ah_read_pc, lda_abs_y};     // 4*
opcode_steps LDA_IND_X[] = {al_read_pc, read_a16_ind_x, sl_read_a16, ah_read_a16_sl2al, lda_a16}; // 6
opcode_steps LDA_IND_Y[] = {al_read_pc, sl_read_a16, ah_read_a16_sl2al, lda_abs_y}; // 5*

opcode_steps LDX_IMM[]   = {ldx_imm};                               // 2
opcode_steps LDX_ZP[]    = {al_read_pc, ldx_a16};                   // 3
opcode_steps LDX_ZP_Y[]  = {al_read_pc, read_a16_ind_y, ldx_a16};   // 4
opcode_steps LDX_ABS[]   = {al_read_pc, ah_read_pc, ldx_a16};       // 4
opcode_steps LDX_ABS_Y[] = {al_read_pc, ah_read_pc, ldx_abs_y};     // 4*

opcode_steps LDY_IMM[]   = {ldy_imm};                               // 2
opcode_steps LDY_ZP[]    = {al_read_pc, ldy_a16};                   // 3
opcode_steps LDY_ZP_X[]  = {al_read_pc, read_a16_ind_x, ldy_a16};   // 4
opcode_steps LDY_ABS[]   = {al_read_pc, ah_read_pc, ldy_a16};       // 4
opcode_steps LDY_ABS_X[] = {al_read_pc, ah_read_pc, ldy_abs_x};     // 4*

opcode_steps LSR_A[]     = {lsr_a};                                 // 2
opcode_steps LSR_ZP[]    = {al_read_pc, sl_read_a16, sl_write_a16, lsr_a16}; // 5
opcode_steps LSR_ZP_X[]  = {al_read_pc, read_a16_ind_x, sl_read_a16, sl_write_a16, lsr_a16}; // 6
opcode_steps LSR_ABS[]   = {al_read_pc, ah_read_pc, sl_read_a16, sl_write_a16, lsr_a16}; // 6
opcode_steps LSR_ABS_X[] = {al_read_pc, ah_read_pc, sl_read_xpf_a16, sl_read_x_a16, sl_write_a16, lsr_a16}; // 7

opcode_steps NOP[]       = {nop};                                   // 2

opcode_steps ORA_IMM[]   = {ora_imm};                               // 2
opcode_steps ORA_ZP[]    = {al_read_pc, ora_a16};                   // 3
opcode_steps ORA_ZP_X[]  = {al_read_pc, read_a16_ind_x, ora_a16};   // 4
opcode_steps ORA_ABS[]   = {al_read_pc, ah_read_pc, ora_a16};       // 4
opcode_steps ORA_ABS_X[] = {al_read_pc, ah_read_pc, ora_abs_x};     // 4*
opcode_steps ORA_ABS_Y[] = {al_read_pc, ah_read_pc, ora_abs_y};     // 4*
opcode_steps ORA_IND_X[] = {al_read_pc, read_a16_ind_x, sl_read_a16, ah_read_a16_sl2al, ora_a16}; // 6
opcode_steps ORA_IND_Y[] = {al_read_pc, sl_read_a16, ah_read_a16_sl2al, ora_abs_y}; // 5*

opcode_steps PHA[]       = {read_pc, pha};                          // 3
opcode_steps PHP[]       = {read_pc, php};                          // 3
opcode_steps PLA[]       = {read_pc, read_sp, pla};                 // 4
opcode_steps PLP[]       = {read_pc, read_sp, plp};                 // 4

opcode_steps ROL_A[]     = {rol_a};                                 // 2
opcode_steps ROL_ZP[]    = {al_read_pc, sl_read_a16, sl_write_a16, rol_a16}; // 5
opcode_steps ROL_ZP_X[]  = {al_read_pc, read_a16_ind_x, sl_read_a16, sl_write_a16, rol_a16}; // 6
opcode_steps ROL_ABS[]   = {al_read_pc, ah_read_pc, sl_read_a16, sl_write_a16, rol_a16}; // 6
opcode_steps ROL_ABS_X[] = {al_read_pc, ah_read_pc, sl_read_xpf_a16, sl_read_x_a16, sl_write_a16, rol_a16}; // 7

opcode_steps ROR_A[]     = {ror_a};                                 // 2
opcode_steps ROR_ZP[]    = {al_read_pc, sl_read_a16, sl_write_a16, ror_a16}; // 5
opcode_steps ROR_ZP_X[]  = {al_read_pc, read_a16_ind_x, sl_read_a16, sl_write_a16, ror_a16}; // 6
opcode_steps ROR_ABS[]   = {al_read_pc, ah_read_pc, sl_read_a16, sl_write_a16, ror_a16}; // 6
opcode_steps ROR_ABS_X[] = {al_read_pc, ah_read_pc, sl_read_xpf_a16, sl_read_x_a16, sl_write_a16, ror_a16}; // 7

opcode_steps RTI[]       = {read_pc, read_sp, p_from_stack, al_from_stack, rti}; // 6
opcode_steps RTS[]       = {read_pc, read_sp, al_from_stack, ah_from_stack, rts}; // 6

opcode_steps SBC_IMM[]   = {sbc_imm};                               // 2
opcode_steps SBC_ZP[]    = {al_read_pc, sbc_a16};                   // 3
opcode_steps SBC_ZP_X[]  = {al_read_pc, read_a16_ind_x, sbc_a16};   // 4
opcode_steps SBC_ABS[]   = {al_read_pc, ah_read_pc, sbc_a16};       // 4
opcode_steps SBC_ABS_X[] = {al_read_pc, ah_read_pc, sbc_abs_x};     // 4*
opcode_steps SBC_ABS_Y[] = {al_read_pc, ah_read_pc, sbc_abs_y};     // 4*
opcode_steps SBC_IND_X[] = {al_read_pc, read_a16_ind_x, sl_read_a16, ah_read_a16_sl2al, sbc_a16}; // 6
opcode_steps SBC_IND_Y[] = {al_read_pc, sl_read_a16, ah_read_a16_sl2al, sbc_abs_y}; // 5*

opcode_steps SEC[]       = {sec};                                   // 2
opcode_steps SED[]       = {sed};                                   // 2
opcode_steps SEI[]       = {sei};                                   // 2

opcode_steps STA_ZP[]    = {al_read_pc, sta_a16};                   // 3
opcode_steps STA_ZP_X[]  = {al_read_pc, read_a16_ind_x, sta_a16};   // 4
opcode_steps STA_ABS[]   = {al_read_pc, ah_read_pc, sta_a16};       // 4
opcode_steps STA_ABS_X[] = {al_read_pc, ah_read_pc, sl_read_xpf_a16, sta_abs_x}; // 5
opcode_steps STA_ABS_Y[] = {al_read_pc, ah_read_pc, sl_read_ypf_a16, sta_abs_y}; // 5
opcode_steps STA_IND_X[] = {al_read_pc, read_a16_ind_x, sl_read_a16, ah_read_a16_sl2al, sta_a16}; // 6
opcode_steps STA_IND_Y[] = {al_read_pc, sl_read_a16, ah_read_a16_sl2al, sl_read_ypf_a16, sta_abs_y}; // 6

opcode_steps STX_ZP[]    = {al_read_pc, stx_a16};                   // 3
opcode_steps STX_ZP_Y[]  = {al_read_pc, read_a16_ind_y, stx_a16};   // 4
opcode_steps STX_ABS[]   = {al_read_pc, ah_read_pc, stx_a16};       // 4

opcode_steps STY_ZP[]    = {al_read_pc, sty_a16};                   // 3
opcode_steps STY_ZP_X[]  = {al_read_pc, read_a16_ind_x, sty_a16};   // 4
opcode_steps STY_ABS[]   = {al_read_pc, ah_read_pc, sty_a16};       // 4

opcode_steps TAX[]       = {tax};                                   // 2
opcode_steps TAY[]       = {tay};                                   // 2
opcode_steps TSX[]       = {tsx};                                   // 2
opcode_steps TXA[]       = {txa};                                   // 2
opcode_steps TXS[]       = {txs};                                   // 2
opcode_steps TYA[]       = {tya};                                   // 2

// All cycles not implemented refer to the UNDEFINED stage, which is just an empty cycle for now
opcode_steps UNDEFINED[] = {empty_cycle};

// The 256 opcodes, as their stage (cycle) function pointer arrays
opcode_steps *opcodes[256] = {
    [0x00] = BRK,
    [0x01] = ORA_IND_X,
    [0x02] = UNDEFINED,
    [0x03] = UNDEFINED,
    [0x04] = UNDEFINED,
    [0x05] = ORA_ZP,
    [0x06] = ASL_ZP,
    [0x07] = UNDEFINED,
    [0x08] = PHP,
    [0x09] = ORA_IMM,
    [0x0A] = ASL_A,
    [0x0B] = UNDEFINED,
    [0x0C] = UNDEFINED,
    [0x0D] = ORA_ABS,
    [0x0E] = ASL_ABS,
    [0x0F] = UNDEFINED,
    [0x10] = BPL,
    [0x11] = ORA_IND_Y,
    [0x12] = UNDEFINED,
    [0x13] = UNDEFINED,
    [0x14] = UNDEFINED,
    [0x15] = ORA_ZP_X,
    [0x16] = ASL_ZP_X,
    [0x17] = UNDEFINED,
    [0x18] = CLC,
    [0x19] = ORA_ABS_Y,
    [0x1A] = UNDEFINED,
    [0x1B] = UNDEFINED,
    [0x1C] = UNDEFINED,
    [0x1D] = ORA_ABS_X,
    [0x1E] = ASL_ABS_X,
    [0x1F] = UNDEFINED,
    [0x20] = JSR_ABS,
    [0x21] = AND_IND_X,
    [0x22] = UNDEFINED,
    [0x23] = UNDEFINED,
    [0x24] = BIT_ZP,
    [0x25] = AND_ZP,
    [0x26] = ROL_ZP,
    [0x27] = UNDEFINED,
    [0x28] = PLP,
    [0x29] = AND_IMM,
    [0x2A] = ROL_A,
    [0x2B] = UNDEFINED,
    [0x2C] = BIT_ABS,
    [0x2D] = AND_ABS,
    [0x2E] = ROL_ABS,
    [0x2F] = UNDEFINED,
    [0x30] = BMI,
    [0x31] = AND_IND_Y,
    [0x32] = UNDEFINED,
    [0x33] = UNDEFINED,
    [0x34] = UNDEFINED,
    [0x35] = AND_ZP_X,
    [0x36] = ROL_ZP_X,
    [0x37] = UNDEFINED,
    [0x38] = SEC,
    [0x39] = AND_ABS_Y,
    [0x3A] = UNDEFINED,
    [0x3B] = UNDEFINED,
    [0x3C] = UNDEFINED,
    [0x3D] = AND_ABS_X,
    [0x3E] = ROL_ABS_X,
    [0x3F] = UNDEFINED,
    [0x40] = RTI,
    [0x41] = EOR_IND_X,
    [0x42] = UNDEFINED,
    [0x43] = UNDEFINED,
    [0x44] = UNDEFINED,
    [0x45] = EOR_ZP,
    [0x46] = LSR_ZP,
    [0x47] = UNDEFINED,
    [0x48] = PHA,
    [0x49] = EOR_IMM,
    [0x4A] = LSR_A,
    [0x4B] = UNDEFINED,
    [0x4C] = JMP_ABS,
    [0x4D] = EOR_ABS,
    [0x4E] = LSR_ABS,
    [0x4F] = UNDEFINED,
    [0x50] = BVC,
    [0x51] = EOR_IND_Y,
    [0x52] = UNDEFINED,
    [0x53] = UNDEFINED,
    [0x54] = UNDEFINED,
    [0x55] = EOR_ZP_X,
    [0x56] = LSR_ZP_X,
    [0x57] = UNDEFINED,
    [0x58] = CLI,
    [0x59] = EOR_ABS_Y,
    [0x5A] = UNDEFINED,
    [0x5B] = UNDEFINED,
    [0x5C] = UNDEFINED,
    [0x5D] = EOR_ABS_X,
    [0x5E] = LSR_ABS_X,
    [0x5F] = UNDEFINED,
    [0x60] = RTS,
    [0x61] = ADC_IND_X,
    [0x62] = UNDEFINED,
    [0x63] = UNDEFINED,
    [0x64] = UNDEFINED,
    [0x65] = ADC_ZP,
    [0x66] = ROR_ZP,
    [0x67] = UNDEFINED,
    [0x68] = PLA,
    [0x69] = ADC_IMM,
    [0x6A] = ROR_A,
    [0x6B] = UNDEFINED,
    [0x6C] = JMP_IND,
    [0x6D] = ADC_ABS,
    [0x6E] = ROR_ABS,
    [0x6F] = UNDEFINED,
    [0x70] = BVS,
    [0x71] = ADC_IND_Y,
    [0x72] = UNDEFINED,
    [0x73] = UNDEFINED,
    [0x74] = UNDEFINED,
    [0x75] = ADC_ZP_X,
    [0x76] = ROR_ZP_X,
    [0x77] = UNDEFINED,
    [0x78] = SEI,
    [0x79] = ADC_ABS_Y,
    [0x7A] = UNDEFINED,
    [0x7B] = UNDEFINED,
    [0x7C] = UNDEFINED,
    [0x7D] = ADC_ABS_X,
    [0x7E] = ROR_ABS_X,
    [0x7F] = UNDEFINED,
    [0x80] = UNDEFINED,
    [0x81] = STA_IND_X,
    [0x82] = UNDEFINED,
    [0x83] = UNDEFINED,
    [0x84] = STY_ZP,
    [0x85] = STA_ZP,
    [0x86] = STX_ZP,
    [0x87] = UNDEFINED,
    [0x88] = DEY,
    [0x89] = UNDEFINED,
    [0x8A] = TXA,
    [0x8B] = UNDEFINED,
    [0x8C] = STY_ABS,
    [0x8D] = STA_ABS,
    [0x8E] = STX_ABS,
    [0x8F] = UNDEFINED,
    [0x90] = BCC,
    [0x91] = STA_IND_Y,
    [0x92] = UNDEFINED,
    [0x93] = UNDEFINED,
    [0x94] = STY_ZP_X,
    [0x95] = STA_ZP_X,
    [0x96] = STX_ZP_Y,
    [0x97] = UNDEFINED,
    [0x98] = TYA,
    [0x99] = STA_ABS_Y,
    [0x9A] = TXS,
    [0x9B] = UNDEFINED,
    [0x9C] = UNDEFINED,
    [0x9D] = STA_ABS_X,
    [0x9E] = UNDEFINED,
    [0x9F] = UNDEFINED,
    [0xA0] = LDY_IMM,
    [0xA1] = LDA_IND_X,
    [0xA2] = LDX_IMM,
    [0xA3] = UNDEFINED,
    [0xA4] = LDY_ZP,
    [0xA5] = LDA_ZP,
    [0xA6] = LDX_ZP,
    [0xA7] = UNDEFINED,
    [0xA8] = TAY,
    [0xA9] = LDA_IMM,
    [0xAA] = TAX,
    [0xAB] = UNDEFINED,
    [0xAC] = LDY_ABS,
    [0xAD] = LDA_ABS,
    [0xAE] = LDX_ABS,
    [0xAF] = UNDEFINED,
    [0xB0] = BCS,
    [0xB1] = LDA_IND_Y,
    [0xB2] = UNDEFINED,
    [0xB3] = UNDEFINED,
    [0xB4] = LDY_ZP_X,
    [0xB5] = LDA_ZP_X,
    [0xB6] = LDX_ZP_Y,
    [0xB7] = UNDEFINED,
    [0xB8] = CLV,
    [0xB9] = LDA_ABS_Y,
    [0xBA] = TSX,
    [0xBB] = UNDEFINED,
    [0xBC] = LDY_ABS_X,
    [0xBD] = LDA_ABS_X,
    [0xBE] = LDX_ABS_Y,
    [0xBF] = UNDEFINED,
    [0xC0] = CPY_IMM,
    [0xC1] = CMP_IND_X,
    [0xC2] = UNDEFINED,
    [0xC3] = UNDEFINED,
    [0xC4] = CPY_ZP,
    [0xC5] = CMP_ZP,
    [0xC6] = DEC_ZP,
    [0xC7] = UNDEFINED,
    [0xC8] = INY,
    [0xC9] = CMP_IMM,
    [0xCA] = DEX,
    [0xCB] = UNDEFINED,
    [0xCC] = CPY_ABS,
    [0xCD] = CMP_ABS,
    [0xCE] = DEC_ABS,
    [0xCF] = UNDEFINED,
    [0xD0] = BNE,
    [0xD1] = CMP_IND_Y,
    [0xD2] = UNDEFINED,
    [0xD3] = UNDEFINED,
    [0xD4] = UNDEFINED,
    [0xD5] = CMP_ZP_X,
    [0xD6] = DEC_ZP_X,
    [0xD7] = UNDEFINED,
    [0xD8] = CLD,
    [0xD9] = CMP_ABS_Y,
    [0xDA] = UNDEFINED,
    [0xDB] = UNDEFINED,
    [0xDC] = UNDEFINED,
    [0xDD] = CMP_ABS_X,
    [0xDE] = DEC_ABS_X,
    [0xDF] = UNDEFINED,
    [0xE0] = CPX_IMM,
    [0xE1] = SBC_IND_X,
    [0xE2] = UNDEFINED,
    [0xE3] = UNDEFINED,
    [0xE4] = CPX_ZP,
    [0xE5] = SBC_ZP,
    [0xE6] = INC_ZP,
    [0xE7] = UNDEFINED,
    [0xE8] = INX,
    [0xE9] = SBC_IMM,
    [0xEA] = NOP,
    [0xEB] = UNDEFINED,
    [0xEC] = CPX_ABS,
    [0xED] = SBC_ABS,
    [0xEE] = INC_ABS,
    [0xEF] = UNDEFINED,
    [0xF0] = BEQ,
    [0xF1] = SBC_IND_Y,
    [0xF2] = UNDEFINED,
    [0xF3] = UNDEFINED,
    [0xF4] = UNDEFINED,
    [0xF5] = SBC_ZP_X,
    [0xF6] = INC_ZP_X,
    [0xF7] = UNDEFINED,
    [0xF8] = SED,
    [0xF9] = SBC_ABS_Y,
    [0xFA] = UNDEFINED,
    [0xFB] = UNDEFINED,
    [0xFC] = UNDEFINED,
    [0xFD] = SBC_ABS_X,
    [0xFE] = INC_ABS_X,
    [0xFF] = UNDEFINED,
};

// Configure RAM
uint8_t ram_init(RAM *ram, uint16_t num_ram_banks) {
    int ram_bank;
    if(!(ram->ram_banks = (RAM_BANK*)malloc(sizeof(RAM_BANK) * num_ram_banks))) {
        return (ram->num_ram_banks = 0);
    }
    ram->num_ram_banks = num_ram_banks;
    for(ram_bank = 0; ram_bank < num_ram_banks; ram_bank++) {
        ram->ram_banks[ram_bank].address = 0;
        ram->ram_banks[ram_bank].length = 0;
        ram->ram_banks[ram_bank].memory = NULL;
    }
    return 1;
}

void ram_add(RAM *ram, uint8_t ram_bank_num, uint32_t address, uint32_t length, uint8_t *memory) {
    assert(ram_bank_num < ram->num_ram_banks);
    RAM_BANK *r = &ram->ram_banks[ram_bank_num];
    r->address = address;
    r->length = length;
    r->memory = memory;
}

// Configure ROMS
uint8_t roms_init(ROMS *roms, uint16_t num_roms) {
    int rom;
    if(!(roms->rom = (ROM*)malloc(sizeof(ROM) * num_roms))) {
        return (roms->num_roms = 0);
    }
    roms->num_roms = num_roms;
    for(rom = 0; rom < num_roms; rom++) {
        roms->rom[rom].address = 0;
        roms->rom[rom].length = 0;
        roms->rom[rom].memory = NULL;
    }
    return 1;
}

void rom_add(ROMS *roms, uint8_t rom_num, uint32_t address, uint32_t length, uint8_t *memory) {
    assert(rom_num < roms->num_roms);
    ROM *r = &roms->rom[rom_num];
    r->address = address;
    r->length = length;
    r->memory = memory;
}

// Configure PAGES
uint8_t pages_init(PAGES *pages, uint16_t num_pages) {
    int page;
    if(!(pages->pages = (PAGE*)malloc(sizeof(PAGE) * num_pages))) {
        return (pages->num_pages = 0);
    }
    pages->num_pages = num_pages;
    for(page = 0; page < num_pages; page++) {
        pages->pages[page].memory = NULL;
    }
    return 1;
}

void pages_map(PAGES *pages, uint32_t start_page, uint32_t num_pages, uint8_t *memory) {
    assert(start_page + num_pages <= pages->num_pages);
    while(num_pages) {
        pages->pages[start_page++].memory = memory;
        memory += PAGE_SIZE;
        num_pages--;
    }
}

// Init the 6502
void cpu_init(CPU *cpu) {
    cpu->pc = 0xfffc;
    cpu->sp = 0x100;
    cpu->A = cpu->X = cpu->Y = 0;
    cpu->flags = 0;
    cpu->page_fault = 0;
    cpu->instruction = 0x4C;                                        // JMP oper
    cpu->instruction_cycle = 0;
    cpu->cycles = 1;
    cpu->address_16 = cpu->scratch_16 = 0;
}

// Step the 6502 a single cycle
void machine_step(MACHINE *m) {
    if(m->cpu.instruction_cycle < 0) {
        oc_read_pc(m);
    } else {
        opcodes[m->cpu.instruction][m->cpu.instruction_cycle](m);
    }
    ++m->cpu.cycles;
}

// Helper Functions
void add_value_to_accumulator(MACHINE *m, uint8_t value) {
    uint8_t a = m->cpu.A;
    m->cpu.scratch_16 = m->cpu.A + value + m->cpu.C;
    set_register_to_value(m, &m->cpu.A, m->cpu.scratch_lo);
    m->cpu.scratch_lo = (a & 0x0F) + (value & 0x0F) + m->cpu.C;
    m->cpu.V = ((a ^ m->cpu.A) & ~(a ^ value) & 0x80) != 0 ? 1 : 0;
    m->cpu.C = m->cpu.scratch_hi;
    if(m->cpu.D) {
        m->cpu.scratch_hi = (a >> 4) + (value >> 4);
        if (m->cpu.scratch_lo > 9) {
            m->cpu.scratch_lo += 6;
            m->cpu.scratch_hi++;
        }
        if (m->cpu.scratch_hi > 9) {
            m->cpu.scratch_hi += 6;
            m->cpu.C = 1;
        }
        m->cpu.A = (m->cpu.scratch_hi << 4) | (m->cpu.scratch_lo & 0x0F);
    }
}

void compare_bytes(MACHINE *m, uint8_t lhs, uint8_t rhs) {
    m->cpu.Z = (lhs == rhs) ? 1 : 0;
    m->cpu.C = (lhs >= rhs) ? 1 : 0;
    m->cpu.N = ((lhs - rhs) & 0x80) ? 1 : 0;
}

uint8_t pull(MACHINE *m) {
    if(++m->cpu.sp >= 0x200) {
        m->cpu.sp = 0x100;
    }
    return read_from_memory(m, m->cpu.sp);
}

void push(MACHINE *m, uint8_t value) {
    write_to_memory(m, m->cpu.sp, value);
    if(--m->cpu.sp < 0x100) {
        m->cpu.sp += 0x100;
    }
}

uint8_t read_from_memory(MACHINE *m, uint16_t address) {
    assert(address / PAGE_SIZE < m->read_pages.num_pages);
    if(m->io_pages.pages[address / PAGE_SIZE].memory[address % PAGE_SIZE]) {
        return m->io_read(m, address);
    }
    return m->read_pages.pages[address / PAGE_SIZE].memory[address % PAGE_SIZE];
}

void set_register_to_value(MACHINE *m, uint8_t *reg, uint8_t value) {
    *reg = value;
    m->cpu.N = *reg & 0x80 ? 1 : 0;
    m->cpu.Z = *reg ? 0 : 1;
}

void write_to_memory(MACHINE *m, uint16_t address, uint8_t value) {
    uint16_t page = address / PAGE_SIZE;
    uint16_t offset = address % PAGE_SIZE;
    assert(page < m->write_pages.num_pages);
    if(m->io_pages.pages[page].memory[offset]) {
        m->io_write(m, address, value);
    } else {
        m->write_pages.pages[page].memory[offset] = value;
    }
}

// Stage instructions
void ah_from_stack(MACHINE *m) {
    m->cpu.address_hi = pull(m);
    m->cpu.instruction_cycle++;
}

void ah_read_a16_sl2al(MACHINE *m) {
    m->cpu.address_lo++;
    m->cpu.address_hi = read_from_memory(m, m->cpu.address_16);
    m->cpu.address_lo = m->cpu.scratch_lo;
    m->cpu.instruction_cycle++;
}

void ah_read_pc(MACHINE *m) {
    m->cpu.address_hi = read_from_memory(m, m->cpu.pc);
    m->cpu.pc++;
    m->cpu.instruction_cycle++;
}

void al_from_stack(MACHINE *m) {
    m->cpu.address_lo = pull(m);
    m->cpu.instruction_cycle++;
}

void al_read_pc(MACHINE *m) {
    m->cpu.address_lo = read_from_memory(m, m->cpu.pc);
    m->cpu.address_hi = 0;
    m->cpu.pc++;
    m->cpu.instruction_cycle++;
}

void branch(MACHINE *m) {
    read_from_memory(m, m->cpu.address_16);
    if(!m->cpu.page_fault && (m->cpu.address_lo + (int8_t)m->cpu.scratch_lo) & 0x100)
    {
        m->cpu.page_fault = 1;
        m->cpu.address_lo += m->cpu.scratch_lo;
    } else {
        m->cpu.pc += (int8_t)m->cpu.scratch_lo;
        m->cpu.page_fault = 0;
        m->cpu.instruction_cycle = -1;
    }
}

void brk_pc(MACHINE *m) {
    m->cpu.pc = 0xFFFE;
    al_read_pc(m);
}

int check_page_fault(MACHINE *m, uint8_t to_add) {
    if(!m->cpu.page_fault) {
        if(((m->cpu.address_16 + to_add) & 0xff00) != (m->cpu.address_16 & 0xff00)) {
            m->cpu.page_fault = 1;
        }
        m->cpu.address_lo += to_add;
    } else {
        m->cpu.address_hi++;
        m->cpu.page_fault = 0;
    }
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    return m->cpu.page_fault;
}

void empty_cycle(MACHINE *m) {
    m->cpu.instruction_cycle++;
}

void p_from_stack(MACHINE *m) {
    m->cpu.flags = (pull(m) & ~0b00010000) | 0b00100000;
    m->cpu.instruction_cycle++;
}

void p_to_stack(MACHINE *m) {
    push(m, m->cpu.flags | 0b00010000);
    m->cpu.instruction_cycle++;
}

void oc_read_pc(MACHINE *m) {
    m->cpu.instruction = read_from_memory(m, m->cpu.pc);
    m->cpu.pc++;
    m->cpu.instruction_cycle = 0;
}

void pc_hi_to_stack(MACHINE *m) {
    push(m, (m->cpu.pc >> 8) & 0xFF);
    m->cpu.instruction_cycle++;
}

void pc_lo_to_stack(MACHINE *m) {
    push(m, m->cpu.pc & 0xFF);
    m->cpu.instruction_cycle++;
}

void read_a16_ind_x(MACHINE *m) {
    read_from_memory(m, m->cpu.address_16);
    m->cpu.address_lo += m->cpu.X;
    m->cpu.instruction_cycle++;
}

void read_a16_ind_y(MACHINE *m) {
    read_from_memory(m, m->cpu.address_16);
    m->cpu.address_lo += m->cpu.Y;
    m->cpu.instruction_cycle++;
}

void read_pc(MACHINE *m) {
    read_from_memory(m, m->cpu.pc);
    m->cpu.instruction_cycle++;
}

void read_sp(MACHINE *m) {
    read_from_memory(m, m->cpu.sp);
    m->cpu.instruction_cycle++;
}

void sl_read_a16(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    m->cpu.instruction_cycle++;
}

void sl_read_xpf_a16(MACHINE *m) {
    if(m->cpu.address_lo + m->cpu.X >= 0x100) {
        m->cpu.page_fault = 1;
    }
    m->cpu.address_lo += m->cpu.X;
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    m->cpu.instruction_cycle++;
}

void sl_read_ypf_a16(MACHINE *m) {
    if(m->cpu.address_lo + m->cpu.Y >= 0x100) {
        m->cpu.page_fault = 1;
    }
    m->cpu.address_lo += m->cpu.Y;
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    m->cpu.instruction_cycle++;
}

void sl_read_x_a16(MACHINE *m) {
    m->cpu.address_hi += m->cpu.page_fault;
    m->cpu.page_fault = 0;
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    m->cpu.instruction_cycle++;
}

void sl_write_a16(MACHINE *m) {
    write_to_memory(m, m->cpu.address_16, m->cpu.scratch_lo);
    m->cpu.instruction_cycle++;
}

void subtract_value_from_accumulator(MACHINE *m, uint8_t value) {
    uint8_t a = m->cpu.A;
    m->cpu.C = 1 - m->cpu.C;
    m->cpu.scratch_16 = a - value - m->cpu.C;
    set_register_to_value(m, &m->cpu.A, m->cpu.scratch_lo);
    m->cpu.V = ((a ^ value) & (a ^ m->cpu.A) & 0x80) != 0 ? 1 : 0;
    if(m->cpu.D) {
        m->cpu.address_lo = (a & 0x0F) - (value & 0x0F) - m->cpu.C;
        m->cpu.address_hi = (a >> 4) - (value >> 4);
        if (m->cpu.address_lo & 0x10) {
            m->cpu.address_lo -= 6;
            m->cpu.address_hi--;
        }
        if (m->cpu.address_hi & 0xF0) {
            m->cpu.address_hi -= 6;
        }
        m->cpu.A = (m->cpu.address_hi << 4) | (m->cpu.address_lo & 0x0F);
    }
    m->cpu.C = m->cpu.scratch_16 < 0x100 ? 1 : 0;
}

// 6502 end of chain instructions - were the work happens and
// terminates with m->cpu.instruction_cycle = -1;
void adc_imm(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    add_value_to_accumulator(m, m->cpu.scratch_lo);
    m->cpu.pc++;
    m->cpu.instruction_cycle = -1;
}

void adc_a16(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    add_value_to_accumulator(m, m->cpu.scratch_lo);
    m->cpu.instruction_cycle = -1;
}

void adc_abs_x(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.X)) {
        add_value_to_accumulator(m, m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void adc_abs_y(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.Y)) {
        add_value_to_accumulator(m, m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void and_imm(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    set_register_to_value(m, &m->cpu.A, m->cpu.A & m->cpu.scratch_lo);
    m->cpu.pc++;
    m->cpu.instruction_cycle = -1;
}

void and_a16(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    set_register_to_value(m, &m->cpu.A, m->cpu.A & m->cpu.scratch_lo);
    m->cpu.instruction_cycle = -1;
}

void and_abs(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    set_register_to_value(m, &m->cpu.A, m->cpu.A & m->cpu.scratch_lo);
    m->cpu.instruction_cycle = -1;
}

void and_abs_x(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.X)) {
        set_register_to_value(m, &m->cpu.A, m->cpu.A & m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void and_abs_y(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.Y)) {
        set_register_to_value(m, &m->cpu.A, m->cpu.A & m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void and_ind_x(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    set_register_to_value(m, &m->cpu.A, m->cpu.A & m->cpu.scratch_lo);
    m->cpu.instruction_cycle = -1;
}

void asl_a(MACHINE *m) {
    read_from_memory(m, m->cpu.pc);
    m->cpu.C = m->cpu.A & 0x80 ? 1 : 0;
    set_register_to_value(m, &m->cpu.A, m->cpu.A <<= 1);
    m->cpu.instruction_cycle = -1;
}

void asl_a16(MACHINE *m) {
    m->cpu.C = m->cpu.scratch_lo & 0x80 ? 1 : 0;
    set_register_to_value(m, &m->cpu.scratch_hi, m->cpu.scratch_lo << 1);
    write_to_memory(m, m->cpu.address_16, m->cpu.scratch_hi);
    m->cpu.instruction_cycle = -1;
}

void bcc(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    m->cpu.address_16 = ++m->cpu.pc;
    if(!m->cpu.C) {
        m->cpu.instruction_cycle++;
    } else {
        m->cpu.instruction_cycle = -1;
    }
}

void bcs(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    m->cpu.address_16 = ++m->cpu.pc;
    if(m->cpu.C) {
        m->cpu.instruction_cycle++;
    } else {
        m->cpu.instruction_cycle = -1;
    }
}

void beq(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    m->cpu.address_16 = ++m->cpu.pc;
    if(m->cpu.Z) {
        m->cpu.instruction_cycle++;
    } else {
        m->cpu.instruction_cycle = -1;
    }
}

void bit_a16(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    set_register_to_value(m, &m->cpu.scratch_hi, m->cpu.A & m->cpu.scratch_lo);
    m->cpu.flags &= 0b00111111;
    m->cpu.flags |= (m->cpu.scratch_lo & 0b11000000);
    m->cpu.instruction_cycle = -1;
}

void bmi(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    m->cpu.address_16 = ++m->cpu.pc;
    if(m->cpu.N) {
        m->cpu.instruction_cycle++;
    } else {
        m->cpu.instruction_cycle = -1;
    }
}

void bne(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    m->cpu.address_16 = ++m->cpu.pc;
    if(!m->cpu.Z) {
        m->cpu.instruction_cycle++;
    } else {
        m->cpu.instruction_cycle = -1;
    }
}

void bpl(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    m->cpu.address_16 = ++m->cpu.pc;
    if(!m->cpu.N) {
        m->cpu.instruction_cycle++;
    } else {
        m->cpu.instruction_cycle = -1;
    }
}

void brk(MACHINE *m) {
    ah_read_pc(m);
    m->cpu.pc = m->cpu.address_16;
    // Interrupt flag on at break
    m->cpu.flags |= 0b00000100;
    m->cpu.instruction_cycle = -1;
}

void bvc(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    m->cpu.address_16 = ++m->cpu.pc;
    if(!m->cpu.V) {
        m->cpu.instruction_cycle++;
    } else {
        m->cpu.instruction_cycle = -1;
    }
}

void bvs(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    m->cpu.address_16 = ++m->cpu.pc;
    if(m->cpu.V) {
        m->cpu.instruction_cycle++;
    } else {
        m->cpu.instruction_cycle = -1;
    }
}

void clc(MACHINE *m) {
    read_from_memory(m, m->cpu.pc);
    m->cpu.C = 0;
    m->cpu.instruction_cycle = -1;
}

void cld(MACHINE *m) {
    read_from_memory(m, m->cpu.pc);
    m->cpu.D = 0;
    m->cpu.instruction_cycle = -1;
}

void cli(MACHINE *m) {
    read_from_memory(m, m->cpu.pc);
    m->cpu.I = 0;
    m->cpu.instruction_cycle = -1;
}

void clv(MACHINE *m) {
    read_from_memory(m, m->cpu.pc);
    m->cpu.V = 0;
    m->cpu.instruction_cycle = -1;
}

void cmp_imm(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    compare_bytes(m, m->cpu.A, m->cpu.scratch_lo);
    m->cpu.pc++;
    m->cpu.instruction_cycle = -1;
}

void cmp_a16(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    compare_bytes(m, m->cpu.A, m->cpu.scratch_lo);
    m->cpu.instruction_cycle = -1;
}

void cmp_abs_x(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.X)) {
        compare_bytes(m, m->cpu.A, m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void cmp_abs_y(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.Y)) {
        compare_bytes(m, m->cpu.A, m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void cpx_imm(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    compare_bytes(m, m->cpu.X, m->cpu.scratch_lo);
    m->cpu.pc++;
    m->cpu.instruction_cycle = -1;
}

void cpx_a16(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    compare_bytes(m, m->cpu.X, m->cpu.scratch_lo);
    m->cpu.instruction_cycle = -1;
}

void cpy_imm(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    compare_bytes(m, m->cpu.Y, m->cpu.scratch_lo);
    m->cpu.pc++;
    m->cpu.instruction_cycle = -1;
}

void cpy_a16(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    compare_bytes(m, m->cpu.Y, m->cpu.scratch_lo);
    m->cpu.instruction_cycle = -1;
}

void dec_a16(MACHINE *m) {
    set_register_to_value(m, &m->cpu.scratch_hi, m->cpu.scratch_lo - 1);
    write_to_memory(m, m->cpu.address_16, m->cpu.scratch_hi);
    m->cpu.instruction_cycle = -1;
}

void dex(MACHINE *m) {
    read_from_memory(m, m->cpu.pc);
    set_register_to_value(m, &m->cpu.X, m->cpu.X - 1);
    m->cpu.instruction_cycle = -1;
}

void dey(MACHINE *m) {
    read_from_memory(m, m->cpu.pc);
    set_register_to_value(m, &m->cpu.Y, m->cpu.Y - 1);
    m->cpu.instruction_cycle = -1;
}

void eor_imm(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    set_register_to_value(m, &m->cpu.A, m->cpu.A ^ m->cpu.scratch_lo);
    m->cpu.pc++;
    m->cpu.instruction_cycle = -1;
}

void eor_a16(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    set_register_to_value(m, &m->cpu.A, m->cpu.A ^ m->cpu.scratch_lo);
    m->cpu.instruction_cycle = -1;
}

void eor_abs_x(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.X)) {
        set_register_to_value(m, &m->cpu.A, m->cpu.A ^ m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void eor_abs_y(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.Y)) {
        set_register_to_value(m, &m->cpu.A, m->cpu.A ^ m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void inc_a16(MACHINE *m) {
    set_register_to_value(m, &m->cpu.scratch_hi, m->cpu.scratch_lo + 1);
    write_to_memory(m, m->cpu.address_16, m->cpu.scratch_hi);
    m->cpu.instruction_cycle = -1;
}

void inx(MACHINE *m) {
    read_from_memory(m, m->cpu.pc);
    set_register_to_value(m, &m->cpu.X, m->cpu.X + 1);
    m->cpu.instruction_cycle = -1;
}

void iny(MACHINE *m) {
    read_from_memory(m, m->cpu.pc);
    set_register_to_value(m, &m->cpu.Y, m->cpu.Y + 1);
    m->cpu.instruction_cycle = -1;
}

void jmp_abs(MACHINE *m) {
    ah_read_pc(m);
    m->cpu.pc = m->cpu.address_16;
    m->cpu.instruction_cycle = -1;
}

void jmp_ind(MACHINE *m) {
    ah_read_a16_sl2al(m);
    m->cpu.pc = m->cpu.address_16;
    m->cpu.instruction_cycle = -1;
}

void jsr_abs(MACHINE *m) {
    ah_read_pc(m);
    m->cpu.pc = m->cpu.address_16;
    m->cpu.instruction_cycle = -1;
}

void lda_imm(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    set_register_to_value(m, &m->cpu.A, m->cpu.scratch_lo);
    m->cpu.pc++;
    m->cpu.instruction_cycle = -1;
}

void lda_a16(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    set_register_to_value(m, &m->cpu.A, m->cpu.scratch_lo);
    m->cpu.instruction_cycle = -1;
}

void lda_abs_x(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.X)) {
        set_register_to_value(m, &m->cpu.A, m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void lda_abs_y(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.Y)) {
        set_register_to_value(m, &m->cpu.A, m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void ldx_imm(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    set_register_to_value(m, &m->cpu.X, m->cpu.scratch_lo);
    m->cpu.pc++;
    m->cpu.instruction_cycle = -1;
}

void ldx_a16(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    set_register_to_value(m, &m->cpu.X, m->cpu.scratch_lo);
    m->cpu.instruction_cycle = -1;
}

void ldx_abs_y(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.Y)) {
        set_register_to_value(m, &m->cpu.X, m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void ldy_imm(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    set_register_to_value(m, &m->cpu.Y, m->cpu.scratch_lo);
    m->cpu.pc++;
    m->cpu.instruction_cycle = -1;
}

void ldy_a16(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    set_register_to_value(m, &m->cpu.Y, m->cpu.scratch_lo);
    m->cpu.instruction_cycle = -1;
}

void ldy_abs_x(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.X)) {
        set_register_to_value(m, &m->cpu.Y, m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void lsr_a(MACHINE *m) {
    read_from_memory(m, m->cpu.pc);
    m->cpu.C = m->cpu.A & 0x01 ? 1 : 0;
    set_register_to_value(m, &m->cpu.A, m->cpu.A >>= 1);
    m->cpu.instruction_cycle = -1;
}

void lsr_a16(MACHINE *m) {
    m->cpu.C = m->cpu.scratch_lo & 0x01 ? 1 : 0;
    set_register_to_value(m, &m->cpu.scratch_hi, m->cpu.scratch_lo >> 1);
    write_to_memory(m, m->cpu.address_16, m->cpu.scratch_hi);
    m->cpu.instruction_cycle = -1;
}

void nop(MACHINE *m) {
    read_from_memory(m, m->cpu.pc);
    m->cpu.instruction_cycle = -1;
}

void ora_imm(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    set_register_to_value(m, &m->cpu.A, m->cpu.A | m->cpu.scratch_lo);
    m->cpu.pc++;
    m->cpu.instruction_cycle = -1;
}

void ora_a16(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    set_register_to_value(m, &m->cpu.A, m->cpu.A | m->cpu.scratch_lo);
    m->cpu.instruction_cycle = -1;
}

void ora_abs_x(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.X)) {
        set_register_to_value(m, &m->cpu.A, m->cpu.A | m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void ora_abs_y(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.Y)) {
        set_register_to_value(m, &m->cpu.A, m->cpu.A | m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void pha(MACHINE *m) {
    push(m, m->cpu.A);
    m->cpu.instruction_cycle = -1;
}

void php(MACHINE *m) {
    push(m, m->cpu.flags | 0b00010000);                             // Break flag on flags push
    m->cpu.instruction_cycle = -1;
}

void pla(MACHINE *m) {
    set_register_to_value(m, &m->cpu.A, pull(m));
    m->cpu.instruction_cycle = -1;
}

void plp(MACHINE *m) {
    m->cpu.flags = (pull(m) & ~0b00010000) | 0b00100000;            // Break flag off, but - flag on
    m->cpu.instruction_cycle = -1;
}

void rol_a(MACHINE *m) {
    uint8_t c = m->cpu.A & 0x80;
    read_pc(m);
    set_register_to_value(m, &m->cpu.A, (m->cpu.A << 1) | m->cpu.C);
    m->cpu.C = c ? 1 : 0;
    m->cpu.instruction_cycle = -1;
}

void rol_a16(MACHINE *m) {
    uint8_t c = m->cpu.scratch_lo & 0x80;
    set_register_to_value(m, &m->cpu.scratch_lo, (m->cpu.scratch_lo << 1) | m->cpu.C);
    write_to_memory(m, m->cpu.address_16, m->cpu.scratch_lo);
    m->cpu.C = c ? 1 : 0;
    m->cpu.instruction_cycle = -1;
}

void ror_a(MACHINE *m) {
    uint8_t c = m->cpu.A & 0x01;
    read_pc(m);
    set_register_to_value(m, &m->cpu.A, (m->cpu.A >> 1) | (m->cpu.C << 7));
    m->cpu.C = c;
    m->cpu.instruction_cycle = -1;
}

void ror_a16(MACHINE *m) {
    uint8_t c = m->cpu.scratch_lo & 0x01;
    set_register_to_value(m, &m->cpu.scratch_lo, (m->cpu.scratch_lo >> 1) | (m->cpu.C << 7));
    write_to_memory(m, m->cpu.address_16, m->cpu.scratch_lo);
    m->cpu.C = c;
    m->cpu.instruction_cycle = -1;
}

void rti(MACHINE *m) {
    ah_from_stack(m);
    m->cpu.pc = m->cpu.address_16;
    m->cpu.instruction_cycle = -1;
}

void rts(MACHINE *m) {
    m->cpu.pc = m->cpu.address_16;
    al_read_pc(m);
    m->cpu.instruction_cycle = -1;
}

void sbc_imm(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.pc);
    subtract_value_from_accumulator(m, m->cpu.scratch_lo);
    m->cpu.pc++;
    m->cpu.instruction_cycle = -1;
}

void sbc_a16(MACHINE *m) {
    m->cpu.scratch_lo = read_from_memory(m, m->cpu.address_16);
    subtract_value_from_accumulator(m, m->cpu.scratch_lo);
    m->cpu.instruction_cycle = -1;
}

void sbc_abs_x(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.X)) {
        subtract_value_from_accumulator(m, m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void sbc_abs_y(MACHINE *m) {
    if(!check_page_fault(m, m->cpu.Y)) {
        subtract_value_from_accumulator(m, m->cpu.scratch_lo);
        m->cpu.instruction_cycle = -1;
    }
}

void sec(MACHINE *m) {
    read_pc(m);
    m->cpu.C = 1;
    m->cpu.instruction_cycle = -1;
}

void sed(MACHINE *m) {
    read_pc(m);
    m->cpu.D = 1;
    m->cpu.instruction_cycle = -1;
}

void sei(MACHINE *m) {
    read_pc(m);
    m->cpu.I = 1;
    m->cpu.instruction_cycle = -1;
}

void sta_a16(MACHINE *m) {
    write_to_memory(m, m->cpu.address_16, m->cpu.A);
    m->cpu.instruction_cycle = -1;
}

void sta_abs_x(MACHINE *m) {
    m->cpu.address_hi += m->cpu.page_fault;
    m->cpu.page_fault = 0;
    write_to_memory(m, m->cpu.address_16, m->cpu.A);
    m->cpu.instruction_cycle = -1;
}

void sta_abs_y(MACHINE *m) {
    m->cpu.address_hi += m->cpu.page_fault;
    m->cpu.page_fault = 0;
    write_to_memory(m, m->cpu.address_16, m->cpu.A);
    m->cpu.instruction_cycle = -1;
}

void stx_a16(MACHINE *m) {
    write_to_memory(m, m->cpu.address_16, m->cpu.X);
    m->cpu.instruction_cycle = -1;
}

void sty_a16(MACHINE *m) {
    write_to_memory(m, m->cpu.address_16, m->cpu.Y);
    m->cpu.instruction_cycle = -1;
}

void tax(MACHINE *m) {
    read_pc(m);
    set_register_to_value(m, &m->cpu.X, m->cpu.A);
    m->cpu.instruction_cycle = -1;
}

void tay(MACHINE *m) {
    read_pc(m);
    set_register_to_value(m, &m->cpu.Y, m->cpu.A);
    m->cpu.instruction_cycle = -1;
}

void tsx(MACHINE *m) {
    read_pc(m);
    set_register_to_value(m, &m->cpu.X, m->cpu.sp - 0x100);
    m->cpu.instruction_cycle = -1;
}

void txa(MACHINE *m) {
    read_pc(m);
    set_register_to_value(m, &m->cpu.A, m->cpu.X);
    m->cpu.instruction_cycle = -1;
}

void txs(MACHINE *m) {
    read_pc(m);
    m->cpu.sp = 0x100 + m->cpu.X;
    m->cpu.instruction_cycle = -1;
}

void tya(MACHINE *m) {
    read_pc(m);
    set_register_to_value(m, &m->cpu.A, m->cpu.Y);
    m->cpu.instruction_cycle = -1;
}

