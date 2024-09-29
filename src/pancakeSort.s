# This program results from the compilation of pancakeSort.c
# Author: Jorge Infante Fragoso

# global array a
    .data
array:  .word 10, 9, 8, 7, 6, 5, 4, 3, 2, 1

# do_flip function
# kind: leaf function
# convention: a0 <-> *list, a1 <-> length, a2 <-> num, t1 <-> i, tp and t0 holds auxiliar values
# frame size: 0 bytes
# access-memory policy: load and store when needed
# returned value: none
#   t1 = i, t0 = list[i], a2 = list[num], tp = swap
    .text
do_flip:
    li      t1, 0               # t1 = 0 
S2: bge     t1, a2, S1          # jumps too S1 if i >= num-- 
    addi    a2, a2, -1           # num--    
    # swap = list[i]
    slli    t0, t1, 2           # t0 = 4*i
    add     t0, a0, t0          # t0 = a0 + 4*t1
    lw      t0, 0(t0)           # t0 = list[i]
    mv      tp, t0              # swap = list[i]
    # list[i] = list[num]
    slli    t2, a2, 2           # t2 = 4*t2
    add     t2, a0, t2          # t2 = a0 + 4*t2
    lw      t2, 0(t2)           # t2 = list[num]
    mv      t0, t2              # list[i] = list[num]
    slli    t3, t1, 2           # t3 = 4*t1
    add     t3, a0, t3          # t3 = a0 + 4*t3
    sw      t0, 0(t3)           # list[i] = t0
    # list[num] = swap
    mv      t2, tp              # t0 = t1
    slli    t3, a2, 2           # t3 = 4*t1
    add     t3, a0, t3          # t3 = a0 + 4*t3
    sw      t2, 0(t3)           # list[i] = t0
    addi    t1, t1, 1            # t1 = t1 + 1
    j       S2                  # jump to S2
    # return 
S1: jr       ra                 # returns control to caller

# pancake_sort function
# kind: nested function
# convention: a0 <-> *list, a1 <-> length, a2 <-> num, tp and t0 hold auxiliar values
# frame size: 48 bytes
#     - 4 words to back ra and fp up
#     - 4 words to back local variables up
#     i <-> -16, a <-> -20, max_num_pos <-> -24
#     - 4 words to back a1 and a0 up
#     a1 <-> -32, a0 <-> -36
# access-memory policy: load when needed store after update
# returne value: none
    .globl pancake_sort
pancake_sort:
    addi     sp, sp, -48        # updates sp
    sw       ra, 48(sp)         # backs ra up
    sw       fp, 44(sp)         # backs fp up
    addi     fp, sp, 48         # updates fp
    li       tp, 2              # tp = 2
    bge      a1, tp, L1         # jumps if a1 >= 2 to L1 (first if)
    # return 
L2: lw       ra, 48(sp)         # restores ra
    lw       fp, 44(sp)         # restores fp
    addi     sp, sp, 48         # frees pancakeSort's frame
    jr       ra                 # returns control caller
    # first for
L1: lw      tp, -16(fp)         # tp = i
    add     tp, a1, zero        # tp = length
    sw      tp, -16(fp)         # i = length
L5: li      t0, 1               # t0 = 1
    lw      tp, -16(fp)         # tp = i
    ble     tp, t0, L2          # jumps to L2 if i <= 1
    li      t0, 0               # t0 = 0
    sw      t0, -24(fp)         # max_num_pos = 0
    # second for
    li      tp, 0               # tp = 0
    sw      tp, -20(fp)         # j = 0
L9: lw      tp, -20(fp)         # tp = j
    lw      t0, -16(fp)         # t0 = i
    bge     tp, t0, L3          # jumps to L3 if j >= i 
    # first if
    # list[j]
    lw      tp, -20(fp)         # tp = j
    slli    tp, tp, 2           # tp = 4*tp
    add     tp, a0, tp          # tp = a0 + 4*tp
    lw      tp, 0(tp)           # tp = list[j]
    # list[max_num_pos]
    lw      t0, -24(fp)         # t0 = max_num_pos
    slli    t0, t0, 2           # t0 = 4*t0
    add     t0, a0, t0          # t0 = a0 + 4*t0
    lw      t0, 0(t0)           # t0 = list[max_num_pos]
    
    ble     tp, t0,L4           # jumps to L4 if list[j] <= list[max_num_pos]
    lw      tp, -24(fp)         # tp = max_num_pos
    lw      t0, -20(fp)         # t0 = j
    mv      tp, t0              # tp = t0
    sw      tp, -24(fp)         # max_num_pos = tp
    # iteration second for
L4: lw      tp, -20(fp)         # tp = j
    addi    tp, tp, 1           # tp = j + 1
    sw      tp, -20(fp)         # j++
    j       L9                  # jumps to L9
    # second if
L3: lw      tp, -24(fp)         # tp = max_num_pos
    lw      t0, -16(fp)         # t0 = i
    addi    t0, t0, -1          # t0 = i - 1
    bne     tp, t0, L6          # jumps to L6 if max_num_pos != i-1
    j       L7                  # jumps to L7
    # third if
L6: lw      tp, -24(fp)         # tp = max_num_pos
    beqz    tp, L8              # if max_num_pos == 0 then jumps to L8
    # calls do_flip function
    sw      a1, -32(fp)         # backs a1 up
    sw      a0, -36(fp)         # backs a0 up
    lw      t0, -24(fp)         # t0 = max_num_pos
    addi    t0, t0, 1           # t0 = max_num_pos + 1
    mv      a2, t0              # a2 = t0
    #lw      t0, -36(fp)         # t0 = addr(a)
    #add     a0, t0, zero
    jal     do_flip             # calls do_flip function
    lw      a1, -32(fp)         # restores a1
    lw      a0, -36(fp)         # restores a0
    j       L8                  # jump to L8
    # iteration first for
L7: lw      tp, -16(fp)         # tp = i
    addi    tp, tp, -1          # tp = tp -1
    sw      tp, -16(fp)         # i--
    j       L5                  # jumps to L5
    # calls second do_flip function
L8: sw      a1, -32(fp)         # backs a1 up
    sw      a0, -36(fp)         # backs a0 up
    #REVISAR SLLI 2
    lw      tp, -16(fp)         # tp = i
    mv      a2, tp              # a2 = tp 
    # a0 = list
    # addi    a0, fp, -36         # a0 = addr(list)
    lw      tp, -36(fp)         # tp = addr(list)
    add     a0, tp, zero        # a0 = addr(list)
    jal     do_flip             # calls do_flip
    lw      a1, -32(fp)         # restores a1
    lw      a0, -36(fp)         # restores a0
    j       L7                  # jump to L7 
# main function
# kind: nested function
# convention: tp holds auxiliar values
# frame size: 16 bytes
#     - 4 words to back ra and fp up
# access-memory policy: load when needed store after update
# returne value: a0 holds 0
    .globl main
main:
    addi     sp, sp, -16        # updates sp
    sw       ra, 16(sp)         # backs ra up
    sw       fp, 12(sp)         # backs fp up
    addi     fp, sp, 16         # updates fp
    # call function
    li       a1, 10             # a1 = 10
    mv       a0, gp             # a0 = *list
    jal      pancake_sort       # calls pancake_sort
    # return 0
    li       a0, 0              # a0 = 0
    lw       ra, 16(sp)         # restores ra
    lw       fp, 12(sp)         # restores fp
    addi     sp, sp, 16         # frees main's frame
    jr       ra                 # returns control to OS
