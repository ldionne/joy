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
# ifndef CHAOS_PREPROCESSOR_PUNCTUATION_COMMA_IF_H
# define CHAOS_PREPROCESSOR_PUNCTUATION_COMMA_IF_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/when.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
#
# /* CHAOS_PP_COMMA_IF */
#
# define CHAOS_PP_COMMA_IF(cond) CHAOS_PP_WHEN(cond)(CHAOS_PP_COMMA())
# define CHAOS_PP_COMMA_IF_ID() CHAOS_PP_COMMA_IF
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_COMMA_IF_ CHAOS_PP_LAMBDA(CHAOS_PP_COMMA_IF)
# endif
#
# endif
