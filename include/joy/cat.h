/*!
 * This file defines macros to cat preprocessor tokens together.
 *
 * @author Louis Dionne
 */

#ifndef JOY_CAT_H
#define JOY_CAT_H

#define JOY_CAT_NOEXP(a, b) a ## b
#define JOY_CAT(a, b) JOY_CAT_NOEXP(a, b)

/* [[[cog

MAX = 30

args = lambda n: ", ".join("arg{}".format(i) for i in range(n))
noexp_body = lambda n: " ## ".join("arg{}".format(i) for i in range(n))

def generate_cat(n):
    cog.outl("#define JOY_CAT_NOEXP{}({}) {}".format(n, args(n), noexp_body(n)))
    cog.outl("#define JOY_CAT{0}({1}) JOY_CAT_NOEXP{0}({1})".format(n, args(n)))

for i in range(3, MAX):
    generate_cat(i)

]]] */
#define JOY_CAT_NOEXP3(arg0, arg1, arg2) arg0 ## arg1 ## arg2
#define JOY_CAT3(arg0, arg1, arg2) JOY_CAT_NOEXP3(arg0, arg1, arg2)
#define JOY_CAT_NOEXP4(arg0, arg1, arg2, arg3) arg0 ## arg1 ## arg2 ## arg3
#define JOY_CAT4(arg0, arg1, arg2, arg3) JOY_CAT_NOEXP4(arg0, arg1, arg2, arg3)
#define JOY_CAT_NOEXP5(arg0, arg1, arg2, arg3, arg4) arg0 ## arg1 ## arg2 ## arg3 ## arg4
#define JOY_CAT5(arg0, arg1, arg2, arg3, arg4) JOY_CAT_NOEXP5(arg0, arg1, arg2, arg3, arg4)
#define JOY_CAT_NOEXP6(arg0, arg1, arg2, arg3, arg4, arg5) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5
#define JOY_CAT6(arg0, arg1, arg2, arg3, arg4, arg5) JOY_CAT_NOEXP6(arg0, arg1, arg2, arg3, arg4, arg5)
#define JOY_CAT_NOEXP7(arg0, arg1, arg2, arg3, arg4, arg5, arg6) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6
#define JOY_CAT7(arg0, arg1, arg2, arg3, arg4, arg5, arg6) JOY_CAT_NOEXP7(arg0, arg1, arg2, arg3, arg4, arg5, arg6)
#define JOY_CAT_NOEXP8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7
#define JOY_CAT8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7) JOY_CAT_NOEXP8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
#define JOY_CAT_NOEXP9(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8
#define JOY_CAT9(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) JOY_CAT_NOEXP9(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)
#define JOY_CAT_NOEXP10(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9
#define JOY_CAT10(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) JOY_CAT_NOEXP10(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)
#define JOY_CAT_NOEXP11(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10
#define JOY_CAT11(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10) JOY_CAT_NOEXP11(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10)
#define JOY_CAT_NOEXP12(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11
#define JOY_CAT12(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11) JOY_CAT_NOEXP12(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11)
#define JOY_CAT_NOEXP13(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12
#define JOY_CAT13(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12) JOY_CAT_NOEXP13(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12)
#define JOY_CAT_NOEXP14(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13
#define JOY_CAT14(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13) JOY_CAT_NOEXP14(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13)
#define JOY_CAT_NOEXP15(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14
#define JOY_CAT15(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14) JOY_CAT_NOEXP15(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14)
#define JOY_CAT_NOEXP16(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14 ## arg15
#define JOY_CAT16(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15) JOY_CAT_NOEXP16(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15)
#define JOY_CAT_NOEXP17(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14 ## arg15 ## arg16
#define JOY_CAT17(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16) JOY_CAT_NOEXP17(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16)
#define JOY_CAT_NOEXP18(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14 ## arg15 ## arg16 ## arg17
#define JOY_CAT18(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17) JOY_CAT_NOEXP18(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17)
#define JOY_CAT_NOEXP19(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14 ## arg15 ## arg16 ## arg17 ## arg18
#define JOY_CAT19(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18) JOY_CAT_NOEXP19(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18)
#define JOY_CAT_NOEXP20(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14 ## arg15 ## arg16 ## arg17 ## arg18 ## arg19
#define JOY_CAT20(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19) JOY_CAT_NOEXP20(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19)
#define JOY_CAT_NOEXP21(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14 ## arg15 ## arg16 ## arg17 ## arg18 ## arg19 ## arg20
#define JOY_CAT21(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20) JOY_CAT_NOEXP21(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20)
#define JOY_CAT_NOEXP22(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14 ## arg15 ## arg16 ## arg17 ## arg18 ## arg19 ## arg20 ## arg21
#define JOY_CAT22(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21) JOY_CAT_NOEXP22(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21)
#define JOY_CAT_NOEXP23(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14 ## arg15 ## arg16 ## arg17 ## arg18 ## arg19 ## arg20 ## arg21 ## arg22
#define JOY_CAT23(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22) JOY_CAT_NOEXP23(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22)
#define JOY_CAT_NOEXP24(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14 ## arg15 ## arg16 ## arg17 ## arg18 ## arg19 ## arg20 ## arg21 ## arg22 ## arg23
#define JOY_CAT24(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23) JOY_CAT_NOEXP24(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23)
#define JOY_CAT_NOEXP25(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14 ## arg15 ## arg16 ## arg17 ## arg18 ## arg19 ## arg20 ## arg21 ## arg22 ## arg23 ## arg24
#define JOY_CAT25(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24) JOY_CAT_NOEXP25(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24)
#define JOY_CAT_NOEXP26(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14 ## arg15 ## arg16 ## arg17 ## arg18 ## arg19 ## arg20 ## arg21 ## arg22 ## arg23 ## arg24 ## arg25
#define JOY_CAT26(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25) JOY_CAT_NOEXP26(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25)
#define JOY_CAT_NOEXP27(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14 ## arg15 ## arg16 ## arg17 ## arg18 ## arg19 ## arg20 ## arg21 ## arg22 ## arg23 ## arg24 ## arg25 ## arg26
#define JOY_CAT27(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26) JOY_CAT_NOEXP27(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26)
#define JOY_CAT_NOEXP28(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14 ## arg15 ## arg16 ## arg17 ## arg18 ## arg19 ## arg20 ## arg21 ## arg22 ## arg23 ## arg24 ## arg25 ## arg26 ## arg27
#define JOY_CAT28(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27) JOY_CAT_NOEXP28(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27)
#define JOY_CAT_NOEXP29(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28) arg0 ## arg1 ## arg2 ## arg3 ## arg4 ## arg5 ## arg6 ## arg7 ## arg8 ## arg9 ## arg10 ## arg11 ## arg12 ## arg13 ## arg14 ## arg15 ## arg16 ## arg17 ## arg18 ## arg19 ## arg20 ## arg21 ## arg22 ## arg23 ## arg24 ## arg25 ## arg26 ## arg27 ## arg28
#define JOY_CAT29(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28) JOY_CAT_NOEXP29(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19, arg20, arg21, arg22, arg23, arg24, arg25, arg26, arg27, arg28)
/* [[[end]]] */

#endif /* !JOY_CAT_H */
