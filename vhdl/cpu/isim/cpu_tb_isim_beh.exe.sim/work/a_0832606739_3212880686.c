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
static const char *ng0 = "D:/vhdl/cpu/alu.vhd";
extern char *IEEE_P_3620187407;

int ieee_p_3620187407_sub_514432868_3965413181(char *, char *, char *);
char *ieee_p_3620187407_sub_767668596_3965413181(char *, char *, char *, char *, char *, char *);
char *ieee_p_3620187407_sub_767740470_3965413181(char *, char *, char *, char *, char *, char *);


static void work_a_0832606739_3212880686_p_0(char *t0)
{
    char t20[16];
    char t33[16];
    char t34[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;
    int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    int t21;
    char *t22;
    int t23;
    char *t24;
    char *t25;
    int t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;

LAB0:    xsi_set_current_line(57, ng0);
    t1 = (t0 + 776U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(61, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB5;

LAB7:
LAB6:    t1 = (t0 + 2616);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(58, ng0);
    t1 = (t0 + 684U);
    t5 = *((char **)t1);
    t1 = (t0 + 4372U);
    t6 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t5, t1);
    t7 = (t0 + 1864U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    *((int *)t7) = t6;
    xsi_set_current_line(59, ng0);
    t1 = (t0 + 960U);
    t2 = *((char **)t1);
    t1 = (t0 + 1864U);
    t5 = *((char **)t1);
    t6 = *((int *)t5);
    t9 = (t6 - 7);
    t10 = (t9 * -1);
    t11 = (8U * t10);
    t12 = (0U + t11);
    t1 = (t0 + 2660);
    t7 = (t1 + 32U);
    t8 = *((char **)t7);
    t13 = (t8 + 40U);
    t14 = *((char **)t13);
    memcpy(t14, t2, 8U);
    xsi_driver_first_trans_delta(t1, t12, 8U, 0LL);
    goto LAB3;

LAB5:    xsi_set_current_line(64, ng0);
    t1 = (t0 + 1052U);
    t5 = *((char **)t1);
    t10 = (15 - 15);
    t11 = (t10 * 1U);
    t12 = (0 + t11);
    t1 = (t5 + t12);
    t7 = (t0 + 2696);
    t8 = (t7 + 32U);
    t13 = *((char **)t8);
    t14 = (t13 + 40U);
    t15 = *((char **)t14);
    memcpy(t15, t1, 5U);
    xsi_driver_first_trans_fast_port(t7);
    xsi_set_current_line(65, ng0);
    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t6 = (11 - 15);
    t10 = (t6 * -1);
    t11 = (1U * t10);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t3 = *((unsigned char *)t1);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(72, ng0);
    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t10 = (15 - 10);
    t11 = (t10 * 1U);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t5 = (t20 + 0U);
    t7 = (t5 + 0U);
    *((int *)t7) = 10;
    t7 = (t5 + 4U);
    *((int *)t7) = 8;
    t7 = (t5 + 8U);
    *((int *)t7) = -1;
    t6 = (8 - 10);
    t16 = (t6 * -1);
    t16 = (t16 + 1);
    t7 = (t5 + 12U);
    *((unsigned int *)t7) = t16;
    t9 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t1, t20);
    t7 = (t0 + 1592U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    *((int *)t7) = t9;
    xsi_set_current_line(73, ng0);
    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t10 = (15 - 2);
    t11 = (t10 * 1U);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t5 = (t20 + 0U);
    t7 = (t5 + 0U);
    *((int *)t7) = 2;
    t7 = (t5 + 4U);
    *((int *)t7) = 0;
    t7 = (t5 + 8U);
    *((int *)t7) = -1;
    t6 = (0 - 2);
    t16 = (t6 * -1);
    t16 = (t16 + 1);
    t7 = (t5 + 12U);
    *((unsigned int *)t7) = t16;
    t9 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t1, t20);
    t7 = (t0 + 1660U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    *((int *)t7) = t9;
    xsi_set_current_line(74, ng0);
    t1 = (t0 + 1420U);
    t2 = *((char **)t1);
    t1 = (t0 + 1592U);
    t5 = *((char **)t1);
    t6 = *((int *)t5);
    t9 = (t6 - 7);
    t10 = (t9 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, t6);
    t11 = (8U * t10);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t7 = (t0 + 2768);
    t8 = (t7 + 32U);
    t13 = *((char **)t8);
    t14 = (t13 + 40U);
    t15 = *((char **)t14);
    memcpy(t15, t1, 8U);
    xsi_driver_first_trans_fast_port(t7);
    xsi_set_current_line(75, ng0);
    t1 = (t0 + 1420U);
    t2 = *((char **)t1);
    t1 = (t0 + 1592U);
    t5 = *((char **)t1);
    t6 = *((int *)t5);
    t9 = (t6 - 7);
    t10 = (t9 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, t6);
    t11 = (8U * t10);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t7 = (t0 + 1728U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    memcpy(t7, t1, 8U);
    xsi_set_current_line(76, ng0);
    t1 = (t0 + 1420U);
    t2 = *((char **)t1);
    t1 = (t0 + 1660U);
    t5 = *((char **)t1);
    t6 = *((int *)t5);
    t9 = (t6 - 7);
    t10 = (t9 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, t6);
    t11 = (8U * t10);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t7 = (t0 + 1796U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    memcpy(t7, t1, 8U);

LAB9:    xsi_set_current_line(78, ng0);
    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t10 = (15 - 15);
    t11 = (t10 * 1U);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t5 = (t0 + 4664);
    t6 = xsi_mem_cmp(t5, t1, 2U);
    if (t6 == 1)
        goto LAB12;

LAB17:    t8 = (t0 + 4666);
    t9 = xsi_mem_cmp(t8, t1, 2U);
    if (t9 == 1)
        goto LAB13;

LAB18:    t14 = (t0 + 4668);
    t21 = xsi_mem_cmp(t14, t1, 2U);
    if (t21 == 1)
        goto LAB14;

LAB19:    t19 = (t0 + 4670);
    t23 = xsi_mem_cmp(t19, t1, 2U);
    if (t23 == 1)
        goto LAB15;

LAB20:
LAB16:    xsi_set_current_line(101, ng0);

LAB11:    goto LAB6;

LAB8:    xsi_set_current_line(66, ng0);
    t5 = (t0 + 1420U);
    t7 = *((char **)t5);
    t9 = (7 - 7);
    t16 = (t9 * -1);
    t17 = (8U * t16);
    t18 = (0 + t17);
    t5 = (t7 + t18);
    t8 = (t0 + 2732);
    t13 = (t8 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t19 = *((char **)t15);
    memcpy(t19, t5, 8U);
    xsi_driver_first_trans_delta(t8, 0U, 8U, 0LL);
    xsi_set_current_line(67, ng0);
    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t10 = (15 - 7);
    t11 = (t10 * 1U);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t5 = (t0 + 2732);
    t7 = (t5 + 32U);
    t8 = *((char **)t7);
    t13 = (t8 + 40U);
    t14 = *((char **)t13);
    memcpy(t14, t1, 8U);
    xsi_driver_first_trans_delta(t5, 8U, 8U, 0LL);
    xsi_set_current_line(68, ng0);
    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t10 = (15 - 10);
    t11 = (t10 * 1U);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t5 = (t20 + 0U);
    t7 = (t5 + 0U);
    *((int *)t7) = 10;
    t7 = (t5 + 4U);
    *((int *)t7) = 8;
    t7 = (t5 + 8U);
    *((int *)t7) = -1;
    t6 = (8 - 10);
    t16 = (t6 * -1);
    t16 = (t16 + 1);
    t7 = (t5 + 12U);
    *((unsigned int *)t7) = t16;
    t9 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t1, t20);
    t7 = (t0 + 1592U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    *((int *)t7) = t9;
    xsi_set_current_line(69, ng0);
    t1 = (t0 + 1420U);
    t2 = *((char **)t1);
    t1 = (t0 + 1592U);
    t5 = *((char **)t1);
    t6 = *((int *)t5);
    t9 = (t6 - 7);
    t10 = (t9 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, t6);
    t11 = (8U * t10);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t7 = (t0 + 2768);
    t8 = (t7 + 32U);
    t13 = *((char **)t8);
    t14 = (t13 + 40U);
    t15 = *((char **)t14);
    memcpy(t15, t1, 8U);
    xsi_driver_first_trans_fast_port(t7);
    xsi_set_current_line(70, ng0);
    t1 = (t0 + 1420U);
    t2 = *((char **)t1);
    t1 = (t0 + 1592U);
    t5 = *((char **)t1);
    t6 = *((int *)t5);
    t9 = (t6 - 7);
    t10 = (t9 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, t6);
    t11 = (8U * t10);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t7 = (t0 + 1728U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    memcpy(t7, t1, 8U);
    goto LAB9;

LAB12:    xsi_set_current_line(80, ng0);
    t24 = (t0 + 1052U);
    t25 = *((char **)t24);
    t26 = (12 - 15);
    t16 = (t26 * -1);
    t17 = (1U * t16);
    t18 = (0 + t17);
    t24 = (t25 + t18);
    t3 = *((unsigned char *)t24);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB22;

LAB24:
LAB23:    goto LAB11;

LAB13:    xsi_set_current_line(84, ng0);
    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t10 = (15 - 13);
    t11 = (t10 * 1U);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t5 = (t20 + 0U);
    t7 = (t5 + 0U);
    *((int *)t7) = 13;
    t7 = (t5 + 4U);
    *((int *)t7) = 12;
    t7 = (t5 + 8U);
    *((int *)t7) = -1;
    t6 = (12 - 13);
    t16 = (t6 * -1);
    t16 = (t16 + 1);
    t7 = (t5 + 12U);
    *((unsigned int *)t7) = t16;
    t7 = (t0 + 4672);
    t13 = (t33 + 0U);
    t14 = (t13 + 0U);
    *((int *)t14) = 0;
    t14 = (t13 + 4U);
    *((int *)t14) = 1;
    t14 = (t13 + 8U);
    *((int *)t14) = 1;
    t9 = (1 - 0);
    t16 = (t9 * 1);
    t16 = (t16 + 1);
    t14 = (t13 + 12U);
    *((unsigned int *)t14) = t16;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t1, t20, t7, t33);
    if (t3 != 0)
        goto LAB25;

LAB27:    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t10 = (15 - 13);
    t11 = (t10 * 1U);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t5 = (t20 + 0U);
    t7 = (t5 + 0U);
    *((int *)t7) = 13;
    t7 = (t5 + 4U);
    *((int *)t7) = 12;
    t7 = (t5 + 8U);
    *((int *)t7) = -1;
    t6 = (12 - 13);
    t16 = (t6 * -1);
    t16 = (t16 + 1);
    t7 = (t5 + 12U);
    *((unsigned int *)t7) = t16;
    t7 = (t0 + 4674);
    t13 = (t33 + 0U);
    t14 = (t13 + 0U);
    *((int *)t14) = 0;
    t14 = (t13 + 4U);
    *((int *)t14) = 1;
    t14 = (t13 + 8U);
    *((int *)t14) = 1;
    t9 = (1 - 0);
    t16 = (t9 * 1);
    t16 = (t16 + 1);
    t14 = (t13 + 12U);
    *((unsigned int *)t14) = t16;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t1, t20, t7, t33);
    if (t3 != 0)
        goto LAB30;

LAB31:    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t10 = (15 - 13);
    t11 = (t10 * 1U);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t5 = (t20 + 0U);
    t7 = (t5 + 0U);
    *((int *)t7) = 13;
    t7 = (t5 + 4U);
    *((int *)t7) = 12;
    t7 = (t5 + 8U);
    *((int *)t7) = -1;
    t6 = (12 - 13);
    t16 = (t6 * -1);
    t16 = (t16 + 1);
    t7 = (t5 + 12U);
    *((unsigned int *)t7) = t16;
    t7 = (t0 + 4676);
    t13 = (t33 + 0U);
    t14 = (t13 + 0U);
    *((int *)t14) = 0;
    t14 = (t13 + 4U);
    *((int *)t14) = 1;
    t14 = (t13 + 8U);
    *((int *)t14) = 1;
    t9 = (1 - 0);
    t16 = (t9 * 1);
    t16 = (t16 + 1);
    t14 = (t13 + 12U);
    *((unsigned int *)t14) = t16;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t1, t20, t7, t33);
    if (t3 != 0)
        goto LAB34;

LAB35:    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t10 = (15 - 13);
    t11 = (t10 * 1U);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t5 = (t20 + 0U);
    t7 = (t5 + 0U);
    *((int *)t7) = 13;
    t7 = (t5 + 4U);
    *((int *)t7) = 12;
    t7 = (t5 + 8U);
    *((int *)t7) = -1;
    t6 = (12 - 13);
    t16 = (t6 * -1);
    t16 = (t16 + 1);
    t7 = (t5 + 12U);
    *((unsigned int *)t7) = t16;
    t7 = (t0 + 4678);
    t13 = (t33 + 0U);
    t14 = (t13 + 0U);
    *((int *)t14) = 0;
    t14 = (t13 + 4U);
    *((int *)t14) = 1;
    t14 = (t13 + 8U);
    *((int *)t14) = 1;
    t9 = (1 - 0);
    t16 = (t9 * 1);
    t16 = (t16 + 1);
    t14 = (t13 + 12U);
    *((unsigned int *)t14) = t16;
    t3 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t1, t20, t7, t33);
    if (t3 != 0)
        goto LAB36;

LAB37:
LAB26:    goto LAB11;

LAB14:    xsi_set_current_line(94, ng0);
    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t6 = (12 - 15);
    t10 = (t6 * -1);
    t11 = (1U * t10);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t3 = *((unsigned char *)t1);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB38;

LAB40:
LAB39:    goto LAB11;

LAB15:    xsi_set_current_line(98, ng0);
    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t6 = (12 - 15);
    t10 = (t6 * -1);
    t11 = (1U * t10);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t3 = *((unsigned char *)t1);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB41;

LAB43:
LAB42:    goto LAB11;

LAB21:;
LAB22:    xsi_set_current_line(81, ng0);
    t27 = (t0 + 1728U);
    t28 = *((char **)t27);
    t27 = (t0 + 2804);
    t29 = (t27 + 32U);
    t30 = *((char **)t29);
    t31 = (t30 + 40U);
    t32 = *((char **)t31);
    memcpy(t32, t28, 8U);
    xsi_driver_first_trans_fast_port(t27);
    goto LAB23;

LAB25:    xsi_set_current_line(85, ng0);
    t14 = (t0 + 1728U);
    t15 = *((char **)t14);
    t14 = (t0 + 4516U);
    t19 = (t0 + 1796U);
    t22 = *((char **)t19);
    t19 = (t0 + 4516U);
    t24 = ieee_p_3620187407_sub_767740470_3965413181(IEEE_P_3620187407, t34, t15, t14, t22, t19);
    t25 = (t34 + 12U);
    t16 = *((unsigned int *)t25);
    t17 = (1U * t16);
    t4 = (8U != t17);
    if (t4 == 1)
        goto LAB28;

LAB29:    t27 = (t0 + 2804);
    t28 = (t27 + 32U);
    t29 = *((char **)t28);
    t30 = (t29 + 40U);
    t31 = *((char **)t30);
    memcpy(t31, t24, 8U);
    xsi_driver_first_trans_fast_port(t27);
    goto LAB26;

LAB28:    xsi_size_not_matching(8U, t17, 0);
    goto LAB29;

LAB30:    xsi_set_current_line(87, ng0);
    t14 = (t0 + 1728U);
    t15 = *((char **)t14);
    t14 = (t0 + 4516U);
    t19 = (t0 + 1796U);
    t22 = *((char **)t19);
    t19 = (t0 + 4516U);
    t24 = ieee_p_3620187407_sub_767668596_3965413181(IEEE_P_3620187407, t34, t15, t14, t22, t19);
    t25 = (t34 + 12U);
    t16 = *((unsigned int *)t25);
    t17 = (1U * t16);
    t4 = (8U != t17);
    if (t4 == 1)
        goto LAB32;

LAB33:    t27 = (t0 + 2804);
    t28 = (t27 + 32U);
    t29 = *((char **)t28);
    t30 = (t29 + 40U);
    t31 = *((char **)t30);
    memcpy(t31, t24, 8U);
    xsi_driver_first_trans_fast_port(t27);
    goto LAB26;

LAB32:    xsi_size_not_matching(8U, t17, 0);
    goto LAB33;

LAB34:    xsi_set_current_line(89, ng0);
    t14 = (t0 + 1052U);
    t15 = *((char **)t14);
    t16 = (15 - 7);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t14 = (t15 + t18);
    t19 = (t0 + 2804);
    t22 = (t19 + 32U);
    t24 = *((char **)t22);
    t25 = (t24 + 40U);
    t27 = *((char **)t25);
    memcpy(t27, t14, 8U);
    xsi_driver_first_trans_fast_port(t19);
    goto LAB26;

LAB36:    xsi_set_current_line(91, ng0);
    t14 = (t0 + 1796U);
    t15 = *((char **)t14);
    t14 = (t0 + 2804);
    t19 = (t14 + 32U);
    t22 = *((char **)t19);
    t24 = (t22 + 40U);
    t25 = *((char **)t24);
    memcpy(t25, t15, 8U);
    xsi_driver_first_trans_fast_port(t14);
    goto LAB26;

LAB38:    xsi_set_current_line(95, ng0);
    t5 = (t0 + 1728U);
    t7 = *((char **)t5);
    t5 = (t0 + 2804);
    t8 = (t5 + 32U);
    t13 = *((char **)t8);
    t14 = (t13 + 40U);
    t15 = *((char **)t14);
    memcpy(t15, t7, 8U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB39;

LAB41:    xsi_set_current_line(99, ng0);
    t5 = (t0 + 1728U);
    t7 = *((char **)t5);
    t5 = (t0 + 2804);
    t8 = (t5 + 32U);
    t13 = *((char **)t8);
    t14 = (t13 + 40U);
    t15 = *((char **)t14);
    memcpy(t15, t7, 8U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB42;

}


extern void work_a_0832606739_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0832606739_3212880686_p_0};
	xsi_register_didat("work_a_0832606739_3212880686", "isim/cpu_tb_isim_beh.exe.sim/work/a_0832606739_3212880686.didat");
	xsi_register_executes(pe);
}
