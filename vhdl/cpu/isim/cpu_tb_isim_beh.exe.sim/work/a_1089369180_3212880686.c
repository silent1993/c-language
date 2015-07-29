/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x8ef4fb42 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/vhdl/cpu/quzhi.vhd";



static void work_a_1089369180_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;

LAB0:    xsi_set_current_line(49, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(53, ng0);
    t1 = (t0 + 868U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB5;

LAB7:    t1 = (t0 + 776U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB8;

LAB9:
LAB6:    t1 = (t0 + 2068);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(50, ng0);
    t1 = (t0 + 684U);
    t5 = *((char **)t1);
    t1 = (t0 + 1316U);
    t6 = *((char **)t1);
    t1 = (t6 + 0);
    memcpy(t1, t5, 16U);
    goto LAB3;

LAB5:    xsi_set_current_line(54, ng0);
    t1 = (t0 + 3411);
    t6 = (t0 + 1316U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    memcpy(t6, t1, 16U);
    goto LAB6;

LAB8:    xsi_set_current_line(56, ng0);
    t1 = (t0 + 1316U);
    t5 = *((char **)t1);
    t1 = (t0 + 2112);
    t6 = (t1 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t9 = *((char **)t8);
    memcpy(t9, t5, 16U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(57, ng0);
    t1 = (t0 + 960U);
    t2 = *((char **)t1);
    t1 = (t0 + 2148);
    t5 = (t1 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 40U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 16U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB6;

}


extern void work_a_1089369180_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1089369180_3212880686_p_0};
	xsi_register_didat("work_a_1089369180_3212880686", "isim/cpu_tb_isim_beh.exe.sim/work/a_1089369180_3212880686.didat");
	xsi_register_executes(pe);
}
