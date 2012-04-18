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
# ifndef CHAOS_PREPROCESSOR_REPETITION_X_REPEAT_SHIFTED_H
# define CHAOS_PREPROCESSOR_REPETITION_X_REPEAT_SHIFTED_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/repetition/x/delineate_shifted.h>
#
# /* CHAOS_PP_REPEAT_SHIFTED_X */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPEAT_SHIFTED_X(size, count, ...) CHAOS_PP_REPEAT_SHIFTED_X_S(CHAOS_PP_STATE(), size, count, __VA_ARGS__)
#    define CHAOS_PP_REPEAT_SHIFTED_X_ CHAOS_PP_LAMBDA(CHAOS_PP_REPEAT_SHIFTED_X_ID)()
# else
#    define CHAOS_PP_REPEAT_SHIFTED_X(size, count, macro, data) CHAOS_PP_REPEAT_SHIFTED_X_S(CHAOS_PP_STATE(), size, count, macro, data)
# endif
#
# define CHAOS_PP_REPEAT_SHIFTED_X_ID() CHAOS_PP_REPEAT_SHIFTED_X
#
# /* CHAOS_PP_REPEAT_SHIFTED_X_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REPEAT_SHIFTED_X_S(s, size, count, ...) CHAOS_PP_DELINEATE_SHIFTED_X_S(s, size, count, CHAOS_PP_EMPTY, __VA_ARGS__)
#    define CHAOS_PP_REPEAT_SHIFTED_X_S_ CHAOS_PP_LAMBDA(CHAOS_PP_REPEAT_SHIFTED_X_S_ID)()
# else
#    define CHAOS_PP_REPEAT_SHIFTED_X_S(s, size, count, macro, data) CHAOS_PP_DELINEATE_SHIFTED_X_S(s, size, count, CHAOS_PP_EMPTY, macro, data)
# endif
#
# define CHAOS_PP_REPEAT_SHIFTED_X_S_ID() CHAOS_PP_REPEAT_SHIFTED_X_S
#
# endif
