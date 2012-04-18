# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_TUPLE_REM_H
# define CHAOS_PREPROCESSOR_TUPLE_REM_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_TUPLE_REM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_REM(size) CHAOS_IP_TUPLE_REM_I
#    define CHAOS_PP_TUPLE_REM_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_REM)
# else
#    define CHAOS_PP_TUPLE_REM(size) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_TUPLE_REM_, size)
# endif
#
# define CHAOS_PP_TUPLE_REM_ID() CHAOS_PP_TUPLE_REM
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_REM_I(...) __VA_ARGS__
# else
#    define CHAOS_IP_TUPLE_REM_0()
#    define CHAOS_IP_TUPLE_REM_1(a) a
#    define CHAOS_IP_TUPLE_REM_2(a, b) a, b
#    define CHAOS_IP_TUPLE_REM_3(a, b, c) a, b, c
#    define CHAOS_IP_TUPLE_REM_4(a, b, c, d) a, b, c, d
#    define CHAOS_IP_TUPLE_REM_5(a, b, c, d, e) a, b, c, d, e
#    define CHAOS_IP_TUPLE_REM_6(a, b, c, d, e, f) a, b, c, d, e, f
#    define CHAOS_IP_TUPLE_REM_7(a, b, c, d, e, f, g) a, b, c, d, e, f, g
#    define CHAOS_IP_TUPLE_REM_8(a, b, c, d, e, f, g, h) a, b, c, d, e, f, g, h
#    define CHAOS_IP_TUPLE_REM_9(a, b, c, d, e, f, g, h, i) a, b, c, d, e, f, g, h, i
#    define CHAOS_IP_TUPLE_REM_10(a, b, c, d, e, f, g, h, i, j) a, b, c, d, e, f, g, h, i, j
#    define CHAOS_IP_TUPLE_REM_11(a, b, c, d, e, f, g, h, i, j, k) a, b, c, d, e, f, g, h, i, j, k
#    define CHAOS_IP_TUPLE_REM_12(a, b, c, d, e, f, g, h, i, j, k, l) a, b, c, d, e, f, g, h, i, j, k, l
#    define CHAOS_IP_TUPLE_REM_13(a, b, c, d, e, f, g, h, i, j, k, l, m) a, b, c, d, e, f, g, h, i, j, k, l, m
#    define CHAOS_IP_TUPLE_REM_14(a, b, c, d, e, f, g, h, i, j, k, l, m, n) a, b, c, d, e, f, g, h, i, j, k, l, m, n
#    define CHAOS_IP_TUPLE_REM_15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o
#    define CHAOS_IP_TUPLE_REM_16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p
#    define CHAOS_IP_TUPLE_REM_17(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q
#    define CHAOS_IP_TUPLE_REM_18(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r
#    define CHAOS_IP_TUPLE_REM_19(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s
#    define CHAOS_IP_TUPLE_REM_20(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t
#    define CHAOS_IP_TUPLE_REM_21(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u
#    define CHAOS_IP_TUPLE_REM_22(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v
#    define CHAOS_IP_TUPLE_REM_23(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w
#    define CHAOS_IP_TUPLE_REM_24(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x
#    define CHAOS_IP_TUPLE_REM_25(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y) a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y
# endif
#
# /* CHAOS_PP_TUPLE_REM_CTOR */
#
# define CHAOS_PP_TUPLE_REM_CTOR(size, tuple) CHAOS_PP_TUPLE_REM(size) tuple
# define CHAOS_PP_TUPLE_REM_CTOR_ID() CHAOS_PP_TUPLE_REM_CTOR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_REM_CTOR_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_REM_CTOR_ID)()
# endif
#
# /* CHAOS_PP_REM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REM(...) __VA_ARGS__
#    define CHAOS_PP_REM_ CHAOS_PP_LAMBDA(CHAOS_PP_REM_ID)()
# else
#    define CHAOS_PP_REM(x) x
# endif
#
# define CHAOS_PP_REM_ID() CHAOS_PP_REM
#
# /* CHAOS_PP_REM_CTOR */
#
# define CHAOS_PP_REM_CTOR(tuple) CHAOS_PP_REM tuple
# define CHAOS_PP_REM_CTOR_ID() CHAOS_PP_REM_CTOR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REM_CTOR_ CHAOS_PP_LAMBDA(CHAOS_PP_REM_CTOR_ID)()
# endif
#
# endif
