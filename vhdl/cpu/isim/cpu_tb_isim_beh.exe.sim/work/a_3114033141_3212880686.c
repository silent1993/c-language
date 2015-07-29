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
static const char *ng0 = "D:/vhdl/cpu/visit_M.vhd";



static void work_a_3114033141_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    int t7;
    char *t8;
    char *t9;
    int t10;
    char *t11;
    int t13;
    char *t14;
    int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;

LAB0:    xsi_set_current_line(50, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 2368);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(51, ng0);
    t1 = (t0 + 960U);
    t5 = *((char **)t1);
    t1 = (t0 + 3978);
    t7 = xsi_mem_cmp(t1, t5, 5U);
    if (t7 == 1)
        goto LAB6;

LAB11:    t8 = (t0 + 3983);
    t10 = xsi_mem_cmp(t8, t5, 5U);
    if (t10 == 1)
        goto LAB7;

LAB12:    t11 = (t0 + 3988);
    t13 = xsi_mem_cmp(t11, t5, 5U);
    if (t13 == 1)
        goto LAB8;

LAB13:    t14 = (t0 + 3993);
    t16 = xsi_mem_cmp(t14, t5, 5U);
    if (t16 == 1)
        goto LAB9;

LAB14:
LAB10:    xsi_set_current_line(69, ng0);

LAB5:    goto LAB3;

LAB6:    xsi_set_current_line(53, ng0);
    t17 = (t0 + 868U);
    t18 = *((char **)t17);
    t17 = (t0 + 2412);
    t19 = (t17 + 32U);
    t20 = *((char **)t19);
    t21 = (t20 + 40U);
    t22 = *((char **)t21);
    memcpy(t22, t18, 8U);
    xsi_driver_first_trans_fast_port(t17);
    goto LAB5;

LAB7:    xsi_set_current_line(56, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t1 = (t0 + 2448);
    t5 = (t1 + 32U);
    t6 = *((char **)t5);
    t8 = (t6 + 40U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 8U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB5;

LAB8:    xsi_set_current_line(59, ng0);
    t1 = (t0 + 1144U);
    t2 = *((char **)t1);
    t1 = (t0 + 2448);
    t5 = (t1 + 32U);
    t6 = *((char **)t5);
    t8 = (t6 + 40U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 8U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(60, ng0);
    t1 = (t0 + 3998);
    t5 = (t0 + 2484);
    t6 = (t5 + 32U);
    t8 = *((char **)t6);
    t9 = (t8 + 40U);
    t11 = *((char **)t9);
    memcpy(t11, t1, 8U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(61, ng0);
    t1 = (t0 + 2520);
    t2 = (t1 + 32U);
    t5 = *((char **)t2);
    t6 = (t5 + 40U);
    t8 = *((char **)t6);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(62, ng0);
    t1 = (t0 + 2556);
    t2 = (t1 + 32U);
    t5 = *((char **)t2);
    t6 = (t5 + 40U);
    t8 = *((char **)t6);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(63, ng0);
    t1 = (t0 + 2592);
    t2 = (t1 + 32U);
    t5 = *((char **)t2);
    t6 = (t5 + 40U);
    t8 = *((char **)t6);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB5;

LAB9:    xsi_set_current_line(65, ng0);
    t1 = (t0 + 868U);
    t2 = *((char **)t1);
    t1 = (t0 + 2484);
    t5 = (t1 + 32U);
    t6 = *((char **)t5);
    t8 = (t6 + 40U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 8U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(66, ng0);
    t1 = (t0 + 2520);
    t2 = (t1 + 32U);
    t5 = *((char **)t2);
    t6 = (t5 + 40U);
    t8 = *((char **)t6);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(67, ng0);
    t1 = (t0 + 2556);
    t2 = (t1 + 32U);
    t5 = *((char **)t2);
    t6 = (t5 + 40U);
    t8 = *((char **)t6);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(68, ng0);
    t1 = (t0 + 2592);
    t2 = (t1 + 32U);
    t5 = *((char **)t2);
    t6 = (t5 + 40U);
    t8 = *((char **)t6);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB5;

LAB15:;
}


extern void work_a_3114033141_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3114033141_3212880686_p_0};
	xsi_register_didat("work_a_3114033141_3212880686", "isim/cpu_tb_isim_beh.exe.sim/work/a_3114033141_3212880686.didat");
	xsi_register_executes(pe);
}
