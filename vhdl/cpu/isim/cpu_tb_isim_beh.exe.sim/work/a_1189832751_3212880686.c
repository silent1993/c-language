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
static const char *ng0 = "D:/vhdl/cpu/back.vhd";
extern char *IEEE_P_3620187407;

char *ieee_p_3620187407_sub_767668596_3965413181(char *, char *, char *, char *, char *, char *);


static void work_a_1189832751_3212880686_p_0(char *t0)
{
    char t26[16];
    char t41[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    int t12;
    int t13;
    char *t14;
    char *t15;
    int t16;
    char *t17;
    char *t18;
    int t19;
    char *t20;
    char *t21;
    int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned char t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;

LAB0:    xsi_set_current_line(53, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 2460);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(54, ng0);
    t1 = (t0 + 2504);
    t5 = (t1 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 40U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(55, ng0);
    t1 = (t0 + 776U);
    t2 = *((char **)t1);
    t9 = (15 - 15);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t1 = (t2 + t11);
    t5 = (t0 + 4169);
    t12 = xsi_mem_cmp(t5, t1, 2U);
    if (t12 == 1)
        goto LAB6;

LAB11:    t7 = (t0 + 4171);
    t13 = xsi_mem_cmp(t7, t1, 2U);
    if (t13 == 1)
        goto LAB7;

LAB12:    t14 = (t0 + 4173);
    t16 = xsi_mem_cmp(t14, t1, 2U);
    if (t16 == 1)
        goto LAB8;

LAB13:    t17 = (t0 + 4175);
    t19 = xsi_mem_cmp(t17, t1, 2U);
    if (t19 == 1)
        goto LAB9;

LAB14:
LAB10:    xsi_set_current_line(85, ng0);

LAB5:    goto LAB3;

LAB6:    xsi_set_current_line(57, ng0);
    t20 = (t0 + 776U);
    t21 = *((char **)t20);
    t22 = (12 - 15);
    t23 = (t22 * -1);
    t24 = (1U * t23);
    t25 = (0 + t24);
    t20 = (t21 + t25);
    t3 = *((unsigned char *)t20);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB16;

LAB18:    xsi_set_current_line(60, ng0);
    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t1 = (t0 + 4008U);
    t5 = (t0 + 4177);
    t7 = (t26 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 7;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t12 = (7 - 0);
    t9 = (t12 * 1);
    t9 = (t9 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t9;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t5, t26);
    if (t3 != 0)
        goto LAB21;

LAB23:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t1 = (t0 + 3944U);
    t5 = (t0 + 4185);
    t7 = (t41 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 15;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t12 = (15 - 0);
    t9 = (t12 * 1);
    t9 = (t9 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t9;
    t8 = ieee_p_3620187407_sub_767668596_3965413181(IEEE_P_3620187407, t26, t2, t1, t5, t41);
    t14 = (t26 + 12U);
    t9 = *((unsigned int *)t14);
    t10 = (1U * t9);
    t3 = (16U != t10);
    if (t3 == 1)
        goto LAB26;

LAB27:    t15 = (t0 + 2540);
    t17 = (t15 + 32U);
    t18 = *((char **)t17);
    t20 = (t18 + 40U);
    t21 = *((char **)t20);
    memcpy(t21, t8, 16U);
    xsi_driver_first_trans_fast_port(t15);

LAB22:
LAB17:    goto LAB5;

LAB7:    xsi_set_current_line(67, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t1 = (t0 + 3944U);
    t5 = (t0 + 4201);
    t7 = (t41 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 15;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t12 = (15 - 0);
    t9 = (t12 * 1);
    t9 = (t9 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t9;
    t8 = ieee_p_3620187407_sub_767668596_3965413181(IEEE_P_3620187407, t26, t2, t1, t5, t41);
    t14 = (t26 + 12U);
    t9 = *((unsigned int *)t14);
    t10 = (1U * t9);
    t3 = (16U != t10);
    if (t3 == 1)
        goto LAB28;

LAB29:    t15 = (t0 + 2540);
    t17 = (t15 + 32U);
    t18 = *((char **)t17);
    t20 = (t18 + 40U);
    t21 = *((char **)t20);
    memcpy(t21, t8, 16U);
    xsi_driver_first_trans_fast_port(t15);
    xsi_set_current_line(68, ng0);
    t1 = (t0 + 2576);
    t2 = (t1 + 32U);
    t5 = *((char **)t2);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(69, ng0);
    t1 = (t0 + 776U);
    t2 = *((char **)t1);
    t9 = (15 - 10);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t1 = (t2 + t11);
    t5 = (t0 + 2612);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t14 = *((char **)t8);
    memcpy(t14, t1, 3U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(70, ng0);
    t1 = (t0 + 1144U);
    t2 = *((char **)t1);
    t1 = (t0 + 2648);
    t5 = (t1 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 40U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 8U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB5;

LAB8:    xsi_set_current_line(72, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t1 = (t0 + 3944U);
    t5 = (t0 + 4217);
    t7 = (t41 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 15;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t12 = (15 - 0);
    t9 = (t12 * 1);
    t9 = (t9 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t9;
    t8 = ieee_p_3620187407_sub_767668596_3965413181(IEEE_P_3620187407, t26, t2, t1, t5, t41);
    t14 = (t26 + 12U);
    t9 = *((unsigned int *)t14);
    t10 = (1U * t9);
    t3 = (16U != t10);
    if (t3 == 1)
        goto LAB30;

LAB31:    t15 = (t0 + 2540);
    t17 = (t15 + 32U);
    t18 = *((char **)t17);
    t20 = (t18 + 40U);
    t21 = *((char **)t20);
    memcpy(t21, t8, 16U);
    xsi_driver_first_trans_fast_port(t15);
    xsi_set_current_line(73, ng0);
    t1 = (t0 + 776U);
    t2 = *((char **)t1);
    t12 = (12 - 15);
    t9 = (t12 * -1);
    t10 = (1U * t9);
    t11 = (0 + t10);
    t1 = (t2 + t11);
    t3 = *((unsigned char *)t1);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB32;

LAB34:
LAB33:    goto LAB5;

LAB9:    xsi_set_current_line(79, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t1 = (t0 + 3944U);
    t5 = (t0 + 4233);
    t7 = (t41 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 15;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t12 = (15 - 0);
    t9 = (t12 * 1);
    t9 = (t9 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t9;
    t8 = ieee_p_3620187407_sub_767668596_3965413181(IEEE_P_3620187407, t26, t2, t1, t5, t41);
    t14 = (t26 + 12U);
    t9 = *((unsigned int *)t14);
    t10 = (1U * t9);
    t3 = (16U != t10);
    if (t3 == 1)
        goto LAB35;

LAB36:    t15 = (t0 + 2540);
    t17 = (t15 + 32U);
    t18 = *((char **)t17);
    t20 = (t18 + 40U);
    t21 = *((char **)t20);
    memcpy(t21, t8, 16U);
    xsi_driver_first_trans_fast_port(t15);
    xsi_set_current_line(80, ng0);
    t1 = (t0 + 776U);
    t2 = *((char **)t1);
    t12 = (12 - 15);
    t9 = (t12 * -1);
    t10 = (1U * t9);
    t11 = (0 + t10);
    t1 = (t2 + t11);
    t3 = *((unsigned char *)t1);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB37;

LAB39:
LAB38:    goto LAB5;

LAB15:;
LAB16:    xsi_set_current_line(58, ng0);
    t27 = (t0 + 684U);
    t28 = *((char **)t27);
    t27 = (t0 + 3944U);
    t29 = (t0 + 868U);
    t30 = *((char **)t29);
    t29 = (t0 + 3976U);
    t31 = ieee_p_3620187407_sub_767668596_3965413181(IEEE_P_3620187407, t26, t28, t27, t30, t29);
    t32 = (t26 + 12U);
    t33 = *((unsigned int *)t32);
    t34 = (1U * t33);
    t35 = (16U != t34);
    if (t35 == 1)
        goto LAB19;

LAB20:    t36 = (t0 + 2540);
    t37 = (t36 + 32U);
    t38 = *((char **)t37);
    t39 = (t38 + 40U);
    t40 = *((char **)t39);
    memcpy(t40, t31, 16U);
    xsi_driver_first_trans_fast_port(t36);
    goto LAB17;

LAB19:    xsi_size_not_matching(16U, t34, 0);
    goto LAB20;

LAB21:    xsi_set_current_line(61, ng0);
    t8 = (t0 + 684U);
    t14 = *((char **)t8);
    t8 = (t0 + 3944U);
    t15 = (t0 + 868U);
    t17 = *((char **)t15);
    t15 = (t0 + 3976U);
    t18 = ieee_p_3620187407_sub_767668596_3965413181(IEEE_P_3620187407, t41, t14, t8, t17, t15);
    t20 = (t41 + 12U);
    t9 = *((unsigned int *)t20);
    t10 = (1U * t9);
    t4 = (16U != t10);
    if (t4 == 1)
        goto LAB24;

LAB25:    t21 = (t0 + 2540);
    t27 = (t21 + 32U);
    t28 = *((char **)t27);
    t29 = (t28 + 40U);
    t30 = *((char **)t29);
    memcpy(t30, t18, 16U);
    xsi_driver_first_trans_fast_port(t21);
    goto LAB22;

LAB24:    xsi_size_not_matching(16U, t10, 0);
    goto LAB25;

LAB26:    xsi_size_not_matching(16U, t10, 0);
    goto LAB27;

LAB28:    xsi_size_not_matching(16U, t10, 0);
    goto LAB29;

LAB30:    xsi_size_not_matching(16U, t10, 0);
    goto LAB31;

LAB32:    xsi_set_current_line(74, ng0);
    t5 = (t0 + 2576);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t14 = *((char **)t8);
    *((unsigned char *)t14) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(75, ng0);
    t1 = (t0 + 776U);
    t2 = *((char **)t1);
    t9 = (15 - 10);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t1 = (t2 + t11);
    t5 = (t0 + 2612);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t14 = *((char **)t8);
    memcpy(t14, t1, 3U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(76, ng0);
    t1 = (t0 + 960U);
    t2 = *((char **)t1);
    t1 = (t0 + 2648);
    t5 = (t1 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 40U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 8U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB33;

LAB35:    xsi_size_not_matching(16U, t10, 0);
    goto LAB36;

LAB37:    xsi_set_current_line(81, ng0);
    t5 = (t0 + 2576);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t14 = *((char **)t8);
    *((unsigned char *)t14) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(82, ng0);
    t1 = (t0 + 776U);
    t2 = *((char **)t1);
    t9 = (15 - 10);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t1 = (t2 + t11);
    t5 = (t0 + 2612);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t14 = *((char **)t8);
    memcpy(t14, t1, 3U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(83, ng0);
    t1 = (t0 + 960U);
    t2 = *((char **)t1);
    t1 = (t0 + 2648);
    t5 = (t1 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 40U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 8U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB38;

}


extern void work_a_1189832751_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1189832751_3212880686_p_0};
	xsi_register_didat("work_a_1189832751_3212880686", "isim/cpu_tb_isim_beh.exe.sim/work/a_1189832751_3212880686.didat");
	xsi_register_executes(pe);
}
